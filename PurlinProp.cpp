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
    quantity = validateNumber<int>("Purlin prop quantity: ", 1, 10);

    double getter = OvDim::getBuildingWidth();
    value = validateNumber<double>("Purlin prop distance: ", 0.0, getter / 3);
    OvDim::setPurlinPropDistance(value);

#else  // TEST - bez rêcznego wpisywania wartoœci
    width = 100;
    height = 100;
    double value;
    quantity = 8;
    OvDim::setPurlinPropDistance(1800);
#endif
}


void PurlinProp::showParameters()
{
    cout << '\n';
    length = OvDim::getPurlinPropLength();
    showDimensions();
    cout << "\n\t\tquantity: " << quantity << endl;
}