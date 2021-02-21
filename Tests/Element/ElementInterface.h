#ifndef ELEMENTINTERFACE_H
#define ELEMENTINTERFACE_H
#include "../../Dimensions.h"
#include <cmath> 
#include <iostream>


// do rozpoznawania typu klasy dziedziczacej po Element*



class ElementInterface
{
private:
    Dimensions& dimensions; 

public:
    ElementInterface(Dimensions& dim); // ?? mockowac?
    virtual ~ElementInterface() = default;

//    virtual ElementType type() const = 0;
    virtual void calculateParameters() = 0;
    virtual void showParameters() = 0;

    virtual const Dimensions* getDimensions() const = 0;
    virtual Dimensions* setDimensions() = 0;

    virtual void setName(const std::string& n) = 0;
    virtual void setWidth() = 0;
    virtual void setHeight() = 0; 
    virtual void setLength(double value) = 0;
    virtual void setQuantity(int value) = 0;

    // do obliczen katow
    virtual double radiansToDegrees(double value) = 0;
    virtual double degreesToRadians(double value) = 0; 
    virtual void calculateAngles(double vertical, double horizontal) = 0; 
    virtual void showDimensions() const = 0; 

    // get
    virtual double getWidth() const = 0;
    virtual double getHeight() const = 0;
    virtual double getAlphaAngle() const = 0;
    virtual double getBetaAngle() const = 0;
    virtual double getQuantity() const = 0;
    virtual const std::string& getName() const = 0;

};


#endif // ELEMENTINTERFACE_H
