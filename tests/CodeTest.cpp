/**
 * @file CodeTest.cpp
 * @author Ethan Silve
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Code.h>

#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

using namespace std;

TEST(CodeTest,Construct)
{
    Code code;
}

TEST(CodeTest, CodeGetterSetter) {
    Code code;
    std::wstring fixed =L"/**\n"
                        L" * The game scoreboard/scoring area\n"
                        L" */\n"
                        L"class ScoreBoard\n"
                        L"{\n"
                        L"private:\n"
                        L"    /// The current score\n"
                        L"    int mScore = 77;\n"
                        L"\n"
                        L"public:\n"
                        L"    void Draw(std::shared_ptr<wxGraphicsContext> graphics);\n"
                        L"};\n";
    code.SetCode(fixed);

    ASSERT_TRUE(fixed == code.GetCode());
}

TEST(CodeTest, SolGetterSetter){
    Code code;
    std::wstring fixed =L"/**\n"
                        L" * The game scoreboard/scoring area\n"
                        L" */\n"
                        L"class ScoreBoard\n"
                        L"{\n"
                        L"private:\n"
                        L"    /// The current score\n"
                        L"    int mScore = 77;\n"
                        L"\n"
                        L"public:\n"
                        L"    void Draw(std::shared_ptr<wxGraphicsContext> graphics);\n"
                        L"};\n";
    code.SetSolution(fixed);

    ASSERT_TRUE(fixed == code.GetSol());
}

TEST(CodeTest, Passes) {
    Code code;
}