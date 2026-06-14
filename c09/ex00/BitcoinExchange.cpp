#include "BitcoinExchange.hpp"
#include <iomanip>

std::map<std::string, float> exchangeRates;
static float stringToFloat(const std::string &str)
{
    std::stringstream ss(str);
    float num;
    ss >> num;
    return num;
}

static int stringToInt(const std::string &str)
{
    std::stringstream ss(str);
    int num;
    ss >> num;
    return num;
}

static bool isValidDate(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
   for (size_t i = 0; i < yearStr.size(); ++i)
    {
        if (!std::isdigit(yearStr[i]))
            return false;
    }
    for (size_t i = 0; i < monthStr.size(); ++i)
    {
        if (!std::isdigit(monthStr[i]))
            return false;
    }
    for (size_t i = 0; i < dayStr.size(); ++i)
    {
        if (!std::isdigit(dayStr[i]))
            return false;
    }
    int year = stringToInt(yearStr);
    int month = stringToInt(monthStr);
    int day = stringToInt(dayStr);

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeapYear ? 29 : 28))
            return false;
    }

    return true;
}

void init_map()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file.\n";
        return;
    }

    std::string line;
    std::getline(file, line); // Skip the header line

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date, rateStr;

        if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
        {
            exchangeRates[date] = stringToFloat(rateStr);
        }
    }
}

int read_file(const char *filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip the header line again
    if (line != "date | value")
    {
        std::cerr << "Error: header should be written like this : \"date | value\"\n";
        return 1;
    }
    
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date, value;

        if (!std::getline(ss, date, '|') || !std::getline(ss, value))
        {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }
        date = date.substr(0, date.find_last_not_of(" \t") + 1);
        value = value.substr(value.find_first_not_of(" \t"));
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << "\n";
            continue;
        }
        try
        {
            float num = stringToFloat(value);
            if (num < 0)
            {
                std::cout << "Error: not a positive number.\n";
                continue;
            }
            if (num > 1000)
            {
                std::cout << "Error: too large a number.\n";
                continue;
            }
            std::map<std::string, float>::iterator it = exchangeRates.lower_bound(date);
            if (it == exchangeRates.end() || it->first != date)
            {
                if (it == exchangeRates.begin())
                {
                    std::cout << "Error: bad input => " << date << "\n";
                    continue;
                }
                --it;
            }
            float rate = it->second;
            float result = num * rate;
            std::ostringstream formattedResult;
            formattedResult << std::fixed << std::setprecision(2) << result;
            std::cout << date << " => " << num << " = " << formattedResult.str() << "\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: bad input => " << value << "\n";
        }
    }
    return 0;
}
