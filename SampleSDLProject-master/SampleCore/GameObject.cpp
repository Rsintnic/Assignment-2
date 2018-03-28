#include "stdafx.h"
#include "GameObject.h"
#include "SystemManager.h"
#include "Window.h"
#include "Input.h"

namespace scene {

	GameObject::GameObject()
	{

		//The image we will place on screen
		image = NULL;
		iRect = NULL;
	}


	GameObject::~GameObject()
	{
	}

	bool GameObject::Init() {
		bool initResult = true;
		image = SDL_LoadBMP("./hello_world.bmp");
		if (image == NULL)
		{
			printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
			initResult = false;
		}
		else {
			iRect = new SDL_Rect;
			iRect->x = 0;
			iRect->y = 0;
			iRect->w = image->w;
			iRect->h = image->h;
		}
		return initResult;
	}

	void GameObject::Update() {
		core::Input* input = core::SystemManager::GetInstance()->GetSystem<core::Input>();
		if (input->IsLeftPressed()) {
			iRect->x -= 1;
		}
		if (input->IsRightPressed()) {
			iRect->x += 1;
		}
		if (input->IsUpPressed()) {
			iRect->y -= 1;
		}
		if (input->IsDownPressed()) {
			iRect->y += 1;
		}
	}

	void GameObject::Draw() const {
		core::Window* window = core::SystemManager::GetInstance()->GetSystem<core::Window>();
		//Apply the image
		SDL_BlitSurface(image, NULL, window->screenSurface, iRect);
		SDL_UpdateWindowSurface(window->window);

	}

	bool GameObject::Shutdown() {
		return true;
	}
}
