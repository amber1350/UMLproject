/*************************************************************************
                           DataManagement  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Class Interface of <DataManagement> (file DataManagement.h) -----------------------
#if ! defined ( DataManagement_H )
#define DataManagement_H

//------------------------------------------------------- Used Interfaces
#include <string>
#include <vector>
#include "../models/Measurement.h"
#include "../models/Sensor.h"


using namespace std; 
//------------------------------------------------------------- Constants

//------------------------------------------------------------------Types

//-----------------------------------------------------------------------
// Role of the class <DataManagement>
//
//
//------------------------------------------------------------------------
class DataManagement 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public Methods

//------------------------------------------------- Operator Overloading

//-------------------------------------------- Constructors - Destructor
    DataManagement();       
    virtual ~DataManagement ( );

//--------------------------------------------------- Other 
    // Methods
    float GenerateMean(const vector<Sensor>& sensors,const vector<Measurement>& measurements, float radius, const pair<float, float>& center, const string& startTime, const string& endTime);
    float MeasureAirQuality(const vector<Measurement>& measurements, const vector<Sensor>& sensors, const pair<float, float>& position, const string& timestamp);
    vector<Measurement> GetMeasurementsByAttribute(const vector<Measurement>& measurements, const string& attributeID);
    vector<Measurement> GetMeasurementsWithinTimePeriod(const vector<Measurement>& measurements, const string& startTime, const string& endTime);
    int ATMO(float O3, float SO2, float NO2, float PM10);

protected:
//----------------------------------------------------- Protected Methods
};

#endif // DataManagement_H