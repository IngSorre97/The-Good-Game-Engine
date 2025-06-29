#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace tgge
{
	Application::Application()
	{ }

	Application::~Application()
	{ }


	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		TGGE_TRACE(e.ToString());

		while (true);
	}
}