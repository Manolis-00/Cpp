#include "OfficeApp.h"

OfficeApp::OfficeApp()
{

}

OfficeApp::OfficeApp(char *applicationId,
                     const string &applicationName,
                     const string &minimumCompatibleOsVersion,
                     double price,
                     const vector<string> &appTypes):
        Application(applicationId, applicationName, minimumCompatibleOsVersion, price)
{
    this->appTypes = appTypes;
}

OfficeApp::OfficeApp(char *applicationId,
                     const string &applicationName,
                     const string &minimumCompatibleOsVersion,
                     UserRating &userFeature,
                     ApplicationCreator &creatorFeatures,
                     double price,
                     const vector<string> &appTypes):
        Application(applicationId, applicationName, minimumCompatibleOsVersion, userFeature, creatorFeatures, price)
{
    this->appTypes = appTypes;
}

void OfficeApp::readAppDataFromFile(string filePath)
{
    char buffer[300];
    ifstream appFile;

    appFile.open(filePath);

    if(!appFile.is_open())
    {
        cout<<"Error opening file";
        exit(1);
    }

    string appID;
    string filePrice;
    string inputString;

    while (!appFile.eof())
    {
        getline(appFile, appID, '\n');
        getline(appFile, applicationName, '\n');
        getline(appFile, minimumCompatibleOSVersion, '\n');
        getline(appFile, filePrice, '\n');
        while (appFile>>inputString)
            appTypes.push_back(inputString);
    }

    applicationId = new char[appID.length() - 2];
    int length = appID.length();

    for(int i = 0; i < length; i++)
        applicationId[i] = appID[i];

    price = stod(filePrice);

}

void OfficeApp::showDataToFile()
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
            .append("\n");

    for(auto appType : appTypes)
        appDetails.append("Compatible FIle Types: ")
                  .append(appType)
                  .append(", ");

    myFile<<appDetails<<endl;

    Application::printRatingsToFile();
    Application::printCreatorsToFile();
}

void OfficeApp::showData()
{
    int i;

    cout<<"Office Application ID: "<<applicationId<<"\n"<<"Office Application Name: "<<applicationName<<"\n"
        <<"Minimum Compatible OS Version: "<<minimumCompatibleOSVersion<<"\n"<<"Price: "<<price<<endl;

    cout<<"Supported Document Types: "<<endl;

    for(i = 0; i < appTypes.size(); i++)
    {
        cout<<appTypes[i]<<endl;
    }
    cout<<"\n";

    Application::printRatings();
    Application::printCreators();
}