#ifndef MENU_H
#define MENU_H

#include "Truss.h" 
#include "GableRoof.h"
#include "HippedRoof.h"
#include "Dimensions.h"

class Menu
{
    Truss *truss = nullptr;
   // Dimensions *dimensions = nullptr;
public:
    Menu() = default;
    ~Menu();

    void show(); // pokazuje wszystkie elementy wiêŸby

};

#endif // MENU_H
