#include "OverallDimensions.h"
#include <iostream>

using namespace std;

using OvDim = OverallDimensions;

// statyczne sk³adniki klasy OverallDimensions
double 
OvDim::buildingLength, 
OvDim::buildingWidth, 
OvDim::trussHeight, 
OvDim::trussLength, 
OvDim::wallPlateHeight,
OvDim::purlinPropDistance, 
OvDim::horizontalEaveLength, 

OvDim::commonRafterHeight, 
OvDim::commonRafterWidth, 
OvDim::commonRaftersDistance, 
OvDim::commRaftTotalLength,

OvDim::hipRafterHeight, 
OvDim::hipRafterWidth,
OvDim::hipRaftTotalLength,

OvDim::purlinDimensions, 
OvDim::purlinHeight,  
OvDim::purlinLevel, 
OvDim::purlinPropLength, 

OvDim::rafterAboveWallPlat;

int OvDim::numberOfRafters;
bool OvDim::purlin = false;


OverallDimensions::OverallDimensions() // konstruktor - wywo³ywany w Menu::show(), przed typem dachu
{
 #ifndef TEST // wersja nie-testowa, podawanie wszystkich wartoœci przez u¿ytkownika

    cout << "\n\t! >ALL VALUES IN MILIMETERS< !\n" << endl;

    double setValue;
    double getValue;

    setValue = validateNumber("Enter building length: ", 1000.0, 50000.0);
    setBuildingLength(setValue);

    setValue = validateNumber<double>("Enter building width: ", 1000.0, 20000.0);
    setBuildingWidth(setValue);

    setValue = validateNumber<double>("Enter truss height: ", 1000.0, 10000.0);
    setTrussHeight(setValue);

    getValue = getBuildingLength();
    setValue = validateNumber<double>("Enter truss length: ", getValue, getValue *1.3);
    setTrussLength(setValue);

    getValue = getTrussHeight();
    setValue = validateNumber<double>("Enter wall plate level: ", 0.0, getValue);
    setWallPlateHeight(setValue);

    getValue = getBuildingWidth(); // ?
    setValue = validateNumber<double>("Enter horizontal eave length: ", 0.0, 3000.0);
    setHorizontalEaveLength(setValue);

#else // TEST - bez rêcznego wpisywania wartoœci przez u¿ytkownika
    setBuildingLength(10000);
    setBuildingWidth(8000);
    setTrussHeight(3500);
    setTrussLength(11000);
    setWallPlateHeight(700);
    setHorizontalEaveLength(1100);
#endif
}

// informacja: czy jest w projekcie p³atew
void OvDim::setPurlin(bool p) { purlin = p; } 
bool OvDim::isPurlin() { return purlin; }

// d³ugoœæ s³upka obliczana i ustawiana przez funkcjê z klasy CommonRafter 
void OvDim::setPurlinPropLength(double value)
{
    purlinPropLength = value;
}

// wprowadzane przez uzytkownika
void OvDim::setBuildingLength(double value)           { buildingLength = value; }
void OvDim::setBuildingWidth(double value)            { buildingWidth = value; }
void OvDim::setTrussHeight(double value)              { trussHeight = value; }
void OvDim::setTrussLength(double value)              { trussLength = value; }
void OvDim::setWallPlateHeight(double value)          { wallPlateHeight = value; }
void OvDim::setPurlinPropDistance(double value)       { purlinPropDistance = value; }
void OvDim::setHorizontalEaveLength(double value)     { horizontalEaveLength = value; }
void OvDim::setCommonRafterHeight(double value)       { commonRafterHeight = value; }
void OvDim::setCommonRafterWidth(double value)        { commonRafterWidth = value; }

// get, set dla p³atwi i s³upka
double OvDim::getPurlinPropLength()           { return purlinPropLength;}
void OvDim::setPurlinDimensions(double value) { purlinHeight = value; }
double OvDim::getPurlinDimensions()           { return purlinHeight; }
void OvDim::setPurlinLevel(double value) { purlinLevel = value; }
double OvDim::getPurlinLevel() { return purlinLevel; }

// get, set dla krowki naro¿nej
void OvDim::setHipWidth(double value) { hipRafterWidth = value; }
double OvDim::getHipWidth() { return hipRafterWidth; }
void OvDim::setHipHeight(double value) {hipRafterHeight = value; }
double OvDim::getHipHeight() { return hipRafterHeight; }

// get, set dla wartoœci pomocniczych - wysokoœæ krokwi nad mur³at¹ w pionie
void OvDim::setRafterAboveWallPlat(double value) { rafterAboveWallPlat = value; }
double OvDim::getRafterAboveWallPlat() { return rafterAboveWallPlat; }

// get
double OvDim::getBuildingLength()           { return  buildingLength;}
double OvDim::getBuildingWidth()            { return  buildingWidth;}
double OvDim::getTrussHeight()              { return  trussHeight;}
double OvDim::getTrussLength()              { return  trussLength;}
double OvDim::getWallPlateHeight()          { return  wallPlateHeight;}
double OvDim::getPurlinPropDistance()       { return  purlinPropDistance;}
double OvDim::getHorizontalEaveLength()     { return  horizontalEaveLength;}
double OvDim::getCommonRafterHeight()       { return  commonRafterHeight;}
double OvDim::getCommonRafterWidth()        { return  commonRafterWidth;}
double OvDim::getCommonRaftersDistance()    { return  commonRaftersDistance;}
double OvDim::getNumberOfCommRafters()      { return  numberOfRafters;}
