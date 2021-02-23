#include "../../Dimensions.cpp"
#include "../../CommonRafter.cpp"
#include "../../Element.cpp"
#include "../../Functions.h"
#include "../../Functions.cpp"
#include "../../GableRoof.cpp"
#include "../../HippedRoof.cpp"
#include "../../HipRafter.cpp"
#include "../../Menu.cpp"
#include "../../Purlin.cpp"
#include "../../PurlinProp.cpp"
#include "../../Truss.cpp"
#include "../../WallPlate.cpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include <iostream>
#include <stdlib.h>

TEST(Name, Sur) {
    Menu menu;
    menu.show();
                               //building                       wallplate   comm raft  dist     purlin   p prop         hip
    std::istringstream input = std::istringstream("10000 8000 3500 11000 700 1100 140 140     180 90 800 120 120  120 120  100 100 8 1800 140 220");
    std::cin.rdbuf(input.rdbuf());
}




