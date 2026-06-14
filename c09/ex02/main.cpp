#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error\n";
        return 1;
    }

    try
    {
        parse_data(av);

        std::cout << "Before: ";
        for (size_t i = 0; i < v.size(); i++)
            std::cout << v[i] << " ";
        std::cout << "\n";

        clock_t start = clock();
        run_vector_sort();
        clock_t end = clock();

        double t_vec = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;

        start = clock();
        run_deque_sort();
        end = clock();

        double t_deq = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;

        std::cout << "After: ";
        for (size_t i = 0; i < v.size(); i++)
            std::cout << v[i] << " ";
        std::cout << "\n";

        std::cout << "Time to process a range of " << v.size()
                  << " elements with std::vector : "
                  << std::fixed << std::setprecision(5)
                  << t_vec << " us\n";

        std::cout << "Time to process a range of " << dq.size()
                  << " elements with std::deque : "
                  << std::fixed << std::setprecision(5)
                  << t_deq << " us\n";
        v.clear();
        dq.clear();
    }
    catch (...)
    {
        std::cerr << "Error\n";
        return 1;
    }
}