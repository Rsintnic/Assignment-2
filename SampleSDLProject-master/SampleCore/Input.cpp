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
			switch(e.type){
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					leftIsPressed = true;
					break;
				case SDLK_RIGHT:
					rightIsPressed = true;
					break;
				case SDLK_UP:
					upIsPressed = true;
					break;
				case SDLK_DOWN:
					downIsPressed = true;
					break;

				case SDLK_ESCAPE:
					quitRequested = true;
					break;
				}	
				break;
			case SDL_KEYUP:
				switch (e.key.keysym.sym)
				{
				case SDLK_LEFT:
					leftIsPressed = false;
					break;
				case SDLK_RIGHT:
					rightIsPressed = false;
					break;
				case SDLK_UP:
					upIsPressed = false;
					break;
				case SDLK_DOWN:
					downIsPressed = false;
					break;
				}
				break;
			case SDL_QUIT:
				quitRequested = true;
				break;
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