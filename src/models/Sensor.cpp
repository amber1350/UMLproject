/*************************************************************************
                           Sensor  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <Sensor> (file Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- System Includes
#include <iostream>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "Sensor.h"

//------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods

//-------------------------------------------- Constructors - Destructor
Sensor::Sensor(const string& id, float lat, float lon)
    : sensorID(id), latitude(lat), longitude(lon)
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the constructor of <Sensor>" << endl;
#endif
} //----- End of Sensor

Sensor::~Sensor ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the destructor of <Sensor>" << endl;
#endif
} //----- End of ~Sensor

// Getters
const string & Sensor::getSensorID() const {
    return sensorID;
}

float Sensor::getLatitude() const {
    return latitude;
}

float Sensor::getLongitude() const {
    return longitude;
}

vector<Measurement> Sensor::getMeasurements() const {
    return measurements;
}

void Sensor::setMeasurements(const vector<Measurement>& measurements) {
    for (const auto& measurement : measurements) {
        if (measurement.getSensorID() == sensorID) {
            this->measurements.push_back(measurement);
        }
    }
}

// Overloaded << operator
ostream& operator<<(ostream& os, const Sensor& s) {
    os << "SensorID: " << s.sensorID << ", Latitude: " << s.latitude << ", Longitude: " << s.longitude;
    return os;
}

//------------------------------------------------------------------ PRIVATE

//----------------------------------------------------- Protected Methods
// Method to add a measurement to the sensor
void Sensor::addMeasurement(const Measurement& measurement) {
    measurements.push_back(measurement);
}