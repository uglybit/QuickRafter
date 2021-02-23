#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../Dimensions.cpp"
#include "../../Functions.cpp"
//#include "DimensionsInterface.h"
#include <sstream>

class FixtureTest : public ::testing::Test {
    protected:
    std::istringstream input; 
    std::ostringstream output; 
    using cout_pointer = decltype(std::cout.rdbuf()); 
    cout_pointer coutPtr; 
    Dimensions* obj;

    void SetUp() override{
        obj = new Dimensions;
        std::cin.rdbuf(input.rdbuf());
        coutPtr = std::cout.rdbuf(); 
        std::cout.rdbuf(output.rdbuf());  
    }

    void TearDown() override {
        std::cout.rdbuf(coutPtr);
        delete obj;
    }
};


TEST_F(FixtureTest, ConstructorTest) {
    input = std::istringstream("10000 8000 3500 11000 700 1100");
    
    EXPECT_EQ(obj->getBuildingLength(), 10000);
    EXPECT_EQ(obj->getBuildingLength(), 10000);
    EXPECT_EQ(obj->getBuildingWidth(), 8000);
    EXPECT_EQ(obj->getTrussHeight(), 3500);
    EXPECT_EQ(obj->getTrussLength(), 11000);
    EXPECT_EQ(obj->getWallPlateHeight(), 700);
    EXPECT_EQ(obj->getHorizontalEaveLength(), 1100);
    std::cout <<  "LALALALLALA\n";
}


