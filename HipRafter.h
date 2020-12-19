#ifndef HIPRAFTER_H
#define HIPRAFTER_H

#include "CommonRafter.h"

//krokiew naro¿na
class HipRafter final: public CommonRafter // krokiew zwykÂ³a
{
public:

    HipRafter();
    ElementType type() const override { return ElementType::HipRafter; }

private:

    double verticalCutToSquare, // d³ugoœæ pionoewgo zaciêcia w osi krokwi - na naro¿e
        horizontalCutToSquare,// d³ugoœæ poziomego zaciêcia w osi krokwi - na naro¿e
        angleCutToSquare; // wymiar pod k¹tem 45 stopni od zewnêtrznej powierzchni krokwi do 
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
