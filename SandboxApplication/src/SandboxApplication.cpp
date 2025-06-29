#include <TheGoodGameEngine.h> 

class SandboxApplication : public tgge::Application
{
public:
	SandboxApplication()
	{
		TGGE_INFO(" *** Welcome to the first Sandbox application! ***\n");
	}

	~SandboxApplication()
	{

	}

};

tgge::Application* tgge::CreateApplication()
{
	return new SandboxApplication();
}