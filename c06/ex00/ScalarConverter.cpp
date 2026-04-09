#include "ScalarConverter.hpp"
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
static void displayChar(double value)
{
	if (std::isinf(value) || std::isnan(value) || value > 127 || value < -128)
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(value);
		if( c < 32 || c > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
	} 
}

static void displayInt(double value)
{
	if(std::isinf(value) || std::isnan(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void displayFloat(double value)
{
	float f = static_cast<float>(value);
	if (std::isinf(f))
		std::cout << "float: " << (f > 0? "+inff":"-inff") << std::endl;
	else if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else
	{
		std::cout << "float: ";
		if (f == static_cast<int>(f) && f >= -1e6 && f <= 1e6)
			std::cout << std::fixed << std::setprecision(1);
		std::cout << f << "f" << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
}

static void displayDouble(double value)
{
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
		std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		std::cout << "double: ";
		if (value == static_cast<int>(value) && value >= -1e6 && value <= 1e6)
			std::cout << std::fixed << std::setprecision(1);
		std::cout << value << std::endl;
		std::cout.unsetf(std::ios::fixed);
	}
}

void ScalarConverter::convert(const std::string& a)
{
	char* end;
	double value = std::strtod(a.c_str(), &end);
	
	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}