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
    double price;
    double starsAverage;

public:
    friend class AppSystem;

    Application(char *applicationId,
                const string &applicationName,
                const string &minimumCompatibleOsVersion,
                double price);

    Application(char *applicationId,
                const string &applicationName,
                const string &minimumCompatibleOsVersion,
                UserRating &userRating,
                ApplicationCreator &applicationCreator,
                double price);

    virtual void showData();

    virtual void showDataToFile();

    virtual void printRatings();

    virtual void printRatingsToFile();

    virtual void printCreators();

    virtual void printCreatorsToFile();

    void addUserRating(UserRating &userRating);

    void addApplicationCreator(ApplicationCreator &applicationCreator);

    float getStars(Application &application);

    void setStarsAverage();
};