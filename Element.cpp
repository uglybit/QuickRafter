#include "Element.h"

using namespace std;


void Element::setWidth() // ustawienie szeroko�ci elementu
{
/*
TEST // TEST - ZMIANA
    double value;
    cout << name << " width: " << std::endl;
    cin >> value;
    width = value;
*/
 // TEST - ZMIANA
    double tmpValue;
    cout << name;
    tmpValue = validateNumber("\twidth:  ", 10.0, 500.0);
    width = tmpValue; 
}


void Element::setHeight() // ustawienie wysoko�ci elementu
{
/*
    (!TEST)  ZMIANA
    double value;
    std::cout << name << " height: " << std::endl;
    std::cin >> value;
    height = value;
*/
    // TEST - ZMIANA
    cout << name;
    height = validateNumber("\theight:  ", 10.0, 500.0);
}


// wy�wietlenie wymiar�w
void Element::showDimensions() 
{
    cout << '\n' << name <<  "\n\t(width/height/length): "
         << width << "/" << height << "/" << length;
}


// konwersja radiany -> stopnie
double Element::radiansToDegrees(double value) 
{
    return value *= convRadtoDeg;
}


// konwersja stopnie -> radiany
double Element::degreesToRadians(double value)
{
    return value *= convDegToRad;
}


// obliczenia k�ta dachu
void Element::calculateAngles(double vertical, double horizontal)
{
    double radians = atan(vertical/horizontal);
    alphaAngle = radiansToDegrees(radians);
    betaAngle = 90 - alphaAngle;
}


/*************** WALL PLATE **********************/


// mur�ata
WallPlate::WallPlate()
{
     name = "Wall plate";
     setParameters();
}


void WallPlate::setParameters() // override
{
#ifndef TEST // TEST
    setWidth();
    setHeight();

#else // TEST - bez r�cznego wpisywania warto�ci
    width = 140;
    height  = 140;
#endif
}


void WallPlate::showParameters() //override
{
    showDimensions();
}


void WallPlate::calculateParameters() //override
{
    length = OvDim::getTrussLength();
}