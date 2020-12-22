#ifndef DIMENSIONS_H
#define DIMENSIONS_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Functions.h"

#define TEST  // do testów - jesli TEST jest zdefiniowany: kompilacja bez wpisywania wartoœci

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
    double purlinPropLength{ 0.0 }; // d³ugosc slupka - obliczane w CommonRafter

    double rafterAboveWallPlat{ 0.0 }; // wysokosc krokwi nad murlata w pionie
    double alphaAngle{ 0 };
    double betaAngle{ 0 }; 

    int numberOfRafters{ 0 }; // liczba krokwi - dopracowac
    bool purlin{ false };  // informacja - czy wystepuje platew w projekcie

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
    void setPurlin(bool pur); 
    void setPurlinPropDistance(double value); 
    void setCommonRafterHeight(double value); 
    void setCommonRafterWidth(double value); 
    void setCommonRafterDistance(double value) {commonRaftersDistance = value; } 

    // wartoœci obliczane przez program
    void setPurlinPropLength(double value); // slupek
    void setPurlinLevel(double value); // platew
    void setPurlinDimensions(double value); 
    void setCommRaftTotalLength(double value) { commRaftTotalLength = value; } // krokiew
    void setHipWidth(double value); // krokiew narozna
    void setHipHeight(double value);
    void setHipRaftTotalLength(double len) {hipRaftTotalLength = len; }
    void setRafterAboveWallPlat(double value); // obliczenia pomocnicze

     // get
    bool isPurlin() const;
    double getPurlinPropLength() const;
    double getPurlinLevel() const;
    double getPurlinDimensions() const;
    double getCommRaftTotalLength() const { return commRaftTotalLength; }
    double getHipWidth() const;
    double getHipHeight() const;
    double getHipRaftTotalLength() const { return hipRaftTotalLength; }
    double getRafterAboveWallPlat() const;
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
