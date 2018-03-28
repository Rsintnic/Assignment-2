#include "stdafx.h"
#include "SceneManager.h"


namespace core {

	SceneManager* SceneManager::m_instance = nullptr;

	SceneManager::SceneManager() {

	}//end scene manager

	SceneManager::~SceneManager() {
	}//end scene manager destructor

	bool SceneManager::Init() {
		for (scene::Scene* s : scenes) {
			if (!s->Init()) {
				return false;
			}//end if
		}//end for
		return true;
	}//end init

	void SceneManager::Update() {
		scenes[sceneIndex]->Update();
	}//end void

	void SceneManager::Draw() const {
		scenes[sceneIndex]->Draw();
	}//end draw

	bool SceneManager::Shutdown() {
		for (scene::Scene* s : scenes) {
			if (!s->Shutdown()) {
				return false;
			}//end if
			delete s;
			s = nullptr;
		}//end for
		scenes.clear();

		return true;
	}//end shutdown

}//end core