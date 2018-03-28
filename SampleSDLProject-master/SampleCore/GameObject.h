#pragma once
#include <SDL\SDL.h>

namespace scene {
	class GameObject
	{
	public:

		SDL_Surface * image;
		SDL_Rect* iRect;

		GameObject();
		virtual ~GameObject();
		bool Init();
		void Update();
		void Draw() const;
		bool Shutdown();
	};

}