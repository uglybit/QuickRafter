#ifndef COMMONRAFTER_H
#define COMMONRAFTER_H

#include "Purlin.h"
//#include "Tests/CommonRafter/CommonRafterInterface.h"

// krokiew zwykła
class CommonRafter : public Element//, public CommonRafterInterface
{
private:
    // dlugosc zaciecia (zewnetrzny wymiar)
    double verticalCut{ 0.0 }; 
    double horizontalCut{ 0.0 };

    // mozna dodać getery i uzyc do weryfikacji poprawnosci kreslenia na krokwi
    double rafterAboveWallPlat{ 0.0 }; // wysokosc krokwi nad murlata
    double angleVerticalLine{ 0.0 }; // pionowa kreska na krokwi pod katem
    double angleHorizontalLine{ 0.0 }; // pozioma kreska na krokwi pod katem
    double horizontalEaveLength{ 0.0 }; // odległosc okapu od murlaty w poziomie

    // wymiary krokwi w jej osi
    double eaveToWallPlate{ 0.0 };  
    double wallPlateToPurlin{ 0.0 }; 
    double purlinToTop{ 0.0 }; 
    double wallPlateToTop{ 0.0 }; 
    double rafterTotalLength{ 0.0 }; 

    // wstępny współczynnik długości zacięcia 
    const double cuttingRatio = 0.25; 

public:
    explicit CommonRafter(Dimensions& dim);
    explicit CommonRafter(Dimensions& dim, int count);
    ElementType type() const override;
    

    //calculating
    void setParameters();
    void calculateParameters() override;
    void calculateVerticalLine(double value);
    void calculateVerticalCut();
    void calculateProperVerticalCut();
    void calculateRafterAboveWallPlatt();
    void calculateHorizontalLine(double value);
    void calculateHorizontalCut();
    void calculatePurlinAndPropLength();
    virtual void calculateRafterDimensions(int sqroot);
    void showParameters() override;

    //set
    void setVerticalCut(const double vCut);
    void setHorizontalCut(const double hCut);
    void setRafterAboveWallPlate(const double rafAbove);
    void setAngleVerticalLine(const double angVert);
    void setAngleHorizontalLine(const double angHor);
    void setHorizontalEaveLength(const double horEave);
    void setEaveToWallPlate(const double eaveWall);
    void setWallPlateToPurlin(const double wallPurl);
    void setPurlinToTop(const double purlTop);
    void setWallPlateToTop(const double wallTop);
    void setRafterTotalLength(const double rafterTotal);

    // get
    double getVerticalCut() const;
    double getHorizontalCut() const;
    double getRafterAboveWallPlate() const;
    double getAngleVerticalLine() const;
    double getAngleHorizontalLine() const;
    double getHorizontalEaveLength() const;
    double getEaveToWallPlate() const;
    double getWallPlateToPurlin() const;
    double getPurlinToTop() const;
    double getwallPlateToTop() const;
    double getRafterTotalLength() const;

};

#endif