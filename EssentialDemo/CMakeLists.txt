# CMakeList.txt: EssentialDemo 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 将源代码添加到此项目的可执行文件。
add_executable (EssentialDemo "EssentialDemo.cpp" "EssentialDemo.h")
add_executable (demo01 "demo01_basic.cc")
<<<<<<< HEAD
add_executable (demo02 "demo02_oop.cc" "demo02_oop.h")
=======
>>>>>>> 038e68bf304f2b9b2aef34f38b309a93dbd84945

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EssentialDemo PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
