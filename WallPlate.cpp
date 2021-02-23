#include "WallPlate.h"

WallPlate::WallPlate(Dimensions& dim) : Element(dim)
{
    setName("Wall plate");
    setParameters();
}


ElementType WallPlate::type() const
{ 
    return ElementType::WallPlate;
}


void WallPlate::setParameters() // override
{
    setWidth();
    setHeight();
}


void WallPlate::showParameters() //override
{
    showDimensions();
}


void WallPlate::calculateParameters() //override
{
    setLength(getDimensions()->getTrussLength());
}