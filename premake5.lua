include "dependencies"

workspace "gitty"
    location "build"
    architecture "x86_64"
    startproject "gitty"

    configurations { "debug", "release" }

group "dependencies"
    include "vendor/ftxui"
    include "vendor/cppgit2"
    include "vendor/libgit2"
group ""

project "gitty"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    
    files { "src/**.h", "src/**.cpp" }

    includedirs {
        "%{wks.location}/src",
        "%{IncludeDirs.ftxui}",
        "%{IncludeDirs.cppgit2}"
    }
