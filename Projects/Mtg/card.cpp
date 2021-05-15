#include "card.h"

card::card(string name, string colour, string prevalence)
{
    this->name = name;
    this->colour = colour;
    this->prevalence = prevalence;
}

string card::getName()const
{
    return name;
}
string card::getColour()const
{
    return colour;
}

string card::getPrevalence()const
{
    return prevalence;
}

ostream &operator<<(ostream &left, card &right)
{
    left<<"Card Name: "<<right.name<<"\n"<<"Card Colour: "<<right.colour<<"\n"<<"Prevalence: "<<right.prevalence<<endl;

    return left;
}