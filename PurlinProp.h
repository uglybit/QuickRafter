#ifndef PURLINPROP_H
#define PURLINPROP_H

#include "Element.h"

// s�upek
class PurlinProp final: public Element // public : Purlin???
{
public:
    PurlinProp(Dimensions& dim);

    ElementType type() const override;
    void setParameters() override;
    void showParameters() override;

    // parametry s�upka musz� zosta� obliczone w CommonRafter
    void calculateParameters() override {}
};

#endif // !PURLINPROP_H
