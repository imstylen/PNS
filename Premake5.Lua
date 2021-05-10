-- premake5.lua
workspace "PoopWorkspace"
   configurations { "Debug", "Release" }

project "PoopProject"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   targetdir "bin/%{cfg.buildcfg}"
   objdir "bin/obj/%{cfg.buildcfg}"
   files { "src/**.h", "src/**.cpp" }

   sysincludedirs {"vendor/spdlog/include"}
   includedirs {"src"}


   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
