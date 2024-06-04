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
#include <string>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "AgentInterface.h"
#include "../management/DataManagement.h"
#include "../management/SensorManagement.h"

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods

void AgentInterface::DisplayMenu()
{
    bool running = true;
    while (running) {
        cout << "====== Agent Menu ======" << endl;
        cout << "1. Monitor Sensor" << endl;
        cout << "2. Monitor Cleaner" << endl;
        cout << "3. Monitor Individual" << endl;
        cout << "4. Generate Mean" << endl;
        cout << "5. Rank Sensor" << endl;
        cout << "6. Calculate Air Quality" << endl;
        cout << "7. Logout" << endl;
        cout << "========================" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                MonitorSensor();
                break;
            case 2:
                MonitorCleaner();
                break;
            case 3:
                MonitorIndividual();
                break;
            case 4:
                GenerateMean();
                break;
            case 5:
                RankSensor();
                break;
            case 6:
                CalculateAirQuality();
                break;
            case 7:
                running = false;
                Logout();
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
} //----- End of DisplayMenu

void AgentInterface::MonitorSensor()
{
    string sensorID;
    cout << "Enter Sensor ID to monitor: ";
    cin >> sensorID;
    cout << "Monitoring Sensor ID: " << sensorID << endl;
} //----- End of MonitorSensor

void AgentInterface::MonitorCleaner()
{
    string cleanerID;
    cout << "Enter Cleaner ID to monitor: ";
    cin >> cleanerID;
    cout << "Monitoring Cleaner ID: " << cleanerID << endl;
} //----- End of MonitorCleaner

void AgentInterface::MonitorIndividual()
{
    string individualID;
    cout << "Enter Individual ID to monitor: ";
    cin >> individualID;
    cout << "Monitoring Individual ID: " << individualID << endl;
} //----- End of MonitorIndividual

void AgentInterface::GenerateMean()
{
    float latitude, longitude, radius;
    string startTime, endTime;
    cout << "Enter center latitude: ";
    cin >> latitude;
    cout << "Enter center longitude: ";
    cin >> longitude;
    cout << "Enter radius (km): ";
    cin >> radius;
    cout << "Enter start time (YYYY-MM-DD HH:MM:SS): ";
    cin >> startTime;
    cout << "Enter end time (YYYY-MM-DD HH:MM:SS): ";
    cin >> endTime;

    DataManagement dataManagement;
    float mean = dataManagement.GenerateMean(sensors, measurements, radius, {latitude, longitude}, startTime, endTime);

    if (mean != -1) {
        cout << "Mean Air Quality Index: " << mean << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }
} //----- End of GenerateMean

void AgentInterface::RankSensor()
{
    cout << "Ranking sensors based on similarity" << endl;
    // Placeholder for actual sensor ranking logic
} //----- End of RankSensor

void AgentInterface::CalculateAirQuality()
{
    float latitude, longitude;
    string timestamp;
    cout << "Enter position latitude: ";
    cin >> latitude;
    cout << "Enter position longitude: ";
    cin >> longitude;
    cout << "Enter timestamp (YYYY-MM-DD HH:MM:SS): ";
    cin >> timestamp;

    DataManagement dataManagement;
    float airQuality = dataManagement.MeasureAirQuality(measurements, sensors, {latitude, longitude}, timestamp);

    if (airQuality != -1) {
        cout << "Air Quality Index at position (" << latitude << ", " << longitude << ") at " << timestamp << " is " << airQuality << endl;
    } else {
        cout << "No data available for the specified parameters." << endl;
    }
} //----- End of CalculateAirQuality

void AgentInterface::Logout()
{
    cout << "Logging out" << endl;
} //----- End of Logout

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
