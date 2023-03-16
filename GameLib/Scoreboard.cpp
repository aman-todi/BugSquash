/**
 * @file Scoreboard.cpp
 * @author Ethan Silver
 */


#include "pch.h"
#include "Scoreboard.h"
#include <wx/graphics.h>

/// Game area in virtual pixels
const static double GameWidth = 1250;

/// Score font size to use
const int ScoreSize = 85;

/// Lable for score font size to use
const int LabelSize = 40;

/// The font color to use
const wxColour FontColor = wxColour(0, 200, 200);

/// Left score X location. The right score is
/// the width minus this value.
const int LeftScoreX = 150;

/// Score Y location
const int ScoreY = 20;

/// Score label Y location
const int ScoreLabelY = 100;


Scoreboard::Scoreboard()
{
    mFixed = 0;
    mMissed = 0;
    mOops = 0;
}

void Scoreboard::KeepScore(int fix, int miss, int oop)
{
    mFixed += fix;
    mMissed += miss;
    mOops += oop;
}

void Scoreboard::Draw(std::shared_ptr<wxGraphicsContext> gc)
{
    //Score
    wxFont fontScore(ScoreSize,
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);

    wxFont fontLabel(LabelSize,
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);

    gc->SetFont(fontScore, FontColor);

    gc->DrawText(L"0", LeftScoreX, ScoreY);
    gc->DrawText(L"0", GameWidth/2, ScoreY);
    gc->DrawText(L"0", GameWidth-LeftScoreX, ScoreY);

    //Label
    gc->SetFont(fontLabel, FontColor);

    double widLabel, hgtLabel;
    gc->GetTextExtent(L"Fixed", &widLabel, &hgtLabel);
    gc->DrawText((L"Fixed"), LeftScoreX - (widLabel/4), ScoreLabelY+(hgtLabel/2));

    gc->GetTextExtent(L"Missed", &widLabel, &hgtLabel);
    gc->DrawText((L"Missed"), (GameWidth/2) - (widLabel/3), ScoreLabelY+(hgtLabel/2));

    gc->GetTextExtent(L"Oops", &widLabel, &hgtLabel);
    gc->DrawText((L"Oops"), (GameWidth-LeftScoreX) - (widLabel/4), ScoreLabelY+(hgtLabel/2));

}
