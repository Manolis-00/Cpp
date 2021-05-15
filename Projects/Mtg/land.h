#ifndef MTG_LAND_H
#define MTG_LAND_H

#include "card.h"

#endif //MTG_LAND_H

class land:public card
{
private:
    int mana;
    string description;
    string tap;
public:
    land(string, string, string, int, string, string);
    friend ostream &operator<<(ostream &left, land &right);
};
