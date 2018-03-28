#pragma once

#include "System.h"
namespace core {

	class Input : public System
	{
		bool quitRequested;
		bool leftIsPressed = false;
		bool rightIsPressed = false;
		bool upIsPressed = false;
		bool downIsPressed = false;
	public:
		Input();
		~Input();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;
		inline bool IsLeftPressed() const { return leftIsPressed; }
		inline bool IsRightPressed() const { return rightIsPressed; }
		inline bool IsUpPressed() const { return upIsPressed; }
		inline bool IsDownPressed() const { return downIsPressed; }

		System* make_system(SystemType type);

		inline bool QuitRequested() const { return quitRequested; }
	};
}
