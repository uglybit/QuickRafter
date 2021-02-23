//#include "CommonRafterInterface.h"
//#include "../Dimensions/DimensionsMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../Dimensions.cpp"
#include "../../Functions.h"
#include "../../Functions.cpp"
#include "../../Element.cpp"
#include "../../CommonRafter.cpp"
#include "../../HipRafter.cpp"
#include "../../WallPlate.cpp"

class FixtureTest : public ::testing::Test {
    protected:
    std::istringstream input = std::istringstream("10000 8000 3500 11000 700 1100 140 140 140 220 "); 
    std::ostringstream output;
    using cout_pointer = decltype(std::cout.rdbuf()); 
    cout_pointer coutPtr; 
    
    Element* hipRafter;
    Element* wallPlate;

    void SetUp() override{
        std::cin.rdbuf(input.rdbuf());
        coutPtr = std::cout.rdbuf(); 
        std::cout.rdbuf(output.rdbuf());  
        Dimensions dimensions;
        wallPlate = new WallPlate(dimensions);
        hipRafter = new HipRafter(dimensions);
    }

    void TearDown() override {
        std::cout.rdbuf(coutPtr);
        delete hipRafter;
        delete wallPlate;
    }
};

TEST_F(FixtureTest, hipRafterConstructor) {
    std::string name;
    name = hipRafter->getName();
    EXPECT_STREQ("Hip rafter", name.c_str());

    int retValue = hipRafter->getHeight();
    EXPECT_EQ(220, retValue);

    retValue = hipRafter->getWidth();
    EXPECT_EQ(140, retValue);


    double retDouble;
}


TEST_F(FixtureTest, SetParametersFunctionTest) {
    //hipRafter->setParameters();
    //hipRafter->calculateParameters();

    double retDouble;
    retDouble = hipRafter->getBetaAngle();
    EXPECT_NEAR(24.98, retDouble, 0.1);
}
