#ifndef MTG_CREATURE_H
#define MTG_CREATURE_H

#include "card.h"

#endif //MTG_CREATURE_H

class creature: public card
{
private:
    int attack;
    int defence;
    string type;
public:
    creature(string, string, string, int, int, string);
    friend ostream &operator<<(ostream &left, creature &right);
};

