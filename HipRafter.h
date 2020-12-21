#ifndef HIPRAFTER_H
#define HIPRAFTER_H

#include "CommonRafter.h"

//krokiew naro�na
class HipRafter final: public CommonRafter // krokiew zwyk³a
{
private:
    // dla krokwi naro�enj -przeniesione z klasy CommonRafter - czemu tam byly?
    double additionToEgdes; // dodatek zale�ny od szeoko�ci krokwi naro�nej
    double rafterTotalOnEdges; // d�ugo�c krokwi z dodatkiem
    double verticalCutToSquare; // d�ugo�� pionoewgo zaci�cia w osi krokwi - na naro�e
    double horizontalCutToSquare;// d�ugo�� poziomego zaci�cia w osi krokwi - na naro�e
    double angleCutToSquare; // wymiar pod k�tem 45 stopni od zewn�trznej powierzchni krokwi do osi krokwi (linia pozioma)

public:
    HipRafter(Dimensions& dim);
    ElementType type() const override { return ElementType::HipRafter; }
    void setParameters() override;
    void showParameters() override;
    void calculateParameters() override;

    void cutToSquare();
    void addToEdges();
    void showHipParameters();

    void setAdditionToEgdes(const double addition) { additionToEgdes = addition; }
    void setRafterTotalOnEdges(const double totalEgdes) { rafterTotalOnEdges = totalEgdes; }

    double getAdditionToEgdes() const { return additionToEgdes; }
    double getRafterTotalOnEdges() const { return rafterTotalOnEdges; }
};

#endif // !HIPRAFTER_H
