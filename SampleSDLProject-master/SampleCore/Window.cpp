#include "stdafx.h"
#include "Window.h"

namespace core {
	Window::Window() : System(SystemType::WINDOW)
	{

	}


	Window::~Window()
	{
	}

	System* Window::make_system(SystemType type) {
		return new Window();
	}
}