#include "WallPlate.h"

WallPlate::WallPlate()
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
#ifndef TEST // wersja nie-testowa, podawanie wszystkich wartoœci przez u¿ytkownika
    setWidth();
    setHeight();

#else // TEST - bez rêcznego wpisywania wartoœci
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
    setLength(OvDim::getTrussLength());
}