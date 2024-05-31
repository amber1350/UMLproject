/*************************************************************************
                           SensorManagement  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <Sensor> (file Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- System Includes
#include <iostream>
#include <cmath>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "SensorManagement.h"

//------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods

//-------------------------------------------- Constructors - Destructor
SensorManagement::SensorManagement()
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the constructor of <SensorManagement>" << endl;
#endif
} //----- End of Sensor

SensorManagement::~SensorManagement ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the destructor of <SensorManagement>" << endl;
#endif
} //----- End of ~Sensor


void SensorManagement::MonitorSensor(const string& sensorID, const vector<Measurement>& measurements) {
    cout << "Monitoring Sensor: " << sensorID << endl;    
    // Add logic to analyze data to ensure the sensor is functioning correctly
}

int SensorManagement::RankSensor(const string& sensorID, const vector<Measurement>& measurements) {
    cout << "Ranking Sensor: " << sensorID << endl; 
    // Add logic to analyze data to ensure the sensor is functioning correctly
    return 0;
}

Sensor SensorManagement::GetSensorByID(const string& sensorID, const vector<Sensor>& sensors) {
    for (const auto& sensor : sensors) {
        if (sensor.getSensorID() == sensorID) {
            return sensor;
        }
    }
    throw runtime_error("Sensor not found");
}

float SensorManagement::CalculateDistance(float lat1, float lon1, float lat2, float lon2) {
    const float R = 6371.0; // Earth's radius in kilometers
    float latRad1 = lat1 * M_PI / 180.0; // Convert latitude from degrees to radians
    float lonRad1 = lon1 * M_PI / 180.0; // Convert longitude from degrees to radians
    float latRad2 = lat2 * M_PI / 180.0; // Convert latitude from degrees to radians
    float lonRad2 = lon2 * M_PI / 180.0; // Convert longitude from degrees to radians

    float dlat = latRad2 - latRad1; // Difference in latitude
    float dlon = lonRad2 - lonRad1; // Difference in longitude

    float a = sin(dlat / 2) * sin(dlat / 2) +
              cos(latRad1) * cos(latRad2) *
              sin(dlon / 2) * sin(dlon / 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c; // Distance in kilometers
}

vector<Sensor> SensorManagement::GetSensorWithinRadius(const pair<float, float>& center, float radius, const vector<Sensor>& sensors) {
    vector<Sensor> result;
    for (const Sensor& sensor : sensors) {
        float distance = CalculateDistance(center.first, center.second, sensor.getLatitude(), sensor.getLongitude());
        if (distance <= radius) {
            result.push_back(sensor);
        }
    }
    return result;
}

