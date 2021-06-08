#ifndef NUVOLA_HOOKS_OPENGL_GLHOOK
#define NUVOLA_HOOKS_OPENGL_GLHOOK

#include "../Hook.h"

class GLHook : public Hook {
public:
	GLHook() : Hook("glfwSwapBuffers")
	{}
	auto Apply() -> bool override;
	auto Remove() -> bool override;
};

#endif /* NUVOLA_HOOKS_OPENGL_GLHOOK */
