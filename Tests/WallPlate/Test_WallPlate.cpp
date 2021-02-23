//#include "ElementInterface.h"
//#include "../Dimensions/DimensionsMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../Dimensions.cpp"
#include "../../Functions.h"
#include "../../Functions.cpp"
#include "../../WallPlate.cpp"
#include "../../Element.cpp"


class FixtureTest : public ::testing::Test {
    protected:
    std::istringstream input; 
    std::ostringstream output; 
    using cout_pointer = decltype(std::cout.rdbuf()); 
    cout_pointer coutPtr; 

    void SetUp() override{
        
        std::cin.rdbuf(input.rdbuf());
        coutPtr = std::cout.rdbuf(); 
        std::cout.rdbuf(output.rdbuf());  
    }

    void TearDown() override {
        std::cout.rdbuf(coutPtr);
    }
};

TEST_F(FixtureTest, surname) {
    input = std::istringstream("10000 8000 3500 11000 700 1100 140 140");
    Dimensions dimMock;
    Element* element = new WallPlate(dimMock);
    
}