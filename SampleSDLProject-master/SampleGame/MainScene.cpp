#include "stdafx.h"
#include "MainScene.h"
#include <SystemManager.h>
#include <Input.h>
#include <Window.h>


MainScene::MainScene()
{
	gameObjects.push_back(new scene::GameObject);
}


MainScene::~MainScene()
{
}

bool MainScene::Init(){
	scene::Scene::Init();
	std::cout << "Scene init" << std::endl;
	return true;
}

void MainScene::Update() {
	scene::Scene::Update();
	using namespace core;
	SystemManager* sm = SystemManager::GetInstance();
	Input* input = dynamic_cast<core::Input*>(sm->GetSystem<core::Input>());
	Window* window = dynamic_cast<core::Window*>(sm->GetSystem<core::Window>());
	if(input->IsLeftPressed()) {

	}
	if (input->IsRightPressed()) {

	}
	if (input->IsUpPressed()) {

	}
	if (input->IsDownPressed()) {

	}

	//std::cout << "Scene update" << std::endl;
}

void MainScene::Draw() const {
	scene::Scene::Draw();
	//std::cout << "Scene draw" << std::endl;
}

bool MainScene::Shutdown() {
	scene::Scene::Shutdown();
	std::cout << "Scene shutdown" << std::endl;
	return true;
}
