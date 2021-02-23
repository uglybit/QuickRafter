#pragma once
//#include "DimensionsInterface.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../Dimensions.h"

class DimensionsMock : public Dimensions
{
public:
    // wartosci wprowadzane przez uzytkownika
    MOCK_METHOD(void, setBuildingLength, (double)) ;
    MOCK_METHOD(void, setBuildingWidth, (double)); 
    MOCK_METHOD(void,  setTrussHeight, (double));
    MOCK_METHOD(void,  setTrussLength, (double));
    MOCK_METHOD(void, setWallPlateHeight, (double));
    MOCK_METHOD(void, setHorizontalEaveLength, (double)); 
    MOCK_METHOD(void, setPurlin, (bool));
    MOCK_METHOD(void, setPurlinPropDistance, (double));
    MOCK_METHOD(void, setCommonRafterHeight, (double));
    MOCK_METHOD(void, setCommonRafterWidth, (double));
    MOCK_METHOD(void, setCommonRafterDistance, (double));

    // wartosci obliczane przez program
    MOCK_METHOD(void, setPurlinPropLength, (double));
    MOCK_METHOD(void, setPurlinLevel, (double));
    MOCK_METHOD(void, setPurlinDimensions, (double)); 
    MOCK_METHOD(void, setCommRaftTotalLength, (double));
    MOCK_METHOD(void, setHipWidth, (double));
    MOCK_METHOD(void, setHipHeight, (double));
    MOCK_METHOD(void, setHipRaftTotalLength, (double));
    MOCK_METHOD(void, setRafterAboveWallPlat, (double));

     // get
    MOCK_METHOD(bool, isPurlin, (), (const));
    MOCK_METHOD(double, getPurlinPropLength, (), (const));
    MOCK_METHOD(double, getPurlinLevel, (), (const));
    MOCK_METHOD(double, getPurlinDimensions, (), (const));
    MOCK_METHOD(double, getCommRaftTotalLength, (), (const));
    MOCK_METHOD(double, getHipWidth, (), (const));
    MOCK_METHOD(double, getHipHeight, (), (const));
    MOCK_METHOD(double, getHipRaftTotalLength, (), (const));
    MOCK_METHOD(double, getRafterAboveWallPlat, (), (const));
    MOCK_METHOD(double, getBuildingLength, (), (const));
    MOCK_METHOD(double, getBuildingWidth, (), (const));
    MOCK_METHOD(double, getTrussHeight, (), (const));
    MOCK_METHOD(double, getTrussLength, (), (const));
    MOCK_METHOD(double, getWallPlateHeight, (), (const));
    MOCK_METHOD(double, getPurlinPropDistance, (), (const));
    MOCK_METHOD(double, getHorizontalEaveLength, (), (const));
    MOCK_METHOD(double, getCommonRafterHeight, (), (const));
    MOCK_METHOD(double, getCommonRafterWidth, (), (const));
    MOCK_METHOD(double, getCommonRaftersDistance, (), (const));
    MOCK_METHOD(double, getNumberOfCommRafters, (), (const));
};
