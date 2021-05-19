#include "appSystem.h"

AppSystem::AppSystem() {
    applications = {};
}

void AppSystem::addApplication(Application &applicationToAdd) {
    applications.push_back(applicationToAdd);
}

void AppSystem::addCreatorsAndRatings(Application &applicationToAdd,
                                      UserRating &feature,
                                      ApplicationCreator &creatorFeatures) {
    applicationToAdd.addUserRating(feature);
    applicationToAdd.addApplicationCreator(creatorFeatures);
    applications.push_back(applicationToAdd);
}

const vector<Application> &AppSystem::getApplications() const {
    return applications;
}

int AppSystem::getTotalApplications() {
    return applications.size();
}

Application AppSystem::getCurrentApplication(int index)
{
        return applications[index];
}

void AppSystem::showData(Application &application) {
    application.showData();

}