#include "Character.h"
#include <iostream>
#include <vector>
#include "DefensiveItem.h"
#include "HelpfulItem.h"
#include "Utility.h"
#include <time.h>
#include <cstdlib>
#include <ctime>


Character::Character(int hp, int armor_, int attackDamage_ ) :
    hitPoints(hp),
    armor(armor_),
    attackDamage(attackDamage_)
{
    initialHitPoints.reset( new int(hitPoints) );
    initialArmorLevel.reset( new int( armor) );
    initialAttackDamage.reset( new int( attackDamage) );
    /*
    std::vector<int> v1;
    for (int i = 1; i <=70; i++)
    {
        srand(time(0)); 
        int b = (rand() %10) + 1;  
        v1.push_back (b); 
    }   
    
    int randNumb1 = rand() % v1.size();
    int randNumb2 = rand() % v1.size();
        
         //std::cout <<randNumb << std::endl;

    //srand(time(NULL));
    //randNumb = (rand() %10) + 1;
    */
    makeHelpfulItems(3);
    makeDefensiveItems(2);
}

void Character::attack( Character& other )
{
    if( hitPoints <= 0 )
    {
        std::cout << getName() << " can't attack. " << getName() << " is dead." << std::endl;
        std::cout << "make another party member use an item to revive them" << std::endl << std::endl;
        return;
    }
        
    isDefending = false;
    std::cout << getName() << " has attacked " << other.getName() << std::endl;
    //subtract attackDamage from other->hitPoints
    if( other.takeDamage(attackDamage) <= 0 )
    {
        //if you kill other, you get a boost in hit points and armor.
        attackInternal(other);
    }
}

void Character::defend()
{
    std::cout << getName() << " is defending!!" << std::endl;
    for( auto& item : defensiveItems )
    {
        if( auto* defensiveItem = dynamic_cast<DefensiveItem*>(item.get()) )
        {
            defensiveItem->use(this);
            item.reset(); //can only be used once!
            break;
        }
    }
    isDefending = true;
}

void Character::help(Character& other)
{
    std::cout << getName() << " is going to help " << other.getName() << std::endl;
    for( auto& item : helpfulItems )
    {
        if( auto* helpfulItem = dynamic_cast<HelpfulItem*>(item.get()) )
        {
            helpfulItem->use(&other);
            item.reset(); //can only be used once!
            break;
        }
    }
}

int Character::takeDamage(int damage)
{
    std::cout << getName() << " is taking " << damage << " damage!" << std::endl;
    if( damage < armor )
    {
        armor -= damage;
    }
    else
    {
        damage -= armor;
        armor = 0;
        
        hitPoints -= damage;
        if( hitPoints < 0 )
        {
            std::cout << getName() << " has died in battle!" << std::endl;
            hitPoints = 0;
        }
    }
    printStats();
    return hitPoints;
}

void Character::resetStats( int& value, int& initValue )
    {
        if(value < initValue)
        {
            value = initValue;
        }
            value *=1.1f;
            initValue = value;
    } 

//#include <assert>
void Character::attackInternal(Character& other)
{
    if( other.hitPoints <= 0 )
    {   
        /*
        When you defeat another Character: 
            a) your stats are restored to their initial value if they are lower than it.
            b) your stats are boosted 10%
            c) the initial value of your stats is updated to reflect this boosted stat for the next time you defeat another character.
      */
        //assert(false);
    `````
        resetStats(hitPoints, *initialHitPoints);
        resetStats(armor, *initialArmorLevel);
        resetStats(attackDamage, *initialAttackDamage);

        std::cout << getName() << " defeated " << other.getName() << " and leveled up!" << std::endl;        
    }
}

void Character::printStats()
{
    std::cout << getName() << "'s stats: " << std::endl;
    //assert(false);
    /*
    make your getStats() use a function from the Utility.h
    */
    std::cout << getStats(); 
    
    std::cout << std::endl;
    std::cout << std::endl;
}
