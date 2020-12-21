#include "CommonRafter.h"

using namespace std;

CommonRafter::CommonRafter(Dimensions& dim) : Element(dim)
{
    setName("Common rafter");
    setParameters(); // override
}


CommonRafter::CommonRafter(Dimensions& dim, int count) : Element(dim)  // tego konstruktora wywo³uje HipRafter
{
    // d³ugoœæ okpau w poziomie - po przek¹tnej dlatego pierwiastek(2)
    horizontalEaveLength = getDimensions()->getHorizontalEaveLength() * sqrt(2);
}


void CommonRafter::setParameters() // override
{
#ifndef TEST // wersja nie-testowa, podawanie wszystkich wartoœci przez u¿ytkownika
    double value;
    setWidth();
    setDimensions()->setCommonRafterWidth(getWidth());
    setHeight();
    setDimensions()->setCommonRafterHeight(getHeight());
    value = validateNumber("Approximate distance between common rafters: ", 100.0, 3000.0);
    setDimensions()->setCommonRafterDistance(value);
    horizontalEaveLength = getDimensions()->getHorizontalEaveLength();

#else  // TEST - bez rêcznego wpisywania wartoœci
    setHeight(180);
    setWidth(90);
    setDimensions()->setCommonRafterHeight(getHeight());
    setDimensions()->setCommonRafterWidth(getWidth());
    setDimensions()->setCommonRafterDistance(800);
    horizontalEaveLength = getDimensions()->getHorizontalEaveLength();
#endif
}


void CommonRafter::calculateParameters() // override
{
    // pobranie wartoœci w celu obliczenia wstêpnego k¹ta dachu
    double height = getDimensions()->getTrussHeight() - getDimensions()->getWallPlateHeight();
    double width = getDimensions()->getBuildingWidth()/2;
    calculateAngles(height, width); // wstêpne wartoœci k¹tów - ulegn¹ zmianie

    // obliczenia wstêpne
    calculateVerticalLine(getDimensions()->getCommonRafterHeight()); // d³ugoœc pionowej kreski na krokwi
    calculateVerticalCut(); // d³ugoœæ zaciêcia

    // obliczenia w³aœciwe
    calculateRafterAboveWallPlatt(); // wysokoœæ krokwi nad mur³at¹ - determinuje w³aœciw¹ wartoœæ k¹ta dachu
    calculateAngles(height - rafterAboveWallPlat, width); // obliczenia k¹ta dachu 
    calculateVerticalLine(getDimensions()->getCommonRafterHeight()); // ponowne obliczenie pionowej linii, bo watoœci siê zmieni³y
    calculateProperVerticalCut(); // w³aœciwa d³ugoœc zaiêcia krokwi w pionie
    calculateHorizontalLine(getDimensions()->getCommonRafterHeight()); // // d³ugoœc poziomej kreski na krokwi
    calculateHorizontalCut(); // w³aœciwa d³ugoœc zaiêcia krokwi w poziomie

    if (getDimensions()->isPurlin()) {             // obliczenia dla p³atwi i s³upka jeœli wystêpuj¹ w projekcie
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
    setDimensions()->setRafterAboveWallPlat(rafterAboveWallPlat);
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
    double pPropDist = getDimensions()->getPurlinPropDistance(); // odleg³oœæ s³upka od mur³aty 
    double tgAngle = tan(degreesToRadians(getAlphaAngle())); // stosunek d³ugoœci
    double wallPlateHeight = getDimensions()->getWallPlateHeight(); // wysokoœæ mur³aty
    double purlinDim = getDimensions()->getPurlinDimensions(); // wymiary p³atwi
    double propLength = tgAngle* pPropDist + wallPlateHeight - purlinDim; // d³ugoœæ s³upka

    setDimensions()->setPurlinPropLength(propLength); // zapisanie d³ugoœci s³upka

    double purDim = getDimensions()->getPurlinDimensions();
    setDimensions()->setPurlinLevel(purDim + propLength); // zapisanie wysokkoœci na jakiej jest p³atew
}


void CommonRafter::calculateHorizontalCut()
{
    horizontalCut = verticalCut/tan(degreesToRadians(getAlphaAngle()));
}


// CommonRafter i HipRafter korzystaj¹ z tej samej funkcji dletego jest paramter: pierwiastek(2 lub 1)
void CommonRafter::calculateRafterDimensions(int sqroot) /* zmodyfikowaæ dla dachu bez p³atwi */
{
    // DIMENSION EAVE - WALL PLATE
    double eave = getDimensions()->getHorizontalEaveLength(); // dlugosc okapu w poziomie
    double propDistance = getDimensions()->getPurlinPropDistance(); // odleglosc slupka
    double buildWidth = getDimensions()->getBuildingWidth() / 2; // polowa szerokosci budynku

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
        setDimensions()->setCommRaftTotalLength(rafterTotalLength);
    } else {
        setDimensions()->setHipRaftTotalLength(rafterTotalLength);
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

    if (getDimensions()->isPurlin() == true) {
        cout << "\t-wall Plate To Purlin: " << wallPlateToPurlin << endl;
        cout << "\t-purlin To Top: " << purlinToTop << endl;
    }
    cout << "\t-wall Plate To Top: " << wallPlateToTop << endl;
    cout << "\t-rafter Total Length: " << rafterTotalLength << endl;

}
