//---------- Realisation of the class <Account> (file Account.cpp) ------------

//---------------------------------------------------------------- INCLUDE
 
//-------------------------------------------------------- System Includes
#include <iostream>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "Account.h"

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods
string Account::getID ( )
{
    return id;
} //----- End of getID

string Account::getUsername ( )
{
    return username;
} //----- End of getUsername

string Account::getPassword ( )
{
    return password;
} //----- End of getPassword

Account::Account ( )
{   
#ifdef MAP
    cout << "Call to the constructor of <Account>" << endl;
#endif
} //----- End of Account

Account::~Account ( )
{
#ifdef MAP
    cout << "Call to the destructor of <Account>" << endl;
#endif
} //----- End of ~Account
