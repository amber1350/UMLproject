/*************************************************************************
                           Cleaner  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <Cleaner> (file Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- System Includes
using namespace std;
#include <iostream>

//------------------------------------------------------ Personal Includes
#include "Cleaner.h"

//------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods

//-------------------------------------------- Constructors - Destructor
Cleaner::Cleaner(const string& id, float lat, float lon, const string& start, const string& stop)
    : CleanerID(id), Latitude(lat), Longitude(lon), TimestampStart(start), TimestampStop(stop)
{
#ifdef MAP
    cout << "Call to the constructor of <Cleaner>" << endl;
#endif
} //----- End of Measurement

Cleaner::~Cleaner ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the destructor of <Cleaner>" << endl;
#endif
} //----- End of ~Measurement

// Getters
string Cleaner::GetCleanerID() const {
    return CleanerID;
}

float Cleaner::GetLatitude() const {
    return Latitude;
}

float Cleaner::GetLongitude() const {
    return Longitude;
}

string Cleaner::GetTimestampStart() const {
    return TimestampStart;
}

string Cleaner::GetTimestampStop() const {
    return TimestampStop;
}

// Overload the << operator
ostream& operator<<(ostream& os, const Cleaner& cleaner) {
    os << "Cleaner ID: " << cleaner.CleanerID
       << ", Latitude: " << cleaner.Latitude
       << ", Longitude: " << cleaner.Longitude
       << ", Timestamp Start: " << cleaner.TimestampStart
       << ", Timestamp Stop: " << cleaner.TimestampStop;
    return os;
}



//------------------------------------------------------------------ PRIVATE

//----------------------------------------------------- Protected Methods