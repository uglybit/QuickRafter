#include "Menu.h"

using namespace std;

Menu::~Menu() { // destrukor
if (truss != nullptr)
    delete truss;
if (dimensions != nullptr)
    delete dimensions;
}


// pokazuje g³ówne menu
void Menu::show()
{
    int choice;
    cout << "\n\t* QuickRafter *\n\n"
         << "1. Gable roof without purlins\n"
         << "2. Gable roof with purlins\n"
         << "3. Hipped roof without purlins\n"
         << "4. Hipped roof with purlins\n" 
         << endl;

    choice = validateNumber<int>("Choose option 1-4: ", 1, 4);

    dimensions = new OverallDimensions;
    
    switch(choice)
    {
        case 1: truss = new GableRoof(); break;
        case 2: truss = new GableRoof(true); break;
        case 3: truss = new HippedRoof("string"); break;
        case 4: truss = new HippedRoof(true); break;
    }

    cout << truss->getTrussType() << endl; // informacja o typie dachu
    truss->calcParam(); // oblicznie parametrów
    truss->show(); // wyœwielenie obliczeñ
}
