#include "Menu.h"

using namespace std;

Menu::~Menu() { 
if (truss != nullptr)
    delete truss;
}


void Menu::show()
{
    std::cout << "\n\t* QuickRafter *\n\n";
    std::cout << "1. Gable roof without purlins\n";
    std::cout << "2. Gable roof with purlins\n";
    std::cout << "3. Hipped roof without purlins\n";
    std::cout << "4. Hipped roof with purlins\n" << std::endl;
   
    // w kostruktorze uzytkownik dostaje instrukcje i wpisuje wartosci
    Dimensions dimensions; 
    
    auto choice = validateNumber("Choose option 1-4: ", 1, 4);

    switch(choice)
    {
        case 1: truss = new GableRoof(dimensions); break;
        case 2: truss = new GableRoof(dimensions, true); break;
        case 3: truss = new HippedRoof(dimensions, "string"); break;
        case 4: truss = new HippedRoof(dimensions, true); break;
    }

    cout << truss->getTrussType() << endl; 
    truss->calcParam(); 
    truss->show(); 
}
