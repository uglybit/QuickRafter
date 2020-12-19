#ifndef PURLIN_H
#define PURLIN_H

#include "Element.h"

// p³atew 
class Purlin : public Element 
{
public:
    Purlin();

    ElementType type() const override { return ElementType::Purlin; }

    void calculateParameters() override;
    void setParameters() override;
    void showParameters() override;
};


#endif // PURLIN_H