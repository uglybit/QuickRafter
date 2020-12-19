#include "Purlin.h"

using namespace std;

Purlin::Purlin() {
    setName("Purlin");
    OvDim::setPurlin(true);
    setParameters();
}


void Purlin::setParameters()
{
#ifndef TEST // wersja nie-testowa, podawanie wszystkich wartoœci przez u¿ytkownika
    setWidth();
    setHeight();
    OvDim::setPurlinDimensions(getHeight());
    
#else  // TEST - bez rêcznego wpisywania wartoœci
    height = 120;
    width = 120;
    OvDim::setPurlinDimensions(120);
#endif
}


void Purlin::calculateParameters() // override
{
    length = OvDim::getBuildingLength();
}


void Purlin::showParameters()
{
    showDimensions();
}

