#ifndef COMMONRAFTERINTERFACE_H
#define COMMONRAFTERINTERFACE_H

#include "../../Purlin.h"

// krokiew zwykła
class CommonRafterInterface 
{
public:
/*
    explicit CommonRafter(Dimensions& dim);
    explicit CommonRafter(Dimensions& dim, int count);
    ElementType type() const override;
*/
 virtual ~CommonRafterInterface() = default;

    //calculating
virtual  void setParameters() = 0;
virtual  void calculateParameters() = 0;
virtual  void calculateVerticalLine(double value) = 0;
virtual  void calculateVerticalCut() = 0;
virtual  void calculateProperVerticalCut() = 0;
virtual  void calculateRafterAboveWallPlatt() = 0;
virtual  void calculateHorizontalLine(double value) = 0;
virtual  void calculateHorizontalCut() = 0;
virtual  void calculatePurlinAndPropLength() = 0;
virtual  void calculateRafterDimensions(int sqroot) = 0;
virtual  void showParameters() = 0;

    //set
virtual  void setVerticalCut(const double vCut) = 0;
virtual  void setHorizontalCut(const double hCut) = 0;
virtual  void setRafterAboveWallPlate(const double rafAbove) = 0;
virtual  void setAngleVerticalLine(const double angVert) = 0;
virtual  void setAngleHorizontalLine(const double angHor) = 0;
virtual  void setHorizontalEaveLength(const double horEave) = 0;
virtual  void setEaveToWallPlate(const double eaveWall) = 0;
virtual  void setWallPlateToPurlin(const double wallPurl) = 0;
virtual  void setPurlinToTop(const double purlTop) = 0;
virtual  void setWallPlateToTop(const double wallTop) = 0;
virtual  void setRafterTotalLength(const double rafterTotal) = 0;

    // get
 virtual double getVerticalCut() const = 0;
 virtual double getHorizontalCut() const = 0;
 virtual double getRafterAboveWallPlate() const = 0;
 virtual double getAngleVerticalLine() const = 0;
 virtual double getAngleHorizontalLine() const = 0;
 virtual double getHorizontalEaveLength() const = 0;
 virtual double getEaveToWallPlate() const = 0;
 virtual double getWallPlateToPurlin() const = 0;
 virtual double getPurlinToTop() const = 0;
 virtual double getwallPlateToTop() const = 0;
 virtual double getRafterTotalLength() const = 0;

};

#endif