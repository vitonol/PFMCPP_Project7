#include "Paladin.h"
#include "Utility.h"

Paladin::Paladin(std::string name_, int hitPoints, int armor) : Character(hitPoints, armor, 10 ), name(name_)
{
    helpfulItems = makeHelpfulItems(2);
    defensiveItems = makeDefensiveItems(1);
}

const std::string& Paladin::getName() { return name; }

std::string Paladin::getStats() {return getCharacterStats(this); }
