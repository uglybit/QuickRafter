//#include "CommonRafterInterface.h"
//#include "../Dimensions/DimensionsMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../Dimensions.cpp"
#include "../../Functions.h"
#include "../../Functions.cpp"
#include "../../Element.cpp"
#include "../../CommonRafter.cpp"
#include "../../PurlinProp.cpp"


class FixtureTest : public ::testing::Test {
    protected:
    std::istringstream input  = std::istringstream("10000 8000 3500 11000 700 1100 100 100 8 1800 90 180 800 "); 
    std::ostringstream output;
    using cout_pointer = decltype(std::cout.rdbuf()); 
    cout_pointer coutPtr; 
    
    Element* commonRafter;
    Dimensions* dimensions;
    Element* purlinProp;

    void SetUp() override{
        std::cin.rdbuf(input.rdbuf());
        coutPtr = std::cout.rdbuf(); 
        std::cout.rdbuf(output.rdbuf());  
        dimensions = new Dimensions;
        purlinProp = new PurlinProp(*dimensions);
        commonRafter = new CommonRafter(*dimensions);
    }

    void TearDown() override {
        std::cout.rdbuf(coutPtr);
        delete commonRafter;
        delete dimensions;
        delete purlinProp;
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

    double retValue = commonRafter->getAlphaAngle();
    EXPECT_NEAR(33.38, retValue, 0.1);

    retValue = commonRafter->getBetaAngle();
    EXPECT_NEAR(56.62, retValue, 0.1);

    retValue = commonRafter->getAngleVerticalLine();
    EXPECT_NEAR(216, retValue, 1);

    retValue = commonRafter->getAngleHorizontalLine();
    EXPECT_NEAR(327, retValue, 1);

    retValue = commonRafter->getRafterAboveWallPlate();
    EXPECT_NEAR(165, retValue, 1);

    retValue = commonRafter->getVerticalCut();
    EXPECT_NEAR(51, retValue, 1);

    retValue = commonRafter->getHorizontalCut();
    EXPECT_NEAR(77, retValue, 1);

    retValue = commonRafter->getEaveToWallPlate();
    EXPECT_NEAR(1317, retValue, 1);

    retValue = commonRafter->getWallPlateToPurlin();
    EXPECT_NEAR(2156, retValue, 1); 

    retValue = commonRafter->getPurlinToTop();
    EXPECT_NEAR(2635, retValue, 1); 

    retValue = commonRafter->getwallPlateToTop();
    EXPECT_NEAR(4790, retValue, 1);

    retValue = commonRafter->getRafterTotalLength();
    EXPECT_NEAR(6107, retValue, 1);


}