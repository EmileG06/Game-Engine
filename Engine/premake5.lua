project "Engine"
    kind "SharedLib"
    language "C++"
    cppdialect "C++23"
    targetdir "../bin/%{cfg.buildcfg}-%{cfg.platform}/"
    objdir "bin-int/%{cfg.buildcfg}-%{cfg.platform}/"

    pchheader "Pch.h"
    pchsource "Pch.cpp"

    defines { "BUILD_DLL",  "GLEW_STATIC", "IMGUI_IMPL_OPENGL_LOADER_CUSTOM" }

    files { "**.h", "**.hpp", "**.cpp" }

    includedirs { "$(ProjectDir)src", "$(ProjectDir)vendor/glfw/include", "$(ProjectDir)vendor/glew/include", "$(ProjectDir)vendor/glm/include", "$(ProjectDir)vendor/spdlog/include", "$(ProjectDir)vendor/glad/include", "$(ProjectDir)vendor/imgui/include" }
    libdirs { "$(ProjectDir)vendor/glfw/lib", "$(ProjectDir)vendor/glew/lib", "$(ProjectDir)vendor/spdlog/lib", "$(ProjectDir)vendor/glad/lib", "$(ProjectDir)vendor/imgui/lib" }

    filter "configurations:Debug"
        links { "opengl32.lib", "glfw3.lib", "glew32s.lib", "spdlog.lib", "glad-d.lib", "imgui-d.lib" }

    filter "configurations:Release"
        links { "opengl32.lib", "glfw3.lib", "glew32s.lib", "spdlog.lib", "glad.lib", "imgui.lib" }
