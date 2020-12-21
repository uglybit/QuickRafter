#include "GableRoof.h"

// dach dwuspadowy
GableRoof::GableRoof(Dimensions& dim) : Truss(dim)
{
    setTrussType("Gable roof without purlins");
}


// dach dwuspadowy z p³atwi¹
GableRoof::GableRoof(Dimensions& dim, bool purl) : GableRoof(dim)
{
    setTrussType("Gable roof with purlins");
    elements.push_back(new Purlin(dim));
    elements.push_back(new PurlinProp(dim));
}