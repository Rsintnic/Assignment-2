#pragma once

#include "System.h"
namespace core {
	class Window : public System
	{
	public:
		Window();
		~Window();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;
		System* make_system(SystemType type);
	};
}

