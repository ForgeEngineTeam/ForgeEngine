#include <Platform/Public/Platform.h>
#include <GraphicsDevice/Public/OpenGL/Win32/WGLGraphicsContext.h>
#include <GraphicsDevice/Public/OpenGL/GLGraphicsContextState.h>

using namespace Forge::Common;
using namespace Forge::Platform;
using namespace Forge::Graphics;

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	Platform::GetInstance().Initialize(hInstance);

	Platform::GetInstance().Info("Hello World");

	WindowPtr wnd = Platform::GetInstance().ConstructWindow("Forge Engine");

	WGLGraphicsContextPtr gc = new WGLGraphicsContext(wnd, 3, 3, GLContextProfileMask::FORGE_CORE, GLContextFlags::FORGE_NONE);
	gc->PreInitialize();
	gc->Initialize();

	GLGraphicsContextState gcs(wnd);

	gcs.SetColorClear(1.0, 0.0, 0.0, 1.0);

	while (!wnd->IsClosing())
	{
		Platform::GetInstance().PumpMessages();

		glClear(GL_COLOR_BUFFER_BIT);

		gc->SwapBuffers(1);
	}
}


