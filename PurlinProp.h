#ifndef PURLINPROP_H
#define PURLINPROP_H

#include "Element.h"

// s³upek
class PurlinProp final: public Element // public : Purlin???
{
public:
    explicit PurlinProp(Dimensions& dim);

    ElementType type() const override final;
    void setParameters(); 
    void showParameters() override final;

    // parametry s³upka musz¹ zostaæ obliczone w CommonRafter
    void calculateParameters() override final {}
};

#endif 
