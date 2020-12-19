#include "Purlin.h"

using namespace std;

Purlin::Purlin() {
    setName("Purlin");
    OvDim::setPurlin(true);
    setParameters();
}


void Purlin::setParameters()
{
#ifndef TEST // wersja nie-testowa, podawanie wszystkich warto�ci przez u�ytkownika
    setWidth();
    setHeight();
    OvDim::setPurlinDimensions(getHeight());
    
#else  // TEST - bez r�cznego wpisywania warto�ci
    setHeight(120);
    setWidth(120);
    OvDim::setPurlinDimensions(120);
#endif
}


void Purlin::calculateParameters() // override
{
    setLength(OvDim::getBuildingLength());
}


void Purlin::showParameters()
{
    showDimensions();
}

