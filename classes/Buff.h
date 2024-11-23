#ifndef BUFF_H
#define BUFF_H

#include <string>
class Character;
class Enemy;

class Buff {
private:
    // priuvate attributes
    int intensity;

    std::string targetStat;

    // composition attributes
    Character* targetCharacter;
    Enemy* targetEnemy;
    
public:
    // constructors
    Buff(Character* targetCharacter, const std::string& targetStat, int intensity);
    Buff(Enemy* targetEnemy, const std::string& targetStat, int intensity);

    // methods
    void affectCharacterStat();
    void affectEnemyStat();
};

#endif
