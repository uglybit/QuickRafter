#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../Dimensions.cpp"
#include "../../Functions.cpp"
#include <sstream>
#include "../FixtureInterface/FixtureInterface.h"


class FixtureDimenions : public FixtureTest {
    protected:
    Dimensions* dimensions;

    FixtureDimenions() : FixtureTest() {
        input = std::istringstream("10000 8000 3500 11000 700 1100");
    }

    void SetUp() override {
        FixtureTest::SetUp();
        dimensions = new Dimensions;
    }
    void TearDown() override {
        FixtureTest::TearDown();
        delete dimensions;
    }
};


TEST_F(FixtureDimenions, ConstructorTest) {
    EXPECT_EQ(dimensions->getBuildingLength(), 10000);
    EXPECT_EQ(dimensions->getBuildingLength(), 10000);
    EXPECT_EQ(dimensions->getBuildingWidth(), 8000);
    EXPECT_EQ(dimensions->getTrussHeight(), 3500);
    EXPECT_EQ(dimensions->getTrussLength(), 11000);
    EXPECT_EQ(dimensions->getWallPlateHeight(), 700);
    EXPECT_EQ(dimensions->getHorizontalEaveLength(), 1100);
}


