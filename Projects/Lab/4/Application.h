#ifndef EXERCISE_4_1_APPLICATION_H
#define EXERCISE_4_1_APPLICATION_H

#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include "UserRating.h"
#include "ApplicationCreator.h"

using namespace std;

#endif //EXERCISE_4_1_APPLICATION_H

class Application
{
protected:
    char *applicationId;
    string applicationName;
    string minimumCompatibleOSVersion;
    vector<ApplicationCreator> creatorDetails;
    vector<UserRating> userRatings;
    float price;
    float starsAverage;

public:
    friend class AppSystem;

    Application(char *applicationId,
                const string &applicationName,
                const string &minimumCompatibleOsVersion,
                float price);

    Application(char *applicationId,
                const string &applicationName,
                const string &minimumCompatibleOsVersion,
                UserRating &userRating,
                ApplicationCreator &applicationCreator,
                float price);

    virtual void showData();

    virtual void printRatings();

    virtual void printCreators();

    void addUserRating(UserRating &userRating);

    void addApplicationCreator(ApplicationCreator &applicationCreator);

    float getStars(Application &application);

    void setStarsAverage(Application &application);

};