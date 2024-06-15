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

#include "interface/AgentInterface.h"

using namespace std;

vector<Measurement> measurements;
vector<Sensor> sensors;
vector<Attribute> attributes;
vector<Cleaner> cleaners;

int main() {
    DataAccess dataAccess;
    SensorManagement sensorManagement;
    DataManagement dataManagement;
    
    // Test reading measurements
    cout << "****** Test : Reading measurements from empty csv file.******" << endl;   
    int measurementResult = dataAccess.readMeasurementData("mexsurements.csv", measurements);
    if (measurementResult == 0) {
        cout << "Measurement data loaded successfully." << endl;
        for (int i=0; i<5; i++) {
            cout << measurements[i] << endl;
        }
    } else {
        cout << "Failed to load measurement data." << endl;
    }
    cout << endl;
    cout << "****** Test : Reading measurements from well formed csv file. ******" << endl;  
    measurementResult = dataAccess.readMeasurementData("measurements.csv", measurements);
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
    cout << "****** Test : Reading sensors from well formed csv file. ******" << endl;  
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
            cout << " Test : Setting sensor's measurements" << endl;  
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
    cout << "****** Test : Reading attributes from well formed csv file.******" << endl;  
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
    cout << "****** Test : Reading cleaners from well formed csv file.******" << endl;   
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

    cout << endl;


    // Test GetSensorWithinRadius
    cout << "****** Test : GetSensorWithinRadius ******" << endl;  
    pair<float, float> center;
    float radius; // in km
    vector<Sensor> result;

    // Test Scenario 1
    cout << "Scenario 1: Center at (44, -1), Radius = 10 km" << endl;
    center = {44, -1};
    radius = 10.0;
    result = sensorManagement.GetSensorWithinRadius(center, radius, sensors);
    if (!result.empty()){
        cout << "Found following sensor(s) :" << endl;
        for (const auto& sensor : result) {
            cout << sensor << endl;
        }
    }else{
        cout << "No sensor found at specified location" << endl;
    }
    cout << endl;

    // Test Scenario 2
    cout << "Scenario 2: Center at (44, -0.3), Radius = 10 km" << endl;
    center = {44, -0.3};
    result = sensorManagement.GetSensorWithinRadius(center, radius, sensors);
    if (!result.empty()){
        cout << "Found following sensor(s) :" << endl;
        for (const auto& sensor : result) {
            cout << sensor << endl;
        }
    }else{
        cout << "No sensor found at specified location" << endl;
    }
    cout << endl;

    // Test Scenario 3
    cout << "Scenario 3: Center at (44.4, 1.8), Radius = 10 km" << endl;
    center = {44.4, 1.8};
    result = sensorManagement.GetSensorWithinRadius(center, radius, sensors);
    if (!result.empty()){
        cout << "Found following sensor(s) :" << endl;
        for (const auto& sensor : result) {
            cout << sensor << endl;
        }
    }else{
        cout << "No sensor found at specified location" << endl;
    }
    cout << endl;

    // Test Scenario 4
    cout << "Scenario 4: Center at (44.4, 44.8), Radius = 10 km" << endl;
    center = {44.4, 44.8};
    result = sensorManagement.GetSensorWithinRadius(center, radius, sensors);
    if (!result.empty()){
        cout << "Found following sensor(s) :" << endl;
        for (const auto& sensor : result) {
            cout << sensor << endl;
        }
    }else{
        cout << "No sensor found at specified location" << endl;
    }
    cout << endl;   

    // Test Scenario 5
    cout << "Scenario 4: Center at (46, 2.5), Radius = 10 km" << endl;
    center = {46, 2.5};
    result = sensorManagement.GetSensorWithinRadius(center, radius, sensors);
    if (!result.empty()){
        cout << "Found following sensor(s) :" << endl;
        for (const auto& sensor : result) {
            cout << sensor << endl;
        }
    }else{
        cout << "No sensor found at specified location" << endl;
    }
    cout << endl;

    // Test Scenario 6
    cout << "Scenario 6: Center at (44.8, 2.5), Radius = 50 km" << endl;
    radius = 50;
    center = {44.8, 2.5};
    result = sensorManagement.GetSensorWithinRadius(center, radius, sensors);
    if (!result.empty()){
        cout << "Found following sensor(s) :" << endl;
        for (const auto& sensor : result) {
            cout << sensor << endl;
        }
    }else{
        cout << "No sensor found at specified location" << endl;
    }
    cout << endl;


    cout << endl;   

    // Test GetMeasurementsWithinTimePeriod
    cout << "****** Test : GetMeasurementsWithinTimePeriod ******" << endl;  
    // Test Scenario 1  
    cout << "Scenario 1: Specified period of time" << endl;
    vector<Measurement> measurementsWithinTimePeriod = dataManagement.GetMeasurementsWithinTimePeriod(measurements,"2019-01-01 00:00:00","2019-01-03 00:00:00");
    if (!measurementsWithinTimePeriod.empty()){
        for (int i=0; i<5; i++) {
            cout << measurementsWithinTimePeriod[i] << endl;
        }        
    } else {
        cout << "No data available" << endl;

    }
    // Test Scenario 2  
    cout << "Scenario 2: Given moment" << endl;
    measurementsWithinTimePeriod = dataManagement.GetMeasurementsWithinTimePeriod(measurements,"2019-01-01 12:00:00","2019-01-01 12:00:00");
    if (!measurementsWithinTimePeriod.empty()){
        for (int i=0; i<5; i++) {
            cout << measurementsWithinTimePeriod[i] << endl;
        }        
    } else {
        cout << "No data available" << endl;

    }
    // Test Scenario 3  
    cout << "Scenario 3: No available data" << endl;
    measurementsWithinTimePeriod = dataManagement.GetMeasurementsWithinTimePeriod(measurements,"2019-01-01 00:00:00","2019-01-01 00:00:00");
    if (!measurementsWithinTimePeriod.empty()){
        for (int i=0; i<5; i++) {
            cout << measurementsWithinTimePeriod[i] << endl;
        }        
    } else {
        cout << "No data available" << endl;

    }


    // Test GenerateMean
    cout << "****** Test : GenerateMean ******" << endl;  
    string startTime;
    string endTime;
    float mean;  
    // Test Scenario 1    
    radius = 50.0;
    center = {44.8, 2.5};
    startTime = "2019-01-01 00:00:00";
    endTime = "2019-01-03 00:00:00";
    cout << "Scenario 1: Calculating mean for a specified period of time" << endl;
    cout << "Center at (44.8, 2.5), Radius = 50 km, startTime = 2019-01-01 00:00:00, endTime = 2019-01-03 00:00:00" << endl;
    mean = dataManagement.GenerateMean(sensors, measurements, radius, center, startTime, endTime);
    if (mean != -1) {
        cout << "Mean Air Quality Index: " << mean << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }
    cout << endl;

    // Test Scenario 2
    cout << "Scenario 2: Calculating mean for a given moment" << endl;
    startTime = endTime = "2019-01-01 12:00:00;"; 
    cout << "Center at (44.8, 2.5), Radius = 50 km, startTime = 2019-01-01 00:00:00, endTime = 2019-01-01 12:00:00" << endl;

    mean = dataManagement.GenerateMean(sensors, measurements, radius, center, startTime, endTime);
    if (mean != -1) {
        cout << "Mean Air Quality Index: " << mean << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }   
    cout << endl; 

    // Test Scenario 3
    cout << "Scenario 3: Calculating mean with no measurements available" << endl;
    cout << "Center at (44.8, 2.5), Radius = 50 km, startTime = 2019-01-01 00:00:10, endTime = 2019-01-01 00:00:10" << endl;

    // Define parameters
    startTime = endTime = "2019-01-01 00:00:10"; 
    mean = dataManagement.GenerateMean(sensors, measurements, radius, center, startTime, endTime);
    if (mean != -1) {
        cout << "Mean Air Quality Index: " << mean << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }
    cout << endl;

    // Test Scenario 4
    cout << "Scenario 4: Calculating mean with no sensors at specified location" << endl;
    cout << "Center at (44.4, 44.8), Radius = 50 km, startTime = 2019-01-01 12:00:00, endTime = 2019-01-02 12:00:00" << endl;
    startTime = "2019-01-01 12:00:00"; 
    endTime = "2019-01-02 12:00:00";
    center = {44.4, 44.8};
    mean = dataManagement.GenerateMean(sensors, measurements, radius, center, startTime, endTime);    
    if (mean != -1) {
        cout << "Mean Air Quality Index: " << mean << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }
    cout << endl;


        
    // Test MeasureAirQuality
    // Test Scenario 1
    cout << endl;
    cout << "Scenario 1: Calculating AirQuality " << endl;
    cout << "Position at (44.8, 2.5), Time = 2019-01-01 12:00:00" << endl;
    // Define parameters
    pair<float, float> position = {44.8, 2.5};
    string timestamp = "2019-01-01 12:00:00";

    float airQuality = dataManagement.MeasureAirQuality(measurements, sensors, position, timestamp);

    // Output result
    if (airQuality != -1) {
        cout << "Air Quality Index at position (" << position.first << ", " << position.second << ") at " << timestamp << " is " << airQuality << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }
    cout << endl;

    // Test Scenario 2
    cout << endl;
    cout << "Scenario 2: Calculating AirQuality with data available" << endl;
    cout << "Position at (44.8, 44.5), Time = 2019-01-01 12:00:00" << endl;
    // Define parameters
    position = {44.8, 44.5};
    airQuality = dataManagement.MeasureAirQuality(measurements, sensors, position, timestamp);

    // Output result
    if (airQuality != -1) {
        cout << "Air Quality Index at position (" << position.first << ", " << position.second << ") at " << timestamp << " is " << airQuality << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }
    cout << endl;

    

    return 0;
}
