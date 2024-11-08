#include "Buff.h"

Buff::Buff(int intensity, Stat targetStat) {
    this->intensity = intensity;
    this->targetStat = targetStat;
}

Buff::Buff(int intensity, Stat targetStat, int duration) {
    this->intensity = intensity;
    this->targetStat = targetStat;
    this->duration = duration;
}

void Buff::affectStat() {
    targetStat.tempChangeStat(intensity, duration);
}

void Buff::permamentStatChange() {
    targetStat.changeStat(intensity);
}

void Buff::affectStatOverTime() {
    // for (i = 1; i < duration; i++) {
        targetStat.changeStat(intensity);
    // }

}
