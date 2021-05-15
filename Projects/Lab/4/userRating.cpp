#include "userRating.h"

userRating::userRating(float stars, string userName, string comment)
{
    this->stars = stars;
    this->userName = userName;
    this->comment = comment;
}

float userRating::getStars() const
{
    return stars;
}

string userRating::getUserName() const
{
    return userName;
}

string userRating::getComment() const
{
    return comment;
}
