#include "AppSystem.h"

AppSystem::AppSystem() {
    applications = {};
    freeOfficeApps = {};
    goodGames = {};
}

void AppSystem::addApplication(Application &applicationToAdd) {
    applications.push_back(&applicationToAdd);

    if(typeid(OfficeApp) == typeid(applicationToAdd) && applicationToAdd.price == 0.0)
        freeOfficeApps.push_back(&applicationToAdd);

    if(typeid(GameApp) == typeid(applicationToAdd) && applicationToAdd.starsAverage > 4)
        goodGames.push_back(&applicationToAdd);
}

void AppSystem::addCreatorsAndRatings(Application &applicationToAdd,
                                      UserRating &feature,
                                      ApplicationCreator &creatorFeatures) {
    applicationToAdd.addUserRating(feature);
    applicationToAdd.addApplicationCreator(creatorFeatures);
}

void AppSystem::setApplicationId(Application &application, char *newApplicationID)
{
    application.applicationId = newApplicationID;
}

void AppSystem::setApplicationName(Application &application, string newApplicationName)
{
    application.applicationName = newApplicationName;
}

void AppSystem::setMinimumCompatibleOSVersion(Application &application, string newMinimumCompatibleOSVersion)
{
    application.minimumCompatibleOSVersion = newMinimumCompatibleOSVersion;
}

void AppSystem::setPrice(Application &application, float newPrice)
{
    application.price = newPrice;
}

void AppSystem::setCreatorDetails(Application &application, ApplicationCreator &newCreatorDetails)
{
    application.creatorDetails.clear();
    application.creatorDetails.assign(1, newCreatorDetails);
}

void AppSystem::addUserRatings(Application &application, UserRating &newUserRatings)
{
    application.userRatings.push_back(newUserRatings);
}

void AppSystem::setOnLine(GameApp &gameApp, bool newOnLine)
{
    gameApp.onLine = newOnLine;
}

void AppSystem::setGameCategory(GameApp &gameApp, string newGameCategory)
{
    gameApp.gameCategory = newGameCategory;
}

void AppSystem::deleteAppType(OfficeApp &officeApp, int index)
{
    officeApp.appTypes.erase(officeApp.appTypes.begin()+index);
}

void AppSystem::addAppType(OfficeApp &officeApp, string newType)
{
    officeApp.appTypes.push_back(newType);
}

void AppSystem::setCreatorID(ApplicationCreator &applicationCreator, string newCreatorID)
{
    applicationCreator.applicationCreatorID = newCreatorID;
}

void AppSystem::setCreatorName(ApplicationCreator &applicationCreator, char *newCreatorName)
{
    delete applicationCreator.applicationCreatorName;
    applicationCreator.applicationCreatorName = new char [strlen(newCreatorName) + 1];
    strcpy(applicationCreator.applicationCreatorName, newCreatorName);
}

void AppSystem::setCreatorEmail(ApplicationCreator &applicationCreator, string newEmail)
{
    applicationCreator.email = newEmail;
}

void AppSystem::setStars(UserRating &userRating, float newStars)
{
    userRating.userStars = newStars;
}

void AppSystem::setUserName(UserRating &userRating, string newUserName)
{
    userRating.userName = newUserName;
}

void AppSystem::setComment(UserRating &userRating, string comment)
{
    userRating.userComment = comment;
}

void AppSystem::deleteMaliciousCreator(string applicationCreator)
{

    for(int i = 0; i < applications.size(); i++)
    {
        if(applications[i]->creatorDetails[0].applicationCreatorID == applicationCreator)
            applications.erase(applications.begin()+i);
    }

    for(int i = 0; i < freeOfficeApps.size(); i++)
    {
        if(freeOfficeApps[i]->creatorDetails[0].applicationCreatorID == applicationCreator)
            freeOfficeApps.erase(freeOfficeApps.begin()+1);
    }

    for(int i = 0; i < goodGames.size(); i++)
    {
        if(goodGames[i]->creatorDetails[0].applicationCreatorID == applicationCreator)
            goodGames.erase(goodGames.begin()+1);
    }

}

void AppSystem::showData() {
    for(auto application : applications)
    {
        application->showData();
    }

    cout<<"The free Office Applications are: "<<endl;

    for(auto freeOfficeApp : freeOfficeApps)
    {
        cout<<freeOfficeApp->applicationName;
        cout<<"\n";
    }

    cout<<"\n"<<"Games with average rating greater than 4 stars: "<<endl;

    for(auto goodGame : goodGames)
    {
        cout<<goodGame->applicationName;
        cout<<"\n";
    }

}