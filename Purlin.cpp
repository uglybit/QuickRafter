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
#if defined TEST // TEST - bez rêcznego wpisywania wartoœci
    setHeight(120);
    setWidth(120);
    setDimensions()->setPurlinDimensions(120);
#else  
    setWidth();
    setHeight();
    setDimensions()->setPurlinDimensions(getHeight());
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

