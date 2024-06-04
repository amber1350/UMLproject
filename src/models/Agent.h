//---------- Class Interface of <Agent> (file Agent.h) -----------------------
#if ! defined ( AGENT_H )
#define AGENT_H

//------------------------------------------------------- Used Interfaces
#include "Account.h"

class Agent : public Account
{
//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructors - Destructor
    Agent(const string& username, const string& password, const string& agentID);
    virtual ~Agent ( );

protected:
};


#endif // AGENT_H
