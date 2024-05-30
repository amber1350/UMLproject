/*************************************************************************
                           DataAccess  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <DataAccess> (file DataAccess.cpp) ------------

//---------------------------------------------------------------- INCLUDE
 
//-------------------------------------------------------- System Includes
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

//------------------------------------------------------ Personal Includes
#include "DataAccess.h"

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods
// Helper function to parse CSV lines
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s); // Stream to process the string
    while (getline(tokenStream, token, delimiter)) { // Read until delimiter
        tokens.push_back(token); // Store token in the vector
    }
    return tokens;
}

int DataAccess::readSensorData(const string& csvFile, vector<Sensor>& sensors) {
    ifstream file(csvFile); // Open the file
    if (!file.is_open()) { // Check if the file is open
        cerr << "Error opening file: " << csvFile << endl;
        return -1;
    }
    string line;
    while (getline(file, line)) { // Read each line from the file
        auto tokens = split(line, ','); // Split the line into tokens
        // Assuming CSV format: SensorID, Latitude, Longitude
        if (tokens.size() == 3) { 
            sensors.push_back(Sensor(tokens[0], stof(tokens[1]), stof(tokens[2])));
        }
    }
    file.close(); // Close the file
    return 0;
} 

int DataAccess::readMeasurementData(const string& csvFile, vector<Measurement>& measurements) {
    ifstream file(csvFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << csvFile << endl;
        return -1;
    }
    string line;
    while (getline(file, line)) {
        auto tokens = split(line, ',');
        if (tokens.size() == 4) {
            // Assuming CSV format: TimeStamp, SensorID, AttributeID, Value
            measurements.push_back(Measurement(tokens[0], tokens[1],  tokens[2], stof(tokens[3])));
        }
    }
    file.close();
    return 0;
} 

int DataAccess::readAttributeData(const string& csvFile, vector<Attribute>& attributes) {
    ifstream file(csvFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << csvFile << endl;
        return -1;
    }
    string line;
    while (getline(file, line)) {
        auto tokens = split(line, ',');
        // Assuming CSV format: AttributeID, Unit, Description
        if (tokens.size() == 3) {
            attributes.push_back(Attribute(tokens[0], tokens[1], tokens[2]));
        }
    }
    file.close();
    return 0;
} 

int DataAccess::readProviderData(const string& csvFile, vector<Provider>& providers) {
    ifstream file(csvFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << csvFile << endl;
        return -1;
    }
    string line;
    while (getline(file, line)) {
        auto tokens = split(line, ',');
        if (tokens.size() == 4) {
            // Assuming CSV format: TimeStamp, SensorID, AttributeID, Value
            providers.push_back(Measurement(tokens[0], tokens[1],  tokens[2], stof(tokens[3])));
        }
    }
    file.close();
    return 0;
}

int DataAccess::readCleanerData(const string& csvFile, vector<Cleaner>& cleaners) {
    ifstream file(csvFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << csvFile << endl;
        return -1;
    }
    string line;
    while (getline(file, line)) {
        auto tokens = split(line, ',');
        if (tokens.size() == 4) {
            // Assuming CSV format: TimeStamp, SensorID, AttributeID, Value
            cleaners.push_back(Measurement(tokens[0], tokens[1],  tokens[2], stof(tokens[3])));
        }
    }
    file.close();
    return 0;
}

int DataAccess::readUserData(const string& csvFile, vector<User>& users) {
    ifstream file(csvFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << csvFile << endl;
        return -1;
    }
    string line;
    while (getline(file, line)) {
        auto tokens = split(line, ',');
        if (tokens.size() == 4) {
            // Assuming CSV format: TimeStamp, SensorID, AttributeID, Value
            users.push_back(Measurement(tokens[0], tokens[1],  tokens[2], stof(tokens[3])));
        }
    }
    file.close();
    return 0;
}

int DataAccess::writeSensorData(const string& csvFile, const vector<Sensor>& sensors) {
    ofstream file(csvFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << csvFile << endl;
        return -1;
    }
    for (const auto& sensor : sensors) {
        file << sensor.getID() << "," << sensor.getLatitude() << "," << sensor.getLongitude() << endl;
    }
    file.close();
    return 0;
}

int DataAccess::writeMeasurementData(const string& csvFile, const vector<Measurement>& measurements) {
    ofstream file(csvFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << csvFile << endl;
        return -1;
    }
    for (const auto& measurement : measurements) {
        file << measurement.getID() << "," << measurement.getLatitude() << "," << measurement.getLongitude() << endl;
    }
    file.close();
    return 0;
}

int DataAccess::writeAttributeData(const string& csvFile, const vector<Attribute>& attributes) {
    ofstream file(csvFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << csvFile << endl;
        return -1;
    }
    for (const auto& attribute : attributes) {
        file << attribute.getID() << "," << attribute.getLatitude() << "," << attribute.getLongitude() << endl;
    }
    file.close();
    return 0;
}

int DataAccess::writeProviderData(const string& csvFile, const vector<Provider>& providers) {
    ofstream file(csvFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << csvFile << endl;
        return -1;
    }
    for (const auto& provider : providers) {
        file << provider.getID() << "," << provider.getLatitude() << "," << provider.getLongitude() << endl;
    }
    file.close();
    return 0;
}

int DataAccess::writeCleanerData(const string& csvFile, const vector<Cleaner>& cleaners) {
    ofstream file(csvFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << csvFile << endl;
        return -1;
    }
    for (const auto& cleaner : cleaners) {
        file << cleaner.getID() << "," << cleaner.getLatitude() << "," << cleaner.getLongitude() << endl;
    }
    file.close();
    return 0;
}

int DataAccess::writeUserData(const string& csvFile, const vector<User>& users) {
    ofstream file(csvFile);
    if (!file.is_open()) {
        cerr << "Error opening file: " << csvFile << endl;
        return -1;
    }
    for (const auto& user : users) {
        file << user.getID() << "," << user.getLatitude() << "," << user.getLongitude() << endl;
    }
    file.close();
    return 0;
}

//-------------------------------------------- Constructors - Destructor
DataAccess::DataAccess() {
#ifdef MAP
    cout << "Call to the constructor of <DataAccess>" << endl;
#endif
}

DataAccess::~DataAccess() {
#ifdef MAP
    cout << "Call to the destructor of <DataAccess>" << endl;
#endif
}
DataAccess::DataAccess ( )
{
#ifdef MAP
    cout << "Call to the constructor of <DataAccess>" << endl;
#endif
} //----- End of DataAccess

DataAccess::~DataAccess ( )
{
#ifdef MAP
    cout << "Call to the destructor of <DataAccess>" << endl;
#endif
} //----- End of ~DataAccess
