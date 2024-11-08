#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
private:
    // Character attributes
    Stat health;
    Stat maxHealth;
    Stat defense;
    Stat meleeDmg;
    Stat magicDmg;
    Stat mana;
    Stat critChance;
    Stat critDmg;
    Stat healthRegen;

    // static attributes: affect all Characters (the whole party)
    static Stat gold;
    static Stat goldGain;
    static Stat shopDiscount;

public:
    Character(Stat health, Stat defense, Stat meleeDmg);
    Character(Stat health, Stat defense, Stat magicDmg);

    void changeHealth(int amount);
    void attackMelee(Enemy target);
    void attackMagic(Enemy target);
    void applyDebuff(Enemy target, Buff current_debuff);
    void applyBuff(Character& ally, Buff current_buff);
    void regenHealth(Character& ally, int amount);
    void regenMana(Character& ally, int amount);

};

#endif
