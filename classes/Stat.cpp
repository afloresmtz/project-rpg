#include "Stat.h"

Stat::Stat(int initialValue){
    value = initialValue;
}

int Stat::getStat() {
    return value;
}

void Stat::changeStat(int amount) {
    value = value + amount;
}

void Stat::tempChangeStat(int amount, int time) {
    // change the stat for X amount for Y amount of turns
}
