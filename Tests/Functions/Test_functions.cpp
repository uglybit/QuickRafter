#include <gtest/gtest.h>
#include "../../Functions.cpp"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class TestFunctionDataValidation : public ::testing::Test {
    protected:
    std::istringstream input; // lokalny bufor do wczytywania
    std::ostringstream output; // lokalny bufor do wypisywania
    using cout_pointer = decltype(std::cout.rdbuf()); // typ wsk na bufor cout 
    cout_pointer coutPtr; // wskaznik do bufora cout

    void SetUp() override {
        std::cin.rdbuf(input.rdbuf()); // ustawiamy std::cin na swoj input
        coutPtr = std::cout.rdbuf(); // zapisujamy wskznik do cout
        std::cout.rdbuf(output.rdbuf());  // zastepowanie wysjcia: zamiast do cout do local

    }

    void TearDown() override {
        std::cout.rdbuf(coutPtr); // wyjscie ustawiamy z powrotem na cout
    }
};


TEST_F(TestFunctionDataValidation, TestForDoubleShouldPass) {
    input = std::istringstream("1.9");
    double retValue;

    retValue = validateNumber<double>("", 1.0, 5.0 );

    EXPECT_NEAR(retValue, 1.9, 0.001);
}



TEST_F(TestFunctionDataValidation, TestForIntShouldPass) {
    input = std::istringstream("3");
    int retValue;

    retValue = validateNumber<int>("", 1, 5 );

    EXPECT_EQ(retValue, 3);

}

TEST_F(TestFunctionDataValidation, LowRangeTestShouldPass) {
    input = std::istringstream("1 500 999 ");

    int retValue;
    retValue = validateNumber<int>("", 1, 1000);
    EXPECT_EQ(retValue, 1);

    retValue = validateNumber<int>("", 500, 1000);
    EXPECT_EQ(retValue, 500);

    retValue = validateNumber<int>("", 999, 1000);
    EXPECT_EQ(retValue, 999);
}

TEST_F(TestFunctionDataValidation, HighRangeTestSholdPass) {
    input = std::istringstream("10.5 1000.5 9999.5");
    double retValue;

    retValue = validateNumber<double>("", 1, 10.5);
    EXPECT_NEAR(retValue, 10.5, 0.01);

    retValue = validateNumber<double>("", 1, 1000.5);
    EXPECT_NEAR(retValue, 1000.5, 0.01);

    retValue = validateNumber<double>("", 1, 9999.5);
    EXPECT_NEAR(retValue, 9999.5, 0.01);
}


TEST_F(TestFunctionDataValidation, ProperDataAfetrWrongDataShouldPass) {
    
    input = std::istringstream("a \n b \n c \n t44 \n 0 100 a \n 9");
    int retValue;

    retValue = validateNumber<int>("", 1, 10.5);

    EXPECT_EQ(retValue, 9);
}
