#ifndef BUFF_H
#define BUFF_H

#include <string>
class Character;
class Enemy;

class Buff {
private:
    int intensity;

    std:.string targetStat;

    Character* targetCharacter;
    Enemy* targetEnemy;
    
public:
    Buff(Character* targetCharacter, const std::string& targetStat, int intensity);
    Buff(Enemy* targetEnemy, const std::string& targetStat, int intensity);

    void affectCharacterStat();
    void affectEnemyStat();
};

#endif
