/*************************************************************************
                           SensorManagement  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Class Interface of <SensorManagement> (file SensorManagement.h) -----------------------
#if ! defined ( SensorManagement_H )
#define SensorManagement_H

//------------------------------------------------------- Used Interfaces
#include <string>
#include <vector>
#include "../models/Sensor.h"
#include "../models/Attribute.h"

using namespace std; 
//------------------------------------------------------------- Constants

//------------------------------------------------------------------Types

//-----------------------------------------------------------------------
// Role of the class <SensorManagement>
//
//
//------------------------------------------------------------------------
class SensorManagement 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public Methods

//------------------------------------------------- Operator Overloading

//-------------------------------------------- Constructors - Destructor
    SensorManagement();       
    virtual ~SensorManagement ( );

//--------------------------------------------------- Other 
    void MonitorSensor(const string& sensorID, const vector<Measurement>& measurements);
    vector<pair<Sensor, float>> RankSensor(const string& sensorID, const string& startTime, const string& endTime, const vector<Sensor>& sensors, const vector<Measurement>& measurements, const vector<Attribute>& attributes);
    Sensor GetSensorByID(const string& sensorID, const vector<Sensor>& sensors);
    vector<Sensor> GetSensorWithinRadius(const pair<float, float>& center, float radius, const vector<Sensor>& sensors);

protected:
//----------------------------------------------------- Protected Methods
    float CalculateDistance(float lat1, float lon1, float lat2, float lon2);
    float CalculateSimilarity(const vector<Attribute>& attributes, const vector<Measurement>& refMeasurements, const vector<Measurement>& otherMeasurements);
};

#endif // SensorManagement_H