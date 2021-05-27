#include "UserRating.h"

UserRating::UserRating()
{

}

UserRating::UserRating(double userStars, const string &userName, const string &userComment)
{
    this->userStars = userStars;
    this->userName = userName;
    this->userComment = userComment;
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

void UserRating::readRatingFromFile(string filePath)
{
    char buffer[300];
    ifstream ratingFile;

    ratingFile.open(filePath);

    if(!ratingFile.is_open())
    {
        cout<<"Error opening file";
        exit(1);
    }

    string firstLine;
    char* pEnd;
    while (!ratingFile.eof())
    {
        getline(ratingFile, firstLine, '\n');
        getline(ratingFile, userName, '\n');
        getline(ratingFile, userComment, '\n');
    }

    userStars = stod(firstLine);

}

void UserRating::showData()
{
    cout<<"User Rating: "<<userStars<<"\n"<<"User Name: "<<userName<<"\n"<<"User Comment: "<<userComment<<"\n"<<endl;
}