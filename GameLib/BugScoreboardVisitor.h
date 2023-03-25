/**
 * @file BugScoreboardVisitor.h
 * @author Ethan Silver
 *
 *
 */

#ifndef PROJECT1_BUGSCOREBOARDVISITOR_H
#define PROJECT1_BUGSCOREBOARDVISITOR_H

#include "ItemsVisitor.h"
#include "Bug.h"
#include "Scoreboard.h"

class GarbageBug;
class FeatureBug;
class NullBug;
class RedundancyBug;
class Spider;

class BugScoreboardVisitor : public ItemsVisitor {
private:
    /// Pointer to Game Scoreboard
    std::shared_ptr<Scoreboard> mScoreboard;
public:

    /**
     * visit garbage bug
     * @param bug garbage bug
     */
    void VisitGarbageBug(GarbageBug* bug) override;

    /**
     * visit null bug
     * @param bug null bug
     */
    void VisitNullBug(NullBug* bug) override;

    /**
     * Visit redundancy bug
     * @param bug redundancy bug in question
     */
    void VisitRedundancyBug (RedundancyBug* bug) override;

    /**
     * Vist Feature bug
     * @param bug feature bug in question
     */
    void VisitFeatureBug (FeatureBug* bug) override ;

    /**
     * Set Scoreboard Pointer to Game Scoreboard
     * @param sb
     */
    void SetScoreboard(std::shared_ptr<Scoreboard> sb) {mScoreboard = sb;}

    /**
     * Call Scoreboard IncMissed Functionality
     */
    void IncMiss();

};

#endif //PROJECT1_BUGSCOREBOARDVISITOR_H
