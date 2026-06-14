#ifndef PMERGME_HPP
#define PMERGME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <climits>
#include <cctype>
#include <algorithm>
#include <ctime>
#include <iomanip>

// ===== GLOBAL DATA =====
extern std::vector<unsigned int> v;
extern std::deque<unsigned int> dq;

// straggler (vector / deque)
extern unsigned int v_straggler;
extern bool v_has_straggler;

extern unsigned int dq_straggler;
extern bool dq_has_straggler;

// ===== FUNCTIONS =====
unsigned int parse_number(const char *av);
void parse_data(char **av);

void run_vector_sort();
void run_deque_sort();

#endif