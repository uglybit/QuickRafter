#ifndef OVERALLDIMENSIONS_H
#define OVERALLDIMENSIONS_H

#include <string>
#include <iostream>
#include <iomanip>

//#define TEST  // do test�w - jesli TEST jest zdefiniowany: kompilacja bez wpisywania warto�ci
                // zostan� u�yte warto�ci domy�lne */ wyrzuci� to st�d

bool dataValidation(std::string info);
std::ostream& manip(std::ostream&);


// walidacja danych wej�ciowych - liczba
template<typename T>
T validateNumber(std::string request, T range_low, T range_high, 
                  std::string info_bad_data = "This is not propper value")
{
    T n;
    do
    {
        std::cout << std::endl << request << std::endl;
        std::cin >> n;
        if (dataValidation(info_bad_data))// z�e dane 
            continue; 
        else if (n < range_low || n > range_high) // je�li poza zakresem 
        {
            std::cout << "You can choose from: " << range_low << " to "
                      << range_high << ". Try again" << std::endl;
        }
        else break; // wszystko ok- wyj�cie z p�tli
    } while (true);

    return n;
}

// klasa wymiary og�lne - dane wej�ciowe wprowadzane przez u�ytkownika
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
        purlinPropDistance, // odleg�o�� podpory platwi - s�upka
        horizontalEaveLength, // dlugosc okapu w poziomie

        commonRafterHeight, // wymiar krokwi - wysokosc
        commonRafterWidth, // wymiar krokwi szerokosc
        commonRaftersDistance, // odleglosc miedzy krokwiami
        commRaftTotalLength, // d�ugo�c krokwi

        hipRafterHeight, // wymiar krokwi naroznej - wysokosc
        hipRafterWidth, // szeroko�� krokwi naro�nej
        hipRaftTotalLength, // wysoko�� krokwi naro�nej

        purlinDimensions, // wymiar platwi: za�o�enie -  przekroj kwadratowy
        purlinHeight, // wysoksc ulozenia platwi - wyoko�� gornej powierzchni
        purlinLevel,
        purlinPropLength, // d�ugo�� s�upka - obliczane w CommonRafter

        rafterAboveWallPlat; // wysokosc krokwi nad murlata w pionie


    static int numberOfRafters; // liczba krokwi - dopracowa�
    static bool purlin;  // informacja - czy wyst�puje p�atew w projekcie

    double alphaAngle, betaAngle; // k�ty dachu

public:

    // warto�ci wprowadane przez u�ytkownika
    void setBuildingLength(double value); // ustawienie d�ugo�ci budynku 
    void setBuildingWidth(double value); // ustawienie szeroko�ci budynku
    void setTrussHeight(double value); // ustawienie wysoko�ci wi�by
    void setTrussLength(double value); // ustawienie d�ugo�ci wi�by
    void setWallPlateHeight(double value); // ustawienie wysoko�ci na jkaiej znajduje si� mur�ata

    void setHorizontalEaveLength(double value); // ustawienie d�ugo�i okapu

    static void setPurlin(bool h); // ustawienie informacji - czy jest p�atew
    static bool isPurlin(); // informacja - czy jest p�atew

    static void setPurlinPropDistance(double value); // ustawienie odleg�osci s�upka 
    static void setCommonRafterHeight(double value); // ustawienie wysoko�ci krokwi
    static void setCommonRafterWidth(double value);  // ustawienie szeroko�ci krokwi
    static void setCommonRafterDistance(double value) {commonRaftersDistance = value; } 
    // ^ ustawienie zak�adanej odleg�o�ci mi�dzy krokwiami

    // warto�ci obliczane przez program
    static void setPurlinPropLength(double value); // s�upek
    static double getPurlinPropLength();

    static void setPurlinLevel(double value); // p�atew
    static double getPurlinLevel();
    static void setPurlinDimensions(double value); 
    static double getPurlinDimensions();

    static void setCommRaftTotalLength(double value) { commRaftTotalLength = value; } // krokiew
    static double getCommRaftTotalLength() { return commRaftTotalLength; }
    static double setCommonRaftersDistance(int value);

    static void setHipWidth(double w); // krokiew naro�na
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
