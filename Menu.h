#ifndef MENU_H
#define MENU_H

#include "Truss.h" 

class Menu
{
    Truss *truss = nullptr;
    OverallDimensions *dimensions = nullptr;
public:
    Menu() {} 
    ~Menu();

    void show(); // pokazuje wszystkie elementy wiêŸby

};

#endif // MENU_H
