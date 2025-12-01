#include "Sed.hpp"
#include <iostream>
#include <fstream>

Sed::Sed(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}

Sed::~Sed() {}

void Sed::Replace()
{
	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return;
	}
	std::ifstream infile(filename.c_str());
	if (!infile) {
		std::cerr << "Error: cannot open input file." << std::endl;
		return;
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile) {
		std::cerr << "Error: cannot create output file." << std::endl;
		return;
	}
	std::string line;
	while (std::getline(infile, line)) {
		std::string result;
		size_t pos = 0;
		size_t found;
		while ((found = line.find(s1, pos)) != std::string::npos) {
			result += line.substr(pos, found - pos);
			result += s2;
			pos = found + s1.length();
		}

		result += line.substr(pos);
		outfile << result;

		if (!infile.eof())
			outfile << '\n';
	}
}
