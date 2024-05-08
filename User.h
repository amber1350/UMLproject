//---------- Class Interface of <User> (file User.h) -----------------------
#if ! defined ( USER_H )
#define USER_H

//------------------------------------------------------- Used Interfaces
#include "Account.h"

class User : public Account
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public Methods
    getScore ( );

//-------------------------------------------- Constructors - Destructor
    User ( );

    virtual ~User ( );

//------------------------------------------------------------------ PRIVATE

protected:

//----------------------------------------------------- Protected Attributes
    int score;
};

#endif // USER_H
