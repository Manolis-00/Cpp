#include "ApplicationCreator.h"

ApplicationCreator::ApplicationCreator(const string &applicationCreatorId,
                                       char *applicationCreatorName,
                                       const string &email)
{
    this->applicationCreatorID = applicationCreatorId;
    this->applicationCreatorName = new char [strlen(applicationCreatorName) +1];
    strcpy(this->applicationCreatorName, applicationCreatorName);
    this->email = email;
}

void ApplicationCreator::showData()
{
    cout<<"Application Creator ID: "<<applicationCreatorID<<"\n"<<"Application Creator Name: "<<applicationCreatorName
        <<"\n"<<"Application Creator email: "<<email<<"\n"<<endl;

}