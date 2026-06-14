#include "PmergeMe.hpp"

// ===== GLOBALS =====
std::vector<unsigned int> v;
std::deque<unsigned int> dq;

unsigned int v_straggler = 0;
bool v_has_straggler = false;

unsigned int dq_straggler = 0;
bool dq_has_straggler = false;
unsigned int parse_number(const char *s)
{
    unsigned int r = 0;

    for (size_t i = 0; s[i]; i++)
    {
        if (!std::isdigit(s[i]))
            throw "Error";

        if (r > UINT_MAX / 10 || (r == UINT_MAX / 10 && (s[i] - '0') > 9))
            throw "Error";

        r = r * 10 + (s[i] - '0');
    }
    return r;
}
void parse_data(char **av)
{
    for (int i = 1; av[i]; i++)
    {
        unsigned int n = parse_number(av[i]);
        v.push_back(n);
        dq.push_back(n);
    }
}
static std::vector<std::pair<unsigned int, unsigned int> >
make_pairs(const std::vector<unsigned int> &a)
{
    std::vector<std::pair<unsigned int, unsigned int> > res;

    for (size_t i = 0; i + 1 < a.size(); i += 2)
        res.push_back(std::make_pair(a[i], a[i + 1]));

    return res;
}
static void sort_pairs(std::vector<std::pair<unsigned int, unsigned int> > &p)
{
    for (size_t i = 0; i < p.size(); i++)
        if (p[i].first < p[i].second)
            std::swap(p[i].first, p[i].second);
}
static void split_pairs(const std::vector<std::pair<unsigned int, unsigned int> > &p,
                        std::vector<unsigned int> &big,
                        std::vector<unsigned int> &small)
{
    for (size_t i = 0; i < p.size(); i++)
    {
        big.push_back(p[i].first);
        small.push_back(p[i].second);
    }
}
static void insertion_sort(std::vector<unsigned int> &v)
{
    for (size_t i = 1; i < v.size(); i++)
    {
        unsigned int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}
static std::vector<size_t> jacobsthal(size_t n)
{
    std::vector<size_t> order;
    std::vector<bool> used(n, false);

    if (!n) return order;

    order.push_back(0);
    used[0] = true;

    size_t a = 0, b = 1;

    while (order.size() < n)
    {
        size_t next = a + 2 * b;

        for (size_t i = next; i > b; --i)
        {
            size_t idx = i - 1;
            if (idx < n && !used[idx])
            {
                used[idx] = true;
                order.push_back(idx);
            }
        }

        a = b;
        b = next;
    }

    for (size_t i = 0; i < n; i++)
        if (!used[i])
            order.push_back(i);

    return order;
}
static void binary_insert(std::vector<unsigned int> &a, unsigned int val)
{
    size_t l = 0, r = a.size();

    while (l < r)
    {
        size_t m = (l + r) / 2;
        if (a[m] < val)
            l = m + 1;
        else
            r = m;
    }
    a.insert(a.begin() + l, val);
}
static void insert_small(std::vector<unsigned int> &big,
                         std::vector<unsigned int> &small)
{
    std::vector<size_t> ord = jacobsthal(small.size());

    for (size_t i = 0; i < ord.size(); i++)
        binary_insert(big, small[ord[i]]);
}
void run_vector_sort()
{
    std::vector<std::pair<unsigned int, unsigned int> > p = make_pairs(v);

    sort_pairs(p);
    std::vector<unsigned int> big;
    std::vector<unsigned int> small;
    split_pairs(p, big, small);
    insertion_sort(big);
    insert_small(big, small);
    if (v.size() % 2 != 0)
        binary_insert(big, v.back());


    v = big;
}
void run_deque_sort()
{
    std::vector<unsigned int> tmp(dq.begin(), dq.end());
    std::vector<std::pair<unsigned int, unsigned int> > p = make_pairs(tmp);
    sort_pairs(p);
    std::vector<unsigned int> big;
    std::vector<unsigned int> small;
    split_pairs(p, big, small);
    insertion_sort(big);
    std::vector<size_t> ord = jacobsthal(small.size());

    for (size_t i = 0; i < ord.size(); i++)
    {
        if (v.size() % 2 != 0)
        {
            unsigned int val = v.back();

            size_t l = 0, r = big.size();
            while (l < r)
            {
                size_t m = (l + r) / 2;
                if (big[m] < val) l = m + 1;
                else r = m;
            }
            big.insert(big.begin() + l, val);
        }
        unsigned int val = small[ord[i]];
        size_t l = 0, r = big.size();
        while (l < r)
        {
            size_t m = (l + r) / 2;
            if (big[m] < val) l = m + 1;
            else r = m;
        }

        big.insert(big.begin() + l, val);
    }
    dq = std::deque<unsigned int>(big.begin(), big.end());
}