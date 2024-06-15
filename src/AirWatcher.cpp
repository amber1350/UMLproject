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


int main() {
    vector<Measurement> measurements;
    vector<Sensor> sensors;
    vector<Attribute> attributes;
    vector<Cleaner> cleaners;

    DataAccess dataAccess;    
    
    // Reading measurements    
    int measurementResult = dataAccess.readMeasurementData("measurements.csv", measurements);
    if (measurementResult == 0) {
        cout << "Measurement data loaded successfully." << endl;
    } else {
        cout << "Failed to load measurement data." << endl;
    }
    cout << endl;

    // Reading sensors
    int sensorResult = dataAccess.readSensorData("sensors.csv", sensors);
    if (sensorResult == 0) {
        cout << "Sensor data loaded successfully." << endl;      
        // Setting Measurements
        for ( Sensor& sensor : sensors) {
            sensor.setMeasurements(measurements);
        }                                 
    } else {
        cout << "Failed to load sensor data." << endl;
    }
    cout << endl;

    // Reading attributes
    int attributeResult = dataAccess.readAttributeData("attributes.csv", attributes);
    if (attributeResult == 0) {
        cout << "Attribute data loaded successfully." << endl;
    } else {
        cout << "Failed to load cleaner data." << endl;
    }
    cout << endl;


    // Reading cleaners    
    int cleanerResult = dataAccess.readCleanerData("cleaners.csv", cleaners);
    if (cleanerResult == 0) {
        cout << "Cleaner data loaded successfully." << endl;
    } else {
        cout << "Failed to load cleaner data." << endl;
    }
    cout << endl;
    
    SensorManagement sensorManagement;
    DataManagement dataManagement;
    // Create an instance of AgentInterface
    AgentInterface agentInterface;

    // Display the menu
    agentInterface.DisplayMenu();

    return 0;
}
