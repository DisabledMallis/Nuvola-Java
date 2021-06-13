add_subdirectory(OpenGL)
add_subdirectory(Win32)

target_sources(Nuvola PUBLIC
	"Hook.cpp"
	"HookManager.cpp"
)