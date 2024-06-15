/*************************************************************************
                           UserInterface  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <UserInterface> (file UserInterface.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- System Includes
#include <iostream>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "UserInterface.h"

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods

void UserInterface::DisplayMenu(const vector<Sensor>& sensors)
{
    bool running = true;
    while (running) {
        cout << "====== Private Individual Menu ======" << endl;
        cout << "1. Register Sensor" << endl;
        cout << "2. View Contribution Point" << endl;
        cout << "3. Logout" << endl;
        cout << "========================" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                RegisterSensor(sensors);
                break;
            case 2:
                ViewContributionPoint();
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

void UserInterface::RegisterSensor(const vector<Sensor>& sensors) {
    float latitude, longitude;
    cout << "You are about to register a sensor" << endl;
    cout << "Please fill out the following fields : " << endl;    
    cout << "Enter latitude (decimal format): ";
    cin >> latitude;    
    cout << "Enter longitude (decimal format) : ";
    cin >> longitude;
    cout << "Registering sensor...." << endl;
}


void UserInterface::ViewContributionPoint() {    
    cout << "You currently have 7 contribution points! " << endl; 
}


void UserInterface::Logout() {
    cout << "Logging out" << endl;
}

//-------------------------------------------- Constructors - Destructor
UserInterface::UserInterface()
{
#ifdef MAP
    cout << "Call to the constructor of <UserInterface>" << endl;
#endif
} //----- End of UserInterface

UserInterface::~UserInterface()
{
#ifdef MAP
    cout << "Call to the destructor of <UserInterface>" << endl;
#endif
} //----- End of ~UserInterface
