#ifndef DIMENSIONS_H
#define DIMENSIONS_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Functions.h"

#define TEST  // do test�w - jesli TEST jest zdefiniowany: kompilacja bez wpisywania warto�ci

// klasa wymiary ogolne
class Dimensions 
{
private:
    double buildingLength{ 0.0 }; // dlugosc bydunku
    double buildingWidth{ 0.0 }; // szerokosc budynku
    double trussHeight{ 0.0 }; // wysokosc wiezby
    double trussLength{ 0.0 }; // dlugosc wiezby - z wiatrolapami
    double wallPlateHeight{ 0.0 }; // wysokosc murlaty
    double purlinPropDistance{ 0.0 }; 
    double horizontalEaveLength{ 0.0 }; 

    double commonRafterHeight{ 0.0 }; 
    double commonRafterWidth{ 0.0 }; 
    double commonRaftersDistance{ 0.0 }; 
    double commRaftTotalLength{ 0.0 }; 

    double hipRafterHeight{ 0.0 }; // wymiar krokwi naroznej - wysokosc
    double hipRafterWidth{ 0.0 }; // szerokosc krokwi naroznej
    double hipRaftTotalLength{ 0.0 }; // wysokosc krokwi naroznej

    double purlinDimensions{ 0.0 }; // wymiar platwi: zalozenie -  przekroj kwadratowy
    double purlinHeight{ 0.0 }; // wysoksc ulozenia platwi - wyokosc gornej powierzchni
    double purlinLevel{ 0.0 };
    double purlinPropLength{ 0.0 }; // d�ugosc slupka - obliczane w CommonRafter

    double rafterAboveWallPlat{ 0.0 }; // wysokosc krokwi nad murlata w pionie
    double alphaAngle, betaAngle; // katy dachu

    int numberOfRafters; // liczba krokwi - dopracowac
    bool purlin;  // informacja - czy wystepuje platew w projekcie

public:
    Dimensions();
    ~Dimensions() = default;

    // wartosci wprowadzane przez uzytkownika
    void setBuildingLength(double value); 
    void setBuildingWidth(double value); 
    void setTrussHeight(double value); 
    void setTrussLength(double value); 
    void setWallPlateHeight(double value);
    void setHorizontalEaveLength(double value); 
    void setPurlin(bool h); 
    void setPurlinPropDistance(double value); 
    void setCommonRafterHeight(double value); 
    void setCommonRafterWidth(double value); 
    void setCommonRafterDistance(double value) {commonRaftersDistance = value; } 

    // warto�ci obliczane przez program
    void setPurlinPropLength(double value); // slupek
    void setPurlinLevel(double value); // platew
    void setPurlinDimensions(double value); 
    void setCommRaftTotalLength(double value) { commRaftTotalLength = value; } // krokiew
    void setHipWidth(double w); // krokiew narozna
    void setHipHeight(double h);
    void setHipRaftTotalLength(double len) {hipRaftTotalLength = len; }
    void setRafterAboveWallPlat(double value); // obliczenia pomocnicze

     // get
    double getPurlinPropLength() const;
    double getPurlinLevel() const;
    double getPurlinDimensions() const;
    double getCommRaftTotalLength() const { return commRaftTotalLength; }
    double getHipWidth() const;
    double getHipHeight() const;
    double getHipRaftTotalLength() const { return hipRaftTotalLength; }
    double getRafterAboveWallPlat() const;
    bool isPurlin() const;
    double getBuildingLength() const;
    double getBuildingWidth() const;
    double getTrussHeight() const;
    double getTrussLength() const;
    double getWallPlateHeight() const;
    double getPurlinPropDistance() const;
    double getHorizontalEaveLength() const;
    double getCommonRafterHeight() const;
    double getCommonRafterWidth() const;
    double getCommonRaftersDistance() const;
    double getNumberOfCommRafters() const;
};

#endif // OVERALLDIMENSIONS_H
