/*************************************************************************
                           AgentInterface  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

#if ! defined ( AGENTINTERFACE_H )
#define AGENTINTERFACE_H

//------------------------------------------------------- Used Interfaces

#include <string>
#include <vector>
using namespace std;

#include "../management/DataManagement.h"
#include "../management/SensorManagement.h"

#include "../models/Sensor.h"
#include "../models/Measurement.h"
#include "../models/Cleaner.h"

class AgentInterface
{
//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructors - Destructor
    AgentInterface();
    virtual ~AgentInterface();

//--------------------------------------------------------- Public Methods
    void DisplayMenu(const vector<Cleaner>& cleaners, const vector<Sensor>& sensors, const vector<Measurement>& measurements);
    void MonitorSensor(const vector<Sensor>& sensors, const vector<Measurement>& measurements);
    void MonitorCleaner(const vector<Cleaner>& cleaners, const vector<Sensor>& sensors, const vector<Measurement>& measurements);
    void MonitorIndividual(const vector<Sensor>& sensors, const vector<Measurement>& measurements);
    void Logout();
    void GenerateMean(const vector<Sensor>& sensors, const vector<Measurement>& measurements);
    void CalculateAirQuality(const vector<Sensor>& sensors, const vector<Measurement>& measurements);
    void RankSensor();
};

#endif // AGENTINTERFACE_H

