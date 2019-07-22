workspace "Mipor"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Mipor"
	location "Mipor"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	include 
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MP_PLATFORM_WINDOWS",
			"MIPOR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MP_DIST"
		optimize "On"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	include 
	{
		"%{prj.name}/vendor/spdlog/include",
		"Mipor/src"
	}

	links
	{
		"Mipor"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MP_DIST"
		optimize "On"