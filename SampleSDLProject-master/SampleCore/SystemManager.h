#pragma once
#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "Manager.h"
#include "System.h"
#include <vector>

namespace core {

	
	class SystemManager : public Manager
	{
		friend System;
		std::vector<System*> systems;
	public:
		SystemManager();
		~SystemManager();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		template<class T>
		T* GetSystem() {
			for (System* s : systems) {
				T* system = dynamic_cast<T*>(s);
				if (system != nullptr) {
					return system;
				}
			}
			/*if (system == SystemType::) {
			return systems[0];
			}
			else if (system == SystemType::WINDOW) {
			return systems[1];
			}*/
		}
	};
}


#endif // !SYSTEM_MANAGER_H