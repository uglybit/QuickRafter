#ifndef COMMONRAFTER_H
#define COMMONRAFTER_H

#include "Purlin.h"

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

    /* wymiary krokwi  !!->W OSI KROKWI - SZCZEGÓLNE ZNACZENIE DLA KROKWI NAROŻNEJ
    wymiary pod odpowiednim kątem, mierzone na górnej powierzchni  */
    eaveToWallPlate,  // od okapu do murłaty
        wallPlateToPurlin, // od murłaty do płatwi (jeśli jest płatew)
        purlinToTop, //  od płatwi do szczytu (jeśli jest płatew)
    wallPlateToTop, // od murłaty do szczytu - jeśli nie ma płatwi
    rafterTotalLength, // długość całkowita

    // dla krokwi narożenj - wymiary są w tej klasie żeby nie pisać oddzielnej funkcji
    additionToEgdes, // dodatek zależny od szeokości krkwi narożnej
    rafterTotalOnEdges; // długośc krokwi z dodatkiem

    // initial cutting ratio
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


/**************** HIP RAFTER ************************/

//krokiew narożna
class HipRafter : public CommonRafter // krokiew zwykÂła
{
public:

    HipRafter();
    ElementType type() const override { return ElementType::HipRafter; }

private:
    // dimensions in '3D' show clearly in the picture
    //
    double verticalCutToSquare, // długość pionoewgo zacięcia w osi krokwi - na naroże
           horizontalCutToSquare,// długość poziomego zacięcia w osi krokwi - na naroże
           angleCutToSquare; // wymiar pod kątem 45 stopni od zewnętrznej powierzchni krokwi do 
                            // osi krokwi (linia pozioma)

    int jackRaftersQuantity;
   
public:
    void setParameters() override;
    void showParameters() override;
    void calculateParameters() override;

    void cutToSquare();
    void addToEdges();

    void showHipParameters();
};




/****************   VALLEY RAFTER ************************/

// krokiew koszowa
/*

class ValleyRafter : public HipRafter // krokiew narożna
{
public:
    ValleyRafter() { name = "Valley rafter"; }
    ElementType type() const override { return ElementType::ValleyRafter; }
    void setParameters() override {}
    void calculateParameters() override {}
};


*/

#endif // COMMONRAFTER_H
