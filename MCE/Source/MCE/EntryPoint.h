#pragma once

extern MCE::Application* MCE::CreateApplication();

int main(int argc, char** argv)
{
	MCE::Log::Init();
	MCE_CORE_WARN("Core logger initialized");
	MCE_INFO("Client logger initialized");

	auto application = MCE::CreateApplication();
	application->Run();
	delete(application);
}
