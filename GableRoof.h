#ifndef GALEROOF_H
#define GALEROOF_H

#include "Truss.h"

class GableRoof : public Truss
{
public:
    explicit GableRoof(Dimensions& dim);
    explicit GableRoof(Dimensions& dim, bool purl);
};

#endif