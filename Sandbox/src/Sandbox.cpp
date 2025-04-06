#include "Engine.h"

class ExampleLayer : public Engine::Layer
{
public:
	ExampleLayer()
		: Layer("ExampleLayer")
	{
	}

	void OnUpdate() override
	{
		CLIENT_TRACE("ExampleLayer::OnUpdate");
	}

	void OnEvent(Engine::Event& event) override
	{
		CLIENT_TRACE("{0}", event.ToString());
	}
};

class Game : public Engine::Application
{
public:
	Game()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Engine::ImGuiLayer());
	}

	~Game()
	{

	}
};

Engine::Application* CreateApplication(int argc, char** argv)
{
	return new Game();
}
