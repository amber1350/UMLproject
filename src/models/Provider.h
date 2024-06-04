/*************************************************************************
                           Provider  -  Description
                             -------------------
    Start Date          : $DATE$
    Copyright           : (C) $YEAR$ by $AUTHOR$
    Email               : $EMAIL$
*************************************************************************/
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
    Provider(const string& username, const string& password, const string& providerID);

    virtual ~Provider ( );
};

#endif // PROVIDER_H
