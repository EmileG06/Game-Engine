#pragma once

#include "Pch.h"
#include "Engine/Core/Core.h"
#include "Engine/Events/Events.h"

class GLFWwindow;

namespace Engine
{
	struct API WindowProps
	{
		std::string Title = "Window";
		uint32_t Width = 1280, Height = 720;
	};

	class API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		Window(const WindowProps& props = WindowProps());
		~Window();

		void Init(const WindowProps& props = WindowProps());
		void Shutdown();

		inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }

		bool IsVSync() const;
		void SetVSync(bool enabled);

		void OnUpdate();

		inline float GetWidth() const { return m_Data.Width; }
		inline float GetHeight() const { return m_Data.Height; }

		inline GLFWwindow* GetInternalWindow() const { return m_Window; }

		static Window* Create(const WindowProps& props = WindowProps());

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}
