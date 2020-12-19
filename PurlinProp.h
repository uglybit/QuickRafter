#ifndef PURLINPROP_H
#define PURLINPROP_H

#include "Element.h"

// s³upek
class PurlinProp : public Element
{
public:
    PurlinProp();

    ElementType type() const override { return ElementType::PurlinProp; }

    void setParameters() override;
    void showParameters() override;

    // parametry s³upka musz¹ zostaæ obliczone w CommonRafter
    void calculateParameters() override {}
};

#endif // !PURLINPROP_H
