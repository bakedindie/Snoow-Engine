workspace "Snoow"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Distro"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["glfw"] = "include/glfw/include"

include "include/glfw"

project "Engine"
    location "Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "Engine/src/pch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Engine/src",
        "include/spdlog/include/",
        "include/SDL2/include/",
        "%{IncludeDir.glfw}"
    }

    libdirs
    {
        "include/SDL2/lib/"
    }

    links
    {
        "SDL2.lib",
        "SDL2_main.lib",
        "glfw",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SN_PLATFORM_WINDOWS",
            "SN_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

        filter "configurations:Debug"
            defines "SN_DEBUG"
            symbols "On"
        
        filter "configurations:Release"
            defines "SN_RELEASE"
            optimize "On"

        filter "configurations:Distro"
            defines "SN_DISTRO"
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
        "%{prj.name}/src/**.cpp",
    }
        
    includedirs
    {
        "include/spdlog/include/",
        "include/SDL2/include/",
        "Engine/src",
        "%{IncludeDir.glfw}"
    }

    libdirs
    {
        "include/SDL2/lib/"
    }

    links
    {
        "Engine",
        "SDL2.lib",
        "SDL2_main.lib",
        "glfw",
        "opengl32.lib"
    }
        
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        
        defines
        {
            "SN_PLATFORM_WINDOWS"
        }
        
    filter "configurations:Debug"
        defines "SN_DEBUG"
        symbols "On"
                
    filter "configurations:Release"
        defines "SN_RELEASE"
        optimize "On"
        
    filter "configurations:Distro"
        defines "SN_DISTRO"
        optimize "On"
        
                