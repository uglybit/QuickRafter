#ifndef ELEMENT_H
#define ELEMENT_H

#include "ElementInterface.h"
#include <cmath> 
#include <iostream>

class Element
{
public:
    Element(Dimensions& dim);
    virtual ~Element() = default;

    virtual ElementType type() const;
    virtual void calculateParameters() = 0;
    virtual void showParameters() = 0;

    const Dimensions* getDimensions() const;
    Dimensions* setDimensions();

    void setName(const std::string& n);
    void setWidth();
    void setHeight(); 
    void setLength(double value);
    void setQuantity(int value);

    // do obliczen katow
    double radiansToDegrees(double value);
    double degreesToRadians(double value); 
    void calculateAngles(double vertical, double horizontal); 
    void showDimensions() const; 

    // get
    double getWidth() const;
    double getHeight() const;
    double getAlphaAngle() const;
    double getBetaAngle() const;
    double getQuantity() const;
    const std::string& getName() const;


#if defined TEST
    void setHeight(double value); 
    void setWidth(double value); 
#endif
    
};


#endif // ELEMENT_H
