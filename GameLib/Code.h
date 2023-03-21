/**
 * @file Code.h
 * @author Ethan Silver
 *
 *
 */

#ifndef PROJECT1_CODE_H
#define PROJECT1_CODE_H
/**
 * What makes a FatBug
 */
class Code {
private:

    /// The current string value of the code
    std::string mCodeData;

    /// The Solution (Loaded via XML)
    std::string mSolution;
public:
	/**
	 * Checks to see if user input is correct
	 * @return True if the user inputted the correct info
	 */
    bool Passes() {return (mCodeData == mSolution);}

	/**
	 * Set the code for fat bug
	 * @param code The string value of the code
	 */
    void SetCode(std::string code) {mCodeData=code;}
	/**
	 * Gets the code for Fat Bug
	 * @return the code for Fat Bug
	 */
    std::string GetCode() {return mCodeData;}
	/**
	 * The answer to the FatBug
	 * @param sol The answer to fat Bug
	 */
    void SetSolution(std::string sol) {mSolution = sol;}
	/**
	 * Get the solution to the fat bug
	 * @return The solution to the Fat Bug
	 */
    std::string GetSol() {return mSolution;}
};

#endif //PROJECT1_CODE_H
