#ifndef HIPPEDROOF_H
#define HIPPEDROOF_H

#include "GableRoof.h"
#include "HipRafter.h"

class HippedRoof final: public GableRoof
{
public:
    HippedRoof(Dimensions& dim);
    HippedRoof(Dimensions& dim, bool purl);
};

#endif // !HIPPED_ROOF


