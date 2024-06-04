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
using namespace std;

class AgentInterface
{
//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructors - Destructor
    AgentInterface();
    virtual ~AgentInterface();

//--------------------------------------------------------- Public Methods
    void DisplayMenu();
    void MonitorSensor();
    void MonitorCleaner();
    void MonitorIndividual();
    void GenerateMean();
    void RankSensor();
    void CalculateAirQuality();
    void Logout();
};

#endif // AGENTINTERFACE_H

