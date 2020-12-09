#include "Purlin.h"

using namespace std;

Purlin::Purlin() {
    name = "Purlin";
    OvDim::setPurlin(true);
    setParameters();
}


void Purlin::setParameters()
{
#ifndef TEST // TEST 
   /* double value;

    value = validateNumber("Purlin width: " , 50.0, 500.0);
    width = value;

    value = validateNumber("Purlin height: ", 50.0, 500.0);
    height = value;
    OvDim::setPurlinDimensions(value);
*/
    setWidth();
    setHeight();
    OvDim::setPurlinDimensions(height);

#else  // TEST - bez rêcznego wpisywania wartoœci
    height = 120;
    width = 120;
    OvDim::setPurlinDimensions(120);
#endif
}


void Purlin::calculateParameters() // override
{
    length = OvDim::getBuildingLength();
}


void Purlin::showParameters()
{
    showDimensions();
}


/*************** PURLIN PROP **********************/


PurlinProp::PurlinProp()
{
    name = "Purlin prop";
    setParameters();
}


void PurlinProp::setParameters() // override
{
 #ifndef TEST // TEST
    int value;
    setWidth();
    setHeight();
//    cout << "Purlin prop quantity: " << endl;
//    cin >> value;
//    quantity = value;
    quantity = validateNumber<int>("Purlin prop quantity: ", 1, 10);

//    cout << "Purlin prop distance: " << endl;
//    cin >> value;
//    OvDim::setPurlinPropDistance(value);

    double getter = OvDim::getBuildingWidth();
     value = validateNumber<double>("Purlin prop distance: ", 0.0, getter/3);
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