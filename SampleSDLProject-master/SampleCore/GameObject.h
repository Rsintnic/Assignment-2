#pragma once

namespace scene {
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();
		bool Init();
		void Update();
		void Draw() const;
		bool Shutdown();
	};

}