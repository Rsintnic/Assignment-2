#pragma once
#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Manager.h"
#include "Scene.h"
#include <vector>
namespace core{
class SceneManager : public Manager
{
	friend scene::Scene;
private:
	static SceneManager* m_instance;
	int sceneIndex;
	SceneManager();
protected:
	std::vector<scene::Scene*> scenes;

public:
	~SceneManager();
	bool Init() override;
	void Update() override;
	void Draw() const override;
	bool Shutdown() override;
	void AddScene(scene::Scene* scene) { scenes.push_back(scene); }

	static SceneManager* GetInstance() {
		if (m_instance == nullptr)
			m_instance = new SceneManager();
		return m_instance;
		;
	}//end scene

	template<class T>
	T* GetScene() {
		for (Scene* s : scenes) {
			T* scene = dynamic_cast<T*>(s);
			if (scene != nullptr) {
				return scene;
			}//end if
		}//end for
	}//end T

};
}//end core
#endif // !SYSTEM_MANAGER_H

