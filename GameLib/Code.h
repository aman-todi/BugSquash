/**
 * @file Code.h
 * @author Ethan Silver
 *
 *
 */

#ifndef PROJECT1_CODE_H
#define PROJECT1_CODE_H

class Code {
private:

    /// The current string value of the code
    std::wstring mCodeData;

    /// The Solution (Loaded via XML)
    std::wstring mSolution;
public:

    bool Passes() {return (mCodeData == mSolution);}

    void SetCode(std::wstring code) {mCodeData = code;}

    std::wstring GetCode() {return mCodeData;}

    void SetSolution(std::wstring sol) {mSolution = sol;}
    std::wstring GetSol() {return mSolution;}

};

#endif //PROJECT1_CODE_H
