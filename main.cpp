#include <iostream>
#include <string>
#include <time.h>
#include <new>
#include <map>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>
#include <typeinfo>

// classes to use in the project
#include "Character.cpp"
#include "Enemy.cpp"
#include "Buff.cpp"
#include "Weapon.cpp"
#include "BlessedWeapon.cpp"

#include <typeinfo>

using namespace std;

// character (and starting weapons) creation
BlessedWeapon basicSword("Basic Sword", 15, true, "Strength", 0);
Character fighter("Fighter", 200, 60, 30, &basicSword);

BlessedWeapon basicStaff("Basic Staff", 10, false, "Savagery", 0);
Character mage("Mage", 150, 40, 30, &basicStaff);

BlessedWeapon basicDagger("Basic Dagger", 10, true, "Ferocity", 0);
Character rogue("Rogue", 175, 30, 15, &basicDagger);

BlessedWeapon basicSpellBook("Basic Spell Book", 5, false, "Toughness", 0);
Character healer("Healer", 200, 50, 5, &basicSpellBook);

// "static" stats, shared by the whole party
int gold = 10;
int regen = 0;
double gold_gain = 1;
double shop_discount = 1;
double difficulty = 1;
double health_regen = 0;

// array of enemy types
string all_enemies[10] = {"Slime", "Skeleton", "Goblin", "Bandit", "Orc", "Giant Spider", "Golem", "Ghost", "Mimic", "Dragon"};

// array of all obtainable blessings (permanent buffs)
string all_blessings[9] = {"Wealth", "Loyalty", "Regeneration", "Strength", "Savagery", "Ferocity", "Fortitude", "Toughness", "Focus"};


// *** UTILITY FUNCTIONS *** ///


// function to apply color to text to make it more visually appealing
string applyColor(string text, string colorCode) {
    return "\033[" + colorCode + "m" + text + "\033[0m";
}

// dictionary of shop items
map<std::string, int> shop_items = {
    {"Blessing of Wealth " + applyColor(" (Gain more gold after battles)", "1;32"), 50},
    {"Blessing of Loyalty " + applyColor(" (Reduce shop prices)", "1;32"), 50},
    {"Blessing of Regeneration " + applyColor(" (Heal some damage after battle)", "1;32"), 50},
    {"Blessing of Strength " + applyColor(" (Permanent damage increase for whole party)", "1;32"), 50},
    {"Blessing of Savagery " + applyColor(" (Permanent critical chance increase)", "1;32"), 50},
    {"Blessing of Ferocity " + applyColor(" (Permanent critical damage increase)", "1;32"), 50},
    {"Blessing of Fortitude " + applyColor(" (Permanent defense increase)", "1;32"), 50},
    {"Blessing of Toughness " + applyColor(" (Permanent maximum health increase)", "1;32"), 50},
    {"Blessing of Focus " + applyColor(" (Permanent maximum mana increase)", "1;32"), 50},
    {"Sword (Fighter)", 25},
    {"Staff (Mage)", 25},
    {"Dagger (Rogue)", 25},
    {"Spell Book (Healer)", 25},
};

// function to create the health bar that will be displayed
// it utilizes 20 characters, using '|' as health and '.' as lack of thereof
string createHealthbar(Character* current_char) {
    int health = current_char->getHealth();
    int maxHealth = current_char->getMaxHealth();

    if(health <= 0) {
        return string(20, '.');
    }
    else {
        int length = (health * 20) / maxHealth;
        return string(length, '|') + string(20 - length, '.');
    }
}

// function to display these health bars each turn
void displayHealth(Enemy* current_enemy) {
    // creating the enemies health bar in here
    int health = current_enemy->getHealth();
    int maxHealth = current_enemy->getMaxHealth();

    if (health > maxHealth) {
        health = maxHealth;
    }

    if(health <= 0) {
        cout << "Enemy Health   : [....................]" << endl;
    }
    else {
        int length = (health * 20) / maxHealth;
        string enemy_healthbar = string(length, '|') + string(20 - length, '.');
        cout << "Enemy Health   : [" << applyColor(enemy_healthbar, "1;31") << "] (" << health << "/" << maxHealth << ")  (" << current_enemy->getName() << ")" << endl;
    }

    cout << "" << endl;

    int length_mana_mage = (mage.getMana() * 20) / mage.getMaxMana();
    int length_mana_healer = (healer.getMana() * 20) / healer.getMaxMana();

    // printing character health bars
    cout << "Fighter Health : [" << applyColor(createHealthbar(&fighter), "1;32") << "] (" << fighter.getHealth() << "/" << fighter.getMaxHealth() << ")" << endl;
    cout << "Mage Health    : [" << applyColor(createHealthbar(&mage), "1;32") << "] (" << mage.getHealth() << "/" << mage.getMaxHealth() << ")  ["
        << applyColor(string(length_mana_mage, '|') + string(20 - length_mana_mage, '.'), "1;34") << "] (" << mage.getMana() << "/" << mage.getMaxMana() << ")" << endl;
    cout << "Rogue Health   : [" << applyColor(createHealthbar(&rogue), "1;32") << "] (" << rogue.getHealth() << "/" << rogue.getMaxHealth() << ")" << endl;
    cout << "Healer Health  : [" << applyColor(createHealthbar(&healer), "1;32") << "] (" << healer.getHealth() << "/" << healer.getMaxHealth() << ")  ["
        << applyColor(string(length_mana_healer, '|') + string(20 - length_mana_healer, '.'), "1;34") << "] (" << healer.getMana() << "/" << healer.getMaxMana() << ")" << endl;
}

// function to generate random numbers
int randomInt(int min_number, int max_number) {
    return min_number + rand() % (max_number - min_number + 1);
}

// function to generate main menu of character
void displayMenu(Character* current_character) {
    if (current_character->getName() == "Fighter" || current_character->getName() == "Rogue") {
        cout << "1. Attack (Melee)" << endl;
        cout << "2. Skills" << endl;
        cout << "3. Guard (Defense + 10)" << endl;
        cout << "4. Check stats" << endl;
    }
    else {
        cout << "1. Attack (Magic)" << endl;
        cout << "2. Skills" << endl;
        cout << "3. Guard (Defense + 10)" << endl;
        cout << "4. Check stats" << endl;
    }
}

// function to generate skill menu for each character
void displaySkillMenu(Character* current_character) {
    cout << "--- SKILLS ---" << endl;
    if (current_character->getName() == "Fighter"){
        cout << "1. Encouraging Speech " <<  applyColor("(Boost everyone's strength slightly)\n", "1;32") <<
            "2. Focused Strike " << applyColor("(Deal big melee damage to enemy)\n", "1;32") <<
            "3. Warrior's Fury " << applyColor("(Boost Fighter's own strength) \n", "1;32") << endl;
    }
    else if (current_character->getName() == "Mage"){
        cout << "1. Arcane Blast " << applyColor("(Deal big magic damage to enemy)", "1;32") << " - " << applyColor("50 mana\n", "1;34") <<
            "2. Foresight Aura " << applyColor("(Boost everyone's critical chance and damage slightly)", "1;32") << " - " << applyColor("40 mana\n", "1;34") <<
            "3. Mana Infusion "<< applyColor("(Slightly heal and regain mana of all allies)", "1;32") << " - "  << applyColor("30 mana\n", "1;34") << endl;
    }
    else if (current_character->getName() == "Rogue") {
        cout << "1. Rapid Flurry " << applyColor("(Deal three small hits to an enemy)\n", "1;32") <<
            "2. Cloak of Confusion " << applyColor("(Reduce enemy attack)\n", "1;32") <<
            "3. Expose Weakness " << applyColor("(Reduce enemy's magic and melee resistance)\n", "1;32") << endl;
    }
    else if (current_character->getName() == "Healer") {
        cout << "1. Circle of Vitality " << applyColor("(Heal all allies)", "1;32") << " - " << applyColor("50 mana\n", "1;34") <<
            "2. Divine Restoration " << applyColor("(Regain all characters' mana)", "1;32") << " - " << applyColor("30 mana \n", "1;34") <<
            "3. Blessing of the Guardian " << applyColor("(Defense boost for all allies)", "1;32") << " - " << applyColor("40 mana\n", "1;34") << endl;
    }
    cout << "4. Go Back to Menu" << endl;
}

// function to generate menu to choose character
void chooseCharacter() {
    cout << applyColor("1. Fighter\n", "1;31") <<
        applyColor("2. Mage\n", "1;34") <<
        applyColor("3. Rogue\n", "1;32") <<
        applyColor("4. Healer\n", "1;33") << "\nChoose target: " << endl;
}

// function to show menu of items available in shop
void displayShopItems() {
    int shop_item_counter = 1;
    for (const auto& item : shop_items) {
        cout << shop_item_counter << ". " << applyColor((to_string((int)(item.second * shop_discount))), "1;33") << " gold -> " << item.first << std::endl;
        shop_item_counter++;
    }
}

// function to create 4 buffs and apply them permanently to the party
void applyBlessingToParty(std::string blessing, int intensity) {
    string tstat;
    if(blessing == "Strength") {
        tstat = "meleeDmg";
    }
    else if(blessing == "Savagery") {
        tstat = "critChance";
    }
    else if(blessing == "Ferocity") {
        tstat = "critDmg";
    }
    else if(blessing == "Fortitude") {
        tstat = "defense";
    }
    else if(blessing == "Toughness") {
        tstat = "maxHealth";
    }
    else if(blessing == "Focus") {
        tstat = "maxMana";
    }
    else if(blessing == "Health") {
        tstat = "health";
    }
    else if(blessing == "Mana") {
        tstat = "mana";
    }

    Buff blessing_buff_fighter(&fighter, tstat, intensity);
    Buff blessing_buff_mage(&mage, tstat, intensity);
    Buff blessing_buff_rogue(&rogue, tstat, intensity);
    Buff blessing_buff_healer(&healer, tstat, intensity);

    blessing_buff_fighter.affectCharacterStat();
    blessing_buff_mage.affectCharacterStat();
    blessing_buff_rogue.affectCharacterStat();
    blessing_buff_healer.affectCharacterStat();

    if(tstat == "meleeDmg") {
        Buff extra_buff_fighter(&fighter, "magicDmg", intensity);
        Buff extra_buff_mage(&mage, "magicDmg", intensity);
        Buff extra_buff_rogue(&rogue, "magicDmg", intensity);
        Buff extra_buff_healer(&healer, "magicDmg", intensity);

        extra_buff_fighter.affectCharacterStat();
        extra_buff_mage.affectCharacterStat();
        extra_buff_rogue.affectCharacterStat();
        extra_buff_healer.affectCharacterStat();
    }
}

// simple function to determine if amount of money is enough to buy something of x cost
bool ableToBuyObject(int cost) {
    if(gold < cost){
        return false;
    }
    else {
        return true;
    }
}


// *** OCCURENCE FUNCTIONS *** ///


// there are four types of occurrences in the game: battle, shop, treasure, and rest
// there will be a corresponding function for each

// function for battle
void startBattle(bool final_battle, bool enemy_mimic) {
    int turn_counter = 0;
    bool battleFinished = false;

    // pseudo-random algorithm to determine the enemy that the party will face
    int random_enemy_index;
    if(final_battle == false && enemy_mimic == false){
        random_enemy_index = randomInt(0, 6); // normal battle: between first six enemies
    }
    else if(final_battle == true && enemy_mimic == false){
        random_enemy_index = 8; // final battle: last enemy (dragon)
    }
    else if(final_battle == false && enemy_mimic == true){
        random_enemy_index = 7; // mimic battle: mimic enemy
    }
    // assign the value chosen to a string of an enemy
    string enemyType = all_enemies[random_enemy_index];

    // in order to create an object (current_enemy), and then define it, allocation of memory must be created
    void* rawMemoryEnemy = operator new(sizeof(Enemy));
    // same as with its weapon
    void* rawMemoryWeapon = operator new(sizeof(Weapon));

    // creation and definition of enemy and weapon as null pointers
    Enemy* current_enemy = nullptr;
    Weapon* enemy_weapon = nullptr;

    // with the memory space created, the actual objects are now created in those spaces
    if (enemyType == "Slime") {
        enemy_weapon = new(rawMemoryWeapon) Weapon("Goop Spray", 10 , false);
        current_enemy = new (rawMemoryEnemy) Enemy("Slime", 200 * difficulty, 40 * difficulty, 20, 80, enemy_weapon);
    } else if (enemyType == "Skeleton") {
        enemy_weapon = new(rawMemoryWeapon) Weapon("Dull Sword", 15 , true);
        current_enemy = new (rawMemoryEnemy) Enemy("Skeleton", 200 * difficulty, 40 * difficulty, 20, 80, enemy_weapon);
    } else if (enemyType == "Goblin") {
        enemy_weapon = new(rawMemoryWeapon) Weapon("Small Dagger", 5 , true);
        current_enemy = new (rawMemoryEnemy) Enemy("Goblin", 200 * difficulty, 40 * difficulty, 50, 50, enemy_weapon);
    } else if (enemyType == "Bandit") {
        enemy_weapon = new(rawMemoryWeapon) Weapon("Scimitar", 15, true);
        current_enemy = new (rawMemoryEnemy) Enemy("Bandit", 150 * difficulty, 45 * difficulty, 60, 40, enemy_weapon);
    } else if (enemyType == "Orc") {
        enemy_weapon = new(rawMemoryWeapon) Weapon("Club", 20, true);
        current_enemy = new (rawMemoryEnemy) Enemy("Orc", 200 * difficulty, 45 * difficulty, 30, 70, enemy_weapon);
    } else if (enemyType == "Giant Spider") {
        enemy_weapon = new(rawMemoryWeapon) Weapon("Web Spit", 10, false);
        current_enemy = new (rawMemoryEnemy) Enemy("Giant Spider", 200 * difficulty, 50 * difficulty, 40, 60, enemy_weapon);
    } else if (enemyType == "Golem") {
        enemy_weapon = new(rawMemoryWeapon) Weapon("Fists", 25, true);
        current_enemy = new (rawMemoryEnemy) Enemy("Golem", 175 * difficulty, 45 * difficulty, 100, 0, enemy_weapon);
    } else if (enemyType == "Ghost") {
        enemy_weapon = new(rawMemoryWeapon) Weapon("Ectoplasm", 20, false);
        current_enemy = new (rawMemoryEnemy) Enemy("Ghost", 150 * difficulty, 45 * difficulty, 0, 100, enemy_weapon);
    } else if (enemyType == "Mimic") {
        enemy_weapon = new(rawMemoryWeapon) Weapon("Teeth", 25, true);
        current_enemy = new (rawMemoryEnemy) Enemy("Mimic", 150 * difficulty, 40 * difficulty, 30, 70, enemy_weapon);
    } else if (enemyType == "Dragon") {
        enemy_weapon = new(rawMemoryWeapon) Weapon("Fire Breathing", 40, false);
        current_enemy = new (rawMemoryEnemy) Enemy("Dragon", 2000, 200, 50, 50, enemy_weapon);
    }


    // definition of buff variables
    bool fighter_buff1_active = false;
    int fighter_buff1_turn;
    bool fighter_buff3_active = false;
    int fighter_buff3_turn;
    bool fighter_guard_active = false;
    int fighter_guard_turn;

    bool mage_buff2_active = false;
    int mage_buff2_turn;
    bool mage_guard_active = false;
    int mage_guard_turn;

    bool rogue_buff2_active = false;
    int rogue_buff2_turn;
    bool rogue_buff3_active = false;
    int rogue_buff3_turn;
    bool rogue_guard_active = false;
    int rogue_guard_turn;

    bool healer_buff3_active = false;
    int healer_buff3_turn;
    bool healer_guard_active = false;
    int healer_guard_turn;

    cout << " --- BATTLE START! --- \n" << endl;
    displayHealth(current_enemy);
    cout << "\n";

    while (battleFinished == false) {
        // turn 1: enemy
        cout << "\n ENEMY'S TURN \n" << endl;

        current_enemy->attack(&fighter);
        current_enemy->attack(&mage);
        current_enemy->attack(&rogue);
        current_enemy->attack(&healer);

        cout << "\n" << endl;

        if (fighter.getHealth() <= 0 && mage.getHealth() <= 0 && rogue.getHealth() <= 0 && healer.getHealth() <= 0) {
            cout << applyColor("You lost!", "1;31") << endl;
            exit(0);
        }

        // turn 2: fighter
        if(fighter.getHealth() > 0){
            while (true) {
                bool turnCompleted = false;

                // buff removal and calculation
                // after X amount of turn, remove the buffs that were placed
                if(fighter_buff1_active == true && turn_counter == fighter_buff1_turn + 2) {
                    applyBlessingToParty("Strength", -5);
                    fighter_buff1_active = false;
                }
                if(fighter_buff3_active == true && turn_counter == fighter_buff3_turn + 3) {
                    fighter.setMeleeDmg(fighter.getMeleeDmg() - 30);
                    fighter_buff3_active = false;
                }
                if(fighter_guard_active == true && turn_counter == fighter_guard_turn + 1) {
                    fighter.setDefense(fighter.getDefense() - 10);
                    fighter_guard_active = false;
                }

                // show fighter menu
                displayHealth(current_enemy);
                cout << "\n " << applyColor("FIGHTER'S TURN\n", "1;31") << endl;
                displayMenu(&fighter);
                cout << "\n";
                int choice_fighter;
                cin >> choice_fighter;
                cout << "\n";

                switch(choice_fighter) {
                    case 1: // attack
                        fighter.attackMelee(current_enemy);
                        applyBlessingToParty(fighter.getWeapon().getBlessing(), fighter.getWeapon().getIntensity());
                        turnCompleted = true;
                        break;
                    case 2: // skill
                        displaySkillMenu(&fighter);
                        cout << "\n";
                        int choice_fighter_skill;
                        cin >> choice_fighter_skill;
                        cout << "\n";
                        switch(choice_fighter_skill) {
                            case 1: { // give a little strength to everyone
                                applyBlessingToParty("Strength", 5);
                                fighter_buff1_active = true;
                                fighter_buff1_turn = turn_counter;
                                turnCompleted = true;
                                break;
                            }
                            case 2: { // big melee damage
                                fighter.attackMelee(current_enemy);
                                fighter.attackMelee(current_enemy);
                                turnCompleted = true;
                                break;
                            }
                            case 3: { // more damage for himself
                                fighter.setMeleeDmg(fighter.getMeleeDmg() + 30);
                                fighter_buff3_active = true;
                                fighter_buff3_turn = turn_counter;
                                turnCompleted = true;
                                break;
                            }
                            case 4:
                                continue;
                        }

                    case 3: // guard
                        fighter.guard();
                        turnCompleted = true;
                        fighter_guard_active = true;
                        fighter_guard_turn = turn_counter;
                        break;
                    case 4: // check stats
                        cout << "Strength: " << (fighter.getMeleeDmg() + fighter.getWeapon().getDamage()) << endl;
                        cout << "Defense: " << fighter.getDefense() << endl;
                        cout << "Critical Chance: " << fighter.getCritChance() << "%" << endl;
                        cout << "Critical Damage: " << (fighter.getCritDmg() + 100) << "%" << endl;
                        cout << "\n";
                        continue;
                    default:
                        cout << "Invalid input" << endl;
                        continue;
                }
                // end character turn
                if(turnCompleted == true){
                    break;
                }
            }
        }

        // repeated function to check if enemy is dead after character attacks
        if(current_enemy->getHealth() <= 0) {
            battleFinished = true;
            break;
        }

        // turn 3: mage
        if(mage.getHealth() > 0){
            while (true) {
                bool turnCompleted = false;

                // buff removal and calculations
                if(mage_buff2_active == true & turn_counter == mage_buff2_turn + 2) {
                    applyBlessingToParty("Savagery", -5);
                    applyBlessingToParty("Ferocity", -15);
                    mage_buff2_active = false;
                }
                if(mage_guard_active == true && turn_counter == mage_guard_turn + 1) {
                    mage.setDefense(mage.getDefense() - 10);
                    mage_guard_active = false;
                }

                displayHealth(current_enemy);
                cout << "\n " << applyColor("MAGE'S TURN\n", "1;34") << endl;
                displayMenu(&mage);
                cout << "\n";
                int choice_mage;
                cin >> choice_mage;
                cout << "\n";
                switch(choice_mage) {
                    case 1: // attack
                        mage.attackMagic(current_enemy, 0);
                        turnCompleted = true;
                        break;
                    case 2: // skill
                        displaySkillMenu(&mage);
                        cout << "\n";
                        int choice_mage_skill;
                        cin >> choice_mage_skill;
                        cout << "\n";
                        switch(choice_mage_skill) {
                            case 1: // big damage to enemy
                                if(mage.getMana() >= 50) {
                                    mage.attackMagic(current_enemy, 50);
                                    mage.attackMagic(current_enemy, 0);
                                    turnCompleted = true;
                                    break;
                                }
                                else {
                                    cout << "Not enough mana!" << endl;
                                    continue;
                                }

                            case 2: // increase crit chance and dmg slightly
                                if(mage.getMana() >= 40) {
                                    applyBlessingToParty("Savagery", 5);
                                    applyBlessingToParty("Ferocity", 15);
                                    mage_buff2_active = true;
                                    mage_buff2_turn = turn_counter;
                                    mage.setMana(mage.getMana() - 40);
                                    turnCompleted = true;
                                    break;
                                }
                                else {
                                    cout << "Not enough mana!" << endl;
                                    continue;
                                }

                            case 3: // heal all allies health & mana slightly
                                if(mage.getMana() >= 30) {
                                    mage.setMana(mage.getMana() - 30);
                                    applyBlessingToParty("Health", 30);
                                    applyBlessingToParty("Mana", 20);
                                    turnCompleted = true;
                                    break;
                                }
                                else {
                                    cout << "Not enough mana!" << endl;
                                    continue;
                                }

                            case 4:
                                continue;
                        }

                    case 3: // guard
                        mage.guard();
                        turnCompleted = true;
                        mage_guard_active = true;
                        mage_guard_turn = turn_counter;
                        break;
                    case 4: // check stats
                        cout << "Strength: " << (mage.getMagicDmg() + mage.getWeapon().getDamage()) << endl;
                        cout << "Defense: " << mage.getDefense() << endl;
                        cout << "Critical Chance: " << mage.getCritChance() << "%" << endl;
                        cout << "Critical Damage: " << (mage.getCritDmg() + 100) << "%" << endl;
                        cout << "\n";
                        continue;
                }
                // end character turn
                if(turnCompleted == true){
                    break;
                }
            }
        }

        // repeated function to check if enemy is dead after character attacks
        if(current_enemy->getHealth() <= 0) {
            battleFinished = true;
            break;
        }

        // turn 4: rogue
        if(rogue.getHealth() > 0) {
            while (true) {
                bool turnCompleted = false;

                // buff removal and calculations
                if(rogue_buff2_active == true && turn_counter == rogue_buff2_turn + 2) {
                    Buff increaseEnemyAtk(current_enemy, "strength", 20);
                    increaseEnemyAtk.affectEnemyStat();
                    rogue_buff2_active = false;
                }
                if(rogue_buff3_active == true && turn_counter == rogue_buff3_turn + 2) {
                    Buff increaseEnemyMagicRes(current_enemy, "magicRes", 20);
                    Buff increaseEnemyMeleeRes(current_enemy, "meleeRes", 20);
                    increaseEnemyMagicRes.affectEnemyStat();
                    increaseEnemyMeleeRes.affectEnemyStat();
                    rogue_buff3_active = false;
                }
                if(rogue_guard_active == true && turn_counter == rogue_guard_turn + 1) {
                    rogue.setDefense(rogue.getDefense() - 10);
                    rogue_guard_active = false;
                }

                displayHealth(current_enemy);
                cout << "\n " << applyColor("ROGUE'S TURN\n", "1;32") << endl;
                displayMenu(&rogue);
                cout << "\n";
                int choice_rogue;
                cin >> choice_rogue;
                cout << "\n";

                switch(choice_rogue) {
                    case 1: // attack
                        rogue.attackMelee(current_enemy);
                        turnCompleted = true;
                        break;
                    case 2: // skill
                        displaySkillMenu(&rogue);
                        cout << "\n";
                        int choice_rogue_skill;
                        cin >> choice_rogue_skill;
                        cout << "\n";
                        switch(choice_rogue_skill) {
                            case 1: {    // moderate melee dmg to enemy
                                rogue.setMeleeDmg(rogue.getMeleeDmg() + 15);
                                rogue.attackMelee(current_enemy);
                                rogue.setMeleeDmg(rogue.getMeleeDmg() - 15);
                                turnCompleted = true;
                                break;
                            }
                            case 2: {       // reduce enemy atk
                                Buff reduceEnemyAtk(current_enemy, "strength", -20);
                                reduceEnemyAtk.affectEnemyStat();
                                rogue_buff2_active = true;
                                rogue_buff2_turn = turn_counter;
                                turnCompleted = true;
                                break;
                            }
                            case 3: {   // reduce enemy magic & melee res
                                Buff reduceEnemyMagicRes(current_enemy, "magicRes", -20);
                                Buff reduceEnemyMeleeRes(current_enemy, "meleeRes", -20);
                                reduceEnemyMagicRes.affectEnemyStat();
                                reduceEnemyMeleeRes.affectEnemyStat();
                                rogue_buff3_active = true;
                                rogue_buff3_turn = turn_counter;
                                turnCompleted = true;
                                break;
                            }
                            case 4:
                                continue;
                        }

                    case 3: // guard
                        rogue.guard();
                        turnCompleted = true;
                        rogue_guard_active = true;
                        rogue_guard_turn = turn_counter;
                        break;
                    case 4: // check stats
                        cout << "Strength: " << (rogue.getMagicDmg() + rogue.getWeapon().getDamage()) << endl;
                        cout << "Defense: " << rogue.getDefense() << endl;
                        cout << "Critical Chance: " << rogue.getCritChance() << "%" << endl;
                        cout << "Critical Damage: " << (rogue.getCritDmg() + 100) << "%" << endl;
                        cout << "\n";
                        continue;
                }
                // end character turn
                if(turnCompleted == true){
                    break;
                }
            }
        }

        // repeated function to check if enemy is dead after character attacks
        if(current_enemy->getHealth() <= 0) {
            battleFinished = true;
            break;
        }

        // turn 5: healer
        if(healer.getHealth() > 0) {
            while (true) {
                bool turnCompleted = false;

                // buff removal and calculation
                if(healer_buff3_active == true && turn_counter == healer_buff3_turn + 2) {
                    applyBlessingToParty("Fortitude", -20);
                    healer_buff3_active = false;
                }
                if(healer_guard_active == true && turn_counter == healer_guard_turn + 1) {
                    healer.setDefense(healer.getDefense() - 10);
                    healer_guard_active = false;
                }

                displayHealth(current_enemy);
                cout << "\n " << applyColor("HEALER'S TURN\n", "1;33") << endl;
                displayMenu(&healer);
                cout << "\n";
                int choice_healer;
                cin >> choice_healer;
                cout << "\n";
                switch(choice_healer) {
                    case 1: // attack
                        healer.attackMagic(current_enemy, 0);
                        turnCompleted = true;
                        break;
                    case 2: // skill
                        displaySkillMenu(&healer);
                        cout << "\n";
                        int choice_healer_skill;
                        cin >> choice_healer_skill;
                        cout << "\n";
                        switch(choice_healer_skill) {
                            case 1: {  // heal all allies
                                if(healer.getMana() >= 50) {
                                    healer.setMana(healer.getMana() - 50);
                                    applyBlessingToParty("Health", 50);
                                    turnCompleted = true;
                                    break;
                                }
                                else {
                                    cout << "Not enough mana!" << endl;
                                    continue;
                                }
                            }
                            case 2: { // regen mana for all allies
                                if(healer.getMana() >= 30) {
                                    healer.setMana(healer.getMana() - 30);
                                    applyBlessingToParty("Mana", 50);
                                    turnCompleted = true;
                                    break;
                                }
                                else {
                                    cout << "Not enough mana!" << endl;
                                    continue;
                                }
                            }
                            case 3: {    // increase def for all allies
                                if(healer.getMana() >= 40) {
                                    applyBlessingToParty("Fortitude", 20);
                                    healer.setMana(healer.getMana() - 40);
                                    healer_buff3_active = true;
                                    healer_buff3_turn = turn_counter;
                                    turnCompleted = true;
                                    break;
                                }
                                else {
                                    cout << "Not enough mana!" << endl;
                                    continue;
                                }
                            }
                            case 4:
                                continue;
                        }

                    case 3: // guard
                        healer.guard();
                        turnCompleted = true;
                        break;
                    case 4: // check stats
                        cout << "Strength: " << (healer.getMagicDmg() + healer.getWeapon().getDamage()) << endl;
                        cout << "Defense: " << healer.getDefense() << endl;
                        cout << "Critical Chance: " << healer.getCritChance() << "%" << endl;
                        cout << "Critical Damage: " << (healer.getCritDmg() + 100) << "%" << endl;
                        cout << "\n";
                        continue;
                }
                // end character turn
                if(turnCompleted == true){
                    break;
                }
            }
        }

        // repeated function to check if enemy is dead after character attacks
        if(current_enemy->getHealth() <= 0) {
            battleFinished = true;
            break;
        }

        turn_counter++;
    }
    cout << applyColor("You won!\n", "1;32") << endl;

    // remove temporary buffs that were applied during battle
    // fighter
    if(fighter_buff1_active == true) {
        applyBlessingToParty("Strength", -5);
        fighter_buff1_active = false;
    }
    if(fighter_buff3_active == true) {
        fighter.setMeleeDmg(fighter.getMeleeDmg() - 30);
        fighter_buff3_active = false;
    }
    if(fighter_guard_active == true) {
        fighter.setDefense(fighter.getDefense() - 10);
        fighter_guard_active = false;
    }
    // mage
    if(mage_buff2_active == true) {
        applyBlessingToParty("Savagery", -5);
        applyBlessingToParty("Ferocity", -15);
        mage_buff2_active = false;
    }
    if(mage_guard_active == true && turn_counter) {
        mage.setDefense(mage.getDefense() - 10);
        mage_guard_active = false;
    }
    // rogue
    if(rogue_buff2_active == true) {
        Buff increaseEnemyAtk(current_enemy, "strength", 20);
        increaseEnemyAtk.affectEnemyStat();
        rogue_buff2_active = false;
    }
    if(rogue_buff3_active == true) {
        Buff increaseEnemyMagicRes(current_enemy, "magicRes", 20);
        Buff increaseEnemyMeleeRes(current_enemy, "meleeRes", 20);
        increaseEnemyMagicRes.affectEnemyStat();
        increaseEnemyMeleeRes.affectEnemyStat();
        rogue_buff3_active = false;
    }
    if(rogue_guard_active == true) {
        rogue.setDefense(rogue.getDefense() - 10);
        rogue_guard_active = false;
    }
    // healer
    if(healer_buff3_active == true && turn_counter == healer_buff3_turn + 2) {
        applyBlessingToParty("Fortitude", -20);
        healer_buff3_active = false;
    }
    if(healer_guard_active == true && turn_counter == healer_guard_turn + 1) {
        healer.setDefense(healer.getDefense() - 10);
        healer_guard_active = false;
    }

    // rewards after battle
    // gold and 1 blessing from 3 options

    int rewardGain = randomInt(2, 8);
    int gold_found = (20 + rewardGain) * gold_gain * difficulty;
    gold = gold + gold_found;
    applyBlessingToParty(all_blessings[rewardGain], 10);

    cout << "--- Rewards! --- \n- " << applyColor(to_string(gold_found) + " gold\n", "1;33") << "- Blessing of " << applyColor(all_blessings[rewardGain], "1;33") << "\n" << endl;

    // regen
    applyBlessingToParty("Health", health_regen);

}

// function for shop
void enterShop() {
    cout << "You encounter a friendly merchant in the middle of the Tower. \n" << " - "<< applyColor("Welcome to the Shop! Will you buy something?\n", "1;36");
    displayShopItems();
    cout << "\n14. Exit the Shop" << endl;
    bool shopping = true;
    while(shopping == true) {
        cout << "Gold: " << applyColor(to_string(gold), "1;33") << endl;
        int shop_choice;
        cout << "What do you want to buy?: ";
        cin >> shop_choice;
        switch(shop_choice) {
            int current_price;
            case 1: // ferocity (crit dmg)
                current_price = (shop_items["Blessing of Ferocity " + applyColor(" (Permanent critical damage increase)", "1;32")]) * shop_discount;
                if(ableToBuyObject(current_price)){
                    applyBlessingToParty("Ferocity", 10);
                    cout << applyColor("\nBlessing acquired! \n", "1;32") << endl;
                    gold = gold - current_price;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }
            case 2: // focus (max mana)
                current_price = (shop_items["Blessing of Focus " + applyColor(" (Permanent maximum mana increase)", "1;32")]) * shop_discount;
                cout << current_price << endl;
                if(ableToBuyObject(current_price)){
                    applyBlessingToParty("Focus", 20);
                    cout << applyColor("Blessing acquired! \n", "1;32") << endl;
                    gold = gold - current_price;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }
            case 3: // fortitude (def increase)
                current_price = (shop_items["Blessing of Fortitude " + applyColor(" (Permanent defense increase)", "1;32")]) * shop_discount;
                cout << current_price << endl;
                if(ableToBuyObject(current_price)){
                    applyBlessingToParty("Fortitude", 20);
                    cout << applyColor("Blessing acquired! \n", "1;32") << endl;
                    gold = gold - current_price;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }
            case 4: // loyalty (shop prices)
                current_price = (shop_items["Blessing of Loyalty " + applyColor(" (Reduce shop prices)", "1;32")]) * shop_discount;
                if(ableToBuyObject(current_price)){
                    shop_discount = shop_discount - 0.1;
                    cout << applyColor("Blessing acquired! \n", "1;32") << endl;
                    gold = gold - current_price;
                    displayShopItems();
                    cout << "\n14. Exit the Shop" << endl;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }
            case 5: // regeneration (heal damage after battles)
                current_price = (shop_items["Blessing of Regeneration " + applyColor(" (Heal some damage after battle)", "1;32")]) * shop_discount;
                if(ableToBuyObject(current_price)){
                    health_regen = health_regen + 5;
                    cout << applyColor("Blessing acquired! \n", "1;32") << endl;
                    gold = gold - current_price;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }
            case 6: // savagery (crit chance)
                current_price = (shop_items["Blessing of Savagery " + applyColor(" (Permanent critical chance increase)", "1;32")]) * shop_discount;
                if(ableToBuyObject(current_price)){
                    applyBlessingToParty("Savagery", 5);
                    cout << applyColor("Blessing acquired! \n", "1;32") << endl;
                    gold = gold - current_price;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }
            case 7: // strength (damage)
                current_price = (shop_items["Blessing of Strength " + applyColor(" (Permanent damage increase for whole party)", "1;32")]) * shop_discount;
                if(ableToBuyObject(current_price)){
                    applyBlessingToParty("Strength", 20);
                    cout << applyColor("Blessing acquired! \n", "1;32") << endl;
                    gold = gold - current_price;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }
            case 8: // toughness (max health)
                current_price = (shop_items["Blessing of Toughness " + applyColor(" (Permanent maximum health increase)", "1;32")]) * shop_discount;
                if(ableToBuyObject(current_price)){
                    applyBlessingToParty("Toughness", 20);
                    cout << applyColor("Blessing acquired! \n", "1;32") << endl;
                    gold = gold - current_price;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }
            case 9: // wealth (more gold after battles)
                current_price = (shop_items["Blessing of Wealth " + applyColor(" (Gain more gold after battles)", "1;32")]) * shop_discount;
                if(ableToBuyObject(current_price)){
                    gold_gain = gold_gain + 0.2;
                    cout << applyColor("Blessing acquired! \n", "1;32") << endl;
                    gold = gold - current_price;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }

            case 10: // rogue weapon
                current_price = (shop_items["Dagger (Rogue)"]) * shop_discount;
                cout << current_price << endl;
                if(ableToBuyObject(current_price)){
                    BlessedWeapon newWeapon("Blessed Dagger", rogue.getWeapon().getDamage() + 20, true, "Ferocity", rogue.getWeapon().getDamage() - 5);
                    rogue.equipWeapon(&newWeapon);
                    cout << applyColor("Dagger equipped! \n", "1;32") << endl;
                    gold = gold - current_price;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }
            case 11: // healer weapon
                current_price = (shop_items["Spell Book (Healer)"]) * shop_discount;
                cout << current_price << endl;
                if(ableToBuyObject(current_price)){
                    BlessedWeapon newWeapon("Blessed Spell Book", healer.getWeapon().getDamage() + 20, true, "Fortitude", healer.getWeapon().getDamage() - 5);
                    healer.equipWeapon(&newWeapon);
                    cout << applyColor("Spell Book equipped! \n", "1;32") << endl;
                    gold = gold - current_price;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }
            case 12: // mage weapon
                current_price = (shop_items["Staff (Mage)"]) * shop_discount;
                cout << current_price << endl;
                if(ableToBuyObject(current_price)){
                    BlessedWeapon newWeapon("Blessed Staff)", mage.getWeapon().getDamage() + 20, true, "Savagery", mage.getWeapon().getDamage() - 5);
                    mage.equipWeapon(&newWeapon);
                    cout << applyColor("Staff equipped! \n", "1;32") << endl;
                    gold = gold - current_price;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }
            case 13: // fighter weapon
                current_price = (shop_items["Sword (Fighter)"]) * shop_discount;
                cout << current_price << endl;
                if(ableToBuyObject(current_price)){
                    BlessedWeapon newWeapon("Blessed Sword", fighter.getWeapon().getDamage() + 20, true, "Strength", fighter.getWeapon().getDamage() - 5);
                    fighter.equipWeapon(&newWeapon);
                    cout << applyColor("Sword equipped! \n", "1;32") << endl;
                    gold = gold - current_price;
                    break;
                }
                else {
                    cout << " - "<< applyColor("You can't afford that!\n", "1;36");
                    continue;
                }
            case 14: // exit shop
                shopping = false;
                cout << " - " << applyColor("See you soon!\n", "1;36");

        }
    }
}

// function for treasure
void enterTreasure() {
    cout << "As you ascend, you encounter a quiet room. In the center of the room, there's a " << applyColor("chest", "1;33") << ". You decide to open it." << endl;
    int treasure_gamble = randomInt(0, 100);
    if(treasure_gamble < 90){
        int gold_found = (30 + (treasure_gamble / 5)) * gold_gain * difficulty;
        gold = gold + gold_found;
        cout << "Inside the chest, you find " << applyColor(to_string(gold_found) + " gold", "1;33") << "!\n";

        int blessing1 = randomInt(2, 8);
        int blessing2 = randomInt(2, 8);
        int blessing3 = randomInt(2, 8);

        applyBlessingToParty(all_blessings[blessing1], 10);
        applyBlessingToParty(all_blessings[blessing2], 10);
        applyBlessingToParty(all_blessings[blessing3], 10);

        cout << "You also found some " << applyColor("blessings", "1;33") << "!\n";
        cout << "You got a Blessing of " << all_blessings[blessing1] << ", a Blessing of " << all_blessings[blessing2] << ", and a Blessing of " << all_blessings[blessing3] << "!\n" <<endl;
        // clearLastLines(4);

    }
    else {
        cout << "As you try to open the chest, you notice some " << applyColor("teeth", "1;31") << " on the border of the chest.\n" <<
            "It's a " << applyColor("mimic", "1;31") << "! You enter battle.\n" << endl;
        startBattle(false, true);

        cout << "\nShaken by the experience, you leave this room. " << endl;
    }
}

// function for rest
void enterRest() {
    cout << "You encounter a safe room. You all decide to " << applyColor("rest", "1;32") << " for a while.\n" << endl;
    int random_healing_amount = randomInt(0, 50);
    int amount_healing = 50 + random_healing_amount;

    cout << "You all healed " << applyColor(to_string(amount_healing) + " HP. ", "1;32") << "\nYou also regained " << applyColor("all your mana", "1;34") << ".\n" << endl;

    applyBlessingToParty("Health", amount_healing);
    applyBlessingToParty("Mana", mage.getMaxMana());
}

int main() {
    // seed the random number generator
    srand(time(nullptr));

    string types_of_rooms[4] = {"Fight", "Shop", "Treasure", "Rest"};

    // rooms: from room 1 (base of the tower) to room 10 (top of the tower)
    for (int i = 1; i <= 10; i++) {
        if(i == 1){
            // introduction
            cout << "You are a group of adventurers that heard stories of an " << applyColor("evil dragon", "1;31") << " that lives on top of a tower. \n"
                << "Said " << applyColor("dragon", "1;31") << " has been terrorizing the locals and stealing their food. \n"
                << "Are you up to the task of " << applyColor("slaying it?", "1;32") << "\n" << endl;

            cout << "Good luck, " << applyColor("heroes! \n", "1;33") << endl;

            // tutorial
            cout << "(The combats in this game are turn-based. First, the enemy has a turn, then each of your allies will get a turn)\n"
                << "(You have four allies in your party:\n - The " << applyColor("Fighter", "1;31") << ", your main melee damage dealer, capable of buffing himself and others."
                << "\n - The " << applyColor("Mage", "1;34") << ", your main magic damage dealer, capable of buffing your allies and delivering big magic damage. "
                << "\n - The " << applyColor("Rogue", "1;32") << ", your main source of debuffs for the enemies, also capable of dealing some melee damage. "
                << "\n - The " << applyColor("Healer", "1;33") << ", capable of healing your allies and granting buffs to them. \n"
                << "\n (After battle, you will gain " << applyColor("gold", "1;33") << " and a " << applyColor("blessing", "1;33") << ". Gold will allow you to buy upgrades at the shop, "
                << "while blessings will provide you with permanent buffs for your party this run.)\n"
                << "\n(You might sometimes find a treasure room, which has gold and three random blessings. But " << applyColor("be careful", "1;31") << ", not everything is what it seems...)\n"
                << "\n(If you ever need it, you can also find a rest place, where all characters will regenerate all health and mana)\n" << endl;

            cout << applyColor("Are you ready?", "1;32") << " Press Enter to continue\n" << endl;
            cin.ignore(1);

            cout << " *** FLOOR 1 *** \n" << endl;
            startBattle(false, false);
        }
        else if(i == 10){
            cout << " *** FLOOR 10 *** \n" << endl;
            cout << "\nYou have reached the top of the tower. The " << applyColor("evil dragon", "1;31") << " lays within. Finish what you came here for. \n" << endl;
            startBattle(true, false);
        }
        else {
            int random_room_1 = randomInt(0, 3);
            int random_room_2 = randomInt(0, 3);
            int random_room_3 = randomInt(0, 3);

            cout << applyColor("Choose your next path: \n", "1;35") << "1. " << types_of_rooms[random_room_1] <<
                "\t 2. " << types_of_rooms[random_room_2] << "\t 3. " << types_of_rooms[random_room_3] << "\nChoose: ";
            int room_choice;
            cin >> room_choice;
            cout << "\n";

            cout << " *** FLOOR "<< i << " *** \n" << endl;

            switch(room_choice){
                case 1:
                    if(types_of_rooms[random_room_1] == "Fight"){
                        startBattle(false, false);
                    }
                    else if(types_of_rooms[random_room_1] == "Shop"){
                        enterShop();
                    }
                    else if(types_of_rooms[random_room_1] == "Treasure"){
                        enterTreasure();
                    }
                    else if(types_of_rooms[random_room_1] == "Rest"){
                        enterRest();
                    }
                    break;
                case 2:
                    if(types_of_rooms[random_room_2] == "Fight"){
                        startBattle(false, false);
                    }
                    else if(types_of_rooms[random_room_2] == "Shop"){
                        enterShop();
                    }
                    else if(types_of_rooms[random_room_2] == "Treasure"){
                        enterTreasure();
                    }
                    else if(types_of_rooms[random_room_2] == "Rest"){
                        enterRest();
                    }
                    break;
                case 3:
                    if(types_of_rooms[random_room_3] == "Fight"){
                        startBattle(false, false);
                    }
                    else if(types_of_rooms[random_room_3] == "Shop"){
                        enterShop();
                    }
                    else if(types_of_rooms[random_room_3] == "Treasure"){
                        enterTreasure();
                    }
                    else if(types_of_rooms[random_room_3] == "Rest"){
                        enterRest();
                    }
                    break;
            }

        }
        // increase difficulty
        difficulty = difficulty + 0.2;
    }
    cout << "\nCongratulations! You've beaten the game\n" << endl;
    cout << "Final Stats: \n" << endl;
}
