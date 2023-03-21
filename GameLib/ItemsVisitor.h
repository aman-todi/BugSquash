/**
 * @file ItemsVisitor.h
 * @author Aman Todi
 *
 *
 */

#ifndef PROJECT1_GAMELIB_ITEMSVISITOR_H
#define PROJECT1_GAMELIB_ITEMSVISITOR_H

// Forward references to all bug types
class Item;
class Bug;
class GarbageBug;
class NullBug;
class RedundancyBug;
class FeatureBug;
class Program;
class Spider;

/** Items visitor base class */
class ItemsVisitor
{
protected:
	/**
	 * Constructor
	 * Ensures this is an abstract class
	 */
	ItemsVisitor() {}

public:
	virtual ~ItemsVisitor() {}

	/**
	 * Visit a Garbage bug
	 * @param bug
	 */
	virtual void VisitGarbageBug(GarbageBug* bug) {}

	/**
	 * Visit a Null bug
	 * @param bug
	 */
	virtual void VisitNullBug(NullBug* bug) {}

	/**
	 * Visit a Redundancy bug
	 * @param bug
	 */
	virtual void VisitRedundancyBug(RedundancyBug* bug) {}

	/**
	 * Visit a Feature bug
	 * @param bug
	 */
	virtual void VisitFeatureBug(FeatureBug* bug) {}

	/**
	 * Visit a Program
	 * @param bug
	 */
	virtual void VisitProgram(Program* bug) {}

	/**
	 * visit spider
	 */
	virtual void VisitSpider (Spider* bug){}

};

#endif //PROJECT1_GAMELIB_ITEMSVISITOR_H
