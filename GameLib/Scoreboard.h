/**
 * @file Scoreboard.h
 * @author Ethan Silver
 *
 *
 */

#ifndef PROJECT1_SCOREBOARD_H
#define PROJECT1_SCOREBOARD_H
/**
 * The Main ScoreBoard class
 */
class Scoreboard {
private:
	/// Score of Fixed Bug
    int mFixed = 0;
	/// Score of Missed Bug
    int mMissed = 0;
	/// Score of squashed Feature bugs
    int mOops = 0;
public:
    Scoreboard();
	/**
	 * Getter for the Fixed score
	 * @return the score of mFixed
	 */
    int GetFixed() {return mFixed;};
	/**
	 * Getter for the Missed  score
	 * @return the score of mMissed
	 */
    int GetMissed() {return mMissed;}
	/**
	 * Getter for the Oops score
	 * @return the score of mOops
	 */
    int GetOops() {return mOops;}

    /**
     * Update Score
     * @param fix
     * @param miss
     * @param oop
     */
    void KeepScore(int fix, int miss, int oop);

    /**
     * Draw Scoreboard
     * @param gc
     */
    void Draw(std::shared_ptr<wxGraphicsContext> gc);
};

#endif //PROJECT1_SCOREBOARD_H
