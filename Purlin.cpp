#include "Purlin.h"


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
    setWidth();
    setHeight();
    setDimensions()->setPurlinDimensions(getHeight());
}


void Purlin::calculateParameters() // override
{
    setLength(getDimensions()->getBuildingLength());
}


void Purlin::showParameters()
{
    showDimensions();
}

