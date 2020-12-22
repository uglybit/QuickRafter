#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>


bool dataValidation(const std::string& info);
std::ostream& manip(std::ostream&);


// walidacja danych - liczba
template<typename T>
T validateNumber(const std::string& request, const T range_low, const T range_high,
    const std::string& info_bad_data = "This is not propper value")
{
    T n;
    do
    {
        std::cout << std::endl << request << std::endl;
        std::cin >> n;
        if (dataValidation(info_bad_data)) { // zle dane
            continue;
        }
        else if (n < range_low || n > range_high) {   // poza zakresem 
            std::cout << "You can choose from: " << range_low << " to "
                      << range_high << ". Try again" << std::endl;
        }
        else {
            break; 
        }
    } while (true);

    return n;
}
#endif