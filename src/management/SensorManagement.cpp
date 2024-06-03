/*************************************************************************
                           SensorManagement  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <SensorManagement> (file Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- System Includes
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "SensorManagement.h"
#include "DataManagement.h"


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

vector<pair<Sensor, float>> SensorManagement::RankSensor(const string& referenceSensorID, const string& startTime, const string& endTime, const vector<Sensor>& sensors, const vector<Measurement>& measurements, const vector<Attribute>& attributes){
    cout << "Ranking Sensor: " << referenceSensorID << endl; 
    vector<pair<Sensor, float>> sensorSimilarities;
    // Get reference sensor
    auto it = find_if(sensors.begin(), sensors.end(), [&](const Sensor& s) { return s.getSensorID() == referenceSensorID; });
    if (it == sensors.end()) {
        cerr << "Reference sensor not found." << endl;
        return sensorSimilarities;
    }
    Sensor referenceSensor = *it;

    // Get measurements for the reference sensor
    vector<Measurement> refMeasurements;
    for (const auto& measurement : referenceSensor.getMeasurements()) {
        if (measurement.getTimestamp() >= startTime && measurement.getTimestamp() <= endTime) {
            refMeasurements.push_back(measurement);
        }
    }

    // Calculate similarity for each sensor
    for (const auto& sensor : sensors) {
        if (sensor.getSensorID() == referenceSensorID) continue;

        vector<Measurement> otherMeasurements;
        for (const auto& measurement : sensor.getMeasurements()) {
            if (measurement.getTimestamp() >= startTime && measurement.getTimestamp() <= endTime) {
                otherMeasurements.push_back(measurement);
            }
        }

        float similarity = CalculateSimilarity(attributes,  refMeasurements, otherMeasurements);
        sensorSimilarities.emplace_back(sensor, similarity);
    }

    // Sort sensors by similarity
    sort(sensorSimilarities.begin(), sensorSimilarities.end(), [](const pair<Sensor, float>& a, const pair<Sensor, float>& b) {
        return a.second < b.second;
    });

    return sensorSimilarities;
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

float SensorManagement::CalculateSimilarity(const vector<Attribute>& attributes, const vector<Measurement>& refMeasurements, const vector<Measurement>& otherMeasurements) {
    // Group measurements by their attribute IDs
    unordered_map<string, vector<float>> refValues, otherValues;
    
    for (const auto& measurement : refMeasurements) {
        refValues[measurement.getAttributeID()].push_back(measurement.getValue());
    }

    for (const auto& measurement : otherMeasurements) {
        otherValues[measurement.getAttributeID()].push_back(measurement.getValue());
    }

    // Calculate Euclidean distance for corresponding attributes
    float similarity = 0.0;
    int count = 0;

    for (const auto& [attributeID, refVec] : refValues) {
        if (otherValues.find(attributeID) != otherValues.end()) {
            const auto& otherVec = otherValues[attributeID];
            for (int i = 0; i < min(refVec.size(), otherVec.size()); ++i) {
                similarity += pow(refVec[i] - otherVec[i], 2);
                ++count;
            }
        }
    }
    // If count is greater than 0, compute the square root of the average squared difference to get the Euclidean distance.
    // If no valid comparisons were made (count is 0), return the maximum possible float value to indicate dissimilarity.
    return count > 0 ? sqrt(similarity / count) : numeric_limits<float>::max();
}
