#include "Engine.h"

class MyGame : public Engine::Game
{
public:

};

Engine::Game* CreateGame(int argc, char** argv)
{
	return new MyGame();
}
