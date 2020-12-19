#ifndef GALEROOF_H
#define GALEROOF_H

#include "Truss.h"

class GableRoof : public Truss
{
public:
    GableRoof();
    GableRoof(bool purl);
};

#endif