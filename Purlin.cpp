#include "Purlin.h"

using namespace std;

Purlin::Purlin(Dimensions& dim) : Element(dim)
{
    setName("Purlin");
    setDimensions()->setPurlin(true);
    setParameters();
}


ElementType Purlin::type() const
{ 
    return ElementType::Purlin;
}


void Purlin::setParameters()
{
#ifndef TEST // wersja nie-testowa, podawanie wszystkich warto�ci przez u�ytkownika
    setWidth();
    setHeight();
    setDimensions()->setPurlinDimensions(getHeight());
    
#else  // TEST - bez r�cznego wpisywania warto�ci
    setHeight(120);
    setWidth(120);
    setDimensions()->setPurlinDimensions(120);
#endif
}


void Purlin::calculateParameters() // override
{
    setLength(getDimensions()->getBuildingLength());
}


void Purlin::showParameters()
{
    showDimensions();
}

