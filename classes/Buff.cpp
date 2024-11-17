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
    switch(targetStat) {
        case "health":
            if(targetCharacter.getHealth() + intensity <= targetCharacter.getMaxHealth()) {
                targetCharacter.setHealth(targetCharacter.getHealth() + intensity);
            }
            else {
                cout << "Health is already at max." << endl;
            }
        case "mana":
            if(targetCharacter.getMana() + intensity <= targetCharacter.getMaxmana()) {
                targetCharacter.setMana(targetCharacter.getMana() + intensity);
            }
            else {
                cout << "mana is already at max." << endl;
            }
        case "defense":
            targetCharacter.setDefense(targetCharacter.getDefense() + intensity);
        case "meleeDmg":
            targetCharacter.setMeleeDmg(targetCharacter.getMeleeDmg() + intenisty);
        case "magicDmg":
            targetCharacter.setMagicDmg(targetCharacter.getMagicDmg() + intensity);
        case "maxMana":
            targetCharacter.setMaxMana(targetCharacter.getMaxMana() + intensity);
        case "critChance":
            targetCharacter.setCritChance(targetCharacter.getCritChance() + intensity);
        case "critDmg":
            targetCharacter.setCritDmg(targetCharacter.getCritDmg() + intensity);

    }
}

void Buff::affectEnemyStat() {
    switch(targetStat) {
        case "health":
            if(targetEnemy.getHealth() + intensity <= targetEnemy.getMaxHealth()) {
                targetEnemy.setHealth(targetEnemy.getHealth() + intensity);
            }
        case "strength":
            targetEnemy.setStrength(targetEnemy.getStrength() + intensity);
        case "magicRes":
            targetEnemy.setMagicRes(targetEnemy.getMagicRes() + intensity);
        case "meleeRes":
            targetEnemy.setMeleeRes(targetEnemy.getMeleeRes() + intensity);
    }
}

