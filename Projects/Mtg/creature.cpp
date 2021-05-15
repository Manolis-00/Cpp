#include "creature.h"

creature::creature(string name, string colour, string prevalence, int attack, int defence, string type):
        card(name, colour, prevalence)
{
    this->attack = attack;
    this->defence = defence;
    this->type = type;
}

ostream &operator<<(ostream &left, creature &right)
{
    left<<"Creature Name: "<<right.getName()<<"\n"<<"Creature Colour: "<<right.getColour()<<"\n"<<"Creature Prevalence: "
        <<right.getPrevalence()<<"\n"<<"Creature Attack: "<<right.attack<<"\n"<<"Creature Defence: "<<right.defence<<"\n"
        <<"Creature Type: "<<right.type<<endl;

    return left;
}
