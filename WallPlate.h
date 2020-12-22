#ifndef WALLPLATE_H
#define WALLPLATE_H

#include "Element.h"

// mur³ata
class WallPlate final: public Element
{
public:
    explicit WallPlate(Dimensions& dim);

    ElementType type() const override;
    void setParameters();
    void calculateParameters() override;
    void showParameters() override;
};

#endif