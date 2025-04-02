workspace "Game-Engine"
    configurations { "Debug", "Release" }
    platforms "x64"

    defines { "WINDOWS" }

filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"

    include "Engine"
    include "Sandbox"