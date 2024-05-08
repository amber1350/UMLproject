//---------- Class Interface of <Provider> (file Provider.h) -----------------------
#if ! defined ( PROVIDER_H )
#define PROVIDER_H

//------------------------------------------------------- Used Interfaces
#include "Account.h"

class Provider : public Account
{
//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructors - Destructor
    Provider ( );

    virtual ~Provider ( );
};

#endif // PROVIDER_H
