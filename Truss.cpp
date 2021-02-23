#include "Truss.h"


Truss::Truss(Dimensions& dim) : dimension{ dim }
{
    elements.push_back(new WallPlate(dim));
    elements.push_back(new CommonRafter(dim));
    calcCommonRaftersDistance();
}


Truss::~Truss()
{
    for (auto a : elements) {
        if (a != nullptr) {
            delete a;
        }
    }
}


const Dimensions* Truss::getDimensions() const
{
    return &dimension;
}


Dimensions* Truss::setDimensions()
{
    return &dimension; 
}


// wywoluje funkcje obliczajaca dla kazdego elementu
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

    std::cout << "\nCommon rafters distance: "
       << getDimensions()->getCommonRaftersDistance();

    std::cout << "\nRoof surface area: " <<  manip
         << calcArea() << " m2" << std::endl;
}


void Truss::getInitialDimensions() const
{
    std::cout << "\n\t! ALL VALUES IN MILIMETERS !\n\n";
    std::cout << "Initial dimensions: \n";
    std::cout << "\n\tBuliding length: " << getDimensions()->getBuildingLength();
    std::cout << "\n\tBuliding width: " << getDimensions()->getBuildingWidth();
    std::cout << "\n\tTruss height: " << getDimensions()->getTrussHeight();
    std::cout << "\n\tTruss length: " << getDimensions()->getTrussLength();
    std::cout << "\n\tWall plate level: " << getDimensions()->getWallPlateHeight();
    std::cout << "\n\tPurlin prop distance: " << getDimensions()->getPurlinPropDistance();
    std::cout << "\n\tHorizontal eave length: " << getDimensions()->getHorizontalEaveLength();
    std::cout << "\n\tCommon rafter height: " << getDimensions()->getCommonRafterHeight();
    std::cout << "\n\tCommon rafter width: " << getDimensions()->getCommonRafterWidth();
    std::cout << "\n\tHip rafter height: " << getDimensions()->getHipHeight();
    std::cout << "\n\tHip rafter width: " << getDimensions()->getHipWidth() << std::endl;
}


// obliczenie odleg�o�ci mi�dzy krokwiami
double Truss::calcCommonRaftersDistance() 
{
    double trussLength = getDimensions()->getTrussLength();
    int numberOfRafters = trussLength /
        (getDimensions()->getCommonRafterWidth() +
            getDimensions()->getCommonRaftersDistance());
    numberOfRafters += 1; 
    double rafterDistance = (trussLength / numberOfRafters); 
    setDimensions()->setCommonRafterDistance(rafterDistance);
    return rafterDistance;
}


//oblicznie powierzchni dachu
double Truss::calcArea()
{
    double height = getDimensions()->getCommRaftTotalLength();
    double width = getDimensions()->getTrussLength();
    surfaceArea = height * width * 2;
    surfaceArea /= 1000000; // przeliczenie na m^2
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
