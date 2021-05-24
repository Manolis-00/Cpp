#ifndef EXERCISE_4_1_APPSYSTEM_H
#define EXERCISE_4_1_APPSYSTEM_H

#include "Application.h"
#include "GameApp.h"
#include "OfficeApp.h"
#include <cstdlib>
#include <iostream>
#include <type_traits>

using namespace std;


#endif //EXERCISE_4_1_APPSYSTEM_H

class AppSystem
{
private:
    vector<Application*> applications;
    vector<Application*> freeOfficeApps;
    vector<Application*> goodGames;

public:
    AppSystem();

    void addApplication(Application &applicationToAdd);

    void addCreatorsAndRatings(Application &applicationToAdd,
                               UserRating &feature,
                               ApplicationCreator &creatorFeatures);

    void setApplicationId(Application &applicationID, char *newApplicationID);

    void setApplicationName(Application &application, string newApplicationName);

    void setMinimumCompatibleOSVersion(Application &application, string newMinimumCompatibleOSVersion);

    void setPrice(Application &application, float newPrice);

    void setCreatorDetails(Application &application, ApplicationCreator &newCreatorDetails);

    void addUserRatings(Application &application, UserRating &newUserRatings);

    void setOnLine(GameApp &gameApp, bool newOnLine);

    void setGameCategory(GameApp &gameApp, string newGameCategory);

    void deleteAppType(OfficeApp &officeApp, int index);

    void addAppType(OfficeApp &officeApp, string newType);

    void setCreatorID(ApplicationCreator &applicationCreator, string newCreatorID);

    void setCreatorName(ApplicationCreator &applicationCreator, char *newCreatorName);

    void setCreatorEmail(ApplicationCreator &applicationCreator, string newEmail);

    void setStars(UserRating &userRating, float newStars);

    void setUserName(UserRating &userRating, string newUserName);

    void setComment(UserRating &userRating, string comment);

    void deleteMaliciousCreator(string applicationCreator);

    void showData();
};