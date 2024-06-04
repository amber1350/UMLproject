//---------- Class Interface of <User> (file User.h) -----------------------
#if ! defined ( USER_H )
#define USER_H

//------------------------------------------------------- Used Interfaces
#include "Account.h"
#include <vector>
#include <string>

class User : public Account
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Public Methods
    int getScore();
    void setScore();

//-------------------------------------------- Constructors - Destructor
    User(const string& username, const string& password, const string& userID);
    virtual ~User();

//------------------------------------------------------------------ PRIVATE

protected:

//----------------------------------------------------- Protected Attributes
    int score;
};

#endif // USER_H