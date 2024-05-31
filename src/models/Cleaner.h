/*************************************************************************
                           Cleaner  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Class Interface of <Cleaner> (file Cleaner.h) -----------------------
#ifndef Cleaner_H
#define Cleaner_H


//------------------------------------------------------- Used Interfaces
#include <string>
using namespace std;

//------------------------------------------------------------- Constants

//------------------------------------------------------------------Types

//-----------------------------------------------------------------------
// Role of the class <Measurement>
//
//
//------------------------------------------------------------------------

class Cleaner 
{
//----------------------------------------------------------------- PUBLIC
public:
//------------------------------------------------- Operator Overloading
    // Overloaded << operator
    friend ostream& operator<<(ostream& os, const Cleaner& c);

//-------------------------------------------- Constructors - Destructor
    // Constructor
    Cleaner(const string& id, float lat, float lon, const string& start, const string& stop);

    virtual ~Cleaner ( );

//-------------------------------------------- Getters
    string GetCleanerID() const;
    float GetLatitude() const;
    float GetLongitude() const;
    string GetTimestampStart() const;
    string GetTimestampStop() const;


//------------------------------------------------------------------ PRIVATE

protected:
//----------------------------------------------------- Protected Methods

//----------------------------------------------------- Protected Attributes
    string CleanerID;
    float Latitude;
    float Longitude;
    string TimestampStart;
    string TimestampStop;

};

//-------------------------------- Other definitions depending on <Cleaner>



#endif // Cleaner_H
