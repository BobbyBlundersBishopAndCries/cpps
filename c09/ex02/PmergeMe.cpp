#include "PmergeMe.hpp"
#include <climits>

std::vector<unsigned int> g_vec;
std::deque<unsigned int> g_deq;
void parse_args(int ac, char** av)
{
    for (int i = 1; i < ac; i++)
    {
        if (av[i][0] == '\0')
            throw "Error\n";
        for (size_t j = 0; av[i][j]; j++)
        {
            if (!(std::isdigit(av[i][j]) || av[i][0] == '+'))
                throw "Error\n";
        }
            long val = std::atol(av[i]);
            if (val < 0 || val > UINT_MAX)
                throw "Error\n";
            g_vec.push_back(static_cast<unsigned int>(val));
            g_deq.push_back(static_cast<unsigned int>(val));
        }
    if (g_vec.empty()) 
        throw "Error\n";
}
template <typename T>
static void print_sequence(const T& container, const std::string& prefix)
{
    std::cout << prefix << " ";
    size_t limit = container.size() > 5 ? 5 : container.size();
    typename T::const_iterator it = container.begin();
    for (size_t i = 0; i < limit; ++i, ++it)
        std::cout << *it << " ";
    if (container.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
}

static size_t jacobsthal_order(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t current = 1;
    for (size_t i = 2; i <= n; ++i)
    {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

void mergeSortPairsVec(std::vector<std::pair<unsigned int, unsigned int> >& pairs, int left, int right)
{
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortPairsVec(pairs, left, mid);
    mergeSortPairsVec(pairs, mid + 1, right);
    std::vector<std::pair<int, int> > temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (pairs[i].first <= pairs[j].first)
            temp.push_back(pairs[i++]);
        else 
            temp.push_back(pairs[j++]);
    }
    while (i <= mid) temp.push_back(pairs[i++]);
    while (j <= right) temp.push_back(pairs[j++]);
    for (int k = 0; k < (int)temp.size(); ++k)
        pairs[left + k] = temp[k];
}

void mergeInsertSortVec(std::vector<unsigned int>& arr)
{
    if (arr.size() < 2) return;
    std::vector<std::pair<unsigned int, unsigned int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;
    if (arr.size() % 2 != 0)
    {
        straggler = arr.back();
        hasStraggler = true;
        arr.pop_back();
    }
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i+1])
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        else
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
    }
    mergeSortPairsVec(pairs, 0, pairs.size() - 1);
    std::vector<unsigned int> mainChain;
    std::vector<unsigned int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    mainChain.insert(mainChain.begin(), pend[0]);
    std::vector<int> insertionOrder;
    size_t jacobIndex = 3;
    size_t lastJacob = 1;
    while (lastJacob < pend.size())
    {
        size_t currentJacob = jacobsthal_order(jacobIndex);
        size_t start = std::min(currentJacob, pend.size());
        for (size_t i = start; i > lastJacob; --i)
            insertionOrder.push_back(i - 1);
        lastJacob = start;
        jacobIndex++;
    }

    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int elementToInsert = pend[insertionOrder[i]];
        std::vector<unsigned int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), elementToInsert);
        mainChain.insert(it, elementToInsert);
    }
    if (hasStraggler) {
        std::vector<unsigned int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }
    arr = mainChain;
}

void mergeSortPairsDeq(std::deque<std::pair<unsigned int, unsigned int> >& pairs, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortPairsDeq(pairs, left, mid);
    mergeSortPairsDeq(pairs, mid + 1, right);

    std::deque<std::pair<int, int> > temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (pairs[i].first <= pairs[j].first)
            temp.push_back(pairs[i++]);
        else 
            temp.push_back(pairs[j++]);    
    }
    while (i <= mid) temp.push_back(pairs[i++]);
    while (j <= right) temp.push_back(pairs[j++]);
    for (int k = 0; k < (int)temp.size(); ++k)
        pairs[left + k] = temp[k];
}

void mergeInsertSortDeq(std::deque<unsigned int>& arr)
{
    if (arr.size() < 2) return;
    std::deque<std::pair<unsigned int, unsigned int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;
    if (arr.size() % 2 != 0)
    {
        straggler = arr.back();
        hasStraggler = true;
        arr.pop_back();
    }
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i+1]) 
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        else 
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
    }
    mergeSortPairsDeq(pairs, 0, pairs.size() - 1);
    std::deque<unsigned int> mainChain;
    std::deque<unsigned int> pend;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    mainChain.insert(mainChain.begin(), pend[0]);
    std::deque<int> insertionOrder;
    size_t jacobIndex = 3;
    size_t lastJacob = 1;
    while (lastJacob < pend.size())
    {
        size_t currentJacob = jacobsthal_order(jacobIndex);
        size_t start = std::min(currentJacob, pend.size());
        for (size_t i = start; i > lastJacob; --i)
            insertionOrder.push_back(i - 1);
        lastJacob = start;
        jacobIndex++;
    }
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int elementToInsert = pend[insertionOrder[i]];
        std::deque<unsigned int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), elementToInsert);
        mainChain.insert(it, elementToInsert);
    }
    if (hasStraggler)
    {
        std::deque<unsigned int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }
    arr = mainChain;
}

void run()
{
    print_sequence(g_vec, "Before:");
    struct timeval start, end;
    gettimeofday(&start, NULL);
    mergeInsertSortVec(g_vec);
    gettimeofday(&end, NULL);
    double timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    struct timeval dstart, dend;
    gettimeofday(&dstart, NULL);
    mergeInsertSortDeq(g_deq);
    gettimeofday(&dend, NULL);
    double timeDeq = (dend.tv_sec - dstart.tv_sec) * 1000000.0 + (dend.tv_usec - dstart.tv_usec);
    print_sequence(g_vec, "After: ");
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << g_vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << g_deq.size() << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
