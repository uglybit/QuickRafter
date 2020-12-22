#ifndef ELEMENT_H
#define ELEMENT_H

#include "Dimensions.h"
#include <cmath> 
#include <iostream>

// do rozpoznawania typu klasy dziedzicz�cej po Element*
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
    // konwersja radiany - stopnie i odwrotnie
    static constexpr  double convRadtoDeg = 180 / 3.141592653589;
    static constexpr  double convDegToRad = 3.141592653589 / 180;

    // nazwa i wymiary elementu
    std::string name; 
    double length{ 0.0 };
    double width{ 0.0 };
    double height{ 0.0 }; 
    int quantity{ 0 }; // ilo��
        
    double alphaAngle{ 0.0 }; // k�t dachu wzg�ldem poziomu  
    double betaAngle{ 0.0 }; // 90 - alphAangle: k�t dachu wzgl�dem pionu
    Dimensions& dimensions;

public:
    Element(Dimensions& dim);
    virtual ~Element() = default;

    // do sprawdzenia typu elementu
    virtual ElementType type() const { return ElementType::Element; }
   
    virtual void calculateParameters() = 0;
    virtual void showParameters() { std::cout << name; }

    void setName(const std::string& n)
    {
        name = n;
    }
    // ustawienie wymiar�w   
    void setWidth();
    void setHeight(); 
    void setLength(double value) { length = value; }
    void setQuantity(int value) { quantity = value; }

    // do oblicze� k�t�w
    double radiansToDegrees(double value);
    double degreesToRadians(double value); 
    void calculateAngles(double vertical, double horizontal); 
    void showDimensions() const; 

    // get
    double getWidth() const { return width;  }
    double getHeight() const { return height;  }
    double getAlphaAngle() const { return alphaAngle; }
    double getBetaAngle() const { return betaAngle; }
    double getQuantity() const { return quantity; }
    const std::string& getName() const { return name; }


    /* TESTY */
    void setHeight(double value); // TESTY!
    void setWidth(double value); 
    const Dimensions* getDimensions() const ;
    Dimensions* setDimensions() { return &dimensions;  }
};


#endif // ELEMENT_H
