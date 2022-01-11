-- Strider2D Premake
-- premake5.lua

workspace "Strider2D"
   configurations { "Debug", "Release" }
   platforms {"Win32"}

project "Strider2D"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   -- C/C++ files
   files { "src/**.h", "src/**.cpp" }
   
   RelativePathCore = "dependencies/OpenGL-Core"
   
   
   -- OpenGL Core
   -- C/C++ files
   files { "%{RelativePathCore}/**.h", "%{RelativePathCore}/**.cpp" }
   removefiles { "%{RelativePathCore}/src/core.cpp"}
   
   includedirs {  
                  "%{RelativePathCore}/dependencies/GLEW/include", 
                  "%{RelativePathCore}/dependencies/GLFW/include",
                  "%{RelativePathCore}/src"
               }

   -- Linker
   libdirs {
               "%{RelativePathCore}/dependencies/GLEW/lib/Release/Win32", 
               "%{RelativePathCore}/dependencies/GLFW/lib-vc2022"
            }
   links {"glew32s", "glfw3", "opengl32", "User32", "Gdi32", "Shell32"}

   filter "configurations:Debug"
   defines { "DEBUG" }
   symbols "On"

   filter "configurations:Release"
   defines { "NDEBUG" }
   optimize "On"