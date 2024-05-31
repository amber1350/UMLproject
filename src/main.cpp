#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "models/Account.h"
#include "models/Agent.h"
#include "models/Attribute.h"
#include "models/Measurement.h"
#include "models/Provider.h"
#include "models/User.h"
#include "models/Sensor.h"
#include "models/Cleaner.h"

#include "dataaccess/DataAccess.h"

#include "management/SensorManagement.h"
#include "management/DataManagement.h"

using namespace std;

int main() {
    DataAccess dataAccess;
    SensorManagement sensorManagement;
    DataManagement dataManagement;
    
    // Test reading measurements
    vector<Measurement> measurements;
    int measurementResult = dataAccess.readMeasurementData("measurements.csv", measurements);
    if (measurementResult == 0) {
        cout << "Measurement data loaded successfully." << endl;
        for (int i=0; i<5; i++) {
            cout << measurements[i] << endl;
        }
    } else {
        cout << "Failed to load measurement data." << endl;
    }
    cout << endl;

    // Test reading sensors
    vector<Sensor> sensors;
    int sensorResult = dataAccess.readSensorData("sensors.csv", sensors);
    if (sensorResult == 0) {
        cout << "Sensor data loaded successfully." << endl;      
        for (int i=0; i<5; i++) {
            cout << sensors[i] << endl;
        }

        // Setting Measurements
        if (!sensors.empty()) {
            for ( Sensor& sensor : sensors) {
                sensor.setMeasurements(measurements);
            } 
            vector<Measurement> sensorMeasurements = sensors[0].getMeasurements();
            cout << "Measurements for Sensor ID: " << sensors[0].getSensorID() << endl;
            for (int i=0; i<5; i++) {
                cout << sensorMeasurements[i] << endl;
            }              
        }            
    } else {
        cout << "Failed to load sensor data." << endl;
    }
    cout << endl;

    // Test reading attributes
    vector<Attribute> attributes;
    int attributeResult = dataAccess.readAttributeData("attributes.csv", attributes);
    if (attributeResult == 0) {
        cout << "Attribute data loaded successfully." << endl;
        for (const Attribute& attribute : attributes) {
            cout << attribute << endl;
        }
    } else {
        cout << "Failed to load cleaner data." << endl;
    }
    cout << endl;


    // Test reading cleaners
    vector<Cleaner> cleaners;
    int cleanerResult = dataAccess.readCleanerData("cleaners.csv", cleaners);
    if (cleanerResult == 0) {
        cout << "Cleaner data loaded successfully." << endl;
        for (const Cleaner& cleaner : cleaners) {
            cout << cleaner << endl;
        }
    } else {
        cout << "Failed to load cleaner data." << endl;
    }
    cout << endl;

    // Test Scenario 1
    cout << "Scenario 1: Center at (44, -1), Radius = 10 km" << endl;
    pair<float, float> center1 = {44, -1};
    float radius1 = 10.0; // in km
    vector<Sensor> result1 = sensorManagement.GetSensorWithinRadius(center1, radius1, sensors);
    for (const auto& sensor : result1) {
        cout << sensor << endl;
    }
    cout << endl;

    // Test Scenario 2
    cout << "Scenario 2: Center at (44, -0.3), Radius = 10 km" << endl;
    pair<float, float> center2 = {44, -0.3};
    float radius2 = 10.0; // in km
    vector<Sensor> result2 = sensorManagement.GetSensorWithinRadius(center2, radius2, sensors);
    for (const auto& sensor : result2) {
        cout << sensor << endl;
    }
    cout << endl;

    // Test Scenario 3
    cout << "Scenario 3: Center at (44.4, 1.8), Radius = 10 km" << endl;
    pair<float, float> center3 = {44.4, 1.8};
    float radius3 = 10.0; // in km
    vector<Sensor> result3 = sensorManagement.GetSensorWithinRadius(center3, radius3, sensors);
    for (const auto& sensor : result3) {
        cout << sensor << endl;
    }
    cout << endl;

    // Test Scenario 4
    cout << "Scenario 4: Center at (46, 2.5), Radius = 10 km" << endl;
    pair<float, float> center4 = {46, 2.5};
    float radius4 = 10.0; // in km
    vector<Sensor> result4 = sensorManagement.GetSensorWithinRadius(center4, radius4, sensors);
    for (const auto& sensor : result4) {
        cout << sensor << endl;
    }
    cout << endl;

    // Test Scenario 5
    cout << "Scenario 5: Center at (44.8, 2.5), Radius = 50 km" << endl;
    pair<float, float> center5 = {44.8, 2.5};
    float radius5 = 50.0; // in km
    vector<Sensor> result5 = sensorManagement.GetSensorWithinRadius(center5, radius5, sensors);
    for (const auto& sensor : result5) {
        cout << sensor << endl;
    }
    cout << endl;

    // Test Scenario 6
    cout << "Scenario 6: Calculating mean for a specified period of time" << endl;
    // Define parameters
    float radius = 50.0;
    pair<float, float> center = {44.8, 2.5};
    string startTime = "2019-01-01 00:00:00"; 
    string endTime = "2019-01-02 23:59:59"; 
    float mean;  
    // Create DataManagement instance and calculate mean
    mean = dataManagement.GenerateMean(sensors, measurements, radius, center, startTime, endTime);
    // Output result
    if (mean != -1) {
        cout << "Mean Air Quality Index: " << mean << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }

    // Test Scenario 7
    cout << "Scenario 7: Calculating mean with no data available" << endl;
    // Define parameters
    endTime = "2019-01-01 00:00:10"; 

    // Create DataManagement instance and calculate mean
    mean = dataManagement.GenerateMean(sensors, measurements, radius, center, startTime, endTime);

    // Output result
    if (mean != -1) {
        cout << "Mean Air Quality Index: " << mean << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }

    // Test Scenario 8
    cout << "Scenario 8: Calculating mean for a given moment" << endl;
    // Define parameters
    startTime = "2019-01-01 12:00:00;"; 
    endTime = "2019-01-01 12:00:00;"; 

    // Create DataManagement instance and calculate mean
    mean = dataManagement.GenerateMean(sensors, measurements, radius, center, startTime, endTime);

    // Output result
    if (mean != -1) {
        cout << "Mean Air Quality Index: " << mean << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }

    return 0;
}
