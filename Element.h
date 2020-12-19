#ifndef ELEMENT_H
#define ELEMENT_H

#include "OverallDimensions.h"
#include <cmath> 
#include <iostream>

// do rozpoznawania typu klasy dziedzicz¹cej po Element*
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


using OvDim =  OverallDimensions; // skrócenie zapisu

class Element
{
//protected:
    std::string name; // nazwa elementu
    // trzy wymiary elementu

protected: /*** zamienic na private */
    double length{ 0.0 };
    double width{ 0.0 };
    double height{ 0.0 }; 
    double alphaAngle{ 0.0 };  // k¹t dachu wzgêldem poziomu
    double betaAngle{ 0.0 }; // 90 - alphAangle: k¹t dachu wzglêdem pionu
    int quantity{0}; // iloœæ elementów

    // konwersja radiany - stopnie i odwrotnie
    static constexpr  double convRadtoDeg = 180 / 3.141592653589;
    static constexpr  double convDegToRad = 3.141592653589 / 180;

public:
    Element() {}
    virtual ~Element() {}

    // do sprawdzenia typu elementu
    virtual ElementType type() const { return ElementType::Element; }
   
    virtual void calculateParameters() = 0;
    virtual void setParameters() = 0;
    virtual void showParameters() { std::cout << name; }

    void setName(const std::string& n)
    {
        name = n;
    }
    // ustawienie wymiarów   
    void setWidth();
    void setHeight(); 
    void setLength(double value) { length = value; }
    void setQuantity(int value) { quantity = value; }

    // do obliczeñ k¹tów
    double radiansToDegrees(double value);
    double degreesToRadians(double value); 

    // obliczenie k¹ta
    void calculateAngles(double vertical, double horizontal); 

    // pokazuje wymiary elementu
    void showDimensions(); 

    // get

    double getWidth() { return width;  }
    double getHeight() { return height;  }
    double getAlfaAngle() { return alphaAngle; }
    double getBetaAngle() { return betaAngle; }
    double getQuantity()  { return quantity; }
    std::string& getName() { return name; }
};


#endif // ELEMENT_H
