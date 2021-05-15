#ifndef EXERCISE_4_MAINAPP_H
#define EXERCISE_4_MAINAPP_H

#pragma once
#include <iostream>
#include <string>
#include "userRating.h"
#include "appCreator.h"

using namespace std;

//#define THREE 3

#endif //EXERCISE_4_MAINAPP_H

class mainApp
{
protected:
    string appID;
    string appName;
    float minCompatibleOSVersion;
    string creator[3];
    userRating rating[3];
    float price;
public:
    mainApp(string, string, float, float, userRating &ob, appCreator &right);
    void setRating(userRating &ob);
};