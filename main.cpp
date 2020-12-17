#include <iostream>
#include "Menu.h"
//#include <conio.h>
//#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h> // w Visual Studio - sprawdzenie wycieków pamiêci

using namespace std;

int main()
{
    { // zakres w celu wykrycia wycieków pamiêci 
        Menu menu;
        menu.show();
    } 
    
    _CrtDumpMemoryLeaks(); // w Visual Studio - sprawdzenie wycieków pamiêci
    
    return 0;
}


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
