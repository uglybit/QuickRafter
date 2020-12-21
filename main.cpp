#include <iostream>
#include "Menu.h"
#include <stdlib.h>

using namespace std;

int main()
{
    Menu menu;
    menu.show();
    
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
    else {
        return false;
    }
}


ostream& manip(ostream& o) // formatowanie wypisywania liczb
{
    o << fixed << setprecision(0);
    return o;
}
