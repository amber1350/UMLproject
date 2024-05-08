//---------- Class Interface of <DataAccess> (file DataAccess.h) -----------------------
#if ! defined ( DATA_H )
#define DATA_H

using namespace std;

//------------------------------------------------------- Used Interfaces
#include <string>

class DataAccess
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public Methods
    initializeData ( );

    readSensorData ( );

    readMeasurementData ( );
    
    readAttributeData ( );
    
    readProviderData ( );
    
    readCleanerData ( );
    
    readUserData ( );
    
    writeSensorData ( );
    
    writeMeasurementData ( );
    
    writeAttributeData ( );
    
    writeProviderData ( );
    
    writeCleanerData ( );
    
    writeUserData ( );

//-------------------------------------------- Constructors - Destructor
    DataAccess ( );

    virtual ~DataAccess ( );
};

#endif // DATA_H
