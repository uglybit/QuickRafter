#include "GableRoof.h"

// dach dwuspadowy
GableRoof::GableRoof() : Truss()
{
    setTrussType("Gable roof without purlins");
}

// dach dwuspadowy z p³atwi¹
GableRoof::GableRoof(bool purl) : GableRoof()
{
    setTrussType("Gable roof with purlins");
    elements.push_back(new Purlin);
    elements.push_back(new PurlinProp);
}


void Truss::setTrussType(std::string type)
{
    trussType = type;
}


const std::string& Truss::getTrussType() const 
{
    return trussType; 
}
