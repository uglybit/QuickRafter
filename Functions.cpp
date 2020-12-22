#include "Functions.h"
#include <iomanip>

using namespace std;


bool dataValidation(const string& info)
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


int validateNumber(std::string request, int range_low, int range_high,
    std::string info_bad_data = "This is not propper value");

double validateNumber(std::string request, double range_low, double range_high,
    std::string info_bad_data = "This is not propper value");
