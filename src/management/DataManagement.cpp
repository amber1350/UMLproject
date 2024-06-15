/*************************************************************************
                           DataManagement  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <DataManagement> (file DataManagement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- System Includes
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <chrono> 
using namespace std;

//------------------------------------------------------ Personal Includes
#include "DataManagement.h"
#include "SensorManagement.h"
#include <unordered_map>

//------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods

//-------------------------------------------- Constructors - Destructor
DataManagement::DataManagement()
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the constructor of <DataManagement>" << endl;
#endif
} //----- End of Sensor

DataManagement::~DataManagement ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the destructor of <DataManagement>" << endl;
#endif
} //----- End of ~Sensor

float DataManagement::GenerateMean(const vector<Sensor>& sensors, const vector<Measurement>& measurements, float radius, const pair<float, float>& center, const string& startTime, const string& endTime) {
    cout << "Call to GenerateMean" << endl;
    auto start = chrono::high_resolution_clock::now(); // Start timing

    

    // Get sensors within the specified radius
    SensorManagement sensorManagement;
    vector<Sensor> sensorsFiltered = sensorManagement.GetSensorWithinRadius(center, radius, sensors);
    unordered_map<string, float> attributeMeasurements;
    int n = 0;
    // Collect all measurements from sensors within the radius
    for (const auto& sensor : sensorsFiltered) {
        for (const auto& measurement : GetMeasurementsWithinTimePeriod(sensor.getMeasurements(), startTime, endTime)) {
             // Separate measurements by attribute
            attributeMeasurements[measurement.getAttributeID()] += measurement.getValue();
            n++;
        }
    }    

    
    if (n > 0) {
        // HP : same number of measurement for each attribute
        n = n / 4;
        // Initialize means for pollutants
        float meanO3 = 0, meanSO2 = 0, meanNO2 = 0, meanPM10 = 0;

        meanO3 = attributeMeasurements["O3"] / n;
        meanSO2 = attributeMeasurements["SO2"] / n;
        meanNO2 = attributeMeasurements["NO2"] / n;
        meanPM10 = attributeMeasurements["PM10"] / n;

        cout << "Mean calculated using " << sensorsFiltered.size() << " sensors and " <<  n << " measurements per attribute" << endl;
        auto end = chrono::high_resolution_clock::now(); // End timing
        chrono::duration<double> duration = end - start;
        cout << "Execution time: " << duration.count() << " seconds" << endl;

        return ATMO(meanO3, meanSO2, meanNO2, meanPM10);
    }

    auto end = chrono::high_resolution_clock::now(); // End timing
    chrono::duration<double> duration = end - start;
    cout << "Execution time: " << duration.count() << " seconds" << endl;
    
    return -1;
}


float DataManagement::MeasureAirQuality(const vector<Measurement>& measurements, const vector<Sensor>& sensors, const pair<float, float>& position, const string& timestamp) {
    auto start = chrono::high_resolution_clock::now(); // Start timing
    // Get sensors within a reasonable radius
    float radius = 10.0; // Assume a default radius of 10 km
    
    SensorManagement sensorManagement;
    vector<Sensor> nearbySensors = sensorManagement.GetSensorWithinRadius(position, radius, sensors);

    if (nearbySensors.empty()) {
        // No sensors found within the radius
        auto end = chrono::high_resolution_clock::now(); // End timing
        chrono::duration<double> duration = end - start;
        cout << "Execution time: " << duration.count() << " seconds" << endl;

        return -1; // Indicate no data
    }

    // Separate measurements by attribute
    // Get measurements for the specified timestamp
    // Use of unordered_map for efficency
    int n = 0;
    unordered_map<string, float> attributeMeasurements;
    for (const Sensor& sensor : nearbySensors) {
        for (const Measurement& measurement : sensor.getMeasurements()) {
            if (measurement.getTimestamp() == timestamp) {
                // Separate measurements by attribute
                n++;
                attributeMeasurements[measurement.getAttributeID()] += measurement.getValue();
            }
        }
    }

    if (n > 0) {
        // HP : the same number of measurements for each attribute
        n = n/4;
        float meanO3 = 0, meanSO2 = 0, meanNO2 = 0, meanPM10 = 0;
        meanO3 = attributeMeasurements["O3"] / n;
        meanSO2 = attributeMeasurements["SO2"] / n;
        meanNO2 = attributeMeasurements["NO2"] / n;
        meanPM10 = attributeMeasurements["PM10"] / n;        

        cout << "AirQuality measured using " << nearbySensors.size() << " sensors found in a " << radius << "km radius" << endl;
        auto end = chrono::high_resolution_clock::now(); // End timing
        chrono::duration<double> duration = end - start;
        cout << "Execution time: " << duration.count() << " seconds" << endl;

        return ATMO(meanO3, meanSO2, meanNO2, meanPM10);
    }

    // No measurements found for the specified timestamp
    auto end = chrono::high_resolution_clock::now(); // End timing
    chrono::duration<double> duration = end - start;
    cout << "Execution time: " << duration.count() << " seconds" << endl;

    return -1; // Indicate no data   
}


vector<Measurement> DataManagement::GetMeasurementsByAttribute(const vector<Measurement>& measurements, const string& attributeID) {
    vector<Measurement> result;
    for (const Measurement& measurement : measurements) {
        if (measurement.getAttributeID() == attributeID) {
            result.push_back(measurement);
        }
    }
    return result;
}

tm StringToTime(const string& timestamp) {
    // Convert a timestamp string to a std::tm structure
    tm tm = {}; // Initializes a std::tm structure to zero. This structure holds time components such as year, month, day, hour, minute, and second.
    istringstream ss(timestamp); // Creates a string stream from the timestamp string allowing us to parse the string as a stream of characters.
    ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S"); // parse the timestamp string into the tm structure. The format "%Y-%m-%d %H:%M:%S" specifies how the string should be interpreted.
    if (ss.fail()) {
        throw runtime_error("Failed to parse timestamp: " + timestamp);
    }
    return tm;
}

bool CompareTimestamps(tm& tm1, tm& tm2) {
    // Compare two timestamp tm
    // mktime(&tm1) : converts the std::tm structure to a time_t value, which represents the number of seconds since the Unix epoch (January 1, 1970).
    // difftime : calculates the difference in seconds between the two time_t values.   
    return difftime(mktime(&tm1), mktime(&tm2)) <= 0;
    // if the result is less than 0, it means tm1 is earlier than tm2.
}

vector<Measurement> DataManagement::GetMeasurementsWithinTimePeriod(const vector<Measurement>& measurements, const string& startTime, const string& endTime) {
    tm startTimeTm = StringToTime(startTime);
    tm endTimeTm = StringToTime(endTime);
    vector<Measurement> result;
    for (const Measurement& measurement : measurements) {
        tm timestampTm = StringToTime(measurement.getTimestamp());
        if (CompareTimestamps(startTimeTm, timestampTm) && CompareTimestamps(timestampTm, endTimeTm)) {            
            result.push_back(measurement);
        }
    }
    return result;
}

int DataManagement::ATMO(float O3, float SO2, float NO2, float PM10) {
    int subIndexO3, subIndexSO2, subIndexNO2, subIndexPM10;

    // Determine sub-index for O3
    switch (static_cast<int>(O3)) {
        case 0 ... 29: subIndexO3 = 1; break;
        case 30 ... 54: subIndexO3 = 2; break;
        case 55 ... 79: subIndexO3 = 3; break;
        case 80 ... 104: subIndexO3 = 4; break;
        case 105 ... 129: subIndexO3 = 5; break;
        case 130 ... 149: subIndexO3 = 6; break;
        case 150 ... 179: subIndexO3 = 7; break;
        case 180 ... 209: subIndexO3 = 8; break;
        case 210 ... 239: subIndexO3 = 9; break;
        default: subIndexO3 = 10; break;
    }

    // Determine sub-index for SO2
    switch (static_cast<int>(SO2)) {
        case 0 ... 39: subIndexSO2 = 1; break;
        case 40 ... 79: subIndexSO2 = 2; break;
        case 80 ... 119: subIndexSO2 = 3; break;
        case 120 ... 159: subIndexSO2 = 4; break;
        case 160 ... 199: subIndexSO2 = 5; break;
        case 200 ... 249: subIndexSO2 = 6; break;
        case 250 ... 299: subIndexSO2 = 7; break;
        case 300 ... 399: subIndexSO2 = 8; break;
        case 400 ... 499: subIndexSO2 = 9; break;
        default: subIndexSO2 = 10; break;
    }

    // Determine sub-index for NO2
    switch (static_cast<int>(NO2)) {
        case 0 ... 29: subIndexNO2 = 1; break;
        case 30 ... 54: subIndexNO2 = 2; break;
        case 55 ... 84: subIndexNO2 = 3; break;
        case 85 ... 109: subIndexNO2 = 4; break;
        case 110 ... 134: subIndexNO2 = 5; break;
        case 135 ... 164: subIndexNO2 = 6; break;
        case 165 ... 199: subIndexNO2 = 7; break;
        case 200 ... 274: subIndexNO2 = 8; break;
        case 275 ... 399: subIndexNO2 = 9; break;
        default: subIndexNO2 = 10; break;
    }

    // Determine sub-index for PM10
    switch (static_cast<int>(PM10)) {
        case 0 ... 6: subIndexPM10 = 1; break;
        case 7 ... 13: subIndexPM10 = 2; break;
        case 14 ... 20: subIndexPM10 = 3; break;
        case 21 ... 27: subIndexPM10 = 4; break;
        case 28 ... 34: subIndexPM10 = 5; break;
        case 35 ... 41: subIndexPM10 = 6; break;
        case 42 ... 49: subIndexPM10 = 7; break;
        case 50 ... 64: subIndexPM10 = 8; break;
        case 65 ... 79: subIndexPM10 = 9; break;
        default: subIndexPM10 = 10; break;
    }

    // The ATMO index is the maximum of the sub-indices
    return max({subIndexO3, subIndexSO2, subIndexNO2, subIndexPM10});
}