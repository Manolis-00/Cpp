#ifndef EXERCISE_4_1_USERRATING_H
#define EXERCISE_4_1_USERRATING_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#endif //EXERCISE_4_1_USERRATING_H

class UserRating
{
private:
    float userStars;
    string userName;
    string userComment;
    friend class AppSystem;

public:
    UserRating(float userStars,
               const string &userName,
               const string &userComment);

    float getUserStars() const;

    string getUserName() const;

    string getUserComment() const;

    void showData();
};