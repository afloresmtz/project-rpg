#include "Buff.h"
#include "Character.h"
#include "Enemy.h"

Buff::Buff(Character targetCharacter, string targetStat, int intensity) {
    this->targetCharacter = targetCharacter;
    this->targetStat = targetStat;
    this->intensity = intensity;
}

Buff::Buff(Character targetCharacter, string targetStat, int intensity, int duration) {
    this->targetCharacter = targetCharacter;
    this->targetStat = targetStat;
    this->intensity = intensity;
    this->duration = duration;
}

Buff::Buff(Enemy targetEnemy, string targetStat, int intensity, int duration) {
    this->targetEnemy = targetEnemy;
    this->targetStat = targetStat;
    this->intensity = intensity;
    this->duration = duration;
}

void Buff::affectCharacterStat() {
    if (targetStat == "health") {
        if (targetCharacter.getHealth() + intensity <= targetCharacter.getMaxHealth()) {
            targetCharacter.setHealth(targetCharacter.getHealth() + intensity);
        } else {
            cout << "Health is already at max." << endl;
        }
    } 
    else if (targetStat == "mana") {
        if (targetCharacter.getMana() + intensity <= targetCharacter.getMaxMana()) {
            targetCharacter.setMana(targetCharacter.getMana() + intensity);
        } else {
            cout << "Mana is already at max." << endl;
        }
    } 
    else if (targetStat == "maxHealth") {
        targetCharacter.setMaxHealth(targetCharacter.getMaxHealth() + intensity);
    } 
    else if (targetStat == "defense") {
        targetCharacter.setDefense(targetCharacter.getDefense() + intensity);
    } 
    else if (targetStat == "meleeDmg") {
        targetCharacter.setMeleeDmg(targetCharacter.getMeleeDmg() + intensity);
    } 
    else if (targetStat == "magicDmg") {
        targetCharacter.setMagicDmg(targetCharacter.getMagicDmg() + intensity);
    } 
    else if (targetStat == "maxMana") {
        targetCharacter.setMaxMana(targetCharacter.getMaxMana() + intensity);
    } 
    else if (targetStat == "critChance") {
        targetCharacter.setCritChance(targetCharacter.getCritChance() + intensity);
    } 
    else if (targetStat == "critDmg") {
        targetCharacter.setCritDmg(targetCharacter.getCritDmg() + intensity);
    }
}

void Buff::affectEnemyStat() {
    if (targetStat == "health") {
        if (targetEnemy.getHealth() + intensity <= targetEnemy.getMaxHealth()) {
            targetEnemy.setHealth(targetEnemy.getHealth() + intensity);
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

