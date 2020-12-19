#include "HipRafter.h"

using namespace std;


HipRafter::HipRafter() : CommonRafter(int())
{
    setName("Hip rafter");
    setParameters();
}


void HipRafter::setParameters()
{
#ifndef TEST // wersja nie-testowa, podawanie wszystkich warto�ci przez u�ytkownika
    setWidth();
    OvDim::setHipWidth(getWidth());
    setHeight();
    OvDim::setHipHeight(getHeight());

#else  // TEST - bez r�cznego wpisywania warto�ci
    setWidth(140);
    setHeight(220);
    OvDim::setHipWidth(140);
    OvDim::setHipHeight(220);
#endif
}


// paramtery krokwi naro�nej 
void HipRafter::calculateParameters()
{
    // wymiar poziomy: po�owa d�ugo�ci budynku - przek�tna
    double horizontal = sqrt(2) * (OvDim::getBuildingWidth() / 2);

    // wymiar pionowy: wysoko�� od mur�aty + wysokos� krokwi nad mur�at� do szczytu dachu
    double vertical = OvDim::getTrussHeight() -
        OvDim::getWallPlateHeight() -
        OvDim::getRafterAboveWallPlat();

    // k�t krokwi naro�nej - zawsze mniejszy ni� zwyk�ej
    calculateAngles(vertical, horizontal);

    // pomocnicza pionowa lina na krokwi pod k�tem
    calculateVerticalLine(OvDim::getHipHeight());

    // d�ugo�� zaci�cia w pionie na zewn�trznej powierzchni krokwi naro�nej
    verticalCut = angleVerticalLine - OvDim::getRafterAboveWallPlat();

    // pomocnicza pozioma lina na krokwi pod k�tem
    calculateHorizontalLine(OvDim::getHipHeight());

    // d�ugo�c zaci�cia w poziomie na zewn�trznej powierzchni krokwi naro�nej
    calculateHorizontalCut();

    // drugie zaci�cie: pionowe i poziome
    cutToSquare();

    // funkcja z klasy CommonRafter  - obliczanie d�ugo�ci sekcji krokwi
    calculateRafterDimensions(2); // 2 means sqrt(2)  for some values, because it is diagonal

    // obliczenie dodatku na powierzchnie zewn�trzne - zale�ne od szerko�ci krokwi
    addToEdges();
}


// obliczenia warto�ci drugiego zaci�cia krokwi naro�enj: w osi krokwi
void HipRafter::cutToSquare()
{
    // w zaleznosci od szerokosci krokwi naroznej  wymiar zaci�cia bedzie sie zmieniac
    double hipWidth = OvDim::getHipWidth();
    double corr = tan(degreesToRadians(getAlphaAngle())) * (0.5 * hipWidth);

    // zaci�cie w pionie
    verticalCutToSquare = verticalCut + corr;

    //zaci�cie w poziomie
    horizontalCutToSquare = verticalCutToSquare / tan(degreesToRadians(getAlphaAngle()));

    // wysoko�� krokwi nad mur�at�
    rafterAboveWallPlat = OvDim::getRafterAboveWallPlat();

    // dl�ugo�� zaci�cia w poziomie: od powierzchni zewn�trznej do osi krowki
    angleCutToSquare = (0.5 * OvDim::getHipWidth()) * sqrt(2);
}


// dodatek na powierzchnie zewn�trzne
void HipRafter::addToEdges()
{
    double cosValue = cos(degreesToRadians(getAlphaAngle()));
    double rafterWidth = OvDim::getHipWidth();
    additionToEgdes = (rafterWidth * 0.5) / cosValue;

    // wymiar na kraw�dzich
    rafterTotalOnEdges = rafterTotalLength + additionToEgdes;
    //std::cout << "Rafter dimension on edges, ver. A: " << rafterTotalOnEdges << std::endl;
    //std::cout << "Rafter dimension on edges, ver. B: " << rafterTotalOnEdges - 2*additionToEgdes << std::endl;
}


void HipRafter::showParameters() // override
{
    CommonRafter::showParameters();
    showHipParameters(); // wy�wietlenie dodatkowych parametr�w krokwi naro�nej
}


// uzupe�nienie paramter�w krokwi naro�nej
void HipRafter::showHipParameters()
{
    //showDimensions();
    cout << "\n\t-vertical Cut To Square: " << verticalCutToSquare << endl;
    cout << "\t-horizontal Cut To Square: " << horizontalCutToSquare << endl;
    cout << "\t-angle Cut To Square: " << angleCutToSquare << endl;
}