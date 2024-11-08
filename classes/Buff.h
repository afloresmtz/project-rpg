#ifndef BUFF_H
#define BUFF_H

class Buff {
private:
    int intensity;
    Stat targetStat;
    int duration;
public:
    Buff(int intensity, Stat targetStat);
    Buff(int intensity, Stat targetStat, int duration);

    void affectStat();
    void permanentStatChange();
    void affectStatOverTime(int duration);
};

#endif
