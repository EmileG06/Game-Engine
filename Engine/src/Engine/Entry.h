#pragma once

#include "Engine/Game.h"

#ifndef BUILD_DLL
	extern Engine::Game* CreateGame(int argc, char** argv);

	int main(int argc, char** argv)
	{
		Engine::Game* game = CreateGame(argc, argv);
		game->Run();
		delete game;
	}
#endif
