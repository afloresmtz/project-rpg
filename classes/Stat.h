#ifndef STAT_H
#define STAT_H

class Stat {
private:
    int value;
public:
    Stat(int initialValue);

    int getStat();
    void changeStat(int amount);
    void tempChangeStat(int amount, int time);
};

#endif

