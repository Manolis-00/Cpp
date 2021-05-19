#ifndef EXERCISE_4_1_APPSYSTEM_H
#define EXERCISE_4_1_APPSYSTEM_H

#include "Application.h"
#include "GameApp.h"
#include "OfficeApp.h"
#include <cstdlib>
#include <iostream>
#include <typeinfo>

using namespace std;


#endif //EXERCISE_4_1_APPSYSTEM_H

class AppSystem
{
private:
    vector<Application> applications;
public:
    AppSystem();
    void addApplication(Application &applicationToAdd);
    void addCreatorsAndRatings(Application &applicationToAdd, UserRating &feature, ApplicationCreator &creatorFeatures);
    const vector<Application> &getApplications() const;
    int getTotalApplications();
    Application getCurrentApplication(int index);
    void showData(Application &application);

};