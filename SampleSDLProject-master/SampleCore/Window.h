#pragma once

#include <SDL\SDL.h>
#include "System.h"
namespace core {
	class Window : public System
	{
	private:
		//Screen dimension constants
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
	public:
		Window();
		~Window();

		SDL_Window* window;
		SDL_Surface* screenSurface;
		SDL_Surface* image;
		SDL_Rect* iRect;

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;
		System* make_system(SystemType type);
	};
}

