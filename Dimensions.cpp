#include "Dimensions.h"
#include <iostream>

using namespace std;


Dimensions::Dimensions() // konstruktor - wywo³ywany w Menu::show(), przed typem dachu
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
void Dimensions::setPurlin(bool pur) { purlin = pur; }
bool Dimensions::isPurlin() const { return purlin; }

// d³ugoœæ s³upka obliczana i ustawiana przez funkcjê z klasy CommonRafter 
void Dimensions::setPurlinPropLength(double value)
{
    purlinPropLength = value;
}

// wprowadzane przez uzytkownika
void Dimensions::setBuildingLength(double value)           { buildingLength = value; }
void Dimensions::setBuildingWidth(double value)            { buildingWidth = value; }
void Dimensions::setTrussHeight(double value)              { trussHeight = value; }
void Dimensions::setTrussLength(double value)              { trussLength = value; }
void Dimensions::setWallPlateHeight(double value)          { wallPlateHeight = value; }
void Dimensions::setPurlinPropDistance(double value)       { purlinPropDistance = value; }
void Dimensions::setHorizontalEaveLength(double value)     { horizontalEaveLength = value; }
void Dimensions::setCommonRafterHeight(double value)       { commonRafterHeight = value; }
void Dimensions::setCommonRafterWidth(double value)        { commonRafterWidth = value; }

// set

void Dimensions::setPurlinDimensions(double value) { purlinHeight = value; }
void Dimensions::setPurlinLevel(double value) { purlinLevel = value; }
void Dimensions::setHipWidth(double value) { hipRafterWidth = value; }
void Dimensions::setHipHeight(double value) {hipRafterHeight = value; }
void Dimensions::setRafterAboveWallPlat(double value) { rafterAboveWallPlat = value; }

// get
double Dimensions::getPurlinPropLength() const { return purlinPropLength; }
double Dimensions::getPurlinDimensions()  const { return purlinHeight; }
double Dimensions::getPurlinLevel() const { return purlinLevel; }
double Dimensions::getHipWidth() const { return hipRafterWidth; }
double Dimensions::getRafterAboveWallPlat() const { return rafterAboveWallPlat; }
double Dimensions::getHipHeight() const { return hipRafterHeight; }

double Dimensions::getBuildingLength() const { return  buildingLength;}
double Dimensions::getBuildingWidth() const { return  buildingWidth;}
double Dimensions::getTrussHeight() const { return  trussHeight;}
double Dimensions::getTrussLength() const { return  trussLength;}
double Dimensions::getWallPlateHeight() const { return  wallPlateHeight;}
double Dimensions::getPurlinPropDistance() const { return  purlinPropDistance;}
double Dimensions::getHorizontalEaveLength() const    { return  horizontalEaveLength;}
double Dimensions::getCommonRafterHeight() const { return  commonRafterHeight;}
double Dimensions::getCommonRafterWidth() const { return  commonRafterWidth;}
double Dimensions::getCommonRaftersDistance() const { return  commonRaftersDistance;}
double Dimensions::getNumberOfCommRafters() const { return  numberOfRafters;}
