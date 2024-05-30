//---------- Realisation of the class <Provider> (file Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE
 
//-------------------------------------------------------- System Includes
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Personal Includes
#include "Cleaner.h"

//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------------- Public Methods
Cleaner::Cleaner ( )
{
#ifdef MAP
    cout << "Call to the constructor of <Cleaner>" << endl;
#endif
} //----- End of Cleaner


Cleaner::~Cleaner ( )
{
#ifdef MAP
    cout << "Call to the destructor of <Cleaner>" << endl;
#endif
} //----- End of ~Cleaner