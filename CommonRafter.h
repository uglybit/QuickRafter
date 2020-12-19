#ifndef COMMONRAFTER_H
#define COMMONRAFTER_H

#include "Purlin.h"

// krokiew zwykła
class CommonRafter : public Element
{
protected:

    double 
    verticalCut, // długość zacięcia w pionie (zewnętrzny wymiar)
    horizontalCut, // długość zacięcia w poziomie (zewnętrzny wymiar)

    // zmienne pomocnicze
    rafterAboveWallPlat, // wysokość krokwi nad murłatą
    angleVerticalLine, // pionowa kreska na krokwi pod kątem
    angleHorizontalLine, // pozioma kreska na krokwi pod kątem
    horizontalEaveLength, // odległość okapu od murłaty w poziomie

    /* wymiary krokwi  !!-> W OSI KROKWI - SZCZEGÓLNE ZNACZENIE DLA KROKWI NAROŻNEJ
    wymiary pod odpowiednim kątem, mierzone na górnej powierzchni  */
    eaveToWallPlate,  // od okapu do murłaty
        wallPlateToPurlin, // od murłaty do płatwi (jeśli jest płatew)
        purlinToTop, //  od płatwi do szczytu (jeśli jest płatew)
    wallPlateToTop, // od murłaty do szczytu - jeśli nie ma płatwi
    rafterTotalLength, // długość całkowita

    // dla krokwi narożenj - wymiary są w tej klasie żeby nie pisać oddzielnej funkcji
    additionToEgdes, // dodatek zależny od szeokości krkwi narożnej
    rafterTotalOnEdges; // długośc krokwi z dodatkiem

    // wstępny współczynnik długości zacięcia - po obliczeniach nieznacznie się zmieni
    const double cuttingRatio = 0.25; 

public:

    CommonRafter();
    explicit CommonRafter(int);

    ElementType type() const override { return ElementType::CommonRafter; }

    void setParameters() override;
    void showParameters() override;
    void calculateParameters() override;

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