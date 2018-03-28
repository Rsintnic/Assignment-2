#include "stdafx.h"
#include "Scene.h"

namespace scene {
	Scene::Scene()
	{
		
	}


	Scene::~Scene()
	{
	}

	bool Scene::Init() {

		for (GameObject* g : gameObjects) {
			g->Init();
		}
		return true;
	}

	void Scene::Update() {
		for (GameObject* g : gameObjects) {
			g->Update();
		}
	}

	void Scene::Draw() const {
		for (GameObject* g : gameObjects) {
			g->Draw();
		}
	}

	bool Scene::Shutdown() {
		for (GameObject* g : gameObjects) {
			g->Shutdown();
		}
		return true;
	}
}