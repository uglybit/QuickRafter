#ifndef HIPRAFTER_H
#define HIPRAFTER_H

#include "CommonRafter.h"

//krokiew naro�na
class HipRafter final: public CommonRafter // krokiew zwyk³a
{
public:

    HipRafter();
    ElementType type() const override { return ElementType::HipRafter; }

private:

    double verticalCutToSquare, // d�ugo�� pionoewgo zaci�cia w osi krokwi - na naro�e
        horizontalCutToSquare,// d�ugo�� poziomego zaci�cia w osi krokwi - na naro�e
        angleCutToSquare; // wymiar pod k�tem 45 stopni od zewn�trznej powierzchni krokwi do 
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

#endif // !HIPRAFTER_H
