#include "OfficeApp.h"

OfficeApp::OfficeApp(char *applicationId,
                     const string &applicationName,
                     const string &minimumCompatibleOsVersion,
                     float price,
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
                     float price,
                     const vector<string> &appTypes):
        Application(applicationId, applicationName, minimumCompatibleOsVersion, userFeature, creatorFeatures, price)
{
    this->appTypes = appTypes;
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