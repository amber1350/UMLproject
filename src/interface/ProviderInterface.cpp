/*************************************************************************
                           ProviderInterface  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <ProviderInterface> (file ProviderInterface.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- System Includes
#include <iostream>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "ProviderInterface.h"

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods

void ProviderInterface::DisplayMenu(const vector<Cleaner>& cleaners, const vector<Sensor>& sensors, const vector<Measurement>& measurements)
{
    bool running = true;
    while (running) {
        cout << "====== Provider Menu ======" << endl;
        cout << "1. Register Cleaner" << endl;
        cout << "2. Monitor Cleaner" << endl;
        cout << "3. Logout" << endl;
        cout << "========================" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                RegisterCleaner(cleaners);
                break;
            case 2:
                MonitorCleaner(cleaners, sensors, measurements);
                break;          
            case 3:
                running = false;
                Logout();
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

void ProviderInterface::RegisterCleaner(const vector<Cleaner>& cleaners) {
    float latitude, longitude;
    string startTime, endTime;
    cout << "You are about to register a cleaner" << endl;
    cout << "Please fill out the following fields : " << endl;    
    cout << "Enter latitude (decimal format): ";
    cin >> latitude;    
    cout << "Enter longitude (decimal format) : ";
    cin >> longitude;
    cout << "Enter start time (YYYY-MM-DD HH:MM:SS): ";
    cin.ignore(); // Clear the input buffer
    getline(cin, startTime);
    cout << "Enter end time (YYYY-MM-DD HH:MM:SS): ";
    cin.ignore(); // Clear the input buffer
    getline(cin, endTime);
    cout << "Registering cleaner...." << endl;
}


void ProviderInterface::MonitorCleaner(const vector<Cleaner>& cleaners, const vector<Sensor>& sensors, const vector<Measurement>& measurements) {    
    string cleanerID;
    cout << "Enter Cleaner ID to monitor: ";
    cin >> cleanerID;
    cout << "Monitoring Cleaner " << cleanerID << "..." <<endl;
    cout << "This cleaner appears to have cleaned a radius of 2km" <<endl;
}


void ProviderInterface::Logout() {
    cout << "Logging out" << endl;
}

//-------------------------------------------- Constructors - Destructor
ProviderInterface::ProviderInterface()
{
#ifdef MAP
    cout << "Call to the constructor of <ProviderInterface>" << endl;
#endif
} //----- End of ProviderInterface

ProviderInterface::~ProviderInterface()
{
#ifdef MAP
    cout << "Call to the destructor of <ProviderInterface>" << endl;
#endif
} //----- End of ~ProviderInterface
