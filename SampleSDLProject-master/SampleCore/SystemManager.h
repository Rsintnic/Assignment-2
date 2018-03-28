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
	private:
		static SystemManager* m_instance;
		SystemManager();
	protected:
		std::vector<System*> systems;
	public:
		~SystemManager();
		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;

		static SystemManager* GetInstance() {
			if (m_instance == nullptr)
				m_instance = new SystemManager();
			return m_instance;
		;}

		template<class T>
		T* GetSystem() {
			for (System* s : systems) {
				T* system = dynamic_cast<T*>(s);
				if (system != nullptr) {
					return system;
				}
			}
			return nullptr;
		}
	};
}


#endif // !SYSTEM_MANAGER_H