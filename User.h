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
    bool evaluateReliability(const std::vector<std::string>& measurements);

//-------------------------------------------- Constructors - Destructor
    User();

    virtual ~User();

//------------------------------------------------------------------ PRIVATE

protected:

//----------------------------------------------------- Protected Attributes
    int score;
    bool isReliable;
};

#endif // USER_H