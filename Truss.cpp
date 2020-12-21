#include "Truss.h"

using namespace std;

Truss::Truss(Dimensions& dim) : dimension{ dim }
{
    elements.push_back(new WallPlate(dim));
    elements.push_back(new CommonRafter(dim));
    calcCommonRaftersDistance();
}


const Dimensions* Truss::getDimensions()
{
    return &dimension;
}


Truss::~Truss()
{
    for (auto a : elements) {
        if (a != nullptr)
            delete a;
    }
}


// wywo³uje funkcjê obliczaj¹c¹ dla ka¿dego elementu
void Truss::calcParam()
{
    for (auto a : elements) {
        a->calculateParameters();
    }
}


// pokazuje wszystkie elementy dachu
void Truss::show()
{
#ifndef TEST   
    system("cls");
#endif
    getInitialDimensions();

    for (auto a : elements ) {
        a->showParameters();
    }

    cout << "\nCommon rafters distance: "
       << getDimensions()->getCommonRaftersDistance() << endl;

    cout << "Roof surface area: " <<  manip
         << calcArea() << " m2" << endl;
}


// pobranie parametrów 
void Truss::getInitialDimensions()
{
    cout << "\n\t! ALL VALUES IN MILIMETERS !\n" << endl;
    cout << "Initial dimensions: \n";
    cout << "\tBuliding length: " << getDimensions()->getBuildingLength() << endl;
    cout << "\tBuliding width: " << getDimensions()->getBuildingWidth() << endl;
    cout << "\tTruss height: " << getDimensions()->getTrussHeight() << endl;
    cout << "\tTruss length: " << getDimensions()->getTrussLength() << endl;
    cout << "\tWall plate level: " << getDimensions()->getWallPlateHeight() << endl;
    cout << "\tPurlin prop distance: " << getDimensions()->getPurlinPropDistance() << endl;
    cout << "\tHorizontal eave length: " << getDimensions()->getHorizontalEaveLength() << endl;
    cout << "\tCommon rafter height: " << getDimensions()->getCommonRafterHeight() << endl;
    cout << "\tCommon rafter width: " << getDimensions()->getCommonRafterWidth() << endl;
    cout << "\tHip rafter height: " << getDimensions()->getHipHeight() << endl;
    cout << "\tHip rafter width: " << getDimensions()->getHipWidth() << endl;
}


// obliczenie odleg³oœci miêdzy krokwiami
double Truss::calcCommonRaftersDistance() // override
{
    double trussLength = getDimensions()->getTrussLength();
    int numberOfRafters = trussLength /
        (getDimensions()->getCommonRafterWidth() +
            getDimensions()->getCommonRaftersDistance());
    numberOfRafters += 1; // liczba krokwi
    double rafterDistance = (trussLength / numberOfRafters); // odleglosc miedzy krokwiami
    setDimensions()->setCommonRafterDistance(rafterDistance);
    return rafterDistance;
}


//oblicznie powierzchni dachu
double Truss::calcArea() // override
{
    double h = getDimensions()->getCommRaftTotalLength();

    double w = getDimensions()->getTrussLength();
    surfaceArea = h*w*2;
    surfaceArea /= 1000000; // result in m^2
    return surfaceArea;
}


double Truss::getRoofArea() const
{
    return surfaceArea;
}


void Truss::setTrussType(const std::string& type)
{
    trussType = type;
}


const std::string& Truss::getTrussType() const
{
    return trussType;
}
