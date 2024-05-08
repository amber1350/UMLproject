//---------- Realisation of the class <User> (file User.cpp) ------------

//---------------------------------------------------------------- INCLUDE
 
//-------------------------------------------------------- System Includes
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "User.h"

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods
string User::getScore ( )
{
    return score;
} //----- End of getScore

User::User ( )
{
#ifdef MAP
    cout << "Call to the constructor of <User>" << endl;
#endif
} //----- End of User


User::~User ( )
{
#ifdef MAP
    cout << "Call to the destructor of <User>" << endl;
#endif
} //----- End of ~User