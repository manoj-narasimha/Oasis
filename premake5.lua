workspace "Oasis"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Oasis"
	location "Oasis"
	kind "SharedLib"
	language "C++"

	--Target Directories For Binaries
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	--Target Directories For Intermediate Binaries
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"OS_PLATFORM_WINDOWS",
			"OASIS_BUILD_DLL"
		}

		configuration "windows"

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_Release"
		symbols "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		symbols "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	--Target Directories For Binaries
	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	--Target Directories For Intermediate Binaries
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Oasis/vendor/spdlog/include",
		"Oasis/src"
	}

	links {
		"Oasis"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"OS_PLATFORM_WINDOWS",
			"OASIS_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_Release"
		symbols "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
		symbols "On"