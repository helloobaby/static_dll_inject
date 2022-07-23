project(static_dll_inject)

set(CMAKE_CXX_STANDARD 20)
add_executable(static_dll_inject main.cpp pe.h pe32.h pe64.h utils.h utils.cpp) 