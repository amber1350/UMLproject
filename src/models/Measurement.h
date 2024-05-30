/*************************************************************************
                           Measurement  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Class Interface of <Measurement> (file Measurement.h) -----------------------
#if ! defined ( MEASUREMENT_H )
#define MEASUREMENT_H

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

class Measurement 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public Methods

//------------------------------------------------- Operator Overloading
    Measurement & operator = ( const Measurement & unMeasurement );
    // Usage:
    //
    // Contract:
    //


//-------------------------------------------- Constructors - Destructor
    Measurement(const string & timestamp, const string & sensorID, const string & attributeID, float value);
    // Usage:
    //
    // Contract:
    //
    
    virtual ~Measurement ( );
    // Usage:
    //
    // Contract:
    //
//-------------------------------------------- Getters
    const std::string & GetTimestamp() const;
    const std::string & GetAttributeID() const;
    float GetValue() const;

//------------------------------------------------------------------ PRIVATE

protected:
//----------------------------------------------------- Protected Methods

//----------------------------------------------------- Protected Attributes
    string timestamp;    
    string sensorID;
    string attributeID;
    float value;
};

//-------------------------------- Other definitions depending on <Measurement>

#endif // MEASUREMENT_H
