#pragma once

extern MCE::Application* MCE::CreateApplication();

int main(int argc, char** argv)
{
	auto application = MCE::CreateApplication();
	application->Run();
	delete(application);
}
