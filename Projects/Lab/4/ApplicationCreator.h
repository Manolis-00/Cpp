#ifndef EXERCISE_4_1_APPLICATIONCREATOR_H
#define EXERCISE_4_1_APPLICATIONCREATOR_H

#pragma once
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
using std::ifstream;

#endif //EXERCISE_4_1_APPLICATIONCREATOR_H

class ApplicationCreator
{
private:
    string applicationCreatorID;
    char *applicationCreatorName;
    string email;
    friend class AppSystem;

public:
    ApplicationCreator();

    ApplicationCreator(const string &applicationCreatorId,
                       char *applicationCreatorName,
                       const string &email);

    string getApplicationCreatorID() const;

    char *getApplicationCreatorName() const;

    string getEmail() const;

    void readDetailsFromFile(string filePath);

    void showData();
};