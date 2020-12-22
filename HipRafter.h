#ifndef HIPRAFTER_H
#define HIPRAFTER_H

#include "CommonRafter.h"

//krokiew naro¿na
class HipRafter final: public CommonRafter // krokiew zwykla
{
private:
    double additionToEgdes{ 0.0 }; // dodatek zalezny od szeokosci krokwi naroznej
    double rafterTotalOnEdges{ 0.0 }; // dlugosc krokwi z tym^ dodatkiem
    double verticalCutToSquare{ 0.0 }; // dlugosc pionowego zaciecia w osi krokwi - na naroze
    double horizontalCutToSquare{ 0.0 }; // dlugosc poziomego zaciecia w osi krokwi - na naroze
    double angleCutToSquare{ 0.0 }; // wymiar pod katem 45 stopni od zewnetrznej powierzchni krokwi do osi krokwi (linia pozioma)

public:
    explicit HipRafter(Dimensions& dim);

    ElementType type() const override;
    void setParameters();
    void showParameters() override;
    void calculateParameters() override;
    void cutToSquare();
    void addToEdges();
    void showHipParameters() const;
    void setAdditionToEgdes(const double addition);
    void setRafterTotalOnEdges(const double totalEgdes);
    double getAdditionToEgdes() const;
    double getRafterTotalOnEdges() const;
};

#endif
