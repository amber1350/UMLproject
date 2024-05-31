/*************************************************************************
                           Sensor  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Class Interface of <Sensor> (file Sensor.h) -----------------------
#if ! defined ( Sensor_H )
#define Sensor_H

//------------------------------------------------------- Used Interfaces
#include <string>
#include <vector>
#include "Measurement.h"

using namespace std; 
//------------------------------------------------------------- Constants

//------------------------------------------------------------------Types

//-----------------------------------------------------------------------
// Role of the class <Sensor>
//
//
//------------------------------------------------------------------------

class Sensor 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public Methods

//------------------------------------------------- Operator Overloading
    // Overloaded << operator
    friend ostream& operator<<(ostream& os, const Sensor& s);

//-------------------------------------------- Constructors - Destructor
    Sensor(const string& id, float lat, float lon);   
    
    
    virtual ~Sensor ( );
    
//-------------------------------------------- Getters
    const string & getSensorID() const;
    float getLatitude() const;
    float getLongitude() const;
    vector<Measurement> getMeasurements(const vector<Measurement>& measurements) const;

//------------------------------------------------------------------ PRIVATE

protected:
//----------------------------------------------------- Protected Methods
    void addMeasurement(const Measurement& measurement);
    // Usage:
    //
    // Contract:
    //

//----------------------------------------------------- Protected Attributes
    string sensorID;
    float latitude;
    float longitude;
    vector<Measurement> measurements;
};

//-------------------------------- Other definitions depending on <Sensor>

#endif // Sensor_H
