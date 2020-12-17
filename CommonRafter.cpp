#include "CommonRafter.h"

using namespace std;

CommonRafter::CommonRafter() : Element()
{
    name = "Common rafter";
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
    OvDim::setCommonRafterWidth(width);
    setHeight();
    OvDim::setCommonRafterHeight(height);
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
    angleVerticalLine = value/sin(degreesToRadians(betaAngle)); 
}


// wstêpnad ³ugoœc zaciêcia
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
    angleHorizontalLine = value/sin(degreesToRadians(alphaAngle));
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
    double tgAngle = tan(degreesToRadians(alphaAngle)); // stosunek d³ugoœci
    double wallPlateHeight = OvDim::getWallPlateHeight(); // wysokoœæ mur³aty
    double purlinDim = OvDim::getPurlinDimensions(); // wymiary p³atwi
    double propLength = tgAngle* pPropDist + wallPlateHeight - purlinDim; // d³ugoœæ s³upka

    OvDim::setPurlinPropLength(propLength); // zapisanie d³ugoœci s³upka

    double purDim = OvDim::getPurlinDimensions();
    OvDim::setPurlinLevel(purDim + propLength); // zapisanie wysokkoœci na jakiej jest p³atew
}


void CommonRafter::calculateHorizontalCut()
{
    horizontalCut = verticalCut/tan(degreesToRadians(alphaAngle));
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
    double cosValue = cos(degreesToRadians(alphaAngle));
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
    cout << "\n\n" << name << " parameters:"  << endl;
    cout << manip; // output format for values
    cout << "\t-rafter Above WallPlat: " << rafterAboveWallPlat << endl;
    cout << "\t-angle Vertical Line: " << angleVerticalLine << endl;
    cout << "\t-angle Horizontal Line: " << angleHorizontalLine << endl;
    cout << "\t-horizontal Eave Length: " << horizontalEaveLength << endl;
    cout << setprecision(2);
    cout << "\t-alpha angle: " << alphaAngle << endl;
    cout << "\t-beta angle " << betaAngle << endl;
    cout << manip; 
    cout << "\t-vertical Cut: " << verticalCut << endl;
    cout << "\t-horizontal Cut: " << horizontalCut << endl;

    cout << '\n' << name << " dimensions:" << endl;
    cout << "\t-eave To Wall Platt: " << eaveToWallPlate << endl;

    if (OvDim::isPurlin() == true) {
        cout << "\t-wall Plate To Purlin: " << wallPlateToPurlin << endl;
        cout << "\t-purlin To Top: " << purlinToTop << endl;
    }
    cout << "\t-wall Plate To Top: " << wallPlateToTop << endl;
    cout << "\t-rafter Total Length: " << rafterTotalLength << endl;

}


/*************** HIP RAFTER **********************/


HipRafter::HipRafter() : CommonRafter(int())
{
    name = "Hip rafter";
    setParameters();
}


void HipRafter::setParameters()
{
#ifndef TEST // wersja nie-testowa, podawanie wszystkich wartoœci przez u¿ytkownika
    setWidth();
    OvDim::setHipWidth(width);
    setHeight();
    OvDim::setHipHeight(height);

#else  // TEST - bez rêcznego wpisywania wartoœci
    width = 140;
    height = 220;
    OvDim::setHipWidth(140);
    OvDim::setHipHeight(220);
#endif
}


// paramtery krokwi naro¿nej 
void HipRafter::calculateParameters()
{
    // wymiar poziomy: po³owa d³ugoœci budynku - przek¹tna
    double horizontal = sqrt(2)*(OvDim::getBuildingWidth()/2);

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
    double corr = tan(degreesToRadians(alphaAngle))*(0.5*hipWidth);

    // zaciêcie w pionie
    verticalCutToSquare = verticalCut + corr;

    //zaciêcie w poziomie
    horizontalCutToSquare = verticalCutToSquare/tan(degreesToRadians(alphaAngle));

    // wysokoœæ krokwi nad mur³at¹
    rafterAboveWallPlat = OvDim::getRafterAboveWallPlat(); 

    // dl³ugoœæ zaciêcia w poziomie: od powierzchni zewnêtrznej do osi krowki
    angleCutToSquare = (0.5*OvDim::getHipWidth())*sqrt(2);
}


// dodatek na powierzchnie zewnêtrzne
void HipRafter::addToEdges()
{
    double cosValue = cos(degreesToRadians(alphaAngle));
    double rafterWidth = OvDim::getHipWidth();
    additionToEgdes = (rafterWidth*0.5)/cosValue;

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