#include "Buff.h"

Buff::Buff(Character* targetCharacter, const std::string& targetStat, int intensity)
    : targetCharacter(targetCharacter), targetEnemy(nullptr), targetStat(targetStat), intensity(intensity) {}

Buff::Buff(Enemy* targetEnemy, const std::string& targetStat, int intensity, int duration)
    : targetCharacter(nullptr), targetEnemy(targetEnemy), targetStat(targetStat), intensity(intensity) {}


void Buff::affectCharacterStat() {
    if (!targetCharacter) return;
    if (targetStat == "health") {
        if (targetCharacter->getHealth() + intensity <= targetCharacter->getMaxHealth()) {
            targetCharacter->setHealth(targetCharacter->getHealth() + intensity);
        } else {
            targetCharacter->setHealth(targetCharacter->getMaxHealth());
        }
    }
    else if (targetStat == "mana") {
        if (targetCharacter->getMana() + intensity <= targetCharacter->getMaxMana()) {
            targetCharacter->setMana(targetCharacter->getMana() + intensity);
        } else {
            targetCharacter->setMana(targetCharacter->getMaxMana());
        }
    }
    else if (targetStat == "maxHealth") {
        targetCharacter->setMaxHealth(targetCharacter->getMaxHealth() + intensity);
    }
    else if (targetStat == "defense") {
        targetCharacter->setDefense(targetCharacter->getDefense() + intensity);
    }
    else if (targetStat == "meleeDmg") {
        targetCharacter->setMeleeDmg(targetCharacter->getMeleeDmg() + intensity);
    }
    else if (targetStat == "magicDmg") {
        targetCharacter->setMagicDmg(targetCharacter->getMagicDmg() + intensity);
    }
    else if (targetStat == "maxMana") {
        targetCharacter->setMaxMana(targetCharacter->getMaxMana() + intensity);
    }
    else if (targetStat == "critChance") {
        targetCharacter->setCritChance(targetCharacter->getCritChance() + intensity);
    }
    else if (targetStat == "critDmg") {
        targetCharacter->setCritDmg(targetCharacter->getCritDmg() + intensity);
    }
}

void Buff::affectEnemyStat() {
    if (targetStat == "health") {
        if (targetEnemy.getHealth() + intensity <= targetEnemy.getMaxHealth()) {
            targetEnemy.setHealth(targetEnemy.getHealth() + intensity);
        } else {
            targetEnemy->setHealth(targetEnemy->getMaxHealth());
        }
    } 
    else if (targetStat == "strength") {
        targetEnemy.setStrength(targetEnemy.getStrength() + intensity);
    } 
    else if (targetStat == "magicRes") {
        targetEnemy.setMagicRes(targetEnemy.getMagicRes() + intensity);
    } 
    else if (targetStat == "meleeRes") {
        targetEnemy.setMeleeRes(targetEnemy.getMeleeRes() + intensity);
    }
}

