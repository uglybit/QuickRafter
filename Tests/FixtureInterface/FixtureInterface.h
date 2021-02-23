#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>



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

