#include <iostream>
#include "Menu.h"
//#include <conio.h>
//#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h> // w Visual Studio - sprawdzenie wyciek�w pami�ci

using namespace std;

int main()
{
    { // zakres w celu wykrycia wyciek�w pami�ci 
        Menu menu;
        menu.show();
    } 
    
    _CrtDumpMemoryLeaks(); // w Visual Studio - sprawdzenie wyciek�w pami�ci
    
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
