/**
 * @file GameApp.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include <MainFrame.h>
#include "GameApp.h"

/**
 * Initialize the application.
 * @return false if the screen can't populate otherwise true
 */
bool GameApp::OnInit()
{
	if(!wxApp::OnInit())
	{
		return false;
	}
	wxInitAllImageHandlers();
	auto frame = new MainFrame();
	frame->Initialize();
	frame->Show(true);

	return true;
}
