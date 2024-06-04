/*************************************************************************
                           Agent  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <Agent> (file Agent.cpp) ------------

//---------------------------------------------------------------- INCLUDE
 
//-------------------------------------------------------- System Includes
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "Agent.h"

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods
Agent::Agent(const string& username, const string& password, const string& agentID)
    : Account(username, password, agentID) // Call to the Account constructor and initialize agentID
{
#ifdef MAP
    cout << "Call to the constructor of <Agent>" << endl;
#endif
} //----- End of Agent



Agent::~Agent ( )
{
#ifdef MAP
    cout << "Call to the destructor of <Agent>" << endl;
#endif
} //----- End of ~Agent