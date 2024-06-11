#include "MCE.h"

class Examples : public MCE::Application
{
public:
	Examples()
	{
	}

	~Examples()
	{
		
	}
};

MCE::Application* MCE::CreateApplication()
{
	return new Examples();
}