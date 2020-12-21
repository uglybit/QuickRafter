#ifndef PURLINPROP_H
#define PURLINPROP_H

#include "Element.h"

// s³upek
class PurlinProp final: public Element // public : Purlin???
{
public:
    PurlinProp(Dimensions& dim);

    ElementType type() const override;
    void setParameters() override;
    void showParameters() override;

    // parametry s³upka musz¹ zostaæ obliczone w CommonRafter
    void calculateParameters() override {}
};

#endif // !PURLINPROP_H
