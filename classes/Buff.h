#ifndef BUFF_H
#define BUFF_H

#include <string>

class Buff {
private:
    int intensity;
    Character targetCharacter;
    Enemy targetEnemy;
    string targetStat;
    int duration;
public:
    Buff(Character targetCharacter, string targetStat, int intensity);
    Buff(Character targetCharacter, string targetStat, int intensity, int duration);
    Buff(Enemy targetEnemy, string targetStat, int intensity, int duration);

    void affectCharacterStat();
    void affectEnemyStat();
};

#endif
