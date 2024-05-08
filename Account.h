//---------- Class Interface of <Account> (file Account.h) -----------------------
#if ! defined ( ACCOUNT_H )
#define ACCOUNT_H

using namespace std;

//------------------------------------------------------- Used Interfaces
#include <string>


class Account
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public Methods
    string getID ( );

    string getUsername ( );

    string getPassword ( );

//-------------------------------------------- Destructor
    virtual ~Account ( );

//------------------------------------------------------------------ PRIVATE

protected:
//-------------------------------------------- Constructors (abstract class)
    Account ( );

//----------------------------------------------------- Protected Attributes
    string id;
    string username;
    string password;
};

#endif // ACCOUNT_H
