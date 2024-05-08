//---------- Realisation of the class <DataAccess> (file DataAccess.cpp) ------------

//---------------------------------------------------------------- INCLUDE
 
//-------------------------------------------------------- System Includes
#include <iostream>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "DataAccess.h"

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods
void DataAccess::initializeData ( )
{

} //----- End of initializeData

string DataAccess::readSensorData ( )
{

} //----- End of readSensorData

string DataAccess::readMeasurementData ( )
{
    
} //----- End of readMeasurementData

string DataAccess::readAttributeData ( )
{

} //----- End of readAttributeData

string DataAccess::readProviderData ( )
{

} //----- End of readProviderData

string DataAccess::readCleanerData ( )
{

} //----- End of readCleanerData

string DataAccess::readUserData ( )
{

} //----- End of readUserData

void DataAccess::writeSensorData ( string sensorData )
{

} //----- End of writeSensorData

void DataAccess::writeMeasurementData ( string measurementData)
{

} //----- End of writeMeasurementData

void DataAccess::writeAttributeData ( string attributeData )
{

} //----- End of writeAttributeData

void DataAccess::writeProviderData ( string providerData )  
{

} //----- End of writeProviderData

void DataAccess::writeCleanerData ( string cleanerData )
{

} //----- End of writeCleanerData

void DataAccess::writeUserData ( string userData )  
{

} //----- End of writeUserData

DataAccess::DataAccess ( )
{
#ifdef MAP
    cout << "Call to the constructor of <DataAccess>" << endl;
#endif
} //----- End of DataAccess

DataAccess::~DataAccess ( )
{
#ifdef MAP
    cout << "Call to the destructor of <DataAccess>" << endl;
#endif
} //----- End of ~DataAccess
