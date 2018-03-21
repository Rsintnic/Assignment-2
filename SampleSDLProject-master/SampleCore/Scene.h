#pragma once

#include <vector>
namespace scene {
	class Scene
	{
	private:
		std::vector<class GameObject*> gameObjects;
	public:
		Scene();
		virtual ~Scene();
		bool Init();
		void Update();
		void Draw() const;
		bool Shutdown();
	};
}
