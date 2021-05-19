#include "UserRating.h"

UserRating::UserRating(float userStars, const string &userName, const string &userComment)
{
    this->userStars = userStars;
    this->userName = userName;
    this->userComment = userComment;
}

void UserRating::showData()
{
    cout<<"User Rating: "<<userStars<<"\n"<<"User Name: "<<userName<<"\n"<<"User Comment: "<<userComment<<"\n"<<endl;
}

float UserRating::getUserStars() const
{
    return userStars;
}

string UserRating::getUserName() const
{
    return userName;
}

string UserRating::getUserComment() const
{
    return userComment;
}


