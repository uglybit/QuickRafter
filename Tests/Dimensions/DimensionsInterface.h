#pragma once

class DimensionsInterface 
{
public:
    virtual ~DimensionsInterface() = default;

    // wartosci wprowadzane przez uzytkownika
    virtual void setBuildingLength(double value) = 0;
    virtual void setBuildingWidth(double value) = 0; 
    virtual void setTrussHeight(double value) = 0;
    virtual void setTrussLength(double value) = 0;
    virtual void setWallPlateHeight(double value) = 0;
    virtual void setHorizontalEaveLength(double value) = 0; 
    virtual void setPurlin(bool pur) = 0;
    virtual void setPurlinPropDistance(double value) = 0;
    virtual void setCommonRafterHeight(double value) = 0;
    virtual void setCommonRafterWidth(double value) = 0;
    virtual void setCommonRafterDistance(double value) = 0;

    // wartosci obliczane przez program
    virtual void setPurlinPropLength(double value) = 0;
    virtual void setPurlinLevel(double value) = 0;
    virtual void setPurlinDimensions(double value) = 0; 
    virtual void setCommRaftTotalLength(double value) = 0;
    virtual void setHipWidth(double value) = 0;
    virtual void setHipHeight(double value) = 0;
    virtual void setHipRaftTotalLength(double len) = 0;
    virtual void setRafterAboveWallPlat(double value) = 0;

     // get
    virtual bool isPurlin() const = 0;
    virtual double getPurlinPropLength() const = 0;
    virtual double getPurlinLevel() const = 0;
    virtual double getPurlinDimensions() const = 0;
    virtual double getCommRaftTotalLength() const = 0;
    virtual double getHipWidth() const = 0;
    virtual double getHipHeight() const = 0;
    virtual double getHipRaftTotalLength() const = 0;
    virtual double getRafterAboveWallPlat() const = 0;
    virtual double getBuildingLength() const = 0;
    virtual double getBuildingWidth() const = 0;
    virtual double getTrussHeight() const = 0;
    virtual double getTrussLength() const = 0;
    virtual double getWallPlateHeight() const = 0;
    virtual double getPurlinPropDistance() const = 0;
    virtual double getHorizontalEaveLength() const = 0;
    virtual double getCommonRafterHeight() const = 0;
    virtual double getCommonRafterWidth() const = 0;
    virtual double getCommonRaftersDistance() const = 0;
    virtual double getNumberOfCommRafters() const = 0;
};