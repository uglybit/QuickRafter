#ifndef PURLINPROP_H
#define PURLINPROP_H

#include "Element.h"

// s�upek
class PurlinProp : public Element
{
public:
    PurlinProp();

    ElementType type() const override { return ElementType::PurlinProp; }

    void setParameters() override;
    void showParameters() override;

    // parametry s�upka musz� zosta� obliczone w CommonRafter
    void calculateParameters() override {}
};

#endif // !PURLINPROP_H
