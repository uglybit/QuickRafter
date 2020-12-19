#include "HipRafter.h"

using namespace std;


HipRafter::HipRafter() : CommonRafter(int())
{
    setName("Hip rafter");
    setParameters();
}


void HipRafter::setParameters()
{
#ifndef TEST // wersja nie-testowa, podawanie wszystkich wartoœci przez u¿ytkownika
    setWidth();
    OvDim::setHipWidth(getWidth());
    setHeight();
    OvDim::setHipHeight(getHeight());

#else  // TEST - bez rêcznego wpisywania wartoœci
    setWidth(140);
    setHeight(220);
    OvDim::setHipWidth(140);
    OvDim::setHipHeight(220);
#endif
}


// paramtery krokwi naro¿nej 
void HipRafter::calculateParameters()
{
    // wymiar poziomy: po³owa d³ugoœci budynku - przek¹tna
    double horizontal = sqrt(2) * (OvDim::getBuildingWidth() / 2);

    // wymiar pionowy: wysokoœæ od mur³aty + wysokosæ krokwi nad mur³at¹ do szczytu dachu
    double vertical = OvDim::getTrussHeight() -
        OvDim::getWallPlateHeight() -
        OvDim::getRafterAboveWallPlat();

    // k¹t krokwi naro¿nej - zawsze mniejszy ni¿ zwyk³ej
    calculateAngles(vertical, horizontal);

    // pomocnicza pionowa lina na krokwi pod k¹tem
    calculateVerticalLine(OvDim::getHipHeight());

    // d³ugoœæ zaciêcia w pionie na zewnêtrznej powierzchni krokwi naro¿nej
    verticalCut = angleVerticalLine - OvDim::getRafterAboveWallPlat();

    // pomocnicza pozioma lina na krokwi pod k¹tem
    calculateHorizontalLine(OvDim::getHipHeight());

    // d³ugoœc zaciêcia w poziomie na zewnêtrznej powierzchni krokwi naro¿nej
    calculateHorizontalCut();

    // drugie zaciêcie: pionowe i poziome
    cutToSquare();

    // funkcja z klasy CommonRafter  - obliczanie d³ugoœci sekcji krokwi
    calculateRafterDimensions(2); // 2 means sqrt(2)  for some values, because it is diagonal

    // obliczenie dodatku na powierzchnie zewnêtrzne - zale¿ne od szerkoœci krokwi
    addToEdges();
}


// obliczenia wartoœci drugiego zaciêcia krokwi naro¿enj: w osi krokwi
void HipRafter::cutToSquare()
{
    // w zaleznosci od szerokosci krokwi naroznej  wymiar zaciêcia bedzie sie zmieniac
    double hipWidth = OvDim::getHipWidth();
    double corr = tan(degreesToRadians(getAlphaAngle())) * (0.5 * hipWidth);

    // zaciêcie w pionie
    verticalCutToSquare = verticalCut + corr;

    //zaciêcie w poziomie
    horizontalCutToSquare = verticalCutToSquare / tan(degreesToRadians(getAlphaAngle()));

    // wysokoœæ krokwi nad mur³at¹
    rafterAboveWallPlat = OvDim::getRafterAboveWallPlat();

    // dl³ugoœæ zaciêcia w poziomie: od powierzchni zewnêtrznej do osi krowki
    angleCutToSquare = (0.5 * OvDim::getHipWidth()) * sqrt(2);
}


// dodatek na powierzchnie zewnêtrzne
void HipRafter::addToEdges()
{
    double cosValue = cos(degreesToRadians(getAlphaAngle()));
    double rafterWidth = OvDim::getHipWidth();
    additionToEgdes = (rafterWidth * 0.5) / cosValue;

    // wymiar na krawêdzich
    rafterTotalOnEdges = rafterTotalLength + additionToEgdes;
    //std::cout << "Rafter dimension on edges, ver. A: " << rafterTotalOnEdges << std::endl;
    //std::cout << "Rafter dimension on edges, ver. B: " << rafterTotalOnEdges - 2*additionToEgdes << std::endl;
}


void HipRafter::showParameters() // override
{
    CommonRafter::showParameters();
    showHipParameters(); // wyœwietlenie dodatkowych parametrów krokwi naro¿nej
}


// uzupe³nienie paramterów krokwi naro¿nej
void HipRafter::showHipParameters()
{
    //showDimensions();
    cout << "\n\t-vertical Cut To Square: " << verticalCutToSquare << endl;
    cout << "\t-horizontal Cut To Square: " << horizontalCutToSquare << endl;
    cout << "\t-angle Cut To Square: " << angleCutToSquare << endl;
}