#include "CommonRafter.h"


CommonRafter::CommonRafter(Dimensions& dim) : Element(dim)
{
    setName("Common rafter");
    setParameters(); // override // virtualna nie w konstruktorze!
}


CommonRafter::CommonRafter(Dimensions& dim, int count) : Element(dim)  // tego konstruktora wywo�uje HipRafter
{
    // dlugosc okpau w poziomie - po przekatnej dlatego pierwiastek(2)
    horizontalEaveLength = getDimensions()->getHorizontalEaveLength() * sqrt(2);
}


ElementType CommonRafter::type() const { 
    return ElementType::CommonRafter; 
}


void CommonRafter::setParameters() 
{
    double value;
    setWidth();
    setDimensions()->setCommonRafterWidth(getWidth());
    setHeight();
    setDimensions()->setCommonRafterHeight(getHeight());
    value = validateNumber<double>("Approximate distance between common rafters: ", 100.0, 3000.0);
    setDimensions()->setCommonRafterDistance(value);
    horizontalEaveLength = getDimensions()->getHorizontalEaveLength();
}


void CommonRafter::calculateParameters() // override
{
    // pobranie warto�ci w celu obliczenia wst�pnego k�ta dachu
    double height = getDimensions()->getTrussHeight() - getDimensions()->getWallPlateHeight();
    double width = getDimensions()->getBuildingWidth()/2;
    calculateAngles(height, width); // wst�pne warto�ci k�t�w - ulegn� zmianie

    // obliczenia wst�pne
    calculateVerticalLine(getDimensions()->getCommonRafterHeight()); // d�ugo�c pionowej kreski na krokwi
    calculateVerticalCut(); // d�ugo�� zaci�cia

    // obliczenia w�a�ciwe
    calculateRafterAboveWallPlatt(); // wysoko�� krokwi nad mur�at� - determinuje w�a�ciw� warto�� k�ta dachu
    calculateAngles(height - rafterAboveWallPlat, width); // obliczenia k�ta dachu 
    calculateVerticalLine(getDimensions()->getCommonRafterHeight()); // ponowne obliczenie pionowej linii, bo wato�ci si� zmieni�y
    calculateProperVerticalCut(); // w�a�ciwa d�ugo�c zai�cia krokwi w pionie
    calculateHorizontalLine(getDimensions()->getCommonRafterHeight()); // // d�ugo�c poziomej kreski na krokwi
    calculateHorizontalCut(); // w�a�ciwa d�ugo�c zai�cia krokwi w poziomie

    if (getDimensions()->isPurlin()) {             // obliczenia dla p�atwi i s�upka je�li wyst�puj� w projekcie
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
    setDimensions()->setRafterAboveWallPlat(rafterAboveWallPlat);
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
    double pPropDist = getDimensions()->getPurlinPropDistance(); // odleg�o�� s�upka od mur�aty 
    double tgAngle = tan(degreesToRadians(getAlphaAngle())); // stosunek d�ugo�ci
    double wallPlateHeight = getDimensions()->getWallPlateHeight(); // wysoko�� mur�aty
    double purlinDim = getDimensions()->getPurlinDimensions(); // wymiary p�atwi
    double propLength = tgAngle* pPropDist + wallPlateHeight - purlinDim; // d�ugo�� s�upka

    setDimensions()->setPurlinPropLength(propLength); // zapisanie d�ugo�ci s�upka

    double purDim = getDimensions()->getPurlinDimensions();
    setDimensions()->setPurlinLevel(purDim + propLength); // zapisanie wysokko�ci na jakiej jest p�atew
}


void CommonRafter::calculateHorizontalCut()
{
    horizontalCut = verticalCut/tan(degreesToRadians(getAlphaAngle()));
}


// CommonRafter i HipRafter korzystaja z tej samej funkcji dletego jest paramter: pierwiastek(2 lub 1)
void CommonRafter::calculateRafterDimensions(int sqroot) /* zmodyfikowac dla dachu bez p�atwi */
{
    // DIMENSION EAVE - WALL PLATE
    double eave = getDimensions()->getHorizontalEaveLength(); // dlugosc okapu w poziomie
    double propDistance = getDimensions()->getPurlinPropDistance(); // odleglosc slupka
    double buildWidth = getDimensions()->getBuildingWidth() / 2; // polowa szerokosci budynku

    // w zaleznoci od rodzaju krokwi wymiar b�dzie inny
    eave *= sqrt(sqroot); 
    propDistance *= sqrt(sqroot);
    buildWidth *= sqrt(sqroot);

    // DLUGOSC KROKWI - SEKCJE:

    // sekcja a) okap - murlata
    double cosValue = cos(degreesToRadians(getAlphaAngle()));
    eaveToWallPlate = eave/cosValue; 

    // sekcja b) murlata - platew
    wallPlateToPurlin = propDistance/cosValue;

    // sekcja c) platew - szczyt
    double dist = buildWidth - propDistance;
    purlinToTop = dist/cosValue;

    // sekcja d) murlata - szczyt
    wallPlateToTop = buildWidth/cosValue;
    
    // dlugosc calkowita
    rafterTotalLength = (buildWidth + eave)/cosValue;
    if (sqroot == 1) {
        setDimensions()->setCommRaftTotalLength(rafterTotalLength);
    } else {
        setDimensions()->setHipRaftTotalLength(rafterTotalLength);
    }
}


// wyswietlenie parametrow krokwi
void CommonRafter::showParameters() // override
{
//    showDimensions();
    std::cout << "\n\n" << getName() << " parameters:"  << "\n";
    std::cout << manip; // output format for values
    std::cout << "\t-rafter Above WallPlat: " << rafterAboveWallPlat << "\n";
    std::cout << "\t-angle Vertical Line: " << angleVerticalLine << "\n";
    std::cout << "\t-angle Horizontal Line: " << angleHorizontalLine << "\n";
    std::cout << "\t-horizontal Eave Length: " << horizontalEaveLength << "\n";
    std::cout << std::setprecision(2);
    std::cout << "\t-alpha angle: " << getAlphaAngle() << "\n";
    std::cout << "\t-beta angle " << getBetaAngle() << "\n";
    std::cout << manip;
    std::cout << "\t-vertical Cut: " << verticalCut << "\n";
    std::cout << "\t-horizontal Cut: " << horizontalCut << "\n";

    std::cout << '\n' << getName() << " dimensions:" << "\n";
    std::cout << "\t-eave To Wall Platt: " << eaveToWallPlate << "\n";

    if (getDimensions()->isPurlin() == true) {
        std::cout << "\t-wall Plate To Purlin: " << wallPlateToPurlin << "\n";
        std::cout << "\t-purlin To Top: " << purlinToTop << "\n";
    }
    std::cout << "\t-wall Plate To Top: " << wallPlateToTop << "\n";
    std::cout << "\t-rafter Total Length: " << rafterTotalLength << std::endl;

}

void CommonRafter::setVerticalCut(const double vCut)
{ 
    verticalCut = vCut; 
}


void CommonRafter::setHorizontalCut(const double hCut)
{ 
    horizontalCut = hCut; 
}


void CommonRafter::setRafterAboveWallPlate(const double rafAbove) 
{ 
    rafterAboveWallPlat = rafAbove; 
}


void CommonRafter::setAngleVerticalLine(const double angVert) 
{ 
    angleVerticalLine = angVert;
}


void CommonRafter::setAngleHorizontalLine(const double angHor)
{
    angleHorizontalLine = angHor; 
}


void CommonRafter::setHorizontalEaveLength(const double horEave)
{
    horizontalEaveLength = horEave; 
}


void CommonRafter::setEaveToWallPlate(const double eaveWall) 
{
    eaveToWallPlate = eaveWall; 
}


void CommonRafter::setWallPlateToPurlin(const double wallPurl) 
{ 
    wallPlateToPurlin = wallPurl; 
}


void CommonRafter::setPurlinToTop(const double purlTop)
{
    purlinToTop = purlTop;
}


void CommonRafter::setWallPlateToTop(const double wallTop)
{ 
    wallPlateToTop = wallTop;
}


void CommonRafter::setRafterTotalLength(const double rafterTotal)
{ 
    rafterTotalLength = rafterTotal;
}

// get
double CommonRafter::getVerticalCut() const 
{ 
    return verticalCut;
}


double CommonRafter::getHorizontalCut() const
{
    return  horizontalCut; 
}


double CommonRafter::getRafterAboveWallPlate() const 
{ 
    return rafterAboveWallPlat;
}


double CommonRafter::getAngleVerticalLine() const
{
    return angleVerticalLine; 
}


double CommonRafter::getAngleHorizontalLine() const
{ 
    return angleHorizontalLine; 
}


double CommonRafter::getHorizontalEaveLength() const
{ 
    return horizontalEaveLength;
}


double CommonRafter::getEaveToWallPlate() const 
{ 
    return eaveToWallPlate; 
}


double CommonRafter::getWallPlateToPurlin() const 
{ 
    return wallPlateToPurlin;
}


double CommonRafter::getPurlinToTop() const 
{ 
    return purlinToTop;
}


double CommonRafter::getwallPlateToTop() const
{ 
    return wallPlateToTop; 
}


double CommonRafter::getRafterTotalLength() const 
{ 
    return rafterTotalLength; 
}