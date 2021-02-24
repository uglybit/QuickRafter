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


    // dodane w celach testowych - usunac w przyszlosci
    virtual double getHorizontalEaveLength() {return 10.0;} // = 0;
    virtual double getAngleVerticalLine() const {return 0.0;} // = 0;
    virtual double getAngleHorizontalLine() const { return 0.0;} // =0;
    virtual double getRafterAboveWallPlate() const { return 0.0;} // =0;
    virtual double getVerticalCut() const { return 0.0;} // =0;
    virtual double getHorizontalCut() const { return 0.0;} // =0;
    virtual double getEaveToWallPlate() const { return 0.0;} // =0;
    virtual double getWallPlateToPurlin() const { return 0.0;} // =0;
    virtual double getPurlinToTop() const { return 0.0;} // =0;
    virtual double getwallPlateToTop() const { return 0.0;} // =0;
    virtual double getRafterTotalLength() const { return 0.0;} // =0;
    //

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

    void setHeight(double value); 
    void setWidth(double value); 
    
};


#endif // ELEMENT_H
