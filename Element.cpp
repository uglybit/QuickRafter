#include "Element.h"

using namespace std;


Element::Element(Dimensions& dim) : dimension{dim}
{

}


const Dimensions* Element::getDimensions()
{
    return &dimension;
}


void Element::setWidth() // ustawienie szerokoœci elementu
{
    double tmpValue;
    cout << name;
    tmpValue = validateNumber("\twidth:  ", 10.0, 500.0);
    width = tmpValue; 
}

void Element::setWidth(double widt) // TESTY!
{
    width = widt;
}
void Element::setHeight(double heigh) // TESTY!
{
    height = heigh;
}


void Element::setHeight() // ustawienie wysokoœci elementu
{
    cout << name;
    height = validateNumber("\theight:  ", 10.0, 500.0);
}


// wyœwietlenie wymiarów
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


// obliczenia k¹ta dachu
void Element::calculateAngles(double vertical, double horizontal)
{
    double radians = atan(vertical/horizontal);
    alphaAngle = radiansToDegrees(radians);
    betaAngle = 90 - alphaAngle;
}

