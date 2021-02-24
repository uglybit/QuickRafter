#! /bin/bash

flags=('-lgtest' '-lgtest_main' '-lgmock' '-pthread')

g++ Test_Dimensions.cpp ${flags[@]}
