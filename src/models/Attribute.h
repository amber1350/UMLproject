/*************************************************************************
                           Attribute  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Class Interface of <Attribute> (file Attribute.h) -----------------------
#if ! defined ( Attribute_H )
#define Attribute_H

//------------------------------------------------------- Used Interfaces
#include <string>
using namespace std; 
//------------------------------------------------------------- Constants

//------------------------------------------------------------------Types

//-----------------------------------------------------------------------
// Role of the class <Attribute>
//
//
//------------------------------------------------------------------------

class Attribute 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public Methods

//------------------------------------------------- Operator Overloading
// Overloaded << operator
    friend ostream& operator<<(ostream& os, const Attribute& a);

//-------------------------------------------- Constructors - Destructor
    Attribute(const string& id, const string& unit, const string& desc);    
    // Usage:
    //
    // Contract:
    //
    
    virtual ~Attribute ( );
    // Usage:
    //
    // Contract:
    //
    
//-------------------------------------------- Getters
    string getAttributeID() const;
    string getUnit() const;
    string getDescription() const;


//------------------------------------------------------------------ PRIVATE

protected:
//----------------------------------------------------- Protected Methods

//----------------------------------------------------- Protected Attributes
    string attributeID;
    string unit;
    string description;  
};

//-------------------------------- Other definitions depending on <Attribute>

#endif // Attribute_H
