//---------- Realisation of the class <Account> (file Account.cpp) ------------

//---------------------------------------------------------------- INCLUDE
 
//-------------------------------------------------------- System Includes
#include <iostream>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "Account.h"

//----------------------------------------------------------------- PUBLIC

string Account::getUsername ( )
{
    return username;
} //----- End of getUsername

string Account::getPassword ( )
{
    return password;
} //----- End of getPassword

Account::Account (string username, string password)
{   
#ifdef MAP
    cout << "Call to the constructor of <Account>" << endl;
#endif
this->username = username;
this->password = password;
} //----- End of Account

Account::~Account ( )
{
#ifdef MAP
    cout << "Call to the destructor of <Account>" << endl;
#endif
} //----- End of ~Account
