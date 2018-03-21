#pragma once

namespace core {
	enum class SystemType : unsigned __int8
	{
		WINDOW,
		INPUT
	};

	class System
	{
	protected:
		const SystemType type;
	public:
		System(SystemType system);
		~System();
		bool Init();
		void Update();
		void Draw() const;
		bool Shutdown();
	private:
		virtual System* make_system(SystemType type) = 0; //to call System::make_system(system);
	};

}