#ifndef GALEROOF_H
#define GALEROOF_H

#include "Truss.h"

class GableRoof : public Truss
{
public:
    GableRoof(Dimensions& dim);
    GableRoof(Dimensions& dim, bool purl);
};

#endif