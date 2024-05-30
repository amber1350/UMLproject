test : main_measurements.o DataAccess.o Attribute.o Measurement.o Sensor.o
	g++ -o test main_measurements.o DataAccess.o Attribute.o Measurement.o Sensor.o

main_measurements.o : main_measurements.cpp
	g++ -c main_measurements.cpp

DataAccess.o : DataAccess.cpp
	g++ -c DataAccess.cpp

Attribute.o : Attribute.cpp
	g++ -c Attribute.cpp

Measurement.o : Measurement.cpp
	g++ -c Measurement.cpp

Sensor.o : Sensor.cpp
	g++ -c Sensor.cpp