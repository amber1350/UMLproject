/*************************************************************************
                           ProviderInterface  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

#if ! defined ( PROVIDERINTERFACE_H )
#define PROVIDERINTERFACE_H

//------------------------------------------------------- Used Interfaces

#include <string>
#include <vector>
using namespace std;

#include "../management/DataManagement.h"
#include "../management/SensorManagement.h"

#include "../models/Cleaner.h"
#include "../models/Measurement.h"
#include "../models/Sensor.h"

class ProviderInterface
{
//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructors - Destructor
    ProviderInterface();
    virtual ~ProviderInterface();

//--------------------------------------------------------- Public Methods
    void DisplayMenu(const vector<Cleaner>& cleaners, const vector<Sensor>& sensors, const vector<Measurement>& measurements);
    void RegisterCleaner(const vector<Cleaner>& cleaners);
    void MonitorCleaner(const vector<Cleaner>& cleaners, const vector<Sensor>& sensors, const vector<Measurement>& measurements);
    void Logout();
    
};

#endif // USERINTERFACE_H

