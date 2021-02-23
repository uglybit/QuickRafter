#include "HipRafter.h"


HipRafter::HipRafter(Dimensions& dim) : CommonRafter(dim, int())
{
    setName("Hip rafter");
    setParameters();
}


ElementType HipRafter::type() const 
{
    return  ElementType::HipRafter; 
}


void HipRafter::setParameters()
{
    setWidth();
    setDimensions()->setHipWidth(getWidth());
    setHeight();
    setDimensions()->setHipHeight(getHeight());
}


void HipRafter::calculateParameters()
{
    double horizontal = sqrt(2) * (getDimensions()->getBuildingWidth() / 2);
    double vertical = 
        getDimensions()->getTrussHeight() - 
        getDimensions()->getWallPlateHeight() - 
        getDimensions()->getRafterAboveWallPlat();

    calculateAngles(vertical, horizontal);
    calculateVerticalLine(getDimensions()->getHipHeight());
    double vertCut = getAngleVerticalLine() - getDimensions()->getRafterAboveWallPlat();
    setVerticalCut(vertCut); 
    calculateHorizontalLine(getDimensions()->getHipHeight());
    calculateHorizontalCut();

    cutToSquare();
    calculateRafterDimensions(2); // 2 means sqrt(2)  for some values, because it is diagonal
    addToEdges();
}


// obliczenia warto�ci drugiego zaci�cia krokwi naro�enj: w osi krokwi
void HipRafter::cutToSquare()
{
    double hipWidth = getDimensions()->getHipWidth();
    double correction = tan(degreesToRadians(getAlphaAngle())) * (0.5 * hipWidth);

    verticalCutToSquare = getVerticalCut() + correction;
    horizontalCutToSquare = verticalCutToSquare / tan(degreesToRadians(getAlphaAngle()));
    setRafterAboveWallPlate(getDimensions()->getRafterAboveWallPlat());
    angleCutToSquare = (0.5 * getDimensions()->getHipWidth()) * sqrt(2);
}


// dodatek na powierzchnie zewn�trzne
void HipRafter::addToEdges()
{
    double cosValue = cos(degreesToRadians(getAlphaAngle()));
    double rafterWidth = getDimensions()->getHipWidth();
    setAdditionToEgdes((rafterWidth * 0.5) / cosValue);
    setRafterTotalOnEdges(getRafterTotalLength() + getAdditionToEgdes());
 }


void HipRafter::showParameters() // override
{
    CommonRafter::showParameters();
    showHipParameters(); // wyswietlenie dodatkowych parametrow krokwi naroznej
}


void HipRafter::showHipParameters() const
{
    //showDimensions();
    std::cout << "\n\t-vertical Cut To Square: " << verticalCutToSquare << "\n";
    std::cout << "\t-horizontal Cut To Square: " << horizontalCutToSquare << "\n";
    std::cout << "\t-angle Cut To Square: " << angleCutToSquare << std::endl;
}


void HipRafter::setAdditionToEgdes(const double addition)
{ 
    additionToEgdes = addition; 
}


void HipRafter::setRafterTotalOnEdges(const double totalEgdes)
{ 
    rafterTotalOnEdges = totalEgdes;
}


double HipRafter::getAdditionToEgdes() const
{ 
    return additionToEgdes; 
}


double HipRafter::getRafterTotalOnEdges() const
{ 
    return rafterTotalOnEdges; 
}
