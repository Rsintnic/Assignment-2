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

	public:
		Engine(scene::Scene* _mainScene);
		~Engine();
		void print();
		int run();

		bool Init();
		void Update();
		void Draw() const;
		bool Shutdown();

	private:
		bool isRunning;
		//scene::Scene* mainScene;
		std::vector<Manager*> managers;
	};
}
