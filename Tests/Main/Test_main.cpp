#include "../../main.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

TEST(Name, Sur) {
                               //building                       wallplate   comm raft  dist     purlin   p prop         hip
    std::istringstream input = std::istringstream("10000 8000 3500 11000 700 1100 140 140     180 90 800 120 120  120 120  100 100 8 1800 140 220");
    std::cin.rdbuf(input.rdbuf());
}




