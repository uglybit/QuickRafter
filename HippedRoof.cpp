#include "HippedRoof.h"

// dach kopertowy
HippedRoof::HippedRoof(Dimensions& dim) : GableRoof(dim)
{
    setTrussType("Hipped roof without purlins");
    elements.push_back(new HipRafter(dim));
}


// dach kopertowy z p³atwi¹
HippedRoof::HippedRoof(Dimensions& dim, bool purl) : GableRoof(dim, purl)
{
    setTrussType("Hipped roof with purlins");
    elements.push_back(new HipRafter(dim));
}
