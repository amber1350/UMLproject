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

User::User()
{
#ifdef MAP
    cout << "Call to the constructor of <User>" << endl;
#endif
} //----- End of User

bool User::evaluateReliability(const std::vector<std::string>& measurements)
{
    int anomalyCount = 0;
    for (const string& measurement : measurements)
    {
        stringstream ss(measurement);
        string timestamp, sensorID, attributeID, valueStr;
        getline(ss, timestamp, ';');
        getline(ss, sensorID, ';');
        getline(ss, attributeID, ';');
        getline(ss, valueStr, ';');

        try
        {
            float value = stof(valueStr);
            if (value < 0 || value > 1000) 
            {
                anomalyCount++;
            }
        }
        catch (invalid_argument& e)
        {
            anomalyCount++;
        }
    }

    isReliable = (anomalyCount <= measurements.size() * 0.1);
    return isReliable;
}

//-------------------------------------------- Constructors - Destructor
User::~User ( )
{
#ifdef MAP
    cout << "Call to the destructor of <User>" << endl;
#endif
    score = 0;
    isReliable = true;
} //----- End of ~User

User::~User()
{
#ifdef MAP
    cout << "Call to the destructor of <User>" << endl;
#endif
} //----- End of ~User