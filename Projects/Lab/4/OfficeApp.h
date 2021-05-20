#ifndef EXERCISE_4_1_OFFICEAPP_H
#define EXERCISE_4_1_OFFICEAPP_H

#pragma once
#include "Application.h"
//#include "vector"

#endif //EXERCISE_4_1_OFFICEAPP_H

class OfficeApp:public Application
{
private:
    vector<string> appTypes;
    friend class AppSystem;

public:
    OfficeApp(char *applicationId,
              const string &applicationName,
              const string &minimumCompatibleOsVersion,
              float price,
              const vector<string> &appTypes);

    OfficeApp(char *applicationId,
              const string &applicationName,
              const string &minimumCompatibleOsVersion,
              UserRating &userFeature,
              ApplicationCreator &creatorFeatures,
              float price,
              const vector<string> &appTypes);

    void showData() override;
};