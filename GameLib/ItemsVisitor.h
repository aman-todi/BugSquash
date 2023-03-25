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
class ShapeShifterBug;

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
	 * @param bug The bug being visited
	 */
	virtual void VisitGarbageBug(GarbageBug* bug) {}

	/**
	 * Visit a Null bug
	 * @param bug The bug being visited
	 */
	virtual void VisitNullBug(NullBug* bug) {}

	/**
	 * Visit a Redundancy bug
	 * @param bug The bug being visited
	 */
	virtual void VisitRedundancyBug(RedundancyBug* bug) {}

	/**
	 * Visit a Feature bug
	 * @param bug The bug being visited
	 */
	virtual void VisitFeatureBug(FeatureBug* bug) {}

	/**
	 * Visit a Program
	 * @param bug The bug being visited
	 */
	virtual void VisitProgram(Program* bug) {}

	/**
	 * Visit a Spider
	 * @param bug The bug being visited
	 */
	virtual void VisitSpider (Spider* bug){}

	/**
 	 * Visit a Spider
	 * @param bug The bug being visited
  	 */
	virtual void VisitShapeShifterBug (ShapeShifterBug* bug){}

};

#endif //PROJECT1_GAMELIB_ITEMSVISITOR_H
