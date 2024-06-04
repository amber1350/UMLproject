//---------- Realisation of the class <User> (file User.cpp) ------------

//---------------------------------------------------------------- INCLUDE
 
//-------------------------------------------------------- System Includes
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "User.h"

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods
int User::getScore()
{
    return score;
} //----- End of getScore

void User::setScore()
{
    score++;
} //----- End of getScore

User::User(const string& username, const string& password, const string& userID)
    : User(username, password, userID) // Call to the User constructor and initialize agentID
{
#ifdef MAP
    cout << "Call to the constructor of <User>" << endl;
#endif
} //----- End of User

//-------------------------------------------- Constructors - Destructor
User::~User ( )
{
#ifdef MAP
    cout << "Call to the destructor of <User>" << endl;
#endif
} //----- End of ~User

User::~User()
{
#ifdef MAP
    cout << "Call to the destructor of <User>" << endl;
#endif
} //----- End of ~User