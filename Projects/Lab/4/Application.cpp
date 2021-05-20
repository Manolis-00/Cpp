#include "Application.h"

Application::Application(char *applicationId,
                         const string &applicationName,
                         const string &minimumCompatibleOsVersion,
                         float price) {
    this->applicationId = new char[strlen(applicationId) + 1];
    strcpy(this->applicationId, applicationId);
    this->applicationName = applicationName;
    this->minimumCompatibleOSVersion = minimumCompatibleOsVersion;
    this->price = price;
    this->userRatings = {};
}

Application::Application(char *applicationId,
                         const string &applicationName,
                         const string &minimumCompatibleOsVersion,
                         UserRating &userRating,
                         ApplicationCreator &applicationCreator,
                         float price) {
    this->applicationId = new char[strlen(applicationId) + 1];
    strcpy(this->applicationId, applicationId);
    this->applicationName = applicationName;
    this->minimumCompatibleOSVersion = minimumCompatibleOsVersion;
    this->price = price;
    this->userRatings.assign(1, userRating);
    this->creatorDetails.assign(1, applicationCreator);
}

void Application::showData() {
    cout << "Application ID: " << applicationId << "\n" << "Application Name: " << applicationName << "\n"
         << "Minimum Compatible OS Version: " << minimumCompatibleOSVersion << "\n" << "Price: " << price << endl;

    printCreators();
    printRatings();
}

void Application::printRatings()
{
    for (UserRating rating : userRatings)
        rating.showData();
}

void Application::printCreators()
{
    for (ApplicationCreator creator : creatorDetails)
        creator.showData();
}


void Application::addUserRating(UserRating &userRating) {
    userRatings.assign(1, userRating);
}

void Application::addApplicationCreator(ApplicationCreator &applicationCreator) {
    creatorDetails.assign(1, applicationCreator);
}






