workspace "Snoow"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Distro"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Engine"
    location "Engine"
    kind "SharedLib"
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
        "include/spdlog/include/"
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
        "../include/spdlog/include/",
        "Engine/src"
    }

    links
    {
        "Engine"
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
        
                