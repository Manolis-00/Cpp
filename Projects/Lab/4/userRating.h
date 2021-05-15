#ifndef EXERCISE_4_USERRATING_H
#define EXERCISE_4_USERRATING_H

#pragma once
#include <iostream>
#include <string>
#include "mainApp.h"

using namespace std;

#endif //EXERCISE_4_USERRATING_H

class mainApp;

class userRating
{
private:
    float stars;
    string userName;
    string comment;
public:
    userRating(float, string, string);
    float getStars()const;
    string getUserName()const;
    string getComment()const;
    friend void mainApp::setRating(userRating &ob);
};