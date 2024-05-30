/*************************************************************************
                           DataAccess  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Class Interface of <DataAccess> (file DataAccess.h) -----------------------
#if ! defined ( DataAccess_H )
#define DataAccess_H

//------------------------------------------------------- Used Interfaces
#include <string>
using namespace std; 
#include <string>
#include <vector>
#include "Measurement.h"
#include "Sensor.h"
#include "Attribute.h"
#include "Provider.h"
#include "Cleaner.h"
#include "User.h"
//------------------------------------------------------------- Constants

//------------------------------------------------------------------Types

class DataAccess
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public Methods
    int readSensorData(const string& csvFile, vector<Sensor>& sensors);
    int readMeasurementData(const string& csvFile, vector<Measurement>& measurements);
    int readAttributeData(const string& csvFile, vector<Attribute>& attributes);
    int readProviderData(const string& csvFile, vector<Provider>& providers);
    int readCleanerData(const string& csvFile, vector<Cleaner>& cleaners);
    int readUserData(const string& csvFile, vector<User>& users);
    int writeSensorData(const string& csvFile, const vector<Sensor>& sensors);
    int writeMeasurementData(const string& csvFile, const vector<Measurement>& measurements);
    int writeAttributeData(const string& csvFile, const vector<Attribute>& attributes);
    int writeProviderData(const string& csvFile, const vector<Provider>& providers);
    int writeCleanerData(const string& csvFile, const vector<Cleaner>& cleaners);
    int writeUserData(const string& csvFile, const vector<User>& users);

//-------------------------------------------- Constructors - Destructor
    DataAccess ( );

    virtual ~DataAccess ( );
};

#endif // DataAccess_H
