DMAP_FLAG :=

ifeq ($(DMAP),1)
    DMAP_FLAG := -D DMAP
endif

all: main

main: main.o DataAccess.o Attribute.o Measurement.o Sensor.o Cleaner.o SensorManagement.o DataManagement.o
	g++ -std=c++17 -o test main.o DataAccess.o Attribute.o Measurement.o Sensor.o Cleaner.o SensorManagement.o DataManagement.o

main.o: main.cpp
	g++ -std=c++17 $(DMAP_FLAG) -c main.cpp

Account.o: models/Account.cpp
	g++ -std=c++17 $(DMAP_FLAG) -c models/Account.cpp

Agent.o: models/Agent.cpp
	g++ -std=c++17 $(DMAP_FLAG) -c models/Agent.cpp

Attribute.o: models/Attribute.cpp
	g++ -std=c++17 $(DMAP_FLAG) -c models/Attribute.cpp

Measurement.o: models/Measurement.cpp
	g++ -std=c++17 $(DMAP_FLAG) -c models/Measurement.cpp

Provider.o: models/Provider.cpp
	g++ -std=c++17 $(DMAP_FLAG) -c models/Provider.cpp

Cleaner.o: models/Cleaner.cpp
	g++ -std=c++17 $(DMAP_FLAG) -c models/Cleaner.cpp

Sensor.o: models/Sensor.cpp
	g++ -std=c++17 $(DMAP_FLAG) -c models/Sensor.cpp

User.o: models/User.cpp
	g++ -std=c++17 $(DMAP_FLAG) -c models/User.cpp

DataAccess.o: dataaccess/DataAccess.cpp
	g++ -std=c++17 $(DMAP_FLAG) -c dataaccess/DataAccess.cpp

SensorManagement.o: management/SensorManagement.cpp
	g++ -std=c++17 $(DMAP_FLAG) -c management/SensorManagement.cpp

DataManagement.o: management/DataManagement.cpp
	g++ -std=c++17 $(DMAP_FLAG) -c management/DataManagement.cpp

clean:
	rm -f *.o main
