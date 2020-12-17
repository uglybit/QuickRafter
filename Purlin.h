#ifndef PURLIN_H
#define PURLIN_H

#include "Element.h"

// p�atew 
class Purlin : public Element 
{
public:
    Purlin();

    ElementType type() const override { return ElementType::Purlin; }

    void calculateParameters() override;
    void setParameters() override;
    void showParameters() override;
};


/*************** PURLIN PROP **********************/

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


#endif // PURLIN_H