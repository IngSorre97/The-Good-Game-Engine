workspace "TheGoodGameEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TheGoodGameEngine"
    location "TheGoodGameEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    buildoptions "/utf-8"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "TGGE_PLATFORM_WINDOWS",
            "TGGE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandboxApplication")
        }

    filter "configurations:Debug"
        defines "TGGE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TGGE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "TGGE_DIST"
        optimize "On"

project "SandboxApplication"
    location "SandboxApplication"
    kind "ConsoleApp"

    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    buildoptions "/utf-8"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "TheGoodGameEngine/vendor/spdlog/include",
        "TheGoodGameEngine/src"
    }

    links
    {
        "TheGoodGameEngine"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "TGGE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "TGGE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "TGGE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "TGGE_DIST"
        optimize "On"
