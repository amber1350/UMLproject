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
    string fullPath = baseDirectory + csvFile;
    ifstream file(fullPath); // Open the file
    if (!file.is_open()) { // Check if the file is open
        cerr << "Error opening file: " << fullPath << endl;
        return -1;
    }
    string line;
    while (getline(file, line)) { // Read each line from the file
        auto tokens = split(line, ';'); // Split the line into tokens       
        if (tokens.size() == 3) { 
             // Assuming CSV format: SensorID; Latitude; Longitude;
            sensors.push_back(Sensor(tokens[0], stof(tokens[1]), stof(tokens[2])));           
        }
    }
    file.close(); // Close the file
    return 0;
} 

int DataAccess::readMeasurementData(const string& csvFile, vector<Measurement>& measurements) {
    string fullPath = baseDirectory + csvFile;
    ifstream file(fullPath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fullPath << endl;
        return -1;
    }
    string line;
    while (getline(file, line)) {
        auto tokens = split(line, ';');
        if (tokens.size() == 4) {
            // Assuming CSV format: TimeStamp; SensorID; AttributeID; Value;
            measurements.push_back(Measurement(tokens[0], tokens[1],  tokens[2], stof(tokens[3])));
        }
    }
    file.close();
    return 0;
} 

int DataAccess::readAttributeData(const string& csvFile, vector<Attribute>& attributes) {
    string fullPath = baseDirectory + csvFile;
    ifstream file(fullPath);

    string line;

    // Skip the first line (header)
    if (!getline(file, line)) {
        cerr << "Error reading file: " << fullPath << endl;
        return -1;
    }    
    
    while (getline(file, line)) {     
        auto tokens = split(line, ';');   
        if (tokens.size() == 4) {
            cout << line << endl;
            cout << Attribute(tokens[0], tokens[1], tokens[2]) << endl;             
            attributes.push_back(Attribute(tokens[0], tokens[1], tokens[2]));
        }
    }    
    file.close();
    return 0;
}

int DataAccess::readCleanerData(const string& csvFile, vector<Cleaner>& cleaners) {
    string fullPath = baseDirectory + csvFile;
    ifstream file(fullPath);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fullPath << endl;
        return -1;
    }

    string line;
    while (getline(file, line)) {
        auto tokens = split(line, ';');         
        if (tokens.size() == 5) {
            // Assuming CSV format: CleanerID, Latitude; Longitude; TimestampStart; TimestampStop
            cleaners.push_back(Cleaner(tokens[0], stof(tokens[1]), stof(tokens[2]), tokens[3], tokens[4]));

        }
    }
    file.close();
    return 0;
}

// int DataAccess::readProviderData(const string& csvFile, vector<Provider>& providers) {
//     string fullPath = baseDirectory + csvFile;
//     ifstream file(fullPath);

//     if (!file.is_open()) {
//         cerr << "Error opening file: " << fullPath << endl;
//         return -1;
//     }
//     string line;
//     while (getline(file, line)) {
//         auto tokens = split(line, ';');
//         if (tokens.size() == 2) {
//             // Assuming CSV format: ProviderID; SensorID;
//             providers.push_back(Provider(tokens[1],  tokens[2]));
//         }
//     }
//     file.close();
//     return 0;
// }


// int DataAccess::readUserData(const string& csvFile, vector<User>& users) {
//     ifstream file(csvFile);
//     if (!file.is_open()) {
//         cerr << "Error opening file: " << csvFile << endl;
//         return -1;
//     }
//     string line;
//     while (getline(file, line)) {
//         auto tokens = split(line, ',');
//         if (tokens.size() == 4) {
//             // Assuming CSV format: TimeStamp, SensorID, AttributeID, Value
//             users.push_back(Measurement(tokens[0], tokens[1],  tokens[2], stof(tokens[3])));
//         }
//     }
//     file.close();
//     return 0;
// }

// int DataAccess::writeSensorData(const string& csvFile, const vector<Sensor>& sensors) {
//     ofstream file(csvFile);
//     if (!file.is_open()) {
//         cerr << "Error opening file: " << csvFile << endl;
//         return -1;
//     }
//     for (const auto& sensor : sensors) {
//         file << sensor.getID() << "," << sensor.getLatitude() << "," << sensor.getLongitude() << endl;
//     }
//     file.close();
//     return 0;
// }

// int DataAccess::writeMeasurementData(const string& csvFile, const vector<Measurement>& measurements) {
//     ofstream file(csvFile);
//     if (!file.is_open()) {
//         cerr << "Error opening file: " << csvFile << endl;
//         return -1;
//     }
//     for (const auto& measurement : measurements) {
//         file << measurement.getID() << "," << measurement.getLatitude() << "," << measurement.getLongitude() << endl;
//     }
//     file.close();
//     return 0;
// }

// int DataAccess::writeAttributeData(const string& csvFile, const vector<Attribute>& attributes) {
//     ofstream file(csvFile);
//     if (!file.is_open()) {
//         cerr << "Error opening file: " << csvFile << endl;
//         return -1;
//     }
//     for (const auto& attribute : attributes) {
//         file << attribute.getID() << "," << attribute.getLatitude() << "," << attribute.getLongitude() << endl;
//     }
//     file.close();
//     return 0;
// }

// int DataAccess::writeProviderData(const string& csvFile, const vector<Provider>& providers) {
//     ofstream file(csvFile);
//     if (!file.is_open()) {
//         cerr << "Error opening file: " << csvFile << endl;
//         return -1;
//     }
//     for (const auto& provider : providers) {
//         file << provider.getID() << "," << provider.getLatitude() << "," << provider.getLongitude() << endl;
//     }
//     file.close();
//     return 0;
// }

// int DataAccess::writeCleanerData(const string& csvFile, const vector<Cleaner>& cleaners) {
//     ofstream file(csvFile);
//     if (!file.is_open()) {
//         cerr << "Error opening file: " << csvFile << endl;
//         return -1;
//     }
//     for (const auto& cleaner : cleaners) {
//         file << cleaner.getID() << "," << cleaner.getLatitude() << "," << cleaner.getLongitude() << endl;
//     }
//     file.close();
//     return 0;
// }

// int DataAccess::writeUserData(const string& csvFile, const vector<User>& users) {
//     ofstream file(csvFile);
//     if (!file.is_open()) {
//         cerr << "Error opening file: " << csvFile << endl;
//         return -1;
//     }
//     for (const auto& user : users) {
//         file << user.getID() << "," << user.getLatitude() << "," << user.getLongitude() << endl;
//     }
//     file.close();
//     return 0;
// }

//-------------------------------------------- Constructors - Destructor
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
