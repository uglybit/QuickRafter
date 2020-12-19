#include "PurlinProp.h"

using namespace std;

PurlinProp::PurlinProp()
{
    setName("Purlin prop");
    setParameters();
}


void PurlinProp::setParameters() // override
{
#ifndef TEST // wersja nie-testowa, podawanie wszystkich wartoœci przez u¿ytkownika
    int value;
    setWidth();
    setHeight();
    value = validateNumber<int>("Purlin prop quantity: ", 1, 10);
    setQuantity(value);

    double getter = OvDim::getBuildingWidth();
    value = validateNumber<double>("Purlin prop distance: ", 0.0, getter / 3);
    OvDim::setPurlinPropDistance(value);

#else  // TEST - bez rêcznego wpisywania wartoœci
    setWidth(100);
    setHeight(100);
    double value;
    setQuantity(8);
    OvDim::setPurlinPropDistance(1800);
#endif
}


void PurlinProp::showParameters()
{
    cout << '\n';
    setLength(OvDim::getPurlinPropLength());
    showDimensions();
    cout << "\n\t\tquantity: " << getQuantity() << endl;
}