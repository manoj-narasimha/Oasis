#pragma once
#include "Core.h"

namespace Oasis{

	class OASIS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined on the client side
	Application* CreateApplication();
}
