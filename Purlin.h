#ifndef PURLIN_H
#define PURLIN_H

#include "Element.h"

// p³atew 
class Purlin final: public Element 
{
public:
    explicit Purlin(Dimensions& dim);

    ElementType type() const override;
    void calculateParameters() override;
    void setParameters() override;
    void showParameters() override;
};

#endif // PURLIN_H