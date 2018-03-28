#include "stdafx.h"
#include "Window.h"

namespace core {
	Window::Window() : System(SystemType::WINDOW)
	{
		//The window we'll be rendering to
		window = NULL;

		//The surface contained by the window
		screenSurface = NULL;

		//The image we will place on screen
		image = NULL;
	}


	Window::~Window()
	{
	}

	bool Window::Init() {

		bool initResult = true;
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			initResult = false;
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
		}
		
		/*//Load splash image
		image = SDL_LoadBMP("./hello_world.bmp");
		if (image == NULL)
		{
			printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
			initResult = false;
		}
		//Grab the dimensions of the image
		else {
			iRect = new SDL_Rect;
			iRect->x = 0;
			iRect->y = 0;
			iRect->w = image->w;
			iRect->h = image->h;
		}*/

		return initResult;
	}

	void Window::Update() {

		
	}

	void Window::Draw() const {
		//Fill the surface blue
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x33, 0xFF, 0xFF));
		//Update the surface
		//SDL_UpdateWindowSurface(window);
	}

	bool Window::Shutdown() {
		//Deallocate surface
		SDL_FreeSurface(image);
		image = NULL;

		//Destroy window
		SDL_DestroyWindow(window);
		screenSurface = NULL;
		window = NULL;

		return true;
	}

	System* Window::make_system(SystemType type) {
		return new Window();
	}

}