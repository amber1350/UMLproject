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
    int RankSensor(const string& sensorID, const vector<Measurement>& measurements);
    Sensor GetSensorByID(const string& sensorID, const vector<Sensor>& sensors);
    vector<Sensor> GetSensorWithinRadius(const pair<float, float>& center, float radius, const vector<Sensor>& sensors);

protected:
//----------------------------------------------------- Protected Methods
    float CalculateDistance(float lat1, float lon1, float lat2, float lon2);
};

#endif // SensorManagement_H