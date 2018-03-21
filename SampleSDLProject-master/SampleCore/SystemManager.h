#pragma once
#include "Manager.h"
#include "System.h"
#include <vector>

namespace core {

	std::vector<System*> systems;
	class SystemManager : public Manager
	{
	public:
		SystemManager();
		~SystemManager();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		System* GetSystem(SystemType system);
	};
}
