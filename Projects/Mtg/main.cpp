#include "card.h"
#include "creature.h"
#include "land.h"

int main()
{
    card c("tname", "blue", "uncommon");

    creature akroanCrusader("Akroan Crusader", "Red", "Common", 1, 1, "Human Soldier");
    creature runeScarredDemon("Rune-Scarred Demon", "Black", "Rare", 6, 6, "Demon");
    land Plains("Plains", "White", "Common", 1, "Basic Land", "Untapped");
    land Swamp("Swamp", "Black", "Common", 1, "Basic Land", "Untapped");
    land Forest("Forest", "Gren", "Common", 1, "Basic Land", "Untapped");



    cout<<c;

    cout<<akroanCrusader;
    cout<<runeScarredDemon;
    cout<<Plains;
    cout<<Swamp;
    cout<<Forest;

    return 0;
}
