#include "Element.h"


Element::Element(Dimensions& dim) : dimensions{dim}
{

}


ElementType Element::type() const 
{
    return ElementType::Element;
}


const Dimensions* Element::getDimensions() const
{
    return &dimensions;
}


Dimensions* Element::setDimensions()
{
    return &dimensions; 
}


void Element::setName(const std::string& n) 
{
    name = n;
}


void Element::setWidth() // ustawienie szeroko�ci elementu
{
    double tmpValue;
    std::cout << name;
    tmpValue = validateNumber<double>("\twidth:  ", 10.0, 500.0);
    width = tmpValue; 
    std::cout << "halllo " << width << '\n';
}

void Element::setWidth(double value)
{
    width = value;
}

void Element::setHeight(double value) 
{
    height = value;
}


void Element::setHeight() // ustawienie wysoko�ci elementu
{
    std::cout << name;
    height = validateNumber<double>("\theight:  ", 10.0, 500.0);
    std::cout << height << '\n';
}


void Element::setLength(double value) 
{
    length = value; 
}


void Element::setQuantity(int value)
{
    quantity = value;
}


void Element::showDimensions() const
{
    std::cout << '\n' << name <<  "\n\t(width/height/length): "
         << width << "/" << height << "/" << length;
}


double Element::radiansToDegrees(double value) 
{
    return value *= convRadtoDeg;
}


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


double Element::getWidth() const
{ 
    return width; 
}


double Element::getHeight() const 
{
    return height; 
}


double Element::getAlphaAngle() const 
{ 
    return alphaAngle;
}


double Element::getBetaAngle() const 
{
    return betaAngle; 
}


double Element::getQuantity() const
{ 
    return quantity; 
}


const std::string& Element::getName() const 
{ 
    return name;
}