#ifndef ELEMENT_H
#define ELEMENT_H

#include "OverallDimensions.h"
#include <cmath> // do funkcji trygonometrycznych
#include <iostream>

// do rozpoznawania typu klasy dziedzicz�cej po *Element
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


using OvDim =  OverallDimensions; // skr�cenie zapisu

class Element
{
protected:
    std::string name; // nazwa elementu
    double length{}, width, height; // trzy wymiary elementu
    double alphaAngle,  // k�t dachu wzg�ldem poziomu
        betaAngle; // 90 - alphAangle: k�t dachu wzgl�dem pionu
    int quantity{}; // ilo�� element�w

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

    // ustawienie wymiar�w   
    void setWidth();
    void setHeight();
    void setLength(double value) { length = value; }
    void setQuantity(int value) { quantity = value; }

    // do oblicze� k�t�w
    double radiansToDegrees(double value);
    double degreesToRadians(double value); 

    // obliczenie k�ta
    void calculateAngles(double vertical, double horizontal); 

    // pokazuje wymiary elementu
    void showDimensions(); 

    // get
    double getAlfaAngle() { return alphaAngle; }
    double getBetaAngle() { return betaAngle; }
    double getQuantity()  { return quantity; }
    std::string getName() { return name; }
};


/*************** WALL PLATE **********************/

// mur�ata
class WallPlate : public Element 
{
public:
    WallPlate();

    ElementType type() const override { return ElementType::WallPlate; }

    void setParameters() override;
    void calculateParameters() override;
    void showParameters() override;
};

#endif // ELEMENT_H
