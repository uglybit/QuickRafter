#include <iostream>
#include "Menu.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

/* true - pomijanie wpisywania wszystkich wartoœci
i obliczanie dla domyœlnych - do testów */
//bool TEST = true;

int main()
{
    { // zakres lokalny w celu wykrycie wycieków pamiêci 
        Menu menu;
        menu.show();
        //int* a = new int;
    } 
    
    _CrtDumpMemoryLeaks(); // Visual Studio - sprawdzenie wycieków pamiêci
    
    return 0;
}


// funkcje globalne u¿ywane w kilku klasach - walidacja etc
/*
void requireEnter()
{
    cout << "\nClick Enter to continue... \n";
    while (_getch() != 13);
}*/

bool dataValidation(string info)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10, '\n');
        cout << info;
        // require_enter();
        return true;
    }
    else
        return false;
}


ostream& manip(ostream& o) // formatowanie wypisywania liczb
{
    o << fixed << setprecision(0);
    return o;
}
