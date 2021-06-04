cmake_minimum_required(VERSION 3.17)
project(NKHook5 VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

# Generate Minecraft source to access game stuff with jni using map2cpp
execute_process(
	COMMAND gradlew.bat run --args="-i ../Tiny/1.8.9-intermediary.tiny -m ../Tiny/1.8.9-named.tiny -cm Nuvola -o ../Nuvola/Gen/"
	WORKING_DIRECTORY map2cpp
)

add_library(Nuvola SHARED)

add_subdirectory(Nuvola)