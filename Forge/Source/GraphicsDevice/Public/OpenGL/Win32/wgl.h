#ifndef WGL_H
#define WGL_H 

#include <Core/Public/Common/Common.h>

#define FORGE_GL_DECL_FUNCTION(__TYPE__, __NAME__) \
	extern FORGE_API __TYPE__ __NAME__;	

#define FORGE_WGL_ARB_buffer_region					   0x006A
#define FORGE_WGL_ARB_context_flush_control			   0x006B
#define FORGE_WGL_ARB_create_context				   0x006C
#define FORGE_WGL_ARB_create_context_no_error		   0x006D
#define FORGE_WGL_ARB_create_context_profile		   0x006E
#define FORGE_WGL_ARB_create_context_robustness		   0x006F
#define FORGE_WGL_ARB_extensions_string				   0x0070
#define FORGE_WGL_ARB_framebuffer_sRGB				   0x0071
#define FORGE_WGL_ARB_make_current_read				   0x0072
#define FORGE_WGL_ARB_multisample					   0x0073
#define FORGE_WGL_ARB_pbuffer						   0x0074
#define FORGE_WGL_ARB_pixel_format					   0x0075
#define FORGE_WGL_ARB_pixel_format_float			   0x0076
#define FORGE_WGL_ARB_render_texture				   0x0077
#define FORGE_WGL_ARB_robustness_application_isolation 0x0078
#define FORGE_WGL_ARB_robustness_share_group_isolation 0x0079
#define FORGE_WGL_3DFX_multisample					   0x007A
#define FORGE_WGL_3DL_stereo_control				   0x007B
#define FORGE_WGL_AMD_gpu_association				   0x007C
#define FORGE_WGL_ATI_pixel_format_float			   0x007D
#define FORGE_WGL_ATI_render_texture_rectangle		   0x007E
#define FORGE_WGL_EXT_colorspace					   0x007F
#define FORGE_WGL_EXT_create_context_es2_profile	   0x0080
#define FORGE_WGL_EXT_create_context_es_profile		   0x0081
#define FORGE_WGL_EXT_depth_float					   0x0082
#define FORGE_WGL_EXT_display_color_table			   0x0083
#define FORGE_WGL_EXT_extensions_string				   0x0084
#define FORGE_WGL_EXT_framebuffer_sRGB				   0x0085
#define FORGE_WGL_EXT_make_current_read				   0x0086
#define FORGE_WGL_EXT_multisample					   0x0087
#define FORGE_WGL_EXT_pbuffer						   0x0088
#define FORGE_WGL_EXT_pixel_format					   0x0089
#define FORGE_WGL_EXT_pixel_format_packed_float		   0x008A
#define FORGE_WGL_EXT_swap_control					   0x008B
#define FORGE_WGL_EXT_swap_control_tear				   0x008C
#define FORGE_WGL_I3D_digital_video_control			   0x008D
#define FORGE_WGL_I3D_gamma							   0x008E
#define FORGE_WGL_I3D_genlock						   0x008F
#define FORGE_WGL_I3D_image_buffer					   0x0090
#define FORGE_WGL_I3D_swap_frame_lock				   0x0091
#define FORGE_WGL_I3D_swap_frame_usage				   0x0092
#define FORGE_WGL_NV_DX_interop						   0x0093
#define FORGE_WGL_NV_DX_interop2					   0x0094
#define FORGE_WGL_NV_copy_image						   0x0095
#define FORGE_WGL_NV_delay_before_swap				   0x0096
#define FORGE_WGL_NV_float_buffer					   0x0097
#define FORGE_WGL_NV_gpu_affinity					   0x0098
#define FORGE_WGL_NV_multigpu_context				   0x0099
#define FORGE_WGL_NV_multisample_coverage			   0x009A
#define FORGE_WGL_NV_present_video					   0x009B
#define FORGE_WGL_NV_render_depth_texture			   0x009C
#define FORGE_WGL_NV_render_texture_rectangle		   0x009D
#define FORGE_WGL_NV_swap_group						   0x009E
#define FORGE_WGL_NV_vertex_array_range				   0x009F
#define FORGE_WGL_NV_video_capture					   0x00A0
#define FORGE_WGL_NV_video_output					   0x00A1
#define FORGE_WGL_OML_sync_control					   0x00A2

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#endif

#define FORGE_WGL_WGLEXT_VERSION 20230220

#ifdef FORGE_WGL_ARB_buffer_region
#define WGL_FRONT_COLOR_BUFFER_BIT_ARB    0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB     0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB          0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB        0x00000008
	typedef HANDLE(WINAPI* PFNWGLCREATEBUFFERREGIONARBPROC) (HDC hDC, int iLayerPlane, UINT uType);
	typedef VOID(WINAPI* PFNWGLDELETEBUFFERREGIONARBPROC) (HANDLE hRegion);
	typedef BOOL(WINAPI* PFNWGLSAVEBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height);
	typedef BOOL(WINAPI* PFNWGLRESTOREBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
#endif /* FORGE_WGL_ARB_buffer_region */

#ifdef FORGE_WGL_ARB_context_flush_control
#define WGL_CONTEXT_RELEASE_BEHAVIOR_ARB  0x2097
#define WGL_CONTEXT_RELEASE_BEHAVIOR_NONE_ARB 0
#define WGL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_ARB 0x2098
#endif /* FORGE_WGL_ARB_context_flush_control */

#ifdef FORGE_WGL_ARB_create_context
#define WGL_CONTEXT_DEBUG_BIT_ARB         0x00000001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x00000002
#define WGL_CONTEXT_MAJOR_VERSION_ARB     0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB     0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB       0x2093
#define WGL_CONTEXT_FLAGS_ARB             0x2094
#define ERROR_INVALID_VERSION_ARB         0x2095
	typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int* attribList);
#endif /* FORGE_WGL_ARB_create_context */

#ifdef FORGE_WGL_ARB_create_context_no_error
#define WGL_CONTEXT_OPENGL_NO_ERROR_ARB   0x31B3
#endif /* FORGE_WGL_ARB_create_context_no_error */

#ifdef FORGE_WGL_ARB_create_context_profile
#define WGL_CONTEXT_PROFILE_MASK_ARB      0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB  0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define ERROR_INVALID_PROFILE_ARB         0x2096
#endif /* FORGE_WGL_ARB_create_context_profile */

#ifdef FORGE_WGL_ARB_create_context_robustness
#define WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB 0x00000004
#define WGL_LOSE_CONTEXT_ON_RESET_ARB     0x8252
#define WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define WGL_NO_RESET_NOTIFICATION_ARB     0x8261
#endif /* FORGE_WGL_ARB_create_context_robustness */

#ifdef FORGE_WGL_ARB_extensions_string
	typedef const char* (WINAPI* PFNWGLGETEXTENSIONSSTRINGARBPROC) (HDC hdc);
#endif /* FORGE_WGL_ARB_extensions_string */

#ifdef FORGE_WGL_ARB_framebuffer_sRGB
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB  0x20A9
#endif /* FORGE_WGL_ARB_framebuffer_sRGB */

#ifdef FORGE_WGL_ARB_make_current_read
#define ERROR_INVALID_PIXEL_TYPE_ARB      0x2043
#define ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB 0x2054
	typedef BOOL(WINAPI* PFNWGLMAKECONTEXTCURRENTARBPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
	typedef HDC(WINAPI* PFNWGLGETCURRENTREADDCARBPROC) (void);
#endif /* FORGE_WGL_ARB_make_current_read */

#ifdef FORGE_WGL_ARB_multisample
#define WGL_SAMPLE_BUFFERS_ARB            0x2041
#define WGL_SAMPLES_ARB                   0x2042
#endif /* FORGE_WGL_ARB_multisample */

#ifdef FORGE_WGL_ARB_pbuffer
DECLARE_HANDLE(HPBUFFERARB);
#define WGL_DRAW_TO_PBUFFER_ARB           0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB        0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB         0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB        0x2030
#define WGL_PBUFFER_LARGEST_ARB           0x2033
#define WGL_PBUFFER_WIDTH_ARB             0x2034
#define WGL_PBUFFER_HEIGHT_ARB            0x2035
#define WGL_PBUFFER_LOST_ARB              0x2036
	typedef HPBUFFERARB(WINAPI* PFNWGLCREATEPBUFFERARBPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList);
	typedef HDC(WINAPI* PFNWGLGETPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer);
	typedef int (WINAPI* PFNWGLRELEASEPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer, HDC hDC);
	typedef BOOL(WINAPI* PFNWGLDESTROYPBUFFERARBPROC) (HPBUFFERARB hPbuffer);
	typedef BOOL(WINAPI* PFNWGLQUERYPBUFFERARBPROC) (HPBUFFERARB hPbuffer, int iAttribute, int* piValue);
#endif /* FORGE_WGL_ARB_pbuffer */

#ifdef FORGE_WGL_ARB_pixel_format
#define WGL_NUMBER_PIXEL_FORMATS_ARB      0x2000
#define WGL_DRAW_TO_WINDOW_ARB            0x2001
#define WGL_DRAW_TO_BITMAP_ARB            0x2002
#define WGL_ACCELERATION_ARB              0x2003
#define WGL_NEED_PALETTE_ARB              0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB       0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB        0x2006
#define WGL_SWAP_METHOD_ARB               0x2007
#define WGL_NUMBER_OVERLAYS_ARB           0x2008
#define WGL_NUMBER_UNDERLAYS_ARB          0x2009
#define WGL_TRANSPARENT_ARB               0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB     0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB   0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB    0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB   0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB   0x203B
#define WGL_SHARE_DEPTH_ARB               0x200C
#define WGL_SHARE_STENCIL_ARB             0x200D
#define WGL_SHARE_ACCUM_ARB               0x200E
#define WGL_SUPPORT_GDI_ARB               0x200F
#define WGL_SUPPORT_OPENGL_ARB            0x2010
#define WGL_DOUBLE_BUFFER_ARB             0x2011
#define WGL_STEREO_ARB                    0x2012
#define WGL_PIXEL_TYPE_ARB                0x2013
#define WGL_COLOR_BITS_ARB                0x2014
#define WGL_RED_BITS_ARB                  0x2015
#define WGL_RED_SHIFT_ARB                 0x2016
#define WGL_GREEN_BITS_ARB                0x2017
#define WGL_GREEN_SHIFT_ARB               0x2018
#define WGL_BLUE_BITS_ARB                 0x2019
#define WGL_BLUE_SHIFT_ARB                0x201A
#define WGL_ALPHA_BITS_ARB                0x201B
#define WGL_ALPHA_SHIFT_ARB               0x201C
#define WGL_ACCUM_BITS_ARB                0x201D
#define WGL_ACCUM_RED_BITS_ARB            0x201E
#define WGL_ACCUM_GREEN_BITS_ARB          0x201F
#define WGL_ACCUM_BLUE_BITS_ARB           0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB          0x2021
#define WGL_DEPTH_BITS_ARB                0x2022
#define WGL_STENCIL_BITS_ARB              0x2023
#define WGL_AUX_BUFFERS_ARB               0x2024
#define WGL_NO_ACCELERATION_ARB           0x2025
#define WGL_GENERIC_ACCELERATION_ARB      0x2026
#define WGL_FULL_ACCELERATION_ARB         0x2027
#define WGL_SWAP_EXCHANGE_ARB             0x2028
#define WGL_SWAP_COPY_ARB                 0x2029
#define WGL_SWAP_UNDEFINED_ARB            0x202A
#define WGL_TYPE_RGBA_ARB                 0x202B
#define WGL_TYPE_COLORINDEX_ARB           0x202C
	typedef BOOL(WINAPI* PFNWGLGETPIXELFORMATATTRIBIVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, int* piValues);
	typedef BOOL(WINAPI* PFNWGLGETPIXELFORMATATTRIBFVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, FLOAT* pfValues);
	typedef BOOL(WINAPI* PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
#endif /* FORGE_WGL_ARB_pixel_format */

#ifdef FORGE_WGL_ARB_pixel_format_float
#define WGL_TYPE_RGBA_FLOAT_ARB           0x21A0
#endif /* FORGE_WGL_ARB_pixel_format_float */

#ifdef FORGE_WGL_ARB_render_texture
#define WGL_BIND_TO_TEXTURE_RGB_ARB       0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB      0x2071
#define WGL_TEXTURE_FORMAT_ARB            0x2072
#define WGL_TEXTURE_TARGET_ARB            0x2073
#define WGL_MIPMAP_TEXTURE_ARB            0x2074
#define WGL_TEXTURE_RGB_ARB               0x2075
#define WGL_TEXTURE_RGBA_ARB              0x2076
#define WGL_NO_TEXTURE_ARB                0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB          0x2078
#define WGL_TEXTURE_1D_ARB                0x2079
#define WGL_TEXTURE_2D_ARB                0x207A
#define WGL_MIPMAP_LEVEL_ARB              0x207B
#define WGL_CUBE_MAP_FACE_ARB             0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x2081
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x2082
#define WGL_FRONT_LEFT_ARB                0x2083
#define WGL_FRONT_RIGHT_ARB               0x2084
#define WGL_BACK_LEFT_ARB                 0x2085
#define WGL_BACK_RIGHT_ARB                0x2086
#define WGL_AUX0_ARB                      0x2087
#define WGL_AUX1_ARB                      0x2088
#define WGL_AUX2_ARB                      0x2089
#define WGL_AUX3_ARB                      0x208A
#define WGL_AUX4_ARB                      0x208B
#define WGL_AUX5_ARB                      0x208C
#define WGL_AUX6_ARB                      0x208D
#define WGL_AUX7_ARB                      0x208E
#define WGL_AUX8_ARB                      0x208F
#define WGL_AUX9_ARB                      0x2090
	typedef BOOL(WINAPI* PFNWGLBINDTEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
	typedef BOOL(WINAPI* PFNWGLRELEASETEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
	typedef BOOL(WINAPI* PFNWGLSETPBUFFERATTRIBARBPROC) (HPBUFFERARB hPbuffer, const int* piAttribList);
#endif /* FORGE_WGL_ARB_render_texture */

#ifdef FORGE_WGL_ARB_robustness_application_isolation
#define WGL_CONTEXT_RESET_ISOLATION_BIT_ARB 0x00000008
#endif /* FORGE_WGL_ARB_robustness_application_isolation */

#ifdef FORGE_WGL_ARB_robustness_share_group_isolation
#define WGL_ARB_robustness_share_group_isolation 1
#endif /* FORGE_WGL_ARB_robustness_share_group_isolation */

#ifdef FORGE_WGL_3DFX_multisample
#define WGL_SAMPLE_BUFFERS_3DFX           0x2060
#define WGL_SAMPLES_3DFX                  0x2061
#endif /* FORGE_WGL_3DFX_multisample */

#ifdef FORGE_WGL_3DL_stereo_control
#define WGL_STEREO_EMITTER_ENABLE_3DL     0x2055
#define WGL_STEREO_EMITTER_DISABLE_3DL    0x2056
#define WGL_STEREO_POLARITY_NORMAL_3DL    0x2057
#define WGL_STEREO_POLARITY_INVERT_3DL    0x2058
	typedef BOOL(WINAPI* PFNWGLSETSTEREOEMITTERSTATE3DLPROC) (HDC hDC, UINT uState);
#endif /* FORGE_WGL_3DL_stereo_control */

#ifdef FORGE_WGL_AMD_gpu_association
#define WGL_GPU_VENDOR_AMD                0x1F00
#define WGL_GPU_RENDERER_STRING_AMD       0x1F01
#define WGL_GPU_OPENGL_VERSION_STRING_AMD 0x1F02
#define WGL_GPU_FASTEST_TARGET_GPUS_AMD   0x21A2
#define WGL_GPU_RAM_AMD                   0x21A3
#define WGL_GPU_CLOCK_AMD                 0x21A4
#define WGL_GPU_NUM_PIPES_AMD             0x21A5
#define WGL_GPU_NUM_SIMD_AMD              0x21A6
#define WGL_GPU_NUM_RB_AMD                0x21A7
#define WGL_GPU_NUM_SPI_AMD               0x21A8
	typedef UINT(WINAPI* PFNWGLGETGPUIDSAMDPROC) (UINT maxCount, UINT* ids);
	typedef INT(WINAPI* PFNWGLGETGPUINFOAMDPROC) (UINT id, INT property, GLenum dataType, UINT size, void* data);
	typedef UINT(WINAPI* PFNWGLGETCONTEXTGPUIDAMDPROC) (HGLRC hglrc);
	typedef HGLRC(WINAPI* PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC) (UINT id);
	typedef HGLRC(WINAPI* PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC) (UINT id, HGLRC hShareContext, const int* attribList);
	typedef BOOL(WINAPI* PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC) (HGLRC hglrc);
	typedef BOOL(WINAPI* PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC) (HGLRC hglrc);
	typedef HGLRC(WINAPI* PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC) (void);
	typedef VOID(WINAPI* PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC) (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#endif /* FORGE_WGL_AMD_gpu_association */

#ifdef FORGE_WGL_ATI_pixel_format_float
#define WGL_TYPE_RGBA_FLOAT_ATI           0x21A0
#endif /* FORGE_WGL_ATI_pixel_format_float */

#ifdef FORGE_WGL_ATI_render_texture_rectangle
#define WGL_TEXTURE_RECTANGLE_ATI         0x21A5
#endif /* FORGE_WGL_ATI_render_texture_rectangle */

#ifdef FORGE_WGL_EXT_colorspace
#define WGL_COLORSPACE_EXT                0x309D
#define WGL_COLORSPACE_SRGB_EXT           0x3089
#define WGL_COLORSPACE_LINEAR_EXT         0x308A
#endif /* FORGE_WGL_EXT_colorspace */

#ifdef FORGE_WGL_EXT_create_context_es2_profile
#define WGL_CONTEXT_ES2_PROFILE_BIT_EXT   0x00000004
#endif /* FORGE_WGL_EXT_create_context_es2_profile */

#ifdef FORGE_WGL_EXT_create_context_es_profile
#define WGL_CONTEXT_ES_PROFILE_BIT_EXT    0x00000004
#endif /* FORGE_WGL_EXT_create_context_es_profile */

#ifdef FORGE_WGL_EXT_depth_float
#define WGL_DEPTH_FLOAT_EXT               0x2040
#endif /* FORGE_WGL_EXT_depth_float */

#ifdef FORGE_WGL_EXT_display_color_table
	typedef GLboolean(WINAPI* PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC) (GLushort id);
	typedef GLboolean(WINAPI* PFNWGLLOADDISPLAYCOLORTABLEEXTPROC) (const GLushort* table, GLuint length);
	typedef GLboolean(WINAPI* PFNWGLBINDDISPLAYCOLORTABLEEXTPROC) (GLushort id);
	typedef VOID(WINAPI* PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC) (GLushort id);
#endif /* FORGE_WGL_EXT_display_color_table */

#ifdef FORGE_WGL_EXT_extensions_string
	typedef const char* (WINAPI* PFNWGLGETEXTENSIONSSTRINGEXTPROC) (void);
#endif /* FORGE_WGL_EXT_extensions_string */

#ifdef FORGE_WGL_EXT_framebuffer_sRGB
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT  0x20A9
#endif /* FORGE_WGL_EXT_framebuffer_sRGB */

#ifdef FORGE_WGL_EXT_make_current_read
#define ERROR_INVALID_PIXEL_TYPE_EXT      0x2043
	typedef BOOL(WINAPI* PFNWGLMAKECONTEXTCURRENTEXTPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
	typedef HDC(WINAPI* PFNWGLGETCURRENTREADDCEXTPROC) (void);
#endif /* FORGE_WGL_EXT_make_current_read */

#ifdef FORGE_WGL_EXT_multisample
#define WGL_SAMPLE_BUFFERS_EXT            0x2041
#define WGL_SAMPLES_EXT                   0x2042
#endif /* FORGE_WGL_EXT_multisample */

#ifdef FORGE_WGL_EXT_pbuffer
DECLARE_HANDLE(HPBUFFEREXT);
#define WGL_DRAW_TO_PBUFFER_EXT           0x202D
#define WGL_MAX_PBUFFER_PIXELS_EXT        0x202E
#define WGL_MAX_PBUFFER_WIDTH_EXT         0x202F
#define WGL_MAX_PBUFFER_HEIGHT_EXT        0x2030
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT     0x2031
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT    0x2032
#define WGL_PBUFFER_LARGEST_EXT           0x2033
#define WGL_PBUFFER_WIDTH_EXT             0x2034
#define WGL_PBUFFER_HEIGHT_EXT            0x2035
	typedef HPBUFFEREXT(WINAPI* PFNWGLCREATEPBUFFEREXTPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList);
	typedef HDC(WINAPI* PFNWGLGETPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer);
	typedef int (WINAPI* PFNWGLRELEASEPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer, HDC hDC);
	typedef BOOL(WINAPI* PFNWGLDESTROYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer);
	typedef BOOL(WINAPI* PFNWGLQUERYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer, int iAttribute, int* piValue);
#endif /* FORGE_WGL_EXT_pbuffer */

#ifdef FORGE_WGL_EXT_pixel_format
#define WGL_NUMBER_PIXEL_FORMATS_EXT      0x2000
#define WGL_DRAW_TO_WINDOW_EXT            0x2001
#define WGL_DRAW_TO_BITMAP_EXT            0x2002
#define WGL_ACCELERATION_EXT              0x2003
#define WGL_NEED_PALETTE_EXT              0x2004
#define WGL_NEED_SYSTEM_PALETTE_EXT       0x2005
#define WGL_SWAP_LAYER_BUFFERS_EXT        0x2006
#define WGL_SWAP_METHOD_EXT               0x2007
#define WGL_NUMBER_OVERLAYS_EXT           0x2008
#define WGL_NUMBER_UNDERLAYS_EXT          0x2009
#define WGL_TRANSPARENT_EXT               0x200A
#define WGL_TRANSPARENT_VALUE_EXT         0x200B
#define WGL_SHARE_DEPTH_EXT               0x200C
#define WGL_SHARE_STENCIL_EXT             0x200D
#define WGL_SHARE_ACCUM_EXT               0x200E
#define WGL_SUPPORT_GDI_EXT               0x200F
#define WGL_SUPPORT_OPENGL_EXT            0x2010
#define WGL_DOUBLE_BUFFER_EXT             0x2011
#define WGL_STEREO_EXT                    0x2012
#define WGL_PIXEL_TYPE_EXT                0x2013
#define WGL_COLOR_BITS_EXT                0x2014
#define WGL_RED_BITS_EXT                  0x2015
#define WGL_RED_SHIFT_EXT                 0x2016
#define WGL_GREEN_BITS_EXT                0x2017
#define WGL_GREEN_SHIFT_EXT               0x2018
#define WGL_BLUE_BITS_EXT                 0x2019
#define WGL_BLUE_SHIFT_EXT                0x201A
#define WGL_ALPHA_BITS_EXT                0x201B
#define WGL_ALPHA_SHIFT_EXT               0x201C
#define WGL_ACCUM_BITS_EXT                0x201D
#define WGL_ACCUM_RED_BITS_EXT            0x201E
#define WGL_ACCUM_GREEN_BITS_EXT          0x201F
#define WGL_ACCUM_BLUE_BITS_EXT           0x2020
#define WGL_ACCUM_ALPHA_BITS_EXT          0x2021
#define WGL_DEPTH_BITS_EXT                0x2022
#define WGL_STENCIL_BITS_EXT              0x2023
#define WGL_AUX_BUFFERS_EXT               0x2024
#define WGL_NO_ACCELERATION_EXT           0x2025
#define WGL_GENERIC_ACCELERATION_EXT      0x2026
#define WGL_FULL_ACCELERATION_EXT         0x2027
#define WGL_SWAP_EXCHANGE_EXT             0x2028
#define WGL_SWAP_COPY_EXT                 0x2029
#define WGL_SWAP_UNDEFINED_EXT            0x202A
#define WGL_TYPE_RGBA_EXT                 0x202B
#define WGL_TYPE_COLORINDEX_EXT           0x202C
	typedef BOOL(WINAPI* PFNWGLGETPIXELFORMATATTRIBIVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, int* piValues);
	typedef BOOL(WINAPI* PFNWGLGETPIXELFORMATATTRIBFVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, FLOAT* pfValues);
	typedef BOOL(WINAPI* PFNWGLCHOOSEPIXELFORMATEXTPROC) (HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
#endif /* FORGE_WGL_EXT_pixel_format */

#ifdef FORGE_WGL_EXT_pixel_format_packed_float
#define WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT  0x20A8
#endif /* FORGE_WGL_EXT_pixel_format_packed_float */

#ifdef FORGE_WGL_EXT_swap_control
	typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC) (int interval);
	typedef int (WINAPI* PFNWGLGETSWAPINTERVALEXTPROC) (void);
#endif /* FORGE_WGL_EXT_swap_control */

#ifdef FORGE_WGL_EXT_swap_control_tear
#define WGL_EXT_swap_control_tear 1
#endif /* FORGE_WGL_EXT_swap_control_tear */

#ifdef FORGE_WGL_I3D_digital_video_control
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D 0x2050
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D 0x2051
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D 0x2052
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D 0x2053
	typedef BOOL(WINAPI* PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int* piValue);
	typedef BOOL(WINAPI* PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int* piValue);
#endif /* FORGE_WGL_I3D_digital_video_control */

#ifdef FORGE_WGL_I3D_gamma
#define WGL_GAMMA_TABLE_SIZE_I3D          0x204E
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D     0x204F
	typedef BOOL(WINAPI* PFNWGLGETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int* piValue);
	typedef BOOL(WINAPI* PFNWGLSETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int* piValue);
	typedef BOOL(WINAPI* PFNWGLGETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, USHORT* puRed, USHORT* puGreen, USHORT* puBlue);
	typedef BOOL(WINAPI* PFNWGLSETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, const USHORT* puRed, const USHORT* puGreen, const USHORT* puBlue);
#endif /* FORGE_WGL_I3D_gamma */

#ifdef FORGE_WGL_I3D_genlock
#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D  0x2044
#define WGL_GENLOCK_SOURCE_EXTERNAL_SYNC_I3D 0x2045
#define WGL_GENLOCK_SOURCE_EXTERNAL_FIELD_I3D 0x2046
#define WGL_GENLOCK_SOURCE_EXTERNAL_TTL_I3D 0x2047
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D 0x2048
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D 0x2049
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D 0x204A
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D 0x204B
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D  0x204C
	typedef BOOL(WINAPI* PFNWGLENABLEGENLOCKI3DPROC) (HDC hDC);
	typedef BOOL(WINAPI* PFNWGLDISABLEGENLOCKI3DPROC) (HDC hDC);
	typedef BOOL(WINAPI* PFNWGLISENABLEDGENLOCKI3DPROC) (HDC hDC, BOOL* pFlag);
	typedef BOOL(WINAPI* PFNWGLGENLOCKSOURCEI3DPROC) (HDC hDC, UINT uSource);
	typedef BOOL(WINAPI* PFNWGLGETGENLOCKSOURCEI3DPROC) (HDC hDC, UINT* uSource);
	typedef BOOL(WINAPI* PFNWGLGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT uEdge);
	typedef BOOL(WINAPI* PFNWGLGETGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT* uEdge);
	typedef BOOL(WINAPI* PFNWGLGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT uRate);
	typedef BOOL(WINAPI* PFNWGLGETGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT* uRate);
	typedef BOOL(WINAPI* PFNWGLGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT uDelay);
	typedef BOOL(WINAPI* PFNWGLGETGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT* uDelay);
	typedef BOOL(WINAPI* PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC) (HDC hDC, UINT* uMaxLineDelay, UINT* uMaxPixelDelay);
#endif /* FORGE_WGL_I3D_genlock */

#ifdef FORGE_WGL_I3D_image_buffer
#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D   0x00000001
#define WGL_IMAGE_BUFFER_LOCK_I3D         0x00000002
	typedef LPVOID(WINAPI* PFNWGLCREATEIMAGEBUFFERI3DPROC) (HDC hDC, DWORD dwSize, UINT uFlags);
	typedef BOOL(WINAPI* PFNWGLDESTROYIMAGEBUFFERI3DPROC) (HDC hDC, LPVOID pAddress);
	typedef BOOL(WINAPI* PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const HANDLE* pEvent, const LPVOID* pAddress, const DWORD* pSize, UINT count);
	typedef BOOL(WINAPI* PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const LPVOID* pAddress, UINT count);
#endif /* FORGE_WGL_I3D_image_buffer */

#ifdef FORGE_WGL_I3D_swap_frame_lock
	typedef BOOL(WINAPI* PFNWGLENABLEFRAMELOCKI3DPROC) (void);
	typedef BOOL(WINAPI* PFNWGLDISABLEFRAMELOCKI3DPROC) (void);
	typedef BOOL(WINAPI* PFNWGLISENABLEDFRAMELOCKI3DPROC) (BOOL* pFlag);
	typedef BOOL(WINAPI* PFNWGLQUERYFRAMELOCKMASTERI3DPROC) (BOOL* pFlag);
#endif /* FORGE_WGL_I3D_swap_frame_lock */

#ifdef FORGE_WGL_I3D_swap_frame_usage
	typedef BOOL(WINAPI* PFNWGLGETFRAMEUSAGEI3DPROC) (float* pUsage);
	typedef BOOL(WINAPI* PFNWGLBEGINFRAMETRACKINGI3DPROC) (void);
	typedef BOOL(WINAPI* PFNWGLENDFRAMETRACKINGI3DPROC) (void);
	typedef BOOL(WINAPI* PFNWGLQUERYFRAMETRACKINGI3DPROC) (DWORD* pFrameCount, DWORD* pMissedFrames, float* pLastMissedUsage);
#endif /* FORGE_WGL_I3D_swap_frame_usage */

#ifdef FORGE_WGL_NV_DX_interop
#define WGL_ACCESS_READ_ONLY_NV           0x00000000
#define WGL_ACCESS_READ_WRITE_NV          0x00000001
#define WGL_ACCESS_WRITE_DISCARD_NV       0x00000002
	typedef BOOL(WINAPI* PFNWGLDXSETRESOURCESHAREHANDLENVPROC) (void* dxObject, HANDLE shareHandle);
	typedef HANDLE(WINAPI* PFNWGLDXOPENDEVICENVPROC) (void* dxDevice);
	typedef BOOL(WINAPI* PFNWGLDXCLOSEDEVICENVPROC) (HANDLE hDevice);
	typedef HANDLE(WINAPI* PFNWGLDXREGISTEROBJECTNVPROC) (HANDLE hDevice, void* dxObject, GLuint name, GLenum type, GLenum access);
	typedef BOOL(WINAPI* PFNWGLDXUNREGISTEROBJECTNVPROC) (HANDLE hDevice, HANDLE hObject);
	typedef BOOL(WINAPI* PFNWGLDXOBJECTACCESSNVPROC) (HANDLE hObject, GLenum access);
	typedef BOOL(WINAPI* PFNWGLDXLOCKOBJECTSNVPROC) (HANDLE hDevice, GLint count, HANDLE* hObjects);
	typedef BOOL(WINAPI* PFNWGLDXUNLOCKOBJECTSNVPROC) (HANDLE hDevice, GLint count, HANDLE* hObjects);
#endif /* FORGE_WGL_NV_DX_interop */

#ifdef FORGE_WGL_NV_DX_interop2
#define WGL_NV_DX_interop2 1
#endif /* FORGE_WGL_NV_DX_interop2 */

#ifdef FORGE_WGL_NV_copy_image
	typedef BOOL(WINAPI* PFNWGLCOPYIMAGESUBDATANVPROC) (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
#endif /* FORGE_WGL_NV_copy_image */

#ifdef FORGE_WGL_NV_delay_before_swap
	typedef BOOL(WINAPI* PFNWGLDELAYBEFORESWAPNVPROC) (HDC hDC, GLfloat seconds);
#endif /* FORGE_WGL_NV_delay_before_swap */

#ifdef FORGE_WGL_NV_float_buffer
#define WGL_FLOAT_COMPONENTS_NV           0x20B0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV 0x20B1
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV 0x20B2
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV 0x20B3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV 0x20B4
#define WGL_TEXTURE_FLOAT_R_NV            0x20B5
#define WGL_TEXTURE_FLOAT_RG_NV           0x20B6
#define WGL_TEXTURE_FLOAT_RGB_NV          0x20B7
#define WGL_TEXTURE_FLOAT_RGBA_NV         0x20B8
#endif /* FORGE_WGL_NV_float_buffer */

#ifdef FORGE_WGL_NV_gpu_affinity
	DECLARE_HANDLE(HGPUNV);
	struct _GPU_DEVICE {
		DWORD  cb;
		CHAR   DeviceName[32];
		CHAR   DeviceString[128];
		DWORD  Flags;
		RECT   rcVirtualScreen;
	};
	typedef struct _GPU_DEVICE* PGPU_DEVICE;
#define ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV 0x20D0
#define ERROR_MISSING_AFFINITY_MASK_NV    0x20D1
	typedef BOOL(WINAPI* PFNWGLENUMGPUSNVPROC) (UINT iGpuIndex, HGPUNV* phGpu);
	typedef BOOL(WINAPI* PFNWGLENUMGPUDEVICESNVPROC) (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
	typedef HDC(WINAPI* PFNWGLCREATEAFFINITYDCNVPROC) (const HGPUNV* phGpuList);
	typedef BOOL(WINAPI* PFNWGLENUMGPUSFROMAFFINITYDCNVPROC) (HDC hAffinityDC, UINT iGpuIndex, HGPUNV* hGpu);
	typedef BOOL(WINAPI* PFNWGLDELETEDCNVPROC) (HDC hdc);
#endif /* FORGE_WGL_NV_gpu_affinity */

#ifdef FORGE_WGL_NV_multigpu_context
#define WGL_CONTEXT_MULTIGPU_ATTRIB_NV    0x20AA
#define WGL_CONTEXT_MULTIGPU_ATTRIB_SINGLE_NV 0x20AB
#define WGL_CONTEXT_MULTIGPU_ATTRIB_AFR_NV 0x20AC
#define WGL_CONTEXT_MULTIGPU_ATTRIB_MULTICAST_NV 0x20AD
#define WGL_CONTEXT_MULTIGPU_ATTRIB_MULTI_DISPLAY_MULTICAST_NV 0x20AE
#endif /* FORGE_WGL_NV_multigpu_context */

#ifdef FORGE_WGL_NV_multisample_coverage
#define WGL_COVERAGE_SAMPLES_NV           0x2042
#define WGL_COLOR_SAMPLES_NV              0x20B9
#endif /* FORGE_WGL_NV_multisample_coverage */

#ifdef FORGE_WGL_NV_present_video
	DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
#define WGL_NUM_VIDEO_SLOTS_NV            0x20F0
	typedef int (WINAPI* PFNWGLENUMERATEVIDEODEVICESNVPROC) (HDC hDc, HVIDEOOUTPUTDEVICENV* phDeviceList);
	typedef BOOL(WINAPI* PFNWGLBINDVIDEODEVICENVPROC) (HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int* piAttribList);
	typedef BOOL(WINAPI* PFNWGLQUERYCURRENTCONTEXTNVPROC) (int iAttribute, int* piValue);
#endif /* FORGE_WGL_NV_present_video */

#ifdef FORGE_WGL_NV_render_depth_texture
#define WGL_BIND_TO_TEXTURE_DEPTH_NV      0x20A3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV 0x20A4
#define WGL_DEPTH_TEXTURE_FORMAT_NV       0x20A5
#define WGL_TEXTURE_DEPTH_COMPONENT_NV    0x20A6
#define WGL_DEPTH_COMPONENT_NV            0x20A7
#endif /* FORGE_WGL_NV_render_depth_texture */

#ifdef FORGE_WGL_NV_render_texture_rectangle
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV 0x20A0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV 0x20A1
#define WGL_TEXTURE_RECTANGLE_NV          0x20A2
#endif /* FORGE_WGL_NV_render_texture_rectangle */

#ifdef FORGE_WGL_NV_swap_group
	typedef BOOL(WINAPI* PFNWGLJOINSWAPGROUPNVPROC) (HDC hDC, GLuint group);
	typedef BOOL(WINAPI* PFNWGLBINDSWAPBARRIERNVPROC) (GLuint group, GLuint barrier);
	typedef BOOL(WINAPI* PFNWGLQUERYSWAPGROUPNVPROC) (HDC hDC, GLuint* group, GLuint* barrier);
	typedef BOOL(WINAPI* PFNWGLQUERYMAXSWAPGROUPSNVPROC) (HDC hDC, GLuint* maxGroups, GLuint* maxBarriers);
	typedef BOOL(WINAPI* PFNWGLQUERYFRAMECOUNTNVPROC) (HDC hDC, GLuint* count);
	typedef BOOL(WINAPI* PFNWGLRESETFRAMECOUNTNVPROC) (HDC hDC);
#endif /* FORGE_WGL_NV_swap_group */

#ifdef FORGE_WGL_NV_vertex_array_range
	typedef void* (WINAPI* PFNWGLALLOCATEMEMORYNVPROC) (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
	typedef void (WINAPI* PFNWGLFREEMEMORYNVPROC) (void* pointer);
#endif /* FORGE_WGL_NV_vertex_array_range */

#ifdef FORGE_WGL_NV_video_capture
	DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
#define WGL_UNIQUE_ID_NV                  0x20CE
#define WGL_NUM_VIDEO_CAPTURE_SLOTS_NV    0x20CF
	typedef BOOL(WINAPI* PFNWGLBINDVIDEOCAPTUREDEVICENVPROC) (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
	typedef UINT(WINAPI* PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC) (HDC hDc, HVIDEOINPUTDEVICENV* phDeviceList);
	typedef BOOL(WINAPI* PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
	typedef BOOL(WINAPI* PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int* piValue);
	typedef BOOL(WINAPI* PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC) (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
#endif /* FORGE_WGL_NV_video_capture */

#ifdef FORGE_WGL_NV_video_output
	DECLARE_HANDLE(HPVIDEODEV);
#define WGL_BIND_TO_VIDEO_RGB_NV          0x20C0
#define WGL_BIND_TO_VIDEO_RGBA_NV         0x20C1
#define WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV 0x20C2
#define WGL_VIDEO_OUT_COLOR_NV            0x20C3
#define WGL_VIDEO_OUT_ALPHA_NV            0x20C4
#define WGL_VIDEO_OUT_DEPTH_NV            0x20C5
#define WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV  0x20C6
#define WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV  0x20C7
#define WGL_VIDEO_OUT_FRAME               0x20C8
#define WGL_VIDEO_OUT_FIELD_1             0x20C9
#define WGL_VIDEO_OUT_FIELD_2             0x20CA
#define WGL_VIDEO_OUT_STACKED_FIELDS_1_2  0x20CB
#define WGL_VIDEO_OUT_STACKED_FIELDS_2_1  0x20CC
	typedef BOOL(WINAPI* PFNWGLGETVIDEODEVICENVPROC) (HDC hDC, int numDevices, HPVIDEODEV* hVideoDevice);
	typedef BOOL(WINAPI* PFNWGLRELEASEVIDEODEVICENVPROC) (HPVIDEODEV hVideoDevice);
	typedef BOOL(WINAPI* PFNWGLBINDVIDEOIMAGENVPROC) (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
	typedef BOOL(WINAPI* PFNWGLRELEASEVIDEOIMAGENVPROC) (HPBUFFERARB hPbuffer, int iVideoBuffer);
	typedef BOOL(WINAPI* PFNWGLSENDPBUFFERTOVIDEONVPROC) (HPBUFFERARB hPbuffer, int iBufferType, unsigned long* pulCounterPbuffer, BOOL bBlock);
	typedef BOOL(WINAPI* PFNWGLGETVIDEOINFONVPROC) (HPVIDEODEV hpVideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo);
#endif /* FORGE_WGL_NV_video_output */

#ifdef FORGE_WGL_OML_sync_control
	typedef BOOL(WINAPI* PFNWGLGETSYNCVALUESOMLPROC) (HDC hdc, INT64* ust, INT64* msc, INT64* sbc);
	typedef BOOL(WINAPI* PFNWGLGETMSCRATEOMLPROC) (HDC hdc, INT32* numerator, INT32* denominator);
	typedef INT64(WINAPI* PFNWGLSWAPBUFFERSMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
	typedef INT64(WINAPI* PFNWGLSWAPLAYERBUFFERSMSCOMLPROC) (HDC hdc, INT fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
	typedef BOOL(WINAPI* PFNWGLWAITFORMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64* ust, INT64* msc, INT64* sbc);
	typedef BOOL(WINAPI* PFNWGLWAITFORSBCOMLPROC) (HDC hdc, INT64 target_sbc, INT64* ust, INT64* msc, INT64* sbc);
#endif /* FORGE_WGL_OML_sync_control */

/**
 *
 *
 * Function declerations
 *
 *
 */

#ifdef FORGE_WGL_ARB_buffer_region
	FORGE_GL_DECL_FUNCTION(PFNWGLCREATEBUFFERREGIONARBPROC, wglCreateBufferRegionARB)
	FORGE_GL_DECL_FUNCTION(PFNWGLDELETEBUFFERREGIONARBPROC, wglDeleteBufferRegionARB)
	FORGE_GL_DECL_FUNCTION(PFNWGLSAVEBUFFERREGIONARBPROC, wglSaveBufferRegionARB)
	FORGE_GL_DECL_FUNCTION(PFNWGLRESTOREBUFFERREGIONARBPROC, wglRestoreBufferRegionARB)
#endif /* FORGE_WGL_ARB_buffer_region */

#ifdef FORGE_WGL_ARB_create_context
	FORGE_GL_DECL_FUNCTION(PFNWGLCREATECONTEXTATTRIBSARBPROC, wglCreateContextAttribsARB)
#endif /* FORGE_WGL_ARB_create_context */

#ifdef FORGE_WGL_ARB_extensions_string
	FORGE_GL_DECL_FUNCTION(PFNWGLGETEXTENSIONSSTRINGARBPROC, wglGetExtensionsStringARB)
#endif /* FORGE_WGL_ARB_extensions_string */

#ifdef FORGE_WGL_ARB_make_current_read
	FORGE_GL_DECL_FUNCTION(PFNWGLMAKECONTEXTCURRENTARBPROC, wglMakeContextCurrentARB)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETCURRENTREADDCARBPROC, wglGetCurrentReadDCARB)
#endif /* FORGE_WGL_ARB_make_current_read */

#ifdef FORGE_WGL_ARB_pbuffer
	FORGE_GL_DECL_FUNCTION(PFNWGLCREATEPBUFFERARBPROC, wglCreatePbufferARB)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETPBUFFERDCARBPROC, wglGetPbufferDCARB)
	FORGE_GL_DECL_FUNCTION(PFNWGLRELEASEPBUFFERDCARBPROC, wglReleasePbufferDCARB)
	FORGE_GL_DECL_FUNCTION(PFNWGLDESTROYPBUFFERARBPROC, wglDestroyPbufferARB)
	FORGE_GL_DECL_FUNCTION(PFNWGLQUERYPBUFFERARBPROC, wglQueryPbufferARB)
#endif /* FORGE_WGL_ARB_pbuffer */

#ifdef FORGE_WGL_ARB_pixel_format
	FORGE_GL_DECL_FUNCTION(PFNWGLGETPIXELFORMATATTRIBIVARBPROC, wglGetPixelFormatAttribivARB)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETPIXELFORMATATTRIBFVARBPROC, wglGetPixelFormatAttribfvARB)
	FORGE_GL_DECL_FUNCTION(PFNWGLCHOOSEPIXELFORMATARBPROC, wglChoosePixelFormatARB)
#endif /* FORGE_WGL_ARB_pixel_format */

#ifdef FORGE_WGL_ARB_render_texture
	FORGE_GL_DECL_FUNCTION(PFNWGLBINDTEXIMAGEARBPROC, wglBindTexImageARB)
	FORGE_GL_DECL_FUNCTION(PFNWGLRELEASETEXIMAGEARBPROC, wglReleaseTexImageARB)
	FORGE_GL_DECL_FUNCTION(PFNWGLSETPBUFFERATTRIBARBPROC, wglSetPbufferAttribARB)
#endif /* FORGE_WGL_ARB_render_texture */

#ifdef FORGE_WGL_3DL_stereo_control
	FORGE_GL_DECL_FUNCTION(PFNWGLSETSTEREOEMITTERSTATE3DLPROC, wglSetStereoEmitterState3DL)
#endif /* FORGE_WGL_3DL_stereo_control */

#ifdef FORGE_WGL_AMD_gpu_association
	FORGE_GL_DECL_FUNCTION(PFNWGLGETGPUIDSAMDPROC, wglGetGPUIDsAMD)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETGPUINFOAMDPROC, wglGetGPUInfoAMD)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETCONTEXTGPUIDAMDPROC, wglGetContextGPUIDAMD)
	FORGE_GL_DECL_FUNCTION(PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC, wglCreateAssociatedContextAMD)
	FORGE_GL_DECL_FUNCTION(PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC, wglCreateAssociatedContextAttribsAMD)
	FORGE_GL_DECL_FUNCTION(PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC, wglDeleteAssociatedContextAMD)
	FORGE_GL_DECL_FUNCTION(PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC, wglMakeAssociatedContextCurrentAMD)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC, wglGetCurrentAssociatedContextAMD)
	FORGE_GL_DECL_FUNCTION(PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC, wglBlitContextFramebufferAMD)
#endif /* FORGE_WGL_AMD_gpu_association */

#ifdef FORGE_WGL_EXT_display_color_table
	FORGE_GL_DECL_FUNCTION(PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC, wglCreateDisplayColorTableEXT)
	FORGE_GL_DECL_FUNCTION(PFNWGLLOADDISPLAYCOLORTABLEEXTPROC, wglLoadDisplayColorTableEXT)
	FORGE_GL_DECL_FUNCTION(PFNWGLBINDDISPLAYCOLORTABLEEXTPROC, wglBindDisplayColorTableEXT)
	FORGE_GL_DECL_FUNCTION(PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC, wglDestroyDisplayColorTableEXT)
#endif /* FORGE_WGL_EXT_display_color_table */

#ifdef FORGE_WGL_EXT_extensions_string
	FORGE_GL_DECL_FUNCTION(PFNWGLGETEXTENSIONSSTRINGEXTPROC, wglGetExtensionsStringEXT)
#endif /* FORGE_WGL_EXT_extensions_string */

#ifdef FORGE_WGL_EXT_make_current_read
	FORGE_GL_DECL_FUNCTION(PFNWGLMAKECONTEXTCURRENTEXTPROC, wglMakeContextCurrentEXT)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETCURRENTREADDCEXTPROC, wglGetCurrentReadDCEXT)
#endif /* FORGE_WGL_EXT_make_current_read */

#ifdef FORGE_WGL_EXT_pbuffer
	FORGE_GL_DECL_FUNCTION(PFNWGLCREATEPBUFFEREXTPROC, wglCreatePbufferEXT)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETPBUFFERDCEXTPROC, wglGetPbufferDCEXT)
	FORGE_GL_DECL_FUNCTION(PFNWGLRELEASEPBUFFERDCEXTPROC, wglReleasePbufferDCEXT)
	FORGE_GL_DECL_FUNCTION(PFNWGLDESTROYPBUFFEREXTPROC, wglDestroyPbufferEXT)
	FORGE_GL_DECL_FUNCTION(PFNWGLQUERYPBUFFEREXTPROC, wglQueryPbufferEXT)
#endif /* FORGE_WGL_EXT_pbuffer */

#ifdef FORGE_WGL_EXT_pixel_format
	FORGE_GL_DECL_FUNCTION(PFNWGLGETPIXELFORMATATTRIBIVEXTPROC, wglGetPixelFormatAttribivEXT)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETPIXELFORMATATTRIBFVEXTPROC, wglGetPixelFormatAttribfvEXT)
	FORGE_GL_DECL_FUNCTION(PFNWGLCHOOSEPIXELFORMATEXTPROC, wglChoosePixelFormatEXT)
#endif /* FORGE_WGL_EXT_pixel_format */

#ifdef FORGE_WGL_EXT_swap_control
	FORGE_GL_DECL_FUNCTION(PFNWGLSWAPINTERVALEXTPROC, wglSwapIntervalEXT)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETSWAPINTERVALEXTPROC, wglGetSwapIntervalEXT)
#endif /* FORGE_WGL_EXT_swap_control */

#ifdef FORGE_WGL_I3D_digital_video_control
	FORGE_GL_DECL_FUNCTION(PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC, wglGetDigitalVideoParametersI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC, wglSetDigitalVideoParametersI3D)
#endif /* FORGE_WGL_I3D_digital_video_control */

#ifdef FORGE_WGL_I3D_gamma
	FORGE_GL_DECL_FUNCTION(PFNWGLGETGAMMATABLEPARAMETERSI3DPROC, wglGetGammaTableParametersI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLSETGAMMATABLEPARAMETERSI3DPROC, wglSetGammaTableParametersI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLSETGAMMATABLEPARAMETERSI3DPROC, wglGetGammaTableI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLSETGAMMATABLEPARAMETERSI3DPROC, wglSetGammaTableI3D)
#endif /* FORGE_WGL_I3D_gamma */

#ifdef FORGE_WGL_I3D_genlock
	FORGE_GL_DECL_FUNCTION(PFNWGLENABLEGENLOCKI3DPROC, wglEnableGenlockI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLDISABLEGENLOCKI3DPROC, wglDisableGenlockI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLISENABLEDGENLOCKI3DPROC, wglIsEnabledGenlockI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLGENLOCKSOURCEI3DPROC, wglGenlockSourceI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETGENLOCKSOURCEI3DPROC, wglGetGenlockSourceI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLGENLOCKSOURCEEDGEI3DPROC, wglGenlockSourceEdgeI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETGENLOCKSOURCEEDGEI3DPROC, wglGetGenlockSourceEdgeI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLGENLOCKSAMPLERATEI3DPROC, wglGenlockSampleRateI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETGENLOCKSAMPLERATEI3DPROC, wglGetGenlockSampleRateI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLGENLOCKSOURCEDELAYI3DPROC, wglGenlockSourceDelayI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETGENLOCKSOURCEDELAYI3DPROC, wglGetGenlockSourceDelayI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC, wglQueryGenlockMaxSourceDelayI3D)
#endif /* FORGE_WGL_I3D_genlock */

#ifdef FORGE_WGL_I3D_image_buffer
	FORGE_GL_DECL_FUNCTION(PFNWGLCREATEIMAGEBUFFERI3DPROC, wglCreateImageBufferI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLDESTROYIMAGEBUFFERI3DPROC, wglDestroyImageBufferI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC, wglAssociateImageBufferEventsI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC, wglReleaseImageBufferEventsI3D)
#endif /* FORGE_WGL_I3D_image_buffer */

#ifdef FORGE_WGL_I3D_swap_frame_lock
	FORGE_GL_DECL_FUNCTION(PFNWGLENABLEFRAMELOCKI3DPROC, wglEnableFrameLockI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLDISABLEFRAMELOCKI3DPROC, wglDisableFrameLockI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLISENABLEDFRAMELOCKI3DPROC, wglIsEnabledFrameLockI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLQUERYFRAMELOCKMASTERI3DPROC, wglQueryFrameLockMasterI3D)
#endif /* FORGE_WGL_I3D_swap_frame_lock */

#ifdef FORGE_WGL_I3D_swap_frame_usage
	FORGE_GL_DECL_FUNCTION(PFNWGLGETFRAMEUSAGEI3DPROC, wglGetFrameUsageI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLBEGINFRAMETRACKINGI3DPROC, wglBeginFrameTrackingI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLENDFRAMETRACKINGI3DPROC, wglEndFrameTrackingI3D)
	FORGE_GL_DECL_FUNCTION(PFNWGLQUERYFRAMETRACKINGI3DPROC, wglQueryFrameTrackingI3D)
#endif /* FORGE_WGL_I3D_swap_frame_usage */

#ifdef FORGE_WGL_NV_DX_interop
	FORGE_GL_DECL_FUNCTION(PFNWGLDXSETRESOURCESHAREHANDLENVPROC, wglDXSetResourceShareHandleNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLDXOPENDEVICENVPROC, wglDXOpenDeviceNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLDXCLOSEDEVICENVPROC, wglDXCloseDeviceNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLDXREGISTEROBJECTNVPROC, wglDXRegisterObjectNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLDXUNREGISTEROBJECTNVPROC, wglDXUnregisterObjectNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLDXOBJECTACCESSNVPROC, wglDXObjectAccessNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLDXLOCKOBJECTSNVPROC, wglDXLockObjectsNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLDXUNLOCKOBJECTSNVPROC, wglDXUnlockObjectsNV)
#endif /* FORGE_WGL_NV_DX_interop */

#ifdef FORGE_WGL_NV_copy_image
		FORGE_GL_DECL_FUNCTION(PFNWGLCOPYIMAGESUBDATANVPROC, wglCopyImageSubDataNV)
#endif /* FORGE_WGL_NV_copy_image */

#ifdef FORGE_WGL_NV_delay_before_swap
	FORGE_GL_DECL_FUNCTION(PFNWGLDELAYBEFORESWAPNVPROC, wglDelayBeforeSwapNV)
#endif /* FORGE_WGL_NV_delay_before_swap */

#ifdef FORGE_WGL_NV_gpu_affinity
	FORGE_GL_DECL_FUNCTION(PFNWGLENUMGPUSNVPROC, wglEnumGpusNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLENUMGPUDEVICESNVPROC, wglEnumGpuDevicesNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLCREATEAFFINITYDCNVPROC, wglCreateAffinityDCNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLENUMGPUSFROMAFFINITYDCNVPROC, wglEnumGpusFromAffinityDCNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLDELETEDCNVPROC, wglDeleteDCNV)
#endif /* FORGE_WGL_NV_gpu_affinity */

#ifdef FORGE_WGL_NV_present_video
	FORGE_GL_DECL_FUNCTION(PFNWGLENUMERATEVIDEODEVICESNVPROC, wglEnumerateVideoDevicesNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLBINDVIDEODEVICENVPROC, wglBindVideoDeviceNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLQUERYCURRENTCONTEXTNVPROC, wglQueryCurrentContextNV)
#endif /* FORGE_WGL_NV_present_video */

#ifdef FORGE_WGL_NV_swap_group
	FORGE_GL_DECL_FUNCTION(PFNWGLJOINSWAPGROUPNVPROC, wglJoinSwapGroupNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLBINDSWAPBARRIERNVPROC, wglBindSwapBarrierNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLQUERYSWAPGROUPNVPROC, wglQuerySwapGroupNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLQUERYMAXSWAPGROUPSNVPROC, wglQueryMaxSwapGroupsNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLQUERYFRAMECOUNTNVPROC, wglQueryFrameCountNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLRESETFRAMECOUNTNVPROC, wglResetFrameCountNV)
#endif /* FORGE_WGL_NV_swap_group */

#ifdef FORGE_WGL_NV_vertex_array_range
	FORGE_GL_DECL_FUNCTION(PFNWGLALLOCATEMEMORYNVPROC, wglAllocateMemoryNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLFREEMEMORYNVPROC, wglFreeMemoryNV)
#endif /* FORGE_WGL_NV_vertex_array_range */

#ifdef FORGE_WGL_NV_video_capture
	FORGE_GL_DECL_FUNCTION(PFNWGLBINDVIDEOCAPTUREDEVICENVPROC, wglBindVideoCaptureDeviceNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC, wglEnumerateVideoCaptureDevicesNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC, wglLockVideoCaptureDeviceNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC, wglQueryVideoCaptureDeviceNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC, wglReleaseVideoCaptureDeviceNV)
#endif /* FORGE_WGL_NV_video_capture */

#ifdef FORGE_WGL_NV_video_output
	FORGE_GL_DECL_FUNCTION(PFNWGLGETVIDEODEVICENVPROC, wglGetVideoDeviceNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLRELEASEVIDEODEVICENVPROC, wglReleaseVideoDeviceNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLBINDVIDEOIMAGENVPROC, wglBindVideoImageNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLRELEASEVIDEOIMAGENVPROC, wglReleaseVideoImageNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLSENDPBUFFERTOVIDEONVPROC, wglSendPbufferToVideoNV)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETVIDEOINFONVPROC, wglGetVideoInfoNV)
#endif /* FORGE_WGL_NV_video_output */

#ifdef FORGE_WGL_OML_sync_control
	FORGE_GL_DECL_FUNCTION(PFNWGLGETSYNCVALUESOMLPROC, wglGetSyncValuesOML)
	FORGE_GL_DECL_FUNCTION(PFNWGLGETMSCRATEOMLPROC, wglGetMscRateOML)
	FORGE_GL_DECL_FUNCTION(PFNWGLSWAPBUFFERSMSCOMLPROC, wglSwapBuffersMscOML)
	FORGE_GL_DECL_FUNCTION(PFNWGLSWAPLAYERBUFFERSMSCOMLPROC, wglSwapLayerBuffersMscOML)
	FORGE_GL_DECL_FUNCTION(PFNWGLWAITFORMSCOMLPROC, wglWaitForMscOML)
	FORGE_GL_DECL_FUNCTION(PFNWGLWAITFORSBCOMLPROC, wglWaitForSbcOML)
#endif /* FORGE_WGL_OML_sync_control */

#ifdef __cplusplus
}
#endif

#endif