/*************************************************************************
                           Xxx  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/

//---------- Realisation of the class <Xxx> (file Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- System Includes
using namespace std;
#include <iostream>

//------------------------------------------------------ Personal Includes
#include "Xxx.h"

//------------------------------------------------------------- Constants

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods
// type Xxx::Method ( list of parameters )
// Algorithm:
//
//{
//} //----- End of Method


//------------------------------------------------- Operator Overloading
Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithm:
//
{
} //----- End of operator =


//-------------------------------------------- Constructors - Destructor
Xxx::Xxx ( const Xxx & unXxx )
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the copy constructor of <Xxx>" << endl;
#endif
} //----- End of Xxx (copy constructor)


Xxx::Xxx ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the constructor of <Xxx>" << endl;
#endif
} //----- End of Xxx


Xxx::~Xxx ( )
// Algorithm:
//
{
#ifdef MAP
    cout << "Call to the destructor of <Xxx>" << endl;
#endif
} //----- End of ~Xxx


//------------------------------------------------------------------ PRIVATE

//----------------------------------------------------- Protected Methods
