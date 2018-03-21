#pragma once

#include "Scene.h"
#include "Input.h"
#include "Manager.h"
#include <SDL\SDL.h>

#define ENGINE_INIT_ERROR     1
#define ENGINE_SHUTDOWN_ERROR 2

namespace core {
	class Engine
	{
	protected:

		// Move to window system
		//The window we'll be rendering to
		SDL_Window* window = NULL;

		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;

	public:
		Engine(scene::Scene* _mainScene);
		~Engine();

		int init();
		void print();
		int run();

	private:
		bool isRunning;
		scene::Scene* mainScene;
		std::vector<Manager*> managers;
		Input inputSystem;

		bool Init();
		void Update();
		void Draw() const;
		bool Shutdown();
	};
}
