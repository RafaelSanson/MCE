workspace "MCE"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "MCE"
	location "MCE"
	kind "SharedLib"
	language "C++"

	targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/ThirdParty/spdlog/include",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17763.0"

		defines
		{	
			"MCE_PLATFORM_WINDOWS",
			"MCE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../Binaries/" .. outputdir .. "/Examples")
		}

	filter "configurations:Debug"
		defines "MCE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "MCE_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "MCE_DIST"
		optimize "On"

project "Examples"
	location "Examples"
	kind "ConsoleApp"
	language "C++"

	targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"MCE/ThirdParty/spdlog/include",
		"MCE/Source",
	}

	links
	{
		"MCE"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17763.0"

		defines
		{	
			"MCE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MCE_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "MCE_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		defines "MCE_DIST"
		optimize "On"