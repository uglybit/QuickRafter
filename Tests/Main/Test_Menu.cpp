#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include "../../CommonRafter.cpp"
#include "../../Dimensions.cpp"
#include "../../Element.cpp"
#include "../../Functions.cpp"
#include "../../Functions.h"
#include "../../GableRoof.cpp"
#include "../../HippedRoof.cpp"
#include "../../HipRafter.cpp"
#include "../../Menu.cpp"
#include "../../Purlin.cpp"
#include "../../PurlinProp.cpp"
#include "../../Truss.cpp"
#include "../../WallPlate.cpp"
#include "../FixtureInterface/FixtureInterface.h"


class FixtureMenu : public FixtureTest {
protected:
    Menu menu;

    FixtureMenu() : FixtureTest() {
        input = std::istringstream("10000 8000 3500 11000 700 1100 4 140 140     90 180 800     120 120  100 100 8 1800 140 220 ");
    }

    void SetUp() override{
        std::cin.rdbuf(input.rdbuf());
        //coutPtr = std::cout.rdbuf(); 
        //std::cout.rdbuf(output.rdbuf());  

    }

    void TearDown() override {
        //std::cout.rdbuf(coutPtr);
    }
};


TEST_F(FixtureMenu, TestWholeApplication) {

    menu.show();
}

/*
    std::cout << "Section length: eave - wall plate " << eaveToWallPlate << "\n";
    std::cout << "Section length:  wall plate - purlin: " << wallPlateToPurlin << "\n";
    std::cout << "Section length: purlin - top: " << purlinToTop << "\n";
    std::cout << "Section length: wall plate - top:  " << wallPlateToTop << "\n";
    std::cout << "Rafter total length: " << rafterTotalLength << "\n";
    std::cout << "Horizontal eave length : " << horizontalEaveLength << std::endl;
*/
