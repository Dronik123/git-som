cmake_minimum_required(VERSION 3.10) # Требования к минимальной версии CMake
project(HelloCMake LANGUAGES CXX) # Название проекта и используемый язык (C++)
set(CMAKE_CXX_STANDARD 17) # Старнадрт языка (C++ 17)

add_executable(
    HelloCMake 
    "main2.cpp" 
)

target_link_libraries(HelloCMake PRIVATE -static-libstdc++)
target_link_libraries(HelloCMake PRIVATE -static-libgcc)
target_link_libraries(HelloCMake PRIVATE -static)
