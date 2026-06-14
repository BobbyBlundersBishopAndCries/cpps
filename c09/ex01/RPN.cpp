#include "RPN.hpp"
std::stack<int> calc;

int rpn(char *av)
{
    std::string to_parse(av);

    for (size_t i = 0; i < to_parse.size(); i++)
    {
        if (to_parse[i] == ' ' || to_parse[i] == '\t')
            continue;
        if (std::isdigit(to_parse[i]))
            calc.push(to_parse[i] - '0');
        else if (to_parse[i] == '+' || to_parse[i] == '-' || to_parse[i] == '*' || to_parse[i] == '/')
        {
            if (calc.size() < 2)
                throw "Error: Not enough operands for operation";
            int b = calc.top();
            calc.pop();
            int a = calc.top();
            calc.pop();
            int result;
            switch (to_parse[i])
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0)
                        throw "Error: can't divide by 0";
                    result = a / b;
                    break;
                default:
                    throw "Error: Unknown operator";
            }
            calc.push(result);
        }
        else
            throw "Error: Invalid character in input";
    }
    if (calc.size() != 1)
        throw "Error: Invalid RPN expression";

    return 0;
}