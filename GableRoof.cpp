#include "GableRoof.h"

// dach dwuspadowy
GableRoof::GableRoof() : Truss()
{
    trussType = "Gable roof without purlins";
}

// dach dwuspadowy z p³atwi¹
GableRoof::GableRoof(bool purl) : GableRoof()
{
    trussType = "Gable roof with purlins";
    elements.push_back(new Purlin);
    elements.push_back(new PurlinProp);
}