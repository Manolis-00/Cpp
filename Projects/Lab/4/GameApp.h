#ifndef EXERCISE_4_1_GAMEAPP_H
#define EXERCISE_4_1_GAMEAPP_H

#pragma once
#include "Application.h"

#endif //EXERCISE_4_1_GAMEAPP_H

class GameApp:public Application
{
private:
    bool onLine;
    string gameCategory;
    friend class AppSystem;

public:
    GameApp(char *applicationId,
            const string &applicationName,
            const string &minimumCompatibleOsVersion,
            double price,
            bool onLine,
            const string &gameCategory);

    GameApp(char *applicationId,
            const string &applicationName,
            const string &minimumCompatibleOsVersion,
            UserRating &userFeature,
            ApplicationCreator &creatorFeatures,
            double price,
            bool onLine,
            const string &gameCategory);

    void showDataToFile() override;

    void showData() override;
};