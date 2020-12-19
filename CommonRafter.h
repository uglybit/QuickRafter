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

    // dla krokwi narożenj - wymiary są w tej klasie żeby nie pisać oddzielnej funkcji
    double additionToEgdes; // dodatek zależny od szeokości krokwi narożnej
    double rafterTotalOnEdges; // długośc krokwi z dodatkiem

    // wstępny współczynnik długości zacięcia - po obliczeniach nieznacznie się zmieni
    const double cuttingRatio = 0.25; 

    // new get set
public:

    void setVerticalCut(const double vCut) { verticalCut = vCut; }
    const double getVerticalCut() { return verticalCut; }
    void setHorizontalCut(const double hCut) { horizontalCut = hCut; }
    const double getHorizontalCut() { return  horizontalCut; }
    void setRafterAboveWallPlate(const double rafAbove) { rafterAboveWallPlat = rafAbove; }
    const double getRafterAboveWallPlate() { return rafterAboveWallPlat;  }
    void setAngleVerticalLine(const double angVert) { angleVerticalLine = angVert; }
    const double getAngleVerticalLine() { return angleVerticalLine; }
    void setAngleHorizontalLine(const double angHor) { angleHorizontalLine = angHor; }
    const double getAngleHorizontalLine() { return angleHorizontalLine; }
    void setHorizontalEaveLength(const double horEave) { horizontalEaveLength = horEave; }
    const double getHorizontalEaveLength() { return horizontalEaveLength; }
    void setEaveToWallPlate(const double eaveWall) { eaveToWallPlate = eaveWall; }
    const double getEaveToWallPlate() { return eaveToWallPlate; }
    void setWallPlateToPurlin(const double wallPurl) { wallPlateToPurlin = wallPurl; }
    const double getWallPlateToPurlin() { return wallPlateToPurlin; }
    void setPurlinToTop(const double purlTop) { purlinToTop = purlTop; }
    const double getPurlinToTop() { return purlinToTop; }
    void setWallPlateToTop(const double wallTop) { wallPlateToTop = wallTop; }
    const double getwallPlateToTop() { return wallPlateToTop; }
    void setRafterTotalLength(const double rafterTotal) { rafterTotalLength = rafterTotal; }
    const double getRafterTotalLength() { return rafterTotalLength; }
    void setAdditionToEgdes(const double addition) { additionToEgdes = addition; }
    const double getAdditionToEgdes() { return additionToEgdes; }
    void setRafterTotalOnEdges(const double totalEgdes) { rafterTotalOnEdges = totalEgdes; }
    const double getRafterTotalOnEdges() { return rafterTotalOnEdges; }

public:
    CommonRafter();
    explicit CommonRafter(int);

    ElementType type() const override { return ElementType::CommonRafter; }

    void setParameters() override;
    void calculateParameters() override;
    void showParameters() override;

    void calculateVerticalLine(double value);
    void calculateVerticalCut();
    void calculateProperVerticalCut();
    void calculateRafterAboveWallPlatt();
    void calculateHorizontalLine(double value);
    void calculateHorizontalCut();
    void calculatePurlinAndPropLength();
    void calculateRafterDimensions(int sqroot);


};

#endif