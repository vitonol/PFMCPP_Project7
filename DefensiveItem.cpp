#include "DefensiveItem.h"
#include "Dwarf.h"
#include "Paladin.h"
#include "DragonSlayer.h"
#include "Dragon.h"

#include "Character.h"
#include "Utility.h"


void DefensiveItem::use(Character* character)
{
    useDefensiveItem(character, *this);
    //assert(false); 
    //make your defensive item use the appropriate Utility helper functions
}
