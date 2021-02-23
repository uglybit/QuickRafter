#ifndef WALLPLATEINTERFACE_H
#define WALLPLATEINTERFACE_H

#include "../../Element.h"

// mur�ata
class WallPlateInterface 
{
public:
    //explicit WallPlate(Dimensions& dim);
    WallPlateInterface() = default;
    virtual ~WallPlateInterface() = default;

    virtual ElementType type() const = 0;
    virtual void setParameters() = 0;
    virtual void calculateParameters() = 0;
    virtual void showParameters() = 0;
};

#endif