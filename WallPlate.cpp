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
//#if defined TEST // TEST - bez r�cznego wpisywania warto�ci
    setWidth(140);
    setHeight(140);
//#else 
    setWidth();
    setHeight();
//#endif
}


void WallPlate::showParameters() //override
{
    showDimensions();
}


void WallPlate::calculateParameters() //override
{
    setLength(getDimensions()->getTrussLength());
}