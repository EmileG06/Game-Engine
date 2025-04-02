project "Engine"
    kind "SharedLib"
    language "C++"
    cppdialect "C++23"
    targetdir "bin/%{cfg.buildcfg}-%{cfg.platform}/"
    objdir "bin-int/%{cfg.buildcfg}-%{cfg.platform}/"
    staticruntime "Off"

    pchheader "Pch.h"
    pchsource "Pch.cpp"

    defines { "BUILD_DLL" }

    files { "src/**.h", "src/**.hpp", "src/**.cpp" }

    includedirs { "src" }

    postbuildcommands {
        "{COPY} %{cfg.targetdir}/%{prj.name}.dll ../Sandbox/bin/%{cfg.buildcfg}-%{cfg.platform}/"
    }