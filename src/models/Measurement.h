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
    // Overloaded << operator
    friend ostream& operator<<(ostream& os, const Measurement& m);


//-------------------------------------------- Constructors - Destructor
    Measurement(const string & timestamp, const string & sensorID, const string & attributeID, float value);
        
    virtual ~Measurement ( );
    
//-------------------------------------------- Getters
    const string & getTimestamp() const;
    const string & getSensorID() const;
    const string & getAttributeID() const;
    float getValue() const;

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
