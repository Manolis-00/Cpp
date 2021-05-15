#include "land.h"

land::land(string name, string colour, string prevalence, int mana, string description, string tap):
    card(name, colour, prevalence)
{
    this->mana = mana;
    this->description = description;
    this->tap = tap;
}

ostream &operator<<(ostream &left, land &right)
{
    left<<"Land Name: "<<right.name<<"\n"<<"Land Colour: "<<right.colour<<"\n"<<"Land Prevalence: "
        <<right.prevalence<<"\n"<<"Land Mana: "<<right.mana<<"\n"<<"Land Description: "<<right.description<<"\n"
        <<"Land Tap State: "<<right.tap<<endl;
}
