#ifndef MENU_H
#define MENU_H

#include "Truss.h" 
#include "GableRoof.h"
#include "HippedRoof.h"
#include "Dimensions.h"

class Menu
{
    Truss *truss = nullptr;
public:
    Menu() = default;
    ~Menu();

    void show();
};

#endif // MENU_H
