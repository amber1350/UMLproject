#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include "models/Account.h"
#include "models/Agent.h"
#include "models/Attribute.h"
#include "models/Measurement.h"
#include "models/Provider.h"
#include "models/User.h"
#include "models/Sensor.h"
#include "models/Cleaner.h"
#include "dataaccess/DataAccess.h"
#include "management/SensorManagement.h"
#include "management/DataManagement.h"

class MainClass {
public:
    MainClass();
    void Run();
    const std::vector<Measurement>& getMeasurements() const;
    const std::vector<Sensor>& getSensors() const;
    const std::vector<Attribute>& getAttributes() const;
    const std::vector<Cleaner>& getCleaners() const;

private:
    std::vector<Measurement> measurements;
    std::vector<Sensor> sensors;
    std::vector<Attribute> attributes;
    std::vector<Cleaner> cleaners;
};

#endif // MAIN_H
