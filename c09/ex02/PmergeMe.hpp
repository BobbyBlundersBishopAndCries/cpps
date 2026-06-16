#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <utility>
#include <sys/time.h>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <climits>
extern std::vector<unsigned int> g_vec;
extern std::deque<unsigned int> g_deq;

void parse_args(int argc, char **argv);
void run();

#endif