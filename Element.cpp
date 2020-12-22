#include "Element.h"


Element::Element( Dimensions& dim) : dimensions{dim}
{

}


const Dimensions* Element::getDimensions() const
{
    return &dimensions;
}


void Element::setWidth() // ustawienie szerokoœci elementu
{
    double tmpValue;
    std::cout << name;
    tmpValue = validateNumber("\twidth:  ", 10.0, 500.0);
    width = tmpValue; 
}

void Element::setWidth(double value) // TESTY!
{
    width = value;
}
void Element::setHeight(double value) // TESTY!
{
    height = value;
}


void Element::setHeight() // ustawienie wysokoœci elementu
{
    std::cout << name;
    height = validateNumber("\theight:  ", 10.0, 500.0);
}


// wyœwietlenie wymiarów
void Element::showDimensions() const
{
    std::cout << '\n' << name <<  "\n\t(width/height/length): "
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

