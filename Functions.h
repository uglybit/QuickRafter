#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>


bool dataValidation(std::string info);
std::ostream& manip(std::ostream&);



// walidacja danych wejœciowych - liczba
template<typename T>
T validateNumber(std::string request, T range_low, T range_high,
    std::string info_bad_data = "This is not propper value")
{
    T n;
    do
    {
        std::cout << std::endl << request << std::endl;
        std::cin >> n;
        if (dataValidation(info_bad_data))// zle dane 
            continue;
        else if (n < range_low || n > range_high) // jesli poza zakresem 
        {
            std::cout << "You can choose from: " << range_low << " to "
                << range_high << ". Try again" << std::endl;
        }
        else break; // wszystko ok- wyjscie z petli
    } while (true);

    return n;
}




#endif