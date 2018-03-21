#include "stdafx.h"
#include "Window.h"

namespace core {
	Window::Window() : System(SystemType::WINDOW)
	{

	}


	Window::~Window()
	{
	}

	bool Window::Init() {
		return true;
	}

	void Window::Update() {

	}

	void Window::Draw() const {

	}

	bool Window::Shutdown() {
		return true;
	}

	System* Window::make_system(SystemType type) {
		return new Window();
	}
}