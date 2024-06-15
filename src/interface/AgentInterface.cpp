/*************************************************************************
                           AgentInterface  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <AgentInterface> (file AgentInterface.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- System Includes
#include <iostream>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "AgentInterface.h"
#include <limits>

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods
    
void AgentInterface::DisplayMenu(const vector<Cleaner>& cleaners, const vector<Sensor>& sensors, const vector<Measurement>& measurements) {
    bool running = true;
    while (running) {
        cout << "====== Agent Menu ======" << endl;
        cout << "1. Monitor Sensor" << endl;
        cout << "2. Monitor Cleaner" << endl;
        cout << "3. Monitor Individual" << endl;
        cout << "4. Generate Mean" << endl;
        cout << "5. Calculate Air Quality " << endl;
        cout << "6. Rank Sensor" << endl;
        cout << "7. Logout" << endl;
        cout << "========================" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                MonitorSensor(sensors, measurements);
                break;
            case 2:
                MonitorCleaner(cleaners,sensors,measurements );
                break;
            case 3:
                MonitorIndividual(sensors,measurements);
                break;
            case 4:
                GenerateMean(sensors, measurements);
                break;
            case 5:
                CalculateAirQuality(sensors, measurements);
                break;
            case 6:
                RankSensor();                
                break;
            case 7:
                running = false;
                Logout();
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

void AgentInterface::MonitorSensor(const vector<Sensor>& sensors, const vector<Measurement>& measurements) {
    string sensorID;
    cout << "Enter Sensor ID to monitor: ";
    cin >> sensorID;
    cout << "Monitoring Sensor " << sensorID << "..." << endl;

    int random_number = rand() % 2;
    if (random_number == 0) {
        cout << "The sensor appears to be functioning correctly !" << endl;
    } else {
        cout << "The sensor appears to be malfunctioning..." << endl;
    }

}

void AgentInterface::MonitorCleaner(const vector<Cleaner>& cleaners, const vector<Sensor>& sensors, const vector<Measurement>& measurements) {
    string cleanerID;
    cout << "Enter Cleaner ID to monitor: ";
    cin >> cleanerID;
    cout << "Monitoring Cleaner " << cleanerID << "..." <<endl;
    cout << "This cleaner appears to have cleaned a radius of 2km" <<endl;
}

void AgentInterface::MonitorIndividual(const vector<Sensor>& sensors, const vector<Measurement>& measurements) {
    string individualID;
    cout << "Enter Individual ID to monitor: ";
    cin >> individualID;
    cout << "Monitoring Individual " << individualID << "..." <<endl;
    int random_number = rand() % 2;
    if (random_number == 0) {
        cout << "This user's behavior has been classified reliable!" << endl;
    } else {
        cout << "This user's behavior has been classified unreliable..." << endl;
    }
}

void AgentInterface::GenerateMean(const std::vector<Sensor>& sensors, const std::vector<Measurement>& measurements) {
    float latitude, longitude, radius;
    string startTime, endTime;

    cout << "Enter center latitude: ";
    cin >> latitude;
    
    cout << "Enter center longitude: ";
    cin >> longitude;
    
    cout << "Enter radius (km): ";
    cin >> radius;
    
    cout << "Do you wish to generate mean for " << endl << "1. A period of time" << endl << "2. A specific moment" << endl;
           
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {        
        case 1:
            cout << "Enter start time (YYYY-MM-DD HH:MM:SS): ";
            getline(cin, startTime);

            cout << "Enter end time (YYYY-MM-DD HH:MM:SS): ";
            getline(cin, endTime);

            cout << "endTime:"<< endTime << endl;
            cout << "startTime:"<< startTime << endl;
            break;
        case 2:
            cout << "Enter timestamp (YYYY-MM-DD HH:MM:SS): ";
            cin.ignore(); // Clear the input buffer
            getline(cin, startTime);
            endTime = startTime;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
            return;
    }

    cout << "Generating Mean..." << endl;

    DataManagement dataManagement;
    float mean = dataManagement.GenerateMean(sensors, measurements, radius, {latitude, longitude}, startTime, endTime);

    if (mean != -1) {
        cout << "Mean Air Quality Index: " << mean << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }
}

void AgentInterface::CalculateAirQuality(const std::vector<Sensor>& sensors, const std::vector<Measurement>& measurements) {
    float latitude, longitude;
    string timestamp;
    
    cout << "Enter position latitude: ";
    cin >> latitude;
    
    cout << "Enter position longitude: ";
    cin >> longitude;
    
    cout << "Enter timestamp (YYYY-MM-DD HH:MM:SS): ";
    cin.ignore(); // Clear the input buffer
    getline(cin, timestamp);

    cout << "Measuring Air Quality..." << endl;
    DataManagement dataManagement;
    float airQuality = dataManagement.MeasureAirQuality(measurements, sensors, {latitude, longitude}, timestamp);

    if (airQuality != -1) {
        cout << "Air Quality Index at position (" << latitude << ", " << longitude << ") at " << timestamp << " is " << airQuality << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }
}

void AgentInterface::RankSensor() {
    cout << "Ranking sensors based on similarity" << endl;
    string sensorID;
    cout << "Enter your reference Sensor ID : ";
    cout << "Ranking sensors..." <<endl;
}

void AgentInterface::Logout() {
    cout << "Logging out" << endl;
}

//-------------------------------------------- Constructors - Destructor

AgentInterface::AgentInterface()
{
#ifdef MAP
    cout << "Call to the constructor of <AgentInterface>" << endl;
#endif
} //----- End of AgentInterface

AgentInterface::~AgentInterface()
{
#ifdef MAP
    cout << "Call to the destructor of <AgentInterface>" << endl;
#endif
} //----- End of ~AgentInterface
