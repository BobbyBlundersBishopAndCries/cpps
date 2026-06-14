#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
extern std::map<std::string, float> exchangeRates;
void init_map();
int read_file(const char *filename);
#endif