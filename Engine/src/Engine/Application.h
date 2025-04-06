#pragma once

#include "Pch.h"
#include "Core/Core.h"
#include "Window/Window.h"
#include "Events/ApplicationEvents.h"
#include "Engine/Layers/LayerStack.h"

namespace Engine
{
	class API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& event);

		static Application* s_Instance;

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication(int argc, char** argv);
}
