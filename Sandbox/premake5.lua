project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++23"
    targetdir "bin/%{cfg.buildcfg}-%{cfg.platform}/"
    objdir "bin-int/%{cfg.buildcfg}-%{cfg.platform}/"
    staticruntime "On"

    files { "src/**.h", "src/**.hpp", "src/**.cpp" }

    includedirs { "../Engine/src", "src" }
    links { "Engine" }