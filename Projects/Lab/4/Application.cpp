#include "Application.h"

Application::Application(char *applicationId,
                         const string &applicationName,
                         const string &minimumCompatibleOsVersion,
                         double price) {
    this->applicationId = new char[strlen(applicationId) + 1];
    strcpy(this->applicationId, applicationId);
    this->applicationName = applicationName;
    this->minimumCompatibleOSVersion = minimumCompatibleOsVersion;
    this->price = price;
    this->userRatings = {};
    starsAverage = 0.0;

}

Application::Application(char *applicationId,
                         const string &applicationName,
                         const string &minimumCompatibleOsVersion,
                         UserRating &userRating,
                         ApplicationCreator &applicationCreator,
                         double price) {
    this->applicationId = new char[strlen(applicationId) + 1];
    strcpy(this->applicationId, applicationId);
    this->applicationName = applicationName;
    this->minimumCompatibleOSVersion = minimumCompatibleOsVersion;
    this->price = price;
    this->userRatings.assign(1, userRating);
    this->creatorDetails.assign(1, applicationCreator);

    setStarsAverage();
}

void Application::showData() {
    cout << "Application ID: " << applicationId << "\n" << "Application Name: " << applicationName << "\n"
         << "Minimum Compatible OS Version: " << minimumCompatibleOSVersion << "\n" << "Price: " << price << endl;

    printCreators();
    printRatings();
}

void Application::showDataToFile()
{
    ofstream myFile;
    myFile.open("new.txt", std::ios_base::app);

    string appDetails;
    appDetails.append("Application Details: ")
              .append("\n")
              .append(applicationId)
              .append(", ")
              .append(applicationName)
              .append(", ")
              .append(minimumCompatibleOSVersion)
              .append(", ")
              .append(to_string(price))
              .append(", ")
              .append(to_string(starsAverage));

    myFile<<appDetails<<"\n"<<"User Ratings: "<<endl;
    printRatingsToFile();

}

void Application::printRatings()
{
    for (UserRating rating : userRatings)
        rating.showData();
}

void Application::printRatingsToFile()
{
    ofstream myFile;
    myFile.open("new.txt", std::ios_base::app);

    for(UserRating rating : userRatings)
    {
        string appDetails;
        appDetails.append(to_string(rating.getUserStars()))
                  .append(", ")
                  .append(rating.getUserName())
                  .append(", ")
                  .append(rating.getUserComment());

        myFile<<appDetails<<endl;
    }

    myFile<<"Application Creator: "<<endl;
    printCreatorsToFile();

}

void Application::printCreators()
{
    for (ApplicationCreator creator : creatorDetails)
        creator.showData();
}

void Application::printCreatorsToFile()
{
    ofstream myFile;
    myFile.open("new.txt", std::ios_base::app);

    for(ApplicationCreator creator : creatorDetails)
    {
        string appDetails;
        appDetails.append("Application Creator: ")
                  .append(creator.getApplicationCreatorID())
                  .append(", ")
                  .append(creator.getApplicationCreatorName())
                  .append(", ")
                  .append(creator.getEmail());
    }

}


void Application::addUserRating(UserRating &userRating) {
    userRatings.assign(1, userRating);

    setStarsAverage();
}

void Application::addApplicationCreator(ApplicationCreator &applicationCreator) {
    creatorDetails.assign(1, applicationCreator);
}

float Application::getStars(Application &application)
{
    return application.userRatings[0].getUserStars();
}

void Application::setStarsAverage()
{
    if(userRatings.size() > 0)
    {
        for(int i = 0; i < userRatings.size(); i++)
        {
            starsAverage += userRatings[0].getUserStars();
        }

        starsAverage = starsAverage/userRatings.size();
    }

}
