#pragma once

#include "Core.h"

namespace Mipor
{
	class  MIPOR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}
