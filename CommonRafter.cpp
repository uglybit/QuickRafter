#include "CommonRafter.h"

using namespace std;

CommonRafter::CommonRafter() : Element()
{
    setName("Common rafter");
    setParameters(); // override
}


CommonRafter::CommonRafter(int) : Element()  // tego konstruktora wywo�uje HipRafter
{
    // d�ugo�� okpau w poziomie - po przek�tnej dlatego pierwiastek(2)
    horizontalEaveLength = OvDim::getHorizontalEaveLength() * sqrt(2);
}


void CommonRafter::setParameters() // override
{
#ifndef TEST // wersja nie-testowa, podawanie wszystkich warto�ci przez u�ytkownika
    double value;
    setWidth();
    OvDim::setCommonRafterWidth(getWidth());
    setHeight();
    OvDim::setCommonRafterHeight(getHeight());
    value = validateNumber("Approximate distance between common rafters: ", 100.0, 3000.0);
    OvDim::setCommonRafterDistance(value);
    horizontalEaveLength = OvDim::getHorizontalEaveLength();

#else  // TEST - bez r�cznego wpisywania warto�ci
    height = 180;
    width = 90;
    OvDim::setCommonRafterHeight(height);
    OvDim::setCommonRafterWidth(width);
    OvDim::setCommonRafterDistance(800);
    horizontalEaveLength = OvDim::getHorizontalEaveLength();
#endif
}


void CommonRafter::calculateParameters() // override
{
    // pobranie warto�ci w celu obliczenia wst�pnego k�ta dachu
    double h = OvDim::getTrussHeight() - OvDim::getWallPlateHeight();
    double v = OvDim::getBuildingWidth()/2;
    calculateAngles(h, v); // wst�pne warto�ci k�t�w - ulegn� zmianie

    // obliczenia wst�pne
    calculateVerticalLine(OvDim::getCommonRafterHeight()); // d�ugo�c pionowej kreski na krokwi
    calculateVerticalCut(); // d�ugo�� zaci�cia

    // obliczenia w�a�ciwe
    calculateRafterAboveWallPlatt(); // wysoko�� krokwi nad mur�at� - determinuje w�a�ciw� warto�� k�ta dachu
    calculateAngles(h - rafterAboveWallPlat, v); // obliczenia k�ta dachu 
    calculateVerticalLine(OvDim::getCommonRafterHeight()); // ponowne obliczenie pionowej linii, bo wato�ci si� zmieni�y
    calculateProperVerticalCut(); // w�a�ciwa d�ugo�c zai�cia krokwi w pionie
    calculateHorizontalLine(OvDim::getCommonRafterHeight()); // // d�ugo�c poziomej kreski na krokwi
    calculateHorizontalCut(); // w�a�ciwa d�ugo�c zai�cia krokwi w poziomie

    if (OvDim::isPurlin()) {             // obliczenia dla p�atwi i s�upka je�li wyst�puj� w projekcie
        calculatePurlinAndPropLength();
    }
    calculateRafterDimensions(1); // obliczenie reszty wymiar�w krokwi
}


// d�ugo�� poziomej linii narysowanej na krokwi pod odpowiednim k�tem - pomocnicza
void CommonRafter::calculateVerticalLine(double value)
{
    angleVerticalLine = value/sin(degreesToRadians(getBetaAngle())); 
}


// wst�pna d�ugo�c zaci�cia
void CommonRafter::calculateVerticalCut() 
{                                        
    verticalCut = angleVerticalLine * cuttingRatio;
}


// wysoko�� krokwi nad mur�at�
void CommonRafter::calculateRafterAboveWallPlatt() 
{
    rafterAboveWallPlat = angleVerticalLine - verticalCut;
    OvDim::setRafterAboveWallPlat(rafterAboveWallPlat);
}


// pomocnicza pozioma linia na krokwi pod k�tem
void CommonRafter::calculateHorizontalLine(double value)
{
    angleHorizontalLine = value/sin(degreesToRadians(getAlphaAngle()));
}


// w�a�ciwa d�ugo�� zaci�cia w pionie
void CommonRafter::calculateProperVerticalCut()
{
    verticalCut = angleVerticalLine - rafterAboveWallPlat;
}


// obliczamy wysokosc s�upka i wysokosc p�atwi - g�ra
void CommonRafter::calculatePurlinAndPropLength() // if there is a purlin
{
    double pPropDist = OvDim::getPurlinPropDistance(); // odleg�o�� s�upka od mur�aty 
    double tgAngle = tan(degreesToRadians(getAlphaAngle())); // stosunek d�ugo�ci
    double wallPlateHeight = OvDim::getWallPlateHeight(); // wysoko�� mur�aty
    double purlinDim = OvDim::getPurlinDimensions(); // wymiary p�atwi
    double propLength = tgAngle* pPropDist + wallPlateHeight - purlinDim; // d�ugo�� s�upka

    OvDim::setPurlinPropLength(propLength); // zapisanie d�ugo�ci s�upka

    double purDim = OvDim::getPurlinDimensions();
    OvDim::setPurlinLevel(purDim + propLength); // zapisanie wysokko�ci na jakiej jest p�atew
}


void CommonRafter::calculateHorizontalCut()
{
    horizontalCut = verticalCut/tan(degreesToRadians(getAlphaAngle()));
}


// CommonRafter i HipRafter korzystaj� z tej samej funkcji dletego jest paramter: pierwiastek(2 lub 1)
void CommonRafter::calculateRafterDimensions(int sqroot) /* zmodyfikowa� dla dachu bez p�atwi */
{
    // DIMENSION EAVE - WALL PLATE
    double eave = OvDim::getHorizontalEaveLength(); // dlugosc okapu w poziomie
    double propDistance = OvDim::getPurlinPropDistance(); // odleglosc slupka
    double buildWidth = OvDim::getBuildingWidth() / 2; // polowa szerokosci budynku

    // w zale�no�ci od rodzaju krokwi wymiar b�dzie inny
    eave *= sqrt(sqroot); 
    propDistance *= sqrt(sqroot);
    buildWidth *= sqrt(sqroot);

    // D�UGO�C KROKWI - SEKCJE:

    // sekcja a) okap - mur�ata
    double cosValue = cos(degreesToRadians(getAlphaAngle()));
    eaveToWallPlate = eave/cosValue; 

    // sekcja b) mur�ata - p�atew
    wallPlateToPurlin = propDistance/cosValue;

    // sekcja c) p�atew - szczyt
    double dist = buildWidth - propDistance;
    purlinToTop = dist/cosValue;

    // sekcja d) mur�ata - szczyt
    wallPlateToTop = buildWidth/cosValue;
    
    // d�ugo�c ca�kowita
    rafterTotalLength = (buildWidth + eave)/cosValue;
    if (sqroot == 1) {
        OvDim::setCommRaftTotalLength(rafterTotalLength);
    } else {
        OvDim::setHipRaftTotalLength(rafterTotalLength);
    }

#ifdef TEST // w celach testowych - wypisanie obliczanych warto�ci na bie��co
    cout << "Section length: eave - wall plate " << eaveToWallPlate << endl;
    cout << "Section length:  wall plate - purlin: " << wallPlateToPurlin << endl;
    cout << "Section length: purlin - top: " << purlinToTop << endl;
    cout << "Section length: wall plate - top:  " << wallPlateToTop << endl;
    cout << "Rafter total length: " << rafterTotalLength << endl;
    cout << "Horizontal eave length : " << horizontalEaveLength << endl;
#endif
}


// wy�wietlenie parametr�w krokwi
void CommonRafter::showParameters() // override
{
//    showDimensions();
    cout << "\n\n" << getName() << " parameters:"  << endl;
    cout << manip; // output format for values
    cout << "\t-rafter Above WallPlat: " << rafterAboveWallPlat << endl;
    cout << "\t-angle Vertical Line: " << angleVerticalLine << endl;
    cout << "\t-angle Horizontal Line: " << angleHorizontalLine << endl;
    cout << "\t-horizontal Eave Length: " << horizontalEaveLength << endl;
    cout << setprecision(2);
    cout << "\t-alpha angle: " << getAlphaAngle() << endl;
    cout << "\t-beta angle " << getBetaAngle() << endl;
    cout << manip; 
    cout << "\t-vertical Cut: " << verticalCut << endl;
    cout << "\t-horizontal Cut: " << horizontalCut << endl;

    cout << '\n' << getName() << " dimensions:" << endl;
    cout << "\t-eave To Wall Platt: " << eaveToWallPlate << endl;

    if (OvDim::isPurlin() == true) {
        cout << "\t-wall Plate To Purlin: " << wallPlateToPurlin << endl;
        cout << "\t-purlin To Top: " << purlinToTop << endl;
    }
    cout << "\t-wall Plate To Top: " << wallPlateToTop << endl;
    cout << "\t-rafter Total Length: " << rafterTotalLength << endl;

}
