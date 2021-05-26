#include "ApplicationCreator.h"

ApplicationCreator::ApplicationCreator()
{

}

ApplicationCreator::ApplicationCreator(const string &applicationCreatorId,
                                       char *applicationCreatorName,
                                       const string &email)
{
    this->applicationCreatorID = applicationCreatorId;
    this->applicationCreatorName = new char [strlen(applicationCreatorName) +1];
    strcpy(this->applicationCreatorName, applicationCreatorName);
    this->email = email;
}

string ApplicationCreator::getApplicationCreatorID() const
{
    return applicationCreatorID;
}

char *ApplicationCreator::getApplicationCreatorName() const
{
    return applicationCreatorName;
}

string ApplicationCreator::getEmail() const
{
    return email;
}

void ApplicationCreator::readDetailsFromFile(string filePath)
{
    char buffer[300];
    ifstream creatorFile;

    creatorFile.open(filePath);

    if(!creatorFile.is_open())
    {
        cout<<"Error opening file";
        exit(1);
    }

    string newName;
    while(!creatorFile.eof())
    {
        getline(creatorFile, applicationCreatorID, '\n');
        getline(creatorFile, newName, '\n');
        getline(creatorFile, email, '\n');
    }

    applicationCreatorName = new char[newName.length() - 1];

    int length = newName.length();

    for(int i = 0; i < length; i++)
        applicationCreatorName[i] = newName[i];

}

void ApplicationCreator::showData()
{
    cout<<"Application Creator ID: "<<applicationCreatorID<<"\n"<<"Application Creator Name: "<<applicationCreatorName
        <<"\n"<<"Application Creator email: "<<email<<"\n"<<endl;

}


