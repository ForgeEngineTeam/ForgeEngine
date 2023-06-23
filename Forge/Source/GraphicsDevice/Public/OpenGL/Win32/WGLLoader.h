#ifndef WGL_LOADER_H
#define WGL_LOADER_H

#include <GraphicsDevice/Public/OpenGL/GLLoader.h>
#include <GraphicsDevice/Public/OpenGL/Win32/wgl.h>

namespace Forge {
	namespace Graphics
	{
		/**
		 * @brief OpenGL loader implementation for windows.
		 * 
		 * @author Karim Hisham.
		 */
		class FORGE_API WGLLoader final : public GLLoader
		{
		public:
			struct BackendProcedures
			{
				using PFNWGLSHARELISTSPROC 
					= BOOL(WINAPI*)(HGLRC, HGLRC);
				using PFNWGLMAKECURRENTPROC 
					= BOOL(WINAPI*)(HDC, HGLRC);
				using PFNWGLCREATECONTEXTPROC 
					= HGLRC(WINAPI*)(HDC);
				using PFNWGLDELETECONTEXTPROC 
					= BOOL(WINAPI*)(HGLRC);
				using PFNWGLGETCURRENTDCPROC 
					= HDC(WINAPI*)(Void);
				using PFNWGLGETPROCADDRESSPROC 
					= PROC(WINAPI*)(LPCSTR);
				using PFNWGLGETCURRENTCONTEXTPROC 
					= HGLRC(WINAPI*)(void);

				PFNWGLSHARELISTSPROC m_fptr_wglShareLists;
				PFNWGLMAKECURRENTPROC m_fptr_wglMakeCurrent;
				PFNWGLCREATECONTEXTPROC m_fptr_wglCreateContext;
				PFNWGLDELETECONTEXTPROC m_fptr_wglDeleteContext;
				PFNWGLGETCURRENTDCPROC m_fptr_wglGetCurrentDC;
				PFNWGLGETPROCADDRESSPROC m_ptr_wglGetProcAddress;
				PFNWGLGETCURRENTCONTEXTPROC m_fptr_wglGetCurrentContext;
			} m_backend_procedures;

		public:
			/**
			 * @brief Default constructor.
			 */
			WGLLoader(Void) = default;

		public:
			/**
			 * @brief Default destructor.
			 */
			~WGLLoader(Void) = default;

		public:
			/**
			 * @brief Pre-initializes the opengl platform backend function
			 * pointers.
			 *
			 * This function loads the opengl dynamic library and performs
			 * function queries to the platform-dependant backend opengl
			 * functions.
			 *
			 * @throw InvalidIOException if failed to load dynamic library or
			 * failed to load dynamic library symbol.
			 */
			Void PreInitialize(Void) override;

			/**
			 * @brief Initializes the opengl function pointers.
			 *
			 * This function performs function queries to the desired opengl
			 * functions.
			 *
			 * @throw InvalidIOException if failed to load dynamic library
			 * symbol.
			 */
			Void Initialize(Void) override;

			/**
			 * @brief Terminates the opengl function pointers.
			 *
			 * This function releases the opengl dynamic library and
			 * perfoms nullification to the initialized opengl functions.
			 * 
			 * @throw InvalidOperationException if the dynamic library is null
			 * or not present in the registry.
			 */
			Void Terminate(Void) override;

		public:
			/**
			 * @brief Loads the specified opengl function symbol from the
			 * loaded opengl dynamic library.
			 *
			 * @param symbol[in] The opengl function symbol to load.
			 *
			 * @returns ConstVoidPtr storing the address of the specified
			 * opengl function symbol.
			 *
			 * @throw InvalidIOException if failed to load dynamic library
			 * symbol
			 * 
			 * @throw InvalidOperationException if the dynamic library is null
			 * or not present in the registry.
			 */
			ConstVoidPtr LoadFunction(ConstCharPtr symbol) override;
		};

		FORGE_TYPEDEF_DECL(WGLLoader)
	}
}

#endif
