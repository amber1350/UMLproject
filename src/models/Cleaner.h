//---------- Class Interface of <Provider> (file Provider.h) -----------------------
#if ! defined ( CLEANER_H )
#define CLEANER_H

//------------------------------------------------------- Used Interfaces
#include "Account.h"

class Cleaner : public Account
{
//----------------------------------------------------------------- PUBLIC

public:
//-------------------------------------------- Constructors - Destructor
    Cleaner ( );

    virtual ~Cleaner ( );
};

#endif // CLEANER_H
