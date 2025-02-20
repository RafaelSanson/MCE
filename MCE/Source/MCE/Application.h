#pragma once

#include "Core.h"

namespace MCE 
{
	class MCE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined on client
	Application* CreateApplication();
}