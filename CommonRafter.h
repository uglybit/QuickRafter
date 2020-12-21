#ifndef COMMONRAFTER_H
#define COMMONRAFTER_H

#include "Purlin.h"

// krokiew zwykła
class CommonRafter : public Element
{
private:
    double verticalCut; // długość zacięcia w pionie (zewnętrzny wymiar)
    double horizontalCut; // długość zacięcia w poziomie (zewnętrzny wymiar)

    // zmienne pomocnicze
    double rafterAboveWallPlat; // wysokość krokwi nad murłatą
    double angleVerticalLine; // pionowa kreska na krokwi pod kątem
    double angleHorizontalLine; // pozioma kreska na krokwi pod kątem
    double horizontalEaveLength; // odległość okapu od murłaty w poziomie

    /* wymiary krokwi  !!-> W OSI KROKWI - SZCZEGÓLNE ZNACZENIE DLA KROKWI NAROŻNEJ
    wymiary pod odpowiednim kątem, mierzone na górnej powierzchni  */
    double eaveToWallPlate;  // od okapu do murłaty
    double wallPlateToPurlin; // od murłaty do płatwi (jeśli jest płatew)
    double purlinToTop; //  od płatwi do szczytu (jeśli jest płatew)
    double wallPlateToTop; // od murłaty do szczytu - jeśli nie ma płatwi
    double rafterTotalLength; // długość całkowita

    // wstępny współczynnik długości zacięcia - po obliczeniach nieznacznie się zmieni
    const double cuttingRatio = 0.25; 

public:
    CommonRafter(Dimensions& dim);
    explicit CommonRafter(Dimensions& dim, int count);

    ElementType type() const override { return ElementType::CommonRafter; }

    //calculating
    void setParameters() override;
    void calculateParameters() override;
    void calculateVerticalLine(double value);
    void calculateVerticalCut();
    void calculateProperVerticalCut();
    void calculateRafterAboveWallPlatt();
    void calculateHorizontalLine(double value);
    void calculateHorizontalCut();
    void calculatePurlinAndPropLength();
    void calculateRafterDimensions(int sqroot);
    void showParameters() override;

    //set
    void setVerticalCut(const double vCut) { verticalCut = vCut; }
    void setHorizontalCut(const double hCut) { horizontalCut = hCut; }
    void setRafterAboveWallPlate(const double rafAbove) { rafterAboveWallPlat = rafAbove; }
    void setAngleVerticalLine(const double angVert) { angleVerticalLine = angVert; }
    void setAngleHorizontalLine(const double angHor) { angleHorizontalLine = angHor; }
    void setHorizontalEaveLength(const double horEave) { horizontalEaveLength = horEave; }
    void setEaveToWallPlate(const double eaveWall) { eaveToWallPlate = eaveWall; }
    void setWallPlateToPurlin(const double wallPurl) { wallPlateToPurlin = wallPurl; }
    void setPurlinToTop(const double purlTop) { purlinToTop = purlTop; }
    void setWallPlateToTop(const double wallTop) { wallPlateToTop = wallTop; }
    void setRafterTotalLength(const double rafterTotal) { rafterTotalLength = rafterTotal; }

    // get
    double getVerticalCut() const { return verticalCut; }
    double getHorizontalCut() const { return  horizontalCut; }
    double getRafterAboveWallPlate() const { return rafterAboveWallPlat; }
    double getAngleVerticalLine() const { return angleVerticalLine; }
    double getAngleHorizontalLine() const { return angleHorizontalLine; }
    double getHorizontalEaveLength() const { return horizontalEaveLength; }
    double getEaveToWallPlate() const { return eaveToWallPlate; }
    double getWallPlateToPurlin() const { return wallPlateToPurlin; }
    double getPurlinToTop() const { return purlinToTop; }
    double getwallPlateToTop() const { return wallPlateToTop; }
    double getRafterTotalLength() const { return rafterTotalLength; }

};

#endif