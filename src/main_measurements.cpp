#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "models/Account.h"
#include "models/Agent.h"
#include "models/Attribute.h"
#include "dataaccess/DataAccess.h"
#include "models/Measurement.h"
#include "models/Provider.h"
#include "models/User.h"
#include "models/Sensor.h"
#include "models/Cleaner.h"

using namespace std;

int main() {
    DataAccess dataAccess;
    
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

    // Test reading sensors
    vector<Sensor> sensors;
    int sensorResult = dataAccess.readSensorData("sensors.csv", sensors);
    if (sensorResult == 0) {
        cout << "Sensor data loaded successfully." << endl;
        for (int i=0; i<5; i++) {
            cout << sensors[i] << endl;
        }

        // Get measurements for the first sensor
        if (!sensors.empty()) {
            vector<Measurement> sensorMeasurements = sensors[0].getMeasurements(measurements);
            cout << "Measurements for Sensor ID: " << sensors[0].getSensorID() << endl;
            for (const auto& measurement : sensorMeasurements) {
                cout << measurement << endl;
            }
        }
        
    } else {
        cout << "Failed to load sensor data." << endl;
    }

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

    return 0;
}
