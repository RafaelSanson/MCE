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

int main()
{
	Examples* examples = new Examples();
	examples->Run();
	delete(examples);
}