#ifndef MTG_CARD_H
#define MTG_CARD_H

#pragma once
#include <iostream>
#include <cstring>
using namespace std;

#endif //MTG_CARD_H

class card
{
protected:
    string name;
    string colour;
    string prevalence;
public:
    card(string, string, string);
    string getName()const;
    string getColour()const;
    string getPrevalence()const;
    friend ostream &operator<<(ostream &left, card &right);
};