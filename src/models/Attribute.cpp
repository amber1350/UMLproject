/*************************************************************************
                           Attribute  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <Attribute> (file Attribute.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- System Includes
using namespace std;
#include <iostream>

//------------------------------------------------------ Personal Includes
#include "Attribute.h"

//------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods

//-------------------------------------------- Constructors - Destructor
Attribute::Attribute(const string& id, const string& unit, const string& desc)
    : attributeID(id), unit(unit), description(desc)
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the constructor of <Attribute>" << endl;
#endif
} //----- End of Attribute

Attribute::~Attribute ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the destructor of <Attribute>" << endl;
#endif
} //----- End of ~Attribute

// Getters
string Attribute::getAttributeID() const {
    return attributeID;
}

string Attribute::getUnit() const {
    return unit;
}

string Attribute::getDescription() const {
    return description;
}

//------------------------------------------------------------------ PRIVATE

//----------------------------------------------------- Protected Methods
