#include "stdafx.h"
#include "SystemManager.h"
#include "System.h"
#include "Input.h"
#include "Window.h"

namespace core {
	SystemManager::SystemManager()
	{
		systems.push_back(new Input());
		systems.push_back(new Window());
	}


	SystemManager::~SystemManager()
	{
	}

	bool SystemManager::Init() {


		for (System* s : systems) {
			if (!s->Init()) {
				return false;
			}
		}
		/*for (size_t i = 0; i < static_cast<size_t>(SystemType::TOTAL_SYSTEMS); i++)
		{

		}*/
		return true;
	}

	void SystemManager::Update() {
		for (System* s : systems) {
			s->Update();
		}
	}

	void SystemManager::Draw() const {

	}

	bool SystemManager::Shutdown() {
		for (System* s : systems) {
			if (!s->Shutdown()) {
				return false;
			}
		}

		return true;
	}

	System* SystemManager::GetSystem(SystemType system) {
		return systems[0];
	}
}