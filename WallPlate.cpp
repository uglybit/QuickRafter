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
#ifndef TEST // wersja nie-testowa, podawanie wszystkich warto�ci przez u�ytkownika
    setWidth();
    setHeight();

#else // TEST - bez r�cznego wpisywania warto�ci
    setWidth(140);
    setHeight(140);
#endif
}


void WallPlate::showParameters() //override
{
    showDimensions();
}


void WallPlate::calculateParameters() //override
{
    setLength(getDimensions()->getTrussLength());
}