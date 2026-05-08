#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>

void ScalarConverter::convert(const std::string& s) 
{
    char c = 0; 
    int i = 0; 
    float f = 0.0f; 
    double d = 0.0;
    bool impossible = false;
    
    char* end;
    d = std::strtod(s.c_str(), &end);
    std::string endStr(end);

    if (s.length() == 1 && !std::isdigit(s[0])) 
    {
        c = s[0]; 
        i = static_cast<int>(c); 
        f = static_cast<float>(c); 
        d = static_cast<double>(c);
    } 
    else if (endStr == "f") 
    {
        f = static_cast<float>(d); 
        c = static_cast<char>(f); 
        i = static_cast<int>(f); 
        d = static_cast<double>(f);
    } 
    else if (endStr == "") 
    {
        if (s.find('.') != std::string::npos || d > INT_MAX || d < INT_MIN || std::isnan(d)) 
        {
            c = static_cast<char>(d); 
            i = static_cast<int>(d); 
            f = static_cast<float>(d);
        } 
        else 
        {
            i = static_cast<int>(d); 
            c = static_cast<char>(i); 
            f = static_cast<float>(i); 
            d = static_cast<double>(i);
        }
    } 
    else 
        impossible = true;

    if (impossible) 
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }

    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) 
    {
        std::cout << "char: impossible\n";
    }
    else if (!std::isprint(i)) 
    {
        std::cout << "char: Non displayable\n";
    }
    else 
    {
        std::cout << "char: '" << c << "'\n";
    }
    
    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX) 
    {
        std::cout << "int: impossible\n";
    }
    else 
    {
        std::cout << "int: " << i << "\n";
    }
    
    if (d == std::floor(d) && !std::isinf(d) && !std::isnan(d)) 
    {
        std::cout << std::fixed << std::setprecision(1); 
    }
        
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << d << "\n";
}