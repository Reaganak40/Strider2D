-- OpenGL-Core Premake
-- premake5.lua
workspace "OpenGl-Core"
   configurations { "Debug", "Release" }
   platforms {"Win32"}

project "OpenGl-Core"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   -- C/C++ files
   files { "**.h", "**.cpp" }
   includedirs {"dependencies/GLEW/include", "dependencies/GLFW/include"}

   -- Linker
   libdirs {"dependencies/GLEW/lib/Release/Win32", "dependencies/GLFW/lib-vc2022"}
   links {"glew32s", "glfw3", "opengl32", "User32", "Gdi32", "Shell32"}

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"