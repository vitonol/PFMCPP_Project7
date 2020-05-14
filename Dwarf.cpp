#include "Dwarf.h"
#include "Utility.h"

Dwarf::Dwarf(std::string name_, int hitPoints, int armor): Character (hitPoints, armor, 4), name(name_) {}

const std::string& Dwarf::getName() {return name;}

std::string Dwarf::getStats() {return getCharacterStats(this); }    

