#include <iostream>
#include "models/Account.h"
#include "models/Agent.h"
#include "models/Attribute.h"
#include "dataaccess/DataAccess.h"
#include "models/Measurement.h"
#include "models/Provider.h"
#include "models/User.h"
#include "models/Sensor.h"


using namespace std;

int main() {
    DataAccess dataAccess;

    // Test reading sensors
    vector<Sensor> sensors;
    int sensorResult = dataAccess.readSensorData("sensors.csv", sensors);
    if (sensorResult == 0) {
        cout << "Sensor data loaded successfully." << endl;
    } else {
        cout << "Failed to load sensor data." << endl;
    }

    // Test reading measurements
    vector<Measurement> measurements;
    int measurementResult = dataAccess.readMeasurementData("measurements.csv", measurements);
    if (measurementResult == 0) {
        cout << "Measurement data loaded successfully." << endl;
    } else {
        cout << "Failed to load measurement data." << endl;
    }
    

    return 0;
}