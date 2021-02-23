#ifndef PURLINPROP_H
#define PURLINPROP_H

#include "Element.h"

// slupek
class PurlinProp final: public Element // public : Purlin???
{
public:
    explicit PurlinProp(Dimensions& dim);

    ElementType type() const override final;
    void setParameters(); 
    void showParameters() override final;

    // parametry s�upka musz� zosta� obliczone w CommonRafter
    void calculateParameters() override final {}
};

#endif 
