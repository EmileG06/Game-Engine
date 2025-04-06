project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++23"
    targetdir "../bin/%{cfg.buildcfg}-%{cfg.platform}/"
    objdir "bin-int/%{cfg.buildcfg}-%{cfg.platform}/"

    files { "**.h", "**.hpp", "**.cpp" }

    includedirs { "../Engine/src", "$(ProjectDir)src", "../Engine/vendor/spdlog/include", "../Engine/vendor/imgui/include" }
    links { "Engine" }