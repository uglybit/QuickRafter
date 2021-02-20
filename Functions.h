#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>

std::ostream& manip(std::ostream&);


bool dataValidation(const std::string& info);

// walidacja danych - liczba
template<typename T>
T validateNumber(const std::string& request, const T range_low, const T range_high,
    const std::string& info_bad_data = "Thisddddddddddddd is not proper value\n")
{
    T number;
    while (true)
    {
        std::cout << '\n' << request;
        std::cin >> number;
        if (!dataValidation(info_bad_data)) { // zle dane
            continue;
        }
        else if (number < range_low || number > range_high) {   // poza zakresem 
            std::cout << "\nYou can choose from: " << range_low << " to "
                    << range_high << ". Try again\n";
        }
        else {
            break; 
        }
    }

    return number;
}
#endif