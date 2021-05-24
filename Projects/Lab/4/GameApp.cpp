#include "GameApp.h"

GameApp::GameApp(char *applicationId,
                 const string &applicationName,
                 const string &minimumCompatibleOsVersion,
                 float price,
                 bool onLine,
                 const string &gameCategory)
        : Application(applicationId, applicationName, minimumCompatibleOsVersion, price)
{
    this->onLine = onLine;
    this->gameCategory = gameCategory;

}

GameApp::GameApp(char *applicationId,
                 const string &applicationName,
                 const string &minimumCompatibleOsVersion,
                 UserRating &userFeature,
                 ApplicationCreator &creatorFeatures,
                 float price,
                 bool onLine,
                 const string &gameCategory)
        : Application(applicationId, applicationName, minimumCompatibleOsVersion, userFeature, creatorFeatures, price)
{
    this->onLine = onLine;
    this->gameCategory = gameCategory;

}

void GameApp::showData()
{
    cout<<"Game ID: "<<applicationId<<"\n"<<"Game Name: "<<applicationName<<"\n"
        <<"Minimum Compatible OS Version: "<<minimumCompatibleOSVersion<<"\n"<<"Price: "<<price<<"\n"
        <<"Game Category: "<<gameCategory<<endl;

    if(onLine)
        cout<<"On Line Play: Yes"<<"\n"<<endl;
    else
        cout<<"On Line Play: No"<<"\n"<<endl;

    Application::printRatings();
    Application::printCreators();
}