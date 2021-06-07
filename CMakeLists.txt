cmake_minimum_required(VERSION 3.17)
project(NKHook5 VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

# Generate Minecraft source to access game stuff with jni using map2cpp
file(WRITE map2cpp/gen.bat [[gradlew.bat run --args="-i ../Tiny/1.8.9-intermediary.tiny -m ../Tiny/1.8.9-named.tiny -cm Nuvola -o ../Nuvola/Gen/"]])
execute_process(
	COMMAND gen.bat
	WORKING_DIRECTORY map2cpp
)
file(REMOVE map2cpp/gen.bat)

if(MSVC)
    add_compile_options(
            $<$<CONFIG:>:/MT> #---------|
            $<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries (Stolen from Jirachi ;D)
            $<$<CONFIG:Release>:/MT> #--|
    )
endif()

link_directories("${CMAKE_CURRENT_LIST_DIR}/PolyHook_2_0/_install/lib/")

add_library(Nuvola SHARED)

add_subdirectory(Nuvola)

target_include_directories(Nuvola PRIVATE "${CMAKE_CURRENT_LIST_DIR}/PolyHook_2_0/_install/include")

target_link_libraries(Nuvola PRIVATE PolyHook_2 capstone)