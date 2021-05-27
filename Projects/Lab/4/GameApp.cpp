#include "GameApp.h"

GameApp::GameApp()
{

}

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

void GameApp::readGameDataFromFile(string filePath)
{
    char buffer[300];
    ifstream gameFile;

    gameFile.open(filePath);

    if(!gameFile.is_open())
    {
        cout<<"Error opening file";
        exit(1);
    }

    string appID; //char*
    string filePrice; //double
    string boolean;

    while (!gameFile.eof())
    {
        getline(gameFile, appID, '\n');
        getline(gameFile, applicationName, '\n');
        getline(gameFile, minimumCompatibleOSVersion, '\n');
        getline(gameFile, filePrice, '\n');
        getline(gameFile, boolean, '\n');
        getline(gameFile, gameCategory, '\n');
    }

    applicationId = new char[appID.length() - 2];
    int length = appID.length()-2;

    for(int i = 0; i < length; i++)
        applicationId[i] = appID[i];

    price = stod(filePrice);

    if(stoi(boolean) == 1)
        onLine = true;
    else
        onLine = false;
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
