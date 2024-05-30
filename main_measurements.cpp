

int main() {
    vector<Sensor> sensors;
    int result = readSensorData("sensors.csv", sensors);
    if (result == 0) {
        cout << "Sensor data loaded successfully." << endl;
    } else {
        cout << "Failed to load sensor data." << endl;
    }
    return 0;
}