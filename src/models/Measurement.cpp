/*************************************************************************
                           Measurement  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <Measurement> (file Measurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- System Includes
using namespace std;
#include <iostream>

//------------------------------------------------------ Personal Includes
#include "Measurement.h"

//------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods

//-------------------------------------------- Constructors - Destructor
Measurement::Measurement(const string & timestamp, const string & sensorID, const string & attributeID, float value)
    : timestamp(timestamp), sensorID(sensorID), attributeID(attributeID), value(value)
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the constructor of <Measurement>" << endl;
#endif
} //----- End of Measurement

Measurement::~Measurement ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the destructor of <Measurement>" << endl;
#endif
} //----- End of ~Measurement

// Getters
const string & Measurement::getTimestamp() const
{
    return timestamp;
}

const string & Measurement::getSensorID() const
{
    return sensorID;
}

const string & Measurement::getAttributeID() const
{
    return attributeID;
}

float Measurement::getValue() const
{
    return value;
}

// Overloaded << operator
ostream& operator<<(ostream& os, const Measurement& m) {
    os << "Timestamp: " << m.timestamp << ", SensorID: " << m.sensorID << ", AttributeID: " << m.attributeID << ", Value: " << m.value;
    return os;
}


//------------------------------------------------------------------ PRIVATE

//----------------------------------------------------- Protected Methods
