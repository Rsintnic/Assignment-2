#include "stdafx.h"
#include "Engine.h"

#include <iostream>
#include "SystemManager.h"
#include "SceneManager.h"
#include "Window.h"
#include <stdio.h>

namespace core {
	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	Engine::Engine(scene::Scene* _mainScene)
	{
		isRunning = false;

		managers.push_back(SceneManager::GetInstance());
		managers.push_back(SystemManager::GetInstance());
		dynamic_cast<SceneManager*>(managers[0])->AddScene(_mainScene);
	}


	Engine::~Engine()
	{
	}

	bool Engine::Init()
	{
		bool initResult = true;
		for (Manager* m : managers) {
			if (!m->Init())
				initResult = false;
		}

		return initResult;
	}

	int Engine::run() {
		isRunning = true;
		Input* inputSystem = dynamic_cast<SystemManager*>(managers[1])->GetSystem<Input>();
		while ( !inputSystem->QuitRequested())
		{
			// Update
			Update();
			// Render
			Draw();

		}

		return Shutdown();

	}

	void Engine::Update() {
		for (Manager* m : managers) {
			m->Update();
		}
	}

	void Engine::Draw() const{
		for (Manager* m : managers) {
			m->Draw();
		}
	}

	bool Engine::Shutdown() {
		
		for (Manager* m : managers) {
			if (!m->Shutdown())
				return false;
		}

		//Quit SDL subsystems
		SDL_Quit();

		return true;
	}

	void Engine::print()
	{
		std::cout << "this is working" << std::endl;
	}

}