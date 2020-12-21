#ifndef OVERALLDIMENSIONS_H
#define OVERALLDIMENSIONS_H

#include <string>
#include <iostream>
#include <iomanip>

//#define TEST  // do testów - jesli TEST jest zdefiniowany: kompilacja bez wpisywania wartoœci
                // zostan¹ u¿yte wartoœci domyœlne */ wyrzuciæ to st¹d

bool dataValidation(std::string info);
std::ostream& manip(std::ostream&);


// walidacja danych wejœciowych - liczba
template<typename T>
T validateNumber(std::string request, T range_low, T range_high, 
                  std::string info_bad_data = "This is not propper value")
{
    T n;
    do
    {
        std::cout << std::endl << request << std::endl;
        std::cin >> n;
        if (dataValidation(info_bad_data))// z³e dane 
            continue; 
        else if (n < range_low || n > range_high) // jeœli poza zakresem 
        {
            std::cout << "You can choose from: " << range_low << " to "
                      << range_high << ". Try again" << std::endl;
        }
        else break; // wszystko ok- wyjœcie z pêtli
    } while (true);

    return n;
}

// klasa wymiary ogólne - dane wejœciowe wprowadzane przez u¿ytkownika
class OverallDimensions 
{
public:
    OverallDimensions(); 
    ~OverallDimensions() {} 

private:
    static
        double buildingLength, // dlugosc bydunku
        buildingWidth, // szerokosc budynku
        trussHeight, // wysokosc wiezby
        trussLength, // dlugosc wiezby - z wiatrolapami
        wallPlateHeight, // wysokosc murlaty
        purlinPropDistance, // odleg³oœæ podpory platwi - s³upka
        horizontalEaveLength, // dlugosc okapu w poziomie

        commonRafterHeight, // wymiar krokwi - wysokosc
        commonRafterWidth, // wymiar krokwi szerokosc
        commonRaftersDistance, // odleglosc miedzy krokwiami
        commRaftTotalLength, // d³ugoœc krokwi

        hipRafterHeight, // wymiar krokwi naroznej - wysokosc
        hipRafterWidth, // szerokoœæ krokwi naro¿nej
        hipRaftTotalLength, // wysokoœæ krokwi naro¿nej

        purlinDimensions, // wymiar platwi: za³o¿enie -  przekroj kwadratowy
        purlinHeight, // wysoksc ulozenia platwi - wyokoœæ gornej powierzchni
        purlinLevel,
        purlinPropLength, // d³ugoœæ s³upka - obliczane w CommonRafter

        rafterAboveWallPlat; // wysokosc krokwi nad murlata w pionie


    static int numberOfRafters; // liczba krokwi - dopracowaæ
    static bool purlin;  // informacja - czy wystêpuje p³atew w projekcie

    double alphaAngle, betaAngle; // k¹ty dachu

public:

    // wartoœci wprowadane przez u¿ytkownika
    void setBuildingLength(double value); // ustawienie d³ugoœci budynku 
    void setBuildingWidth(double value); // ustawienie szerokoœci budynku
    void setTrussHeight(double value); // ustawienie wysokoœci wiêŸby
    void setTrussLength(double value); // ustawienie d³ugoœci wiêŸby
    void setWallPlateHeight(double value); // ustawienie wysokoœci na jkaiej znajduje siê mur³ata

    void setHorizontalEaveLength(double value); // ustawienie d³ugoœi okapu

    static void setPurlin(bool h); // ustawienie informacji - czy jest p³atew
    static bool isPurlin(); // informacja - czy jest p³atew

    static void setPurlinPropDistance(double value); // ustawienie odleg³osci s³upka 
    static void setCommonRafterHeight(double value); // ustawienie wysokoœci krokwi
    static void setCommonRafterWidth(double value);  // ustawienie szerokoœci krokwi
    static void setCommonRafterDistance(double value) {commonRaftersDistance = value; } 
    // ^ ustawienie zak³adanej odleg³oœci miêdzy krokwiami

    // wartoœci obliczane przez program
    static void setPurlinPropLength(double value); // s³upek
    static double getPurlinPropLength();

    static void setPurlinLevel(double value); // p³atew
    static double getPurlinLevel();
    static void setPurlinDimensions(double value); 
    static double getPurlinDimensions();

    static void setCommRaftTotalLength(double value) { commRaftTotalLength = value; } // krokiew
    static double getCommRaftTotalLength() { return commRaftTotalLength; }
    static double setCommonRaftersDistance(int value);

    static void setHipWidth(double w); // krokiew naro¿na
    static void setHipHeight(double h);
    static double getHipWidth();
    static double getHipHeight();
    static void setHipRaftTotalLength(double len) {hipRaftTotalLength = len; }
    static double getHipRaftTotalLength() { return hipRaftTotalLength; }

    static void setRafterAboveWallPlat(double value); // obliczenia pomocnicze
    static double getRafterAboveWallPlat();

    // get
    static double getBuildingLength();
    static double getBuildingWidth();
    static double getTrussHeight();
    static double getTrussLength();
    static double getWallPlateHeight();
    static double getPurlinPropDistance();
    static double getHorizontalEaveLength();
    static double getCommonRafterHeight();
    static double getCommonRafterWidth();
    static double getCommonRaftersDistance();
    static double getNumberOfCommRafters();
};

#endif // OVERALLDIMENSIONS_H
