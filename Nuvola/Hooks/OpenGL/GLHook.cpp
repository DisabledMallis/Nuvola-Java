#include "GLHook.h"

#include <gl/GL.h>

uintptr_t oglSwapBuffers;

auto oglHook(HDC hdc, int b) -> bool {
	glPushMatrix();

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glViewport(0, 0, viewport[2], viewport[3]);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, viewport[2], viewport[3], 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);


	glBegin(GL_QUADS);
	glColor3d(1,1,1);
	glVertex2d(0,0);
	glVertex2d(0,100);
	glVertex2d(100,100);
	glVertex2d(100,0);
	glEnd();


    glEnable(GL_DEPTH_TEST);

    glPopMatrix();


    return PLH::FnCast(oglSwapBuffers, oglHook)(hdc, b);
}

auto GLHook::Apply() -> bool {

	HMODULE oGlHandle = GetModuleHandleA("OPENGL32.dll");
    uintptr_t fp = (uintptr_t)GetProcAddress(oGlHandle, "wglSwapBuffers");

	PLH::x64Detour* detour = new PLH::x64Detour(fp, (uintptr_t)&oglHook, &oglSwapBuffers, this->GetDis());
	if(detour->hook()) {
		return true;
	}
	return false;
}