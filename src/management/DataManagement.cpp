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
using namespace std;

//------------------------------------------------------ Personal Includes
#include "DataManagement.h"
#include "SensorManagement.h"

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
    // Initialize means for pollutants
    float meanO3 = 0, meanSO2 = 0, meanNO2 = 0, meanPM10 = 0;

    // Get sensors within the specified radius
    SensorManagement sensorManagement;
    vector<Sensor> sensorsFiltered = sensorManagement.GetSensorWithinRadius(center, radius, sensors);

    // Collect all measurements from sensors within the radius
    vector<Measurement> allMeasurements;
    for (const Sensor& sensor : sensorsFiltered) {
        vector<Measurement> sensorMeasurements = sensor.getMeasurements();
        allMeasurements.insert(allMeasurements.end(), sensorMeasurements.begin(), sensorMeasurements.end());
    }

    // Filter measurements by the specified time period
    allMeasurements = GetMeasurementsWithinTimePeriod(allMeasurements, startTime, endTime);

    // Separate measurements by attribute
    vector<Measurement> measurementsO3 = GetMeasurementsByAttribute(allMeasurements, "O3");
    vector<Measurement> measurementsSO2 = GetMeasurementsByAttribute(allMeasurements, "SO2");
    vector<Measurement> measurementsNO2 = GetMeasurementsByAttribute(allMeasurements, "NO2");
    vector<Measurement> measurementsPM10 = GetMeasurementsByAttribute(allMeasurements, "PM10");

    // Calculate means
    int n = measurementsO3.size();
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            meanO3 += measurementsO3[i].getValue();
            meanSO2 += measurementsSO2[i].getValue();
            meanNO2 += measurementsNO2[i].getValue();
            meanPM10 += measurementsPM10[i].getValue();
        }
        meanO3 /= n;
        meanSO2 /= n;
        meanNO2 /= n;
        meanPM10 /= n;

        // Calculate ATMO index
        return ATMO(meanO3, meanSO2, meanNO2, meanPM10);
    }

    // Return null or some indicator of no data if n == 0
    return -1;
}

float DataManagement::MeasureAirQuality(float radius, const pair<float, float>& center) {
    // Placeholder implementation: Measure air quality index within a radius from the center
    // Implement the actual air quality measurement logic here
    return 0;
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

bool CompareTimestamps(const string& t1, const string& t2) {
    // Compare two timestamp strings
    tm tm1 = StringToTime(t1);
    tm tm2 = StringToTime(t2);
    // mktime(&tm1) converts the std::tm structure to a time_t value, which represents the number of seconds since the Unix epoch (January 1, 1970).
    //difftime calculates the difference in seconds between the two time_t values.
    return difftime(mktime(&tm1), mktime(&tm2)) < 0;
}

vector<Measurement> DataManagement::GetMeasurementsWithinTimePeriod(const vector<Measurement>& measurements, const string& startTime, const string& endTime) {
    vector<Measurement> result;
    for (const Measurement& measurement : measurements) {
        if (CompareTimestamps(measurement.getTimestamp(), startTime) && CompareTimestamps(measurement.getTimestamp(), endTime)) {            
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