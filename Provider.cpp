//---------- Realisation of the class <Provider> (file Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE
 
//-------------------------------------------------------- System Includes
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "Provider.h"

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods
Provider::Provider ( )
{
#ifdef MAP
    cout << "Call to the constructor of <Provider>" << endl;
#endif
} //----- End of Provider


Provider::~Provider ( )
{
#ifdef MAP
    cout << "Call to the destructor of <Provider>" << endl;
#endif
} //----- End of ~Provider