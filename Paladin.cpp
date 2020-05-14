#include "Paladin.h"
#include "Utility.h"

Paladin::Paladin(std::string name_, int hitPoints, int armor) : Character(int hp, int armor_, int 10 ), name(name_){}

const std::string& Paladin::getName() { return name; }

std::string Paladin::getStats() {return getCharacterStats(this); }
