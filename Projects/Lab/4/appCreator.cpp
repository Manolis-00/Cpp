#include "appCreator.h"

appCreator::appCreator(string ID, string name, string email)
{
    creatorID =ID;
    creatorName = name;
    creatorEmail = email;
}

string appCreator::getCreatorID() const
{
    return creatorID;
}

string appCreator::getCreatorName() const
{
    return creatorName;
}

string appCreator::getCreatorEmail() const
{
    return creatorEmail;
}
