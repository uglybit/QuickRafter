#include "PurlinProp.h"


PurlinProp::PurlinProp(Dimensions& dim) : Element(dim)
{
    setName("Purlin prop");
    setParameters();
}


ElementType PurlinProp::type() const 
{ 
    return ElementType::PurlinProp; 
}


void PurlinProp::setParameters() 
{
#if defined TEST // TEST - bez rêcznego wpisywania wartoœci
    setWidth(100);
    setHeight(100);
    setQuantity(8);
    setDimensions()->setPurlinPropDistance(1800);
#else  
    int value;
    setWidth();
    setHeight();
    value = validateNumber<int>("Purlin prop quantity: ", 1, 10);
    setQuantity(value);
    double getter = getDimensions()->getBuildingWidth();
    value = validateNumber<double>("Purlin prop distance: ", 0.0, getter / 3);
    setDimensions()->setPurlinPropDistance(value);
#endif
}


void PurlinProp::showParameters()
{
    setLength(getDimensions()->getPurlinPropLength());
    std::cout << '\n';
    showDimensions();
    std::cout << "\n\t\tquantity: " << getQuantity() << std::endl;
}