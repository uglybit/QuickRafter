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
private:
    std::string trussType;
    double surfaceArea{ 0.0 };
protected:
    std::vector<Element*> elements;

public:
    Truss();
    virtual ~Truss();

    void setTrussType(std::string type);
    const std::string& getTrussType() const;
    double calcArea();
    double getRoofArea() const;
    void calcParam();
    void show();
    void getInitialDimensions();
    double calcCommonRaftersDistance();
};

#endif // TRUSS_H
