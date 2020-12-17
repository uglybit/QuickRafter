#include "Truss.h"

using namespace std;

Truss::Truss()
{
    elements.push_back(new WallPlate);
    elements.push_back(new CommonRafter);
    calcCommonRaftersDistance();
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
       << OvDim::getCommonRaftersDistance() << endl;

    cout << "Roof surface area: " <<  manip
         << calcArea() << " m2" << endl;
}


// pobranie parametrów 
void Truss::getInitialDimensions()
{
    cout << "\n\t! ALL VALUES IN MILIMETERS !\n" << endl;
    cout << "Initial dimensions: \n";

    cout << "\tBuliding length: " << OvDim::getBuildingLength() << endl;
    cout << "\tBuliding width: " << OvDim::getBuildingWidth() << endl;
    cout << "\tTruss height: " << OvDim::getTrussHeight() << endl;
    cout << "\tTruss length: " << OvDim::getTrussLength() << endl;
    cout << "\tWall plate level: " << OvDim::getWallPlateHeight() << endl;
    cout << "\tPurlin prop distance: " << OvDim::getPurlinPropDistance() << endl;
    cout << "\tHorizontal eave length: " << OvDim::getHorizontalEaveLength() << endl;
    cout << "\tCommon rafter height: " << OvDim::getCommonRafterHeight() << endl;
    cout << "\tCommon rafter width: " << OvDim::getCommonRafterWidth() << endl;
    cout << "\tHip rafter height: " << OvDim::getHipHeight() << endl;
    cout << "\tHip rafter width: " << OvDim::getHipWidth() << endl;
}


// obliczenie odleg³oœci miêdzy krokwiami
double Truss::calcCommonRaftersDistance() // override
{
    double trussLength = OvDim::getTrussLength();
    int numberOfRafters = trussLength /
        (OvDim::getCommonRafterWidth() +
            OvDim::getCommonRaftersDistance());
    numberOfRafters += 1; // liczba krokwi
    double rafterDistance = (trussLength / numberOfRafters); // odleglosc miedzy krokwiami
    OvDim::setCommonRafterDistance(rafterDistance);
    return rafterDistance;
}


//oblicznie powierzchni dachu
double Truss::calcArea() // override
{
    double h = OvDim::getCommRaftTotalLength();

    double w = OvDim::getTrussLength();
    surfaceArea = h*w*2;
    surfaceArea /= 1000000; // result in m^2
    return surfaceArea;
}


/*********** GABLE ROOF ****************/


// dach dwuspadowy
GableRoof::GableRoof() : Truss()
{
    trussType = "Gable roof without purlins";
}

// dach dwuspadowy z p³atwi¹
GableRoof::GableRoof(bool purl) : GableRoof()
{
    trussType = "Gable roof with purlins";
    elements.push_back(new Purlin);
    elements.push_back(new PurlinProp);
}


/*********** HIPPED ROOF ****************/


// dach kopertowy
HippedRoof::HippedRoof() : GableRoof()
{
    trussType = "Hipped roof without purlins";
    elements.push_back(new HipRafter);
}


// dach kopertowy z p³atwi¹
HippedRoof::HippedRoof(bool purl) : GableRoof(purl)
{
    trussType = "Hipped roof with purlins";
    elements.push_back(new HipRafter);
}

