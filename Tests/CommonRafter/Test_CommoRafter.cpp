//#include "CommonRafterInterface.h"
#include "../Dimensions/DimensionsMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../Dimensions.cpp"
#include "../../Functions.h"
#include "../../Functions.cpp"
#include "../../Element.cpp"
#include "../../CommonRafter.cpp"

class FixtureTest : public ::testing::Test {
    protected:
    std::istringstream input  = std::istringstream("10000 8000 3500 11000 700 1100 90 180 800 "); 
    std::ostringstream output;
    using cout_pointer = decltype(std::cout.rdbuf()); 
    //cout_pointer coutPtr; 
    
    Element* commonRafter;

    void SetUp() override{
        std::cin.rdbuf(input.rdbuf());
        //coutPtr = std::cout.rdbuf(); 
        //std::cout.rdbuf(output.rdbuf());  
        Dimensions dimensions;
        commonRafter = new CommonRafter(dimensions);
    }

    void TearDown() override {
        //std::cout.rdbuf(coutPtr);
        delete commonRafter;
    }
};

TEST_F(FixtureTest, commonRafterConstructor) {
    std::string name;
    name = commonRafter->getName();
    EXPECT_STREQ("Common rafter", name.c_str());

    int retValue = commonRafter->getHeight();
    EXPECT_EQ(180, retValue);

    retValue = commonRafter->getWidth();
    EXPECT_EQ(90, retValue);

    retValue = commonRafter->getDimensions()->getCommonRaftersDistance();
    EXPECT_EQ(800, retValue);

    double retDouble;
    retDouble = commonRafter->getDimensions()->getHorizontalEaveLength();
    EXPECT_NEAR(1100, retDouble, 0.01);
}

TEST_F(FixtureTest, calculateParametersTestFunction) {
    commonRafter->calculateParameters();
    int retValue = commonRafter->getAlphaAngle();
    EXPECT_NEAR(34, retValue, 0.1);
}