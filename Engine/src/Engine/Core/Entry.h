#pragma once

#include "Engine/Application.h"

#ifndef BUILD_DLL
	extern Engine::Application* CreateApplication(int argc, char** argv);

	int main(int argc, char** argv)
	{
		Engine::Application* app = CreateApplication(argc, argv);
		app->Run();
		delete app;
	}
#endif
