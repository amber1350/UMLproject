#include "Main.h"
#include "interface/AgentInterface.h"
#include "interface/ProviderInterface.h"
#include "interface/UserInterface.h"

#include <iostream>

MainClass::MainClass() {
    DataAccess dataAccess;
    // Reading measurements    
    int measurementResult = dataAccess.readMeasurementData("measurements.csv", measurements);
    if (measurementResult == 0) {
        std::cout << "Measurement data loaded successfully." << std::endl;
    } else {
        std::cout << "Failed to load measurement data." << std::endl;
    }
    std::cout << std::endl;

    // Reading sensors
    int sensorResult = dataAccess.readSensorData("sensors.csv", sensors);
    if (sensorResult == 0) {
        std::cout << "Sensor data loaded successfully." << std::endl;
        // Setting Measurements
        for (Sensor& sensor : sensors) {
            sensor.setMeasurements(measurements);
        }
    } else {
        std::cout << "Failed to load sensor data." << std::endl;
    }
    std::cout << std::endl;

    // Reading attributes
    int attributeResult = dataAccess.readAttributeData("attributes.csv", attributes);
    if (attributeResult == 0) {
        std::cout << "Attribute data loaded successfully." << std::endl;
    } else {
        std::cout << "Failed to load attribute data." << std::endl;
    }
    std::cout << std::endl;

    // Reading cleaners    
    int cleanerResult = dataAccess.readCleanerData("cleaners.csv", cleaners);
    if (cleanerResult == 0) {
        std::cout << "Cleaner data loaded successfully." << std::endl;
    } else {
        std::cout << "Failed to load cleaner data." << std::endl;
    }
    std::cout << std::endl;
}

const std::vector<Measurement>& MainClass::getMeasurements() const {
    return measurements;
}

const std::vector<Sensor>& MainClass::getSensors() const {
    return sensors;
}

const std::vector<Attribute>& MainClass::getAttributes() const {
    return attributes;
}

const std::vector<Cleaner>& MainClass::getCleaners() const {
    return cleaners;
}

void MainClass::Run() { 
    string username, password, userType;
    int choice;
    cout << "Enter your user type :" << endl;
    cout << "1. Government Agent" << endl;
    cout << "2. Provider" << endl;
    cout << "3. Private Individual" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            // Login logic 
            cout << "Login successful!" << endl;
            // Create an instance of AgentInterface
            AgentInterface agentInterface;
            // Display the menu
            agentInterface.DisplayMenu(cleaners,sensors, measurements);
            break;
        }
        case 2: {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            // Login logic 
            cout << "Login successful!" << endl;
            ProviderInterface providerInterface;
            // Display the menu
            providerInterface.DisplayMenu(cleaners,sensors, measurements);        
            break;
        }
        case 3: {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            // Login logic 
            cout << "Login successful!" << endl;
            UserInterface userInterface;
            // Display the menu
            userInterface.DisplayMenu(sensors);
            break;
        }
        case 4:
            cout << "Goodbye" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }   
}

int main() {
    MainClass mainClass;
    mainClass.Run();
    return 0;
}