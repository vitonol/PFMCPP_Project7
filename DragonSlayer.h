#pragma once
#include "Character.h"
#include "AttackItem.h"
#include <memory>

struct DragonSlayer : Character
{
    DragonSlayer(std::string name_, int hitPoints, int armor);
    
    const std::string& getName() override;
    std::string getStats() override;
    void attack(Character& other) override;
    
private:
    const std::string name;
    std::unique_ptr<Item> attackItem;
};
