#ifndef WALLPLATE_H
#define WALLPLATE_H

#include "Element.h"

// mur³ata
class WallPlate : public Element
{
public:
    WallPlate();

    ElementType type() const override { return ElementType::WallPlate; }

    void setParameters() override;
    void calculateParameters() override;
    void showParameters() override;
};

#endif