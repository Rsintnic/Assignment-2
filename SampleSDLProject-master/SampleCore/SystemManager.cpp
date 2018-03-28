#include "stdafx.h"
#include "SystemManager.h"
#include "Input.h"
#include "Window.h"

namespace core {
	SystemManager* SystemManager::m_instance = nullptr;

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
		return true;
	}

	void SystemManager::Update() {
		for (System* s : systems) {
			s->Update();
		}
	}

	void SystemManager::Draw() const {
		for (System* s : systems) {
			s->Draw();
		}
	}

	bool SystemManager::Shutdown() {
		for (System* s : systems) {
			if (!s->Shutdown()) {
				return false;
			}
			delete s;
			s = nullptr;
		}
		systems.clear();
		
		return true;
	}
	
}