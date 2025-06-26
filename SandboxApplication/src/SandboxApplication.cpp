#include <TheGoodGameEngine.h> 

class SandboxApplication : public tgge::Application
{
public:
	SandboxApplication()
	{
		printf("Welcome to the first Sandbox application!");
	}

	~SandboxApplication()
	{

	}

};

tgge::Application* tgge::CreateApplication()
{
	return new SandboxApplication();
}