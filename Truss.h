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
    Dimensions& dimension;
    std::string trussType;
    double surfaceArea{ 0.0 };
protected:
    std::vector<Element*> elements;

public:
    Truss(Dimensions &dim);
    virtual ~Truss();

    void setTrussType(const std::string& type);
    const std::string& getTrussType() const;
    double calcArea();
    double getRoofArea() const;
    void calcParam();
    void show();
    void getInitialDimensions();
    double calcCommonRaftersDistance();
    const Dimensions* getDimensions();
    Dimensions* setDimensions() { return &dimension; }
};

#endif // TRUSS_H
