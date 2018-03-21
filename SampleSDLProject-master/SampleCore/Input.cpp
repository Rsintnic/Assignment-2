#include "stdafx.h"
#include "Input.h"
#include <SDL\SDL.h>
namespace core {
	Input::Input() : System(SystemType::INPUT), quitRequested(false)
	{

	}

	Input::~Input()
	{
	}

	bool Input::Init() {
		return true;
	}

	void Input::Update() {
		SDL_Event e;

		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT) {
				quitRequested = true;
			}
		}
	}

	void Input::Draw() const {

	}

	bool Input::Shutdown() {
		return true;
	}

	System* Input::make_system(SystemType type) {
		return new Input();
	}
}