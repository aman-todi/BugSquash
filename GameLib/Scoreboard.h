/**
 * @file Scoreboard.h
 * @author Ethan Silver
 *
 *
 */

#ifndef PROJECT1_SCOREBOARD_H
#define PROJECT1_SCOREBOARD_H

class Scoreboard {
private:
    int mFixed;
    int mMissed;
    int mOops;
public:
    Scoreboard();

    int GetFixed() {return mFixed;};
    int GetMissed() {return mMissed;}
    int GetOops() {return mOops;}

    void KeepScore(int fix, int miss, int oop);
};

#endif //PROJECT1_SCOREBOARD_H
