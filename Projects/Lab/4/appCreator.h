#ifndef EXERCISE_4_APPCREATOR_H
#define EXERCISE_4_APPCREATOR_H

#include "iostream"
#include "string"

using namespace std;

#endif //EXERCISE_4_APPCREATOR_H

class appCreator
{
private:
    string creatorID;
    string creatorName;
    string creatorEmail;
public:
    appCreator(string, string, string);
    string getCreatorID()const;
    string getCreatorName()const;
    string getCreatorEmail()const;
};