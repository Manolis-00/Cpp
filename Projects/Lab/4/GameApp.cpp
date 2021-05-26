#include "GameApp.h"

GameApp::GameApp(char *applicationId,
                 const string &applicationName,
                 const string &minimumCompatibleOsVersion,
                 double price,
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
                 double price,
                 bool onLine,
                 const string &gameCategory)
        : Application(applicationId, applicationName, minimumCompatibleOsVersion, userFeature, creatorFeatures, price)
{
    this->onLine = onLine;
    this->gameCategory = gameCategory;

}

void GameApp::showDataToFile()
{
    ofstream myFile;
    myFile.open("new.txt", std::ios_base::app);

    string appDetails;
    appDetails.append("Application Details: ")
            .append(applicationId)
            .append(", ")
            .append(applicationName)
            .append(", ")
            .append(minimumCompatibleOSVersion)
            .append(", ")
            .append(to_string(price))
            .append(", ")
            .append(to_string(starsAverage))
            .append(", ")
            .append(gameCategory)
            .append(", ");

    if(onLine)
        appDetails.append("True");
    else
        appDetails.append("False");

    myFile<<appDetails<<endl;

    Application::printRatingsToFile();
    Application::printCreatorsToFile();
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