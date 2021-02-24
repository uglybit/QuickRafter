#! /bin/bash

flags=('-lgtest' '-lgtest_main' '-lgmock' '-pthread')

g++ ../Functions/Test_Functions.cpp ${flags[@]}
./a.out
rm a.out
g++ ../Dimensions/Test_Dimensions.cpp ${flags[@]}
./a.out
rm a.out
g++ ../Element/Test_Element.cpp ${flags[@]}
./a.out
rm a.out
g++ ../CommonRafter/Test_CommonRafter.cpp ${flags[@]}
./a.out
rm a.out
g++ ../Dimensions/Test_Dimensions.cpp ${flags[@]}
./a.out
rm a.out
g++ ../WallPlate/Test_WallPlate.cpp ${flags[@]}
./a.out
rm a.out
g++ ../Main/Test_Menu.cpp ${flags[@]}
./a.out
rm a.out

