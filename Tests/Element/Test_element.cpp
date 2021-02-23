//#include "ElementInterface.h"
//#include "../Dimensions/DimensionsMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../Dimensions.cpp"
#include "../../Functions.h"
#include "../../Functions.cpp"
#include "../../Element.cpp"
#include "../FixtureInterface/FixtureInterface.h"


class FixtureElement : public FixtureTest {
    protected:
    FixtureElement() : FixtureTest() {
        input = std::istringstream("10000 8000 3500 11000 700 1100");
    }   
};


TEST_F(FixtureElement, surname) {
    //input = std::istringstream("10000 8000 3500 11000 700 1100");
    Dimensions dimMock;
    Element* element = new Element(dimMock);
    
}