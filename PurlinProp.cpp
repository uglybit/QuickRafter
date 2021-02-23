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
    int value;
    setWidth();
    setHeight();
    value = validateNumber<int>("Purlin prop quantity: ", 1, 10);
    setQuantity(value);
    double getter = getDimensions()->getBuildingWidth();
    value = validateNumber<double>("Purlin prop distance: ", 0.0, getter / 3);
    setDimensions()->setPurlinPropDistance(value);
    std::cout << "Purlin prop distance w PP: " << getDimensions()->getPurlinPropDistance() << '\n';
}


void PurlinProp::showParameters()
{
    setLength(getDimensions()->getPurlinPropLength());
    std::cout << '\n';
    showDimensions();
    std::cout << "\n\t\tquantity: " << getQuantity() << std::endl;
}