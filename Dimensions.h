#ifndef DIMENSIONS_H
#define DIMENSIONS_H

#include <string>
#include <iostream>
#include <iomanip>
#include "Functions.h"

#define TEST  // do testów - jesli TEST jest zdefiniowany: kompilacja bez wpisywania wartoœci
                // zostan¹ u¿yte wartoœci domyœlne */ wyrzuciæ to st¹d



// klasa wymiary ogolne - dane wejsciowe wprowadzane przez uzytkownika
class Dimensions 
{
private:
    double buildingLength{ 0.0 }; // dlugosc bydunku
    double buildingWidth{ 0.0 }; // szerokosc budynku
    double trussHeight{ 0.0 }; // wysokosc wiezby
    double trussLength{ 0.0 }; // dlugosc wiezby - z wiatrolapami
    double wallPlateHeight{ 0.0 }; // wysokosc murlaty
    double purlinPropDistance{ 0.0 }; // odleg³oœæ podpory platwi - s³upka
    double horizontalEaveLength{ 0.0 }; // dlugosc okapu w poziomie

    double commonRafterHeight{ 0.0 }; // wymiar krokwi - wysokosc
    double commonRafterWidth{ 0.0 }; // wymiar krokwi szerokosc
    double commonRaftersDistance{ 0.0 }; // odleglosc miedzy krokwiami
    double commRaftTotalLength{ 0.0 }; // d³ugosc krokwi

    double hipRafterHeight{ 0.0 }; // wymiar krokwi naroznej - wysokosc
    double hipRafterWidth{ 0.0 }; // szerokosc krokwi naroznej
    double hipRaftTotalLength{ 0.0 }; // wysokosc krokwi naroznej

    double purlinDimensions{ 0.0 }; // wymiar platwi: zalozenie -  przekroj kwadratowy
    double purlinHeight{ 0.0 }; // wysoksc ulozenia platwi - wyokosc gornej powierzchni
    double purlinLevel{ 0.0 };
    double purlinPropLength{ 0.0 }; // d³ugosc slupka - obliczane w CommonRafter

    double rafterAboveWallPlat{ 0.0 }; // wysokosc krokwi nad murlata w pionie
    int numberOfRafters; // liczba krokwi - dopracowac
    bool purlin;  // informacja - czy wystepuje platew w projekcie
    double alphaAngle, betaAngle; // katy dachu

public:
    Dimensions();
    ~Dimensions() = default;

    // wartosci wprowadzane przez uzytkownika
    void setBuildingLength(double value); // ustawienie dlugosci budynku 
    void setBuildingWidth(double value); // ustawienie szerokosci budynku
    void setTrussHeight(double value); // ustawienie wysokosci wiezby
    void setTrussLength(double value); // ustawienie d³ugoœci wiezby
    void setWallPlateHeight(double value); // ustawienie wysokosci na jakiej znajduje sie murlata
    void setHorizontalEaveLength(double value); // ustawienie d³ugosci okapu
    void setPurlin(bool h); // ustawienie informacji - czy jest platew
    void setPurlinPropDistance(double value); // ustawienie odleglosci slupka 
    void setCommonRafterHeight(double value); // ustawienie wysokosci krokwi
    void setCommonRafterWidth(double value);  // ustawienie szerokosci krokwi
    void setCommonRafterDistance(double value) {commonRaftersDistance = value; } 

    // wartoœci obliczane przez program
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
    bool isPurlin() const; // informacja - czy jest p³atew
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
