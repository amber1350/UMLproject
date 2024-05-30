//---------- Class Interface of <Account> (file Account.h) -----------------------
#if ! defined ( ACCOUNT_H )
#define ACCOUNT_H

using namespace std;

//------------------------------------------------------- Used Interfaces
#include <string>


class Account
{
public:
    string getUsername ( );
    string getPassword ( );
    virtual ~Account ( );
protected:
    Account ( );
    string username;
    string password;
};

#endif // ACCOUNT_H
