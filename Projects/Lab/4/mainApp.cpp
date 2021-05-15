#include "mainApp.h"

mainApp::mainApp(string appID, string appName, float minCompatibleOSVersion, float price, userRating &ob, appCreator &right)
{
    this->appID = appID;
    this->appName = appName;
    this->minCompatibleOSVersion = minCompatibleOSVersion;
    this->price = price;

    //rating[0] = ob.getStars();

    creator[0] = right.getCreatorID();
    creator[1] = right.getCreatorName();
    creator[2] = right.getCreatorEmail();
}

void mainApp::setRating(userRating &ob)
{

}
