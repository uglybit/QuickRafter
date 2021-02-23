#ifndef ELEMENT_H
#define ELEMENT_H

#include "Dimensions.h"
#include <cmath> 
#include <iostream>

//#include "Tests/Element/ElementInterface.h"

enum class ElementType {
    Element,
    CommonRafter,
    HipRafter,
    ValleyRafter,
    Purlin,
    PurlinProp,
    WallPlate,
    CollarBeam
    };



class Element
{
private:
    // przelicznik do konwersji radiany <--> stopnie
    static constexpr  double convRadtoDeg = 180 / 3.141592653589;
    static constexpr  double convDegToRad = 3.141592653589 / 180;

    std::string name; 
    double length{ 0.0 };
    double width{ 0.0 };
    double height{ 0.0 }; 
    int quantity{ 0 };
        
    double alphaAngle{ 0.0 }; // k�t nachylenia dachu wzgeldem poziomu  
    double betaAngle{ 0.0 }; //  k�t nachylenia dachu wzgledem pionu
    Dimensions& dimensions;

public:
    Element(Dimensions& dim);
    virtual ~Element() = default;

    virtual ElementType type() const;
    virtual void calculateParameters() {} //= 0;
    virtual void showParameters() {} //= 0;

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


//#if defined TEST
    void setHeight(double value); 
    void setWidth(double value); 
//#endif
    
};


#endif // ELEMENT_H
