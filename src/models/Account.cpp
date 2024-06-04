/*************************************************************************
                           Account  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

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

Account::Account (string username, string password, string accountID)
{   
#ifdef MAP
    cout << "Call to the constructor of <Account>" << endl;
#endif
this->username = username;
this->password = password;
this->accountID = accountID;
} //----- End of Account

Account::~Account ( )
{
#ifdef MAP
    cout << "Call to the destructor of <Account>" << endl;
#endif
} //----- End of ~Account
