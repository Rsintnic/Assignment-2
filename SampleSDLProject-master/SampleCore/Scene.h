#pragma once
#include "GameObject.h"
#include <vector>
namespace scene {
	class Scene
	{
	private:
	public:
		std::vector<class GameObject*> gameObjects;
		Scene();
		virtual ~Scene();
		virtual bool Init();
		virtual void Update();
		virtual void Draw() const;
		virtual bool Shutdown();
	};
}
