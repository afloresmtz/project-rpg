#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
private:
    int health;
    int maxHealth;
    int strength;
    int magicRes;
    int meleeRes;
public:
    Enemy(int health, int strength, int magicRes, int meleeRes);

    int getHealth();
    void setHealth(int amount);

    int getMaxHealth();

    int getStrength();
    void setStrength(int amount);

    int getMagicRes();
    void setMagicRes(int amount);

    int getMeleeRes();
    void setMeleeRes(int amount);

    void attack(Character target);
    void applyBuff(Buff current_buff);
    void applyDebuff(Buff current_debuff);
};

#endif
