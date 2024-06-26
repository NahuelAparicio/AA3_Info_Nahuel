#include "InputManager.h"
InputManager::InputManager()
{
	mouse = new Mouse();
	_wPressed = false;
	_aPressed = false;
	_sPressed = false;
	_dPressed = false;
	_fPressed = false;
	_wasFPressed = false;
}

void InputManager::HandleInputs(GLFWwindow* window)
{
	UpdateInputs(window);
	UpdateMouse(window);
}

void InputManager::UpdateInputs(GLFWwindow* window)
{
	_wPressed = glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
	_aPressed = glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
	_sPressed = glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
	_dPressed = glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;
	_fPressed = glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS;

	bool isFPressedNow = glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS;

	if (isFPressedNow && !_wasFPressed)
	{
		_fPressed = true;
	}
	else
	{
		_fPressed = false;
	}

	_wasFPressed = isFPressedNow;
}

void InputManager::UpdateMouse(GLFWwindow* window)
{
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	GetMouse()->SetMouseDirection(window, xpos, ypos);
}
