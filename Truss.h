#ifndef TRUSS_H
#define TRUSS_H

#include <vector>

#include "Element.h"
#include "Purlin.h"
#include "CommonRafter.h"
#include "WallPlate.h"
#include "PurlinProp.h"

class Truss
{
 protected:
    std::string trussType;
    double surfaceArea;
    std::vector<Element*> elements;

 public:
     Truss();
     virtual ~Truss();

    std::string getTrussType() { return trussType; }

    double calcArea();
    void calcParam();
    void show();
    void getInitialDimensions();
    double calcCommonRaftersDistance();
};

#endif // TRUSS_H
