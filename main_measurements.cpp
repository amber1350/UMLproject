#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "DataAccess.h"
#include "Measurement.h"
#include "Sensor.h"


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
