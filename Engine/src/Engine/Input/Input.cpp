#include "Pch.h"
#include "Input.h"
#include "Engine/Application.h"

#include <GLFW/glfw3.h>

namespace Engine
{
	std::unique_ptr<Input> Input::s_Instance = std::unique_ptr<Input>(new Input());

	bool Input::IsKeyPressedImpl(int keycode)
	{
		GLFWwindow* window = Application::Get().GetWindow().GetInternalWindow();
		int state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressedImpl(int button)
	{
		GLFWwindow* window = Application::Get().GetWindow().GetInternalWindow();
		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> Input::GetMousePositionImpl()
	{
		GLFWwindow* window = Application::Get().GetWindow().GetInternalWindow();
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}

	float Input::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return x;
	}

	float Input::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}
}
