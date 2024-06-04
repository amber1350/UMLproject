//---------- Realisation of the class <Provider> (file Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE
 
//-------------------------------------------------------- System Includes
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "Provider.h"

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods
Provider::Provider(const string& username, const string& password, const string& providerID)
    : Account(username, password, providerID) // Call to the Account constructor and initialize agentID
{
#ifdef MAP
    cout << "Call to the constructor of <Agent>" << endl;
#endif
} //----- End of Agent



Provider::~Provider ( )
{
#ifdef MAP
    cout << "Call to the destructor of <Provider>" << endl;
#endif
} //----- End of ~Provider