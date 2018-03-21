#pragma once

#include "System.h"
namespace core {
	class Input : public System
	{
		bool quitRequested;
	public:
		Input();
		~Input();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;
		System* make_system(SystemType type);

		inline bool QuitRequested() const { return quitRequested; }
	};
}
