workspace "SpaceAdventures_2.0"
	architecture "x86"

	configurations
	{
		"Debug",
		"Release"		
	}
	

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["SDL2"] = "%{wks.location}/Dependencies/SDL2/include"
IncludeDir["SDL2_image"] = "%{wks.location}/Dependencies/SDL2_image/include"
IncludeDir["SDL2_ttf"] = "%{wks.location}/Dependencies/SDL2_ttf/include"


project "SpaceAdventures_2.0"
	location "SpaceAdventures_2.0"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/%{cfg.buildcfg}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		--"Dependencies/SDL2/include",
		--"Dependencies/SDL2_image",
		"%{IncludeDir.SDL2}",
		"%{IncludeDir.SDL2_image}",
		"%{IncludeDir.SDL2_ttf}"	
	}

	libdirs
	{
		"%{wks.location}/Dependencies/SDL2/lib/x86",
		"%{wks.location}/Dependencies/SDL2_image/lib/x86",
		"%{wks.location}/Dependencies/SDL2_ttf/lib/x86",
	}

	links
	{
		"SDL2.lib",
		"SDL2main.lib",
		"SDL2_image.lib",
		"SDL2_ttf.lib"
	}
	
	filter { "configurations:Debug" }
      	defines { "DEBUG" }
      	symbols "On"

	filter { "configurations:Release" }
      	defines { "NDEBUG" }
      	optimize "On"