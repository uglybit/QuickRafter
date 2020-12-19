#include "CommonRafter.h"

using namespace std;

CommonRafter::CommonRafter() : Element()
{
    setName("Common rafter");
    setParameters(); // override
}


CommonRafter::CommonRafter(int) : Element()  // tego konstruktora wywo³uje HipRafter
{
    // d³ugoœæ okpau w poziomie - po przek¹tnej dlatego pierwiastek(2)
    horizontalEaveLength = OvDim::getHorizontalEaveLength() * sqrt(2);
}


void CommonRafter::setParameters() // override
{
#ifndef TEST // wersja nie-testowa, podawanie wszystkich wartoœci przez u¿ytkownika
    double value;
    setWidth();
    OvDim::setCommonRafterWidth(getWidth());
    setHeight();
    OvDim::setCommonRafterHeight(getHeight());
    value = validateNumber("Approximate distance between common rafters: ", 100.0, 3000.0);
    OvDim::setCommonRafterDistance(value);
    horizontalEaveLength = OvDim::getHorizontalEaveLength();

#else  // TEST - bez rêcznego wpisywania wartoœci
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
    // pobranie wartoœci w celu obliczenia wstêpnego k¹ta dachu
    double h = OvDim::getTrussHeight() - OvDim::getWallPlateHeight();
    double v = OvDim::getBuildingWidth()/2;
    calculateAngles(h, v); // wstêpne wartoœci k¹tów - ulegn¹ zmianie

    // obliczenia wstêpne
    calculateVerticalLine(OvDim::getCommonRafterHeight()); // d³ugoœc pionowej kreski na krokwi
    calculateVerticalCut(); // d³ugoœæ zaciêcia

    // obliczenia w³aœciwe
    calculateRafterAboveWallPlatt(); // wysokoœæ krokwi nad mur³at¹ - determinuje w³aœciw¹ wartoœæ k¹ta dachu
    calculateAngles(h - rafterAboveWallPlat, v); // obliczenia k¹ta dachu 
    calculateVerticalLine(OvDim::getCommonRafterHeight()); // ponowne obliczenie pionowej linii, bo watoœci siê zmieni³y
    calculateProperVerticalCut(); // w³aœciwa d³ugoœc zaiêcia krokwi w pionie
    calculateHorizontalLine(OvDim::getCommonRafterHeight()); // // d³ugoœc poziomej kreski na krokwi
    calculateHorizontalCut(); // w³aœciwa d³ugoœc zaiêcia krokwi w poziomie

    if (OvDim::isPurlin()) {             // obliczenia dla p³atwi i s³upka jeœli wystêpuj¹ w projekcie
        calculatePurlinAndPropLength();
    }
    calculateRafterDimensions(1); // obliczenie reszty wymiarów krokwi
}


// d³ugoœæ poziomej linii narysowanej na krokwi pod odpowiednim k¹tem - pomocnicza
void CommonRafter::calculateVerticalLine(double value)
{
    angleVerticalLine = value/sin(degreesToRadians(getBetaAngle())); 
}


// wstêpna d³ugoœc zaciêcia
void CommonRafter::calculateVerticalCut() 
{                                        
    verticalCut = angleVerticalLine * cuttingRatio;
}


// wysokoœæ krokwi nad mur³at¹
void CommonRafter::calculateRafterAboveWallPlatt() 
{
    rafterAboveWallPlat = angleVerticalLine - verticalCut;
    OvDim::setRafterAboveWallPlat(rafterAboveWallPlat);
}


// pomocnicza pozioma linia na krokwi pod k¹tem
void CommonRafter::calculateHorizontalLine(double value)
{
    angleHorizontalLine = value/sin(degreesToRadians(getAlphaAngle()));
}


// w³aœciwa d³ugoœæ zaciêcia w pionie
void CommonRafter::calculateProperVerticalCut()
{
    verticalCut = angleVerticalLine - rafterAboveWallPlat;
}


// obliczamy wysokosc s³upka i wysokosc p³atwi - góra
void CommonRafter::calculatePurlinAndPropLength() // if there is a purlin
{
    double pPropDist = OvDim::getPurlinPropDistance(); // odleg³oœæ s³upka od mur³aty 
    double tgAngle = tan(degreesToRadians(getAlphaAngle())); // stosunek d³ugoœci
    double wallPlateHeight = OvDim::getWallPlateHeight(); // wysokoœæ mur³aty
    double purlinDim = OvDim::getPurlinDimensions(); // wymiary p³atwi
    double propLength = tgAngle* pPropDist + wallPlateHeight - purlinDim; // d³ugoœæ s³upka

    OvDim::setPurlinPropLength(propLength); // zapisanie d³ugoœci s³upka

    double purDim = OvDim::getPurlinDimensions();
    OvDim::setPurlinLevel(purDim + propLength); // zapisanie wysokkoœci na jakiej jest p³atew
}


void CommonRafter::calculateHorizontalCut()
{
    horizontalCut = verticalCut/tan(degreesToRadians(getAlphaAngle()));
}


// CommonRafter i HipRafter korzystaj¹ z tej samej funkcji dletego jest paramter: pierwiastek(2 lub 1)
void CommonRafter::calculateRafterDimensions(int sqroot) /* zmodyfikowaæ dla dachu bez p³atwi */
{
    // DIMENSION EAVE - WALL PLATE
    double eave = OvDim::getHorizontalEaveLength(); // dlugosc okapu w poziomie
    double propDistance = OvDim::getPurlinPropDistance(); // odleglosc slupka
    double buildWidth = OvDim::getBuildingWidth() / 2; // polowa szerokosci budynku

    // w zale¿noœci od rodzaju krokwi wymiar bêdzie inny
    eave *= sqrt(sqroot); 
    propDistance *= sqrt(sqroot);
    buildWidth *= sqrt(sqroot);

    // D£UGOŒC KROKWI - SEKCJE:

    // sekcja a) okap - mur³ata
    double cosValue = cos(degreesToRadians(getAlphaAngle()));
    eaveToWallPlate = eave/cosValue; 

    // sekcja b) mur³ata - p³atew
    wallPlateToPurlin = propDistance/cosValue;

    // sekcja c) p³atew - szczyt
    double dist = buildWidth - propDistance;
    purlinToTop = dist/cosValue;

    // sekcja d) mur³ata - szczyt
    wallPlateToTop = buildWidth/cosValue;
    
    // d³ugoœc ca³kowita
    rafterTotalLength = (buildWidth + eave)/cosValue;
    if (sqroot == 1) {
        OvDim::setCommRaftTotalLength(rafterTotalLength);
    } else {
        OvDim::setHipRaftTotalLength(rafterTotalLength);
    }

#ifdef TEST // w celach testowych - wypisanie obliczanych wartoœci na bie¿¹co
    cout << "Section length: eave - wall plate " << eaveToWallPlate << endl;
    cout << "Section length:  wall plate - purlin: " << wallPlateToPurlin << endl;
    cout << "Section length: purlin - top: " << purlinToTop << endl;
    cout << "Section length: wall plate - top:  " << wallPlateToTop << endl;
    cout << "Rafter total length: " << rafterTotalLength << endl;
    cout << "Horizontal eave length : " << horizontalEaveLength << endl;
#endif
}


// wyœwietlenie parametrów krokwi
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
