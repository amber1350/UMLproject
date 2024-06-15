/*************************************************************************
                           UserInterface  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

#if ! defined ( USERINTERFACE_H )
#define USERINTERFACE_H

//------------------------------------------------------- Used Interfaces

#include <string>
#include <vector>
using namespace std;

#include "../management/DataManagement.h"
#include "../management/SensorManagement.h"

#include "../models/Sensor.h"

class UserInterface
{
//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructors - Destructor
    UserInterface();
    virtual ~UserInterface();

//--------------------------------------------------------- Public Methods
    void DisplayMenu(const vector<Sensor>& sensors);
    void RegisterSensor(const vector<Sensor>& sensors);
    void ViewContributionPoint();
    void Logout();
    
};

#endif // USERINTERFACE_H

