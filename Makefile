DMAP_FLAG :=
ifeq ($(DMAP),1)
    DMAP_FLAG := -D DMAP
endif

main : main.o Account.o Agent.o Attribute.o	Measurement.o Provider.o Sensor.o User.o DataAccess.o
	g++ -o main main.o Account.o Agent.o Attribute.o Measurement.o Provider.o Sensor.o User.o DataAccess.o

test : main_measurements.o DataAccess.o Attribute.o Measurement.o Sensor.o
	g++ -o test main_measurements.o DataAccess.o Attribute.o Measurement.o Sensor.o

main.o : main.cpp 
	g++ $(DMAP_FLAG) -c main.cpp 

main_measurements.o : main_measurements.cpp
	g++ $(DMAP_FLAG) -c main_measurements.cpp

Account.o : Account.cpp
	g++ $(DMAP_FLAG) -c Account.cpp

Agent.o : Agent.cpp	
	g++ $(DMAP_FLAG) -c Agent.cpp

Attribute.o : Attribute.cpp	
	g++ $(DMAP_FLAG) -c Attribute.cpp

Measurement.o : Measurement.cpp
	g++ $(DMAP_FLAG) -c Measurement.cpp

Provider.o : Provider.cpp
	g++ $(DMAP_FLAG) -c Provider.cpp

Sensor.o : Sensor.cpp
	g++ $(DMAP_FLAG) -c Sensor.cpp

User.o : User.cpp
	g++ $(DMAP_FLAG) -c User.cpp

DataAccess.o : DataAccess.cpp
	g++ $(DMAP_FLAG) -c DataAccess.cpp

clean :
	rm main main.o Account.o Agent.o Attribute.o Measurement.o Provider.o Sensor.o User.o SClass.o DataAccess.o