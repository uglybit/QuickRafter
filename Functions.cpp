#include "Functions.h"
#include <iomanip>

// formatowanie wypisywania liczb
std::ostream& manip(std::ostream& o) 
{
    o << std::fixed << std::setprecision(0);
    return o;
}

bool dataValidation(const std::string& info)
{
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10, '\n');
        std::cout << info;
        return false;
    }
    return true;
}


int validateNumber(std::string request, int range_low, int range_high,
    std::string info_bad_data = "This is not propper value");

double validateNumber(std::string request, double range_low, double range_high,
    std::string info_bad_data = "This is not propper value");


