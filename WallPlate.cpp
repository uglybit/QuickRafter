#include "WallPlate.h"

WallPlate::WallPlate()
{
    setName("Wall plate");
    setParameters();
}


void WallPlate::setParameters() // override
{
#ifndef TEST // wersja nie-testowa, podawanie wszystkich wartoœci przez u¿ytkownika
    setWidth();
    setHeight();

#else // TEST - bez rêcznego wpisywania wartoœci
    width = 140;
    height = 140;
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