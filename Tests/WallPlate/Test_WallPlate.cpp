//#include "ElementInterface.h"
//#include "../Dimensions/DimensionsMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../Dimensions.cpp"
#include "../../Functions.h"
#include "../../Functions.cpp"
#include "../../WallPlate.cpp"
#include "../../Element.cpp"
#include "../FixtureInterface/FixtureInterface.h"


class FixtureCommonRafter : public FixtureTest {
    protected:
    FixtureCommonRafter() : FixtureTest() {
        input = std::istringstream("10000 8000 3500 11000 700 1100 140 140");
    }
};


TEST_F(FixtureCommonRafter, surname) {
    Dimensions dimMock;
    Element* element = new WallPlate(dimMock);
    
}