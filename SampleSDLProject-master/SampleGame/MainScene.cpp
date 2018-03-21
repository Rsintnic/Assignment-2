#include "stdafx.h"
#include "MainScene.h"


MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}

bool MainScene::Init() {
	std::cout << "Scene init" << std::endl;
	return true;
}

void MainScene::Update() {
	std::cout << "Scene update" << std::endl;
}

void MainScene::Draw() const {
	std::cout << "Scene draw" << std::endl;
}

bool MainScene::Shutdown() {
	std::cout << "Scene shutdown" << std::endl;
	return true;
}
