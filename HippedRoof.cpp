#include "HippedRoof.h"

// dach kopertowy
HippedRoof::HippedRoof() : GableRoof()
{
    setTrussType("Hipped roof without purlins");
    elements.push_back(new HipRafter);
}


// dach kopertowy z p³atwi¹
HippedRoof::HippedRoof(bool purl) : GableRoof(purl)
{
    setTrussType("Hipped roof with purlins");
    elements.push_back(new HipRafter);
}
