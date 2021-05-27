#ifndef EXERCISE_4_1_USERRATING_H
#define EXERCISE_4_1_USERRATING_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#endif //EXERCISE_4_1_USERRATING_H

class UserRating
{
private:
    double userStars;
    string userName;
    string userComment;
    friend class AppSystem;

public:
    UserRating();

    UserRating(double userStars,
               const string &userName,
               const string &userComment);

    float getUserStars() const;

    string getUserName() const;

    string getUserComment() const;

    void readRatingFromFile(string filePath);

    void showData();
};