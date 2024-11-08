#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
private:
    Stat health;
    Stat strength;
    Stat magicRes;
    Stat meleeRes;
public:
    Enemy(Stat health, Stat strength, Stat magicRes, Stat meleeRes);

    void changeHealth(int amount);
    void attack(Character target);
    void applyBuff(Enemy& ally, Buff current_buff);
    void applyDebuff(Character target, Buff current_debuff);
};

#endif
