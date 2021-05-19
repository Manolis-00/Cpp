#ifndef EXERCISE_4_1_APPLICATIONCREATOR_H
#define EXERCISE_4_1_APPLICATIONCREATOR_H

#pragma once
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

#endif //EXERCISE_4_1_APPLICATIONCREATOR_H

class ApplicationCreator
{
private:
    string applicationCreatorID;
    char *applicationCreatorName;
    string email;

public:
    ApplicationCreator(const string &applicationCreatorId,
                       char *applicationCreatorName,
                       const string &email);
    void showData();
    friend class application;

};