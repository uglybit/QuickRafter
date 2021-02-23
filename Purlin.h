#ifndef PURLIN_H
#define PURLIN_H

#include "Element.h"

// platew 
class Purlin final: public Element 
{
public:
    explicit Purlin(Dimensions& dim);

    ElementType type() const override final;
    void calculateParameters() override final;
    void setParameters();
    void showParameters() override final;
};

#endif 