#ifndef GL_H
#define GL_H

#include <Core/Public/Common/Common.h>

#define __GL_H__		  1 /* Windows */
#define __gl_h_           1 /* Windows / Linux */
#define __gl_glext_h_     1 /* Khronos compatibility  profile and extension interfaces. */    
#define __gl_glcorearb_h_ 1 /* Khronos core profile and ARB extension interfaces */

#ifndef FORGE_GL_MAJOR_VERSION
#define FORGE_GL_MAJOR_VERSION 3
#endif

#ifndef FORGE_GL_MINOR_VERSION
#define FORGE_GL_MINOR_VERSION 0
#endif

#define FORGE_GL_DECL_FUNCTION(__TYPE__, __NAME__) \
	extern FORGE_API __TYPE__ __NAME__;

#define FORGE_GL_DEF_FUNCTION(__TYPE__, __NAME__) \
	__TYPE__ __NAME__ = (__TYPE__) ((void*)0);

#define FORGE_GL_VERSION(__MAJOR__, __MINOR__)

#define FORGE_ARB_ES3_2_compatibility							0x0000
#define FORGE_ARB_bindless_texture								0x0001
#define FORGE_ARB_cl_event										0x0002
#define FORGE_ARB_compute_variable_group_size					0x0003
#define FORGE_ARB_debug_output									0x0004
#define FORGE_ARB_draw_buffers_blend							0x0005
#define FORGE_ARB_draw_instanced								0x0006
#define FORGE_ARB_geometry_shader4								0x0007
#define FORGE_ARB_gl_spirv										0x0008
#define FORGE_ARB_gpu_shader_int64								0x0009
#define FORGE_ARB_indirect_parameters							0x000A
#define FORGE_ARB_instanced_arrays								0x000B		
#define FORGE_ARB_internalformat_query2							0x000C
#define FORGE_ARB_parallel_shader_compile						0x000D
#define FORGE_ARB_pipeline_statistics_query						0x000E
#define FORGE_ARB_pixel_buffer_object							0x000F
#define FORGE_ARB_robustness									0x0010
#define FORGE_ARB_sample_locations								0x0011
#define FORGE_ARB_sample_shading								0x0012
#define FORGE_ARB_shading_language_include						0x0013
#define FORGE_ARB_sparse_buffer									0x0014
#define FORGE_ARB_sparse_texture								0x0015
#define FORGE_ARB_texture_border_clamp							0x0016
#define FORGE_ARB_texture_buffer_object							0x0017
#define FORGE_ARB_texture_compression_bptc						0x0018
#define FORGE_ARB_texture_cube_map_array						0x0019
#define FORGE_ARB_texture_filter_minmax							0x001A
#define FORGE_ARB_texture_gather								0x001B
#define FORGE_ARB_texture_mirrored_repeat						0x001C
#define FORGE_ARB_transform_feedback_overflow_query				0x001D
#define FORGE_ARB_viewport_array								0x001E
#define FORGE_KHR_blend_equation_advanced						0x001F
#define FORGE_KHR_blend_equation_advanced_coherent				0x0020
#define FORGE_KHR_no_error										0x0021
#define FORGE_KHR_parallel_shader_compile						0x0022
#define FORGE_KHR_robustness									0x0023
#define FORGE_KHR_shader_subgroup								0x0024
#define FORGE_KHR_texture_compression_astc_hdr					0x0025
#define FORGE_AMD_framebuffer_multisample_advanced				0x0026
#define FORGE_AMD_performance_monitor							0x0027
#define FORGE_APPLE_rgb_422										0x0028
#define FORGE_EXT_EGL_image_storage								0x0029
#define FORGE_EXT_debug_label									0x002A
#define FORGE_EXT_debug_marker									0x002B
#define FORGE_EXT_direct_state_access							0x002C
#define FORGE_EXT_draw_instanced								0x002D
#define FORGE_EXT_polygon_offset_clamp							0x002E
#define FORGE_EXT_raster_multisample							0x002F
#define FORGE_EXT_separate_shader_objects						0x0030
#define FORGE_EXT_shader_framebuffer_fetch						0x0031
#define FORGE_EXT_shader_framebuffer_fetch_non_coherent			0x0032
#define FORGE_EXT_texture_compression_s3tc						0x0033
#define FORGE_EXT_texture_filter_minmax							0x0034
#define FORGE_EXT_texture_sRGB_R8								0x0035
#define FORGE_EXT_texture_sRGB_RG8								0x0036
#define FORGE_EXT_texture_sRGB_decode							0x0037
#define FORGE_EXT_texture_storage								0x0038
#define FORGE_EXT_window_rectangles								0x0039
#define FORGE_INTEL_blackhole_render							0x003A
#define FORGE_INTEL_conservative_rasterization					0x003B
#define FORGE_INTEL_framebuffer_CMAA							0x003C
#define FORGE_INTEL_performance_query							0x003D
#define FORGE_MESA_framebuffer_flip_x							0x003E
#define FORGE_MESA_framebuffer_flip_y							0x003F
#define FORGE_MESA_framebuffer_swap_xy							0x0040
#define FORGE_NV_bindless_multi_draw_indirect					0x0041
#define FORGE_NV_bindless_multi_draw_indirect_count				0x0042
#define FORGE_NV_bindless_texture								0x0043
#define FORGE_NV_blend_equation_advanced						0x0044
#define FORGE_NV_blend_equation_advanced_coherent				0x0045
#define FORGE_NV_blend_minmax_factor							0x0046
#define FORGE_NV_clip_space_w_scaling							0x0047
#define FORGE_NV_command_list									0x0048
#define FORGE_NV_conditional_render								0x0049
#define FORGE_NV_conservative_raster							0x004A
#define FORGE_NV_conservative_raster_dilate						0x004B
#define FORGE_NV_conservative_raster_pre_snap					0x004C
#define FORGE_NV_conservative_raster_pre_snap_triangles			0x004D
#define FORGE_NV_depth_buffer_float								0x004E
#define FORGE_NV_draw_vulkan_image								0x004F
#define FORGE_NV_fill_rectangle									0x0050
#define FORGE_NV_fragment_coverage_to_color						0x0051
#define FORGE_NV_framebuffer_mixed_samples						0x0052
#define FORGE_NV_framebuffer_multisample_coverage				0x0053
#define FORGE_NV_gpu_shader5									0x0054
#define FORGE_NV_internalformat_sample_query					0x0055
#define FORGE_NV_memory_attachment								0x0056
#define FORGE_NV_memory_object_sparse							0x0057
#define FORGE_NV_mesh_shader									0x0058
#define FORGE_NV_path_rendering									0x0059
#define FORGE_NV_path_rendering_shared_edge						0x005A
#define FORGE_NV_primitive_shading_rate							0x005B
#define FORGE_NV_representative_fragment_test					0x005C
#define FORGE_NV_sample_locations								0x005D
#define FORGE_NV_scissor_exclusive								0x005E
#define FORGE_NV_shader_buffer_load								0x005F
#define FORGE_NV_shader_buffer_store							0x0060
#define FORGE_NV_shader_subgroup_partitioned					0x0061
#define FORGE_NV_shader_thread_group							0x0062
#define FORGE_NV_shading_rate_image								0x0063
#define FORGE_NV_texture_barrier								0x0064
#define FORGE_NV_uniform_buffer_unified_memory					0x0065
#define FORGE_NV_vertex_attrib_integer_64bit					0x0066
#define FORGE_NV_vertex_buffer_unified_memory					0x0067
#define FORGE_NV_viewport_swizzle								0x0068
#define FORGE_OVR_multiview										0x0069

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

#ifndef __khrplatform_h_
#define __khrplatform_h_

#if defined(__SCITECH_SNAP__) && !defined(KHRONOS_STATIC)
#   define KHRONOS_STATIC 1
#endif

#if defined(KHRONOS_STATIC)
#   define KHRONOS_APICALL
#elif defined(_WIN32)
#   define KHRONOS_APICALL __declspec(dllimport)
#elif defined (__SYMBIAN32__)
#   define KHRONOS_APICALL IMPORT_C
#elif defined(__ANDROID__)
#   define KHRONOS_APICALL __attribute__((visibility("default")))
#else
#   define KHRONOS_APICALL
#endif

#if defined(_WIN32) && !defined(_WIN32_WCE) && !defined(__SCITECH_SNAP__)
#   define KHRONOS_APIENTRY __stdcall
#else
#   define KHRONOS_APIENTRY
#endif

#if defined (__ARMCC_2__)
#define KHRONOS_APIATTRIBUTES __softfp
#else
#define KHRONOS_APIATTRIBUTES
#endif

#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__GNUC__) || defined(__SCO__) || defined(__USLC__)
#include <stdint.h>
	typedef int32_t                 khronos_int32_t;
	typedef uint32_t                khronos_uint32_t;
	typedef int64_t                 khronos_int64_t;
	typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#if defined(__SIZEOF_LONG__) && defined(__SIZEOF_POINTER__)
#if __SIZEOF_POINTER__ > __SIZEOF_LONG__
#define KHRONOS_USE_INTPTR_T
#endif
#endif

#elif defined(__VMS ) || defined(__sgi)
#include <inttypes.h>
	typedef int32_t                 khronos_int32_t;
	typedef uint32_t                khronos_uint32_t;
	typedef int64_t                 khronos_int64_t;
	typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(_WIN32) && !defined(__SCITECH_SNAP__)
	typedef __int32                 khronos_int32_t;
	typedef unsigned __int32        khronos_uint32_t;
	typedef __int64                 khronos_int64_t;
	typedef unsigned __int64        khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(__sun__) || defined(__digital__)
	typedef int                     khronos_int32_t;
	typedef unsigned int            khronos_uint32_t;
#if defined(__arch64__) || defined(_LP64)
	typedef long int                khronos_int64_t;
	typedef unsigned long int       khronos_uint64_t;
#else
	typedef long long int           khronos_int64_t;
	typedef unsigned long long int  khronos_uint64_t;
#endif /* __arch64__ */
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif 0
	typedef int                     khronos_int32_t;
	typedef unsigned int            khronos_uint32_t;
#define KHRONOS_SUPPORT_INT64   0
#define KHRONOS_SUPPORT_FLOAT   0

#else

#include <stdint.h>
	typedef int32_t                 khronos_int32_t;
	typedef uint32_t                khronos_uint32_t;
	typedef int64_t                 khronos_int64_t;
	typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#endif

	typedef signed   char          khronos_int8_t;
	typedef unsigned char          khronos_uint8_t;
	typedef signed   short int     khronos_int16_t;
	typedef unsigned short int     khronos_uint16_t;

#ifdef KHRONOS_USE_INTPTR_T
	typedef intptr_t               khronos_intptr_t;
	typedef uintptr_t              khronos_uintptr_t;
#elif defined(_WIN64)
	typedef signed   long long int khronos_intptr_t;
	typedef unsigned long long int khronos_uintptr_t;
#else
	typedef signed   long  int     khronos_intptr_t;
	typedef unsigned long  int     khronos_uintptr_t;
#endif

#if defined(_WIN64)
	typedef signed   long long int khronos_ssize_t;
	typedef unsigned long long int khronos_usize_t;
#else
	typedef signed   long  int     khronos_ssize_t;
	typedef unsigned long  int     khronos_usize_t;
#endif

#if KHRONOS_SUPPORT_FLOAT
	typedef         float         khronos_float_t;
#endif

#if KHRONOS_SUPPORT_INT64
	typedef khronos_uint64_t       khronos_utime_nanoseconds_t;
	typedef khronos_int64_t        khronos_stime_nanoseconds_t;
#endif

#ifndef KHRONOS_MAX_ENUM
#define KHRONOS_MAX_ENUM 0x7FFFFFFF
#endif

	typedef enum {
		KHRONOS_FALSE = 0,
		KHRONOS_TRUE = 1,
		KHRONOS_BOOLEAN_ENUM_FORCE_SIZE = KHRONOS_MAX_ENUM
	} khronos_boolean_enum_t;

#endif /* __khrplatform_h_ */

#ifdef FORGE_GL_VERSION(1, 0)
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;
#define GL_DEPTH_BUFFER_BIT               0x00000100
#define GL_STENCIL_BUFFER_BIT             0x00000400
#define GL_COLOR_BUFFER_BIT               0x00004000
#define GL_FALSE                          0
#define GL_TRUE                           1
#define GL_POINTS                         0x0000
#define GL_LINES                          0x0001
#define GL_LINE_LOOP                      0x0002
#define GL_LINE_STRIP                     0x0003
#define GL_TRIANGLES                      0x0004
#define GL_TRIANGLE_STRIP                 0x0005
#define GL_TRIANGLE_FAN                   0x0006
#define GL_QUADS                          0x0007
#define GL_NEVER                          0x0200
#define GL_LESS                           0x0201
#define GL_EQUAL                          0x0202
#define GL_LEQUAL                         0x0203
#define GL_GREATER                        0x0204
#define GL_NOTEQUAL                       0x0205
#define GL_GEQUAL                         0x0206
#define GL_ALWAYS                         0x0207
#define GL_ZERO                           0
#define GL_ONE                            1
#define GL_SRC_COLOR                      0x0300
#define GL_ONE_MINUS_SRC_COLOR            0x0301
#define GL_SRC_ALPHA                      0x0302
#define GL_ONE_MINUS_SRC_ALPHA            0x0303
#define GL_DST_ALPHA                      0x0304
#define GL_ONE_MINUS_DST_ALPHA            0x0305
#define GL_DST_COLOR                      0x0306
#define GL_ONE_MINUS_DST_COLOR            0x0307
#define GL_SRC_ALPHA_SATURATE             0x0308
#define GL_NONE                           0
#define GL_FRONT_LEFT                     0x0400
#define GL_FRONT_RIGHT                    0x0401
#define GL_BACK_LEFT                      0x0402
#define GL_BACK_RIGHT                     0x0403
#define GL_FRONT                          0x0404
#define GL_BACK                           0x0405
#define GL_LEFT                           0x0406
#define GL_RIGHT                          0x0407
#define GL_FRONT_AND_BACK                 0x0408
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_OUT_OF_MEMORY                  0x0505
#define GL_CW                             0x0900
#define GL_CCW                            0x0901
#define GL_POINT_SIZE                     0x0B11
#define GL_POINT_SIZE_RANGE               0x0B12
#define GL_POINT_SIZE_GRANULARITY         0x0B13
#define GL_LINE_SMOOTH                    0x0B20
#define GL_LINE_WIDTH                     0x0B21
#define GL_LINE_WIDTH_RANGE               0x0B22
#define GL_LINE_WIDTH_GRANULARITY         0x0B23
#define GL_POLYGON_MODE                   0x0B40
#define GL_POLYGON_SMOOTH                 0x0B41
#define GL_CULL_FACE                      0x0B44
#define GL_CULL_FACE_MODE                 0x0B45
#define GL_FRONT_FACE                     0x0B46
#define GL_DEPTH_RANGE                    0x0B70
#define GL_DEPTH_TEST                     0x0B71
#define GL_DEPTH_WRITEMASK                0x0B72
#define GL_DEPTH_CLEAR_VALUE              0x0B73
#define GL_DEPTH_FUNC                     0x0B74
#define GL_STENCIL_TEST                   0x0B90
#define GL_STENCIL_CLEAR_VALUE            0x0B91
#define GL_STENCIL_FUNC                   0x0B92
#define GL_STENCIL_VALUE_MASK             0x0B93
#define GL_STENCIL_FAIL                   0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL        0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS        0x0B96
#define GL_STENCIL_REF                    0x0B97
#define GL_STENCIL_WRITEMASK              0x0B98
#define GL_VIEWPORT                       0x0BA2
#define GL_DITHER                         0x0BD0
#define GL_BLEND_DST                      0x0BE0
#define GL_BLEND_SRC                      0x0BE1
#define GL_BLEND                          0x0BE2
#define GL_LOGIC_OP_MODE                  0x0BF0
#define GL_DRAW_BUFFER                    0x0C01
#define GL_READ_BUFFER                    0x0C02
#define GL_SCISSOR_BOX                    0x0C10
#define GL_SCISSOR_TEST                   0x0C11
#define GL_COLOR_CLEAR_VALUE              0x0C22
#define GL_COLOR_WRITEMASK                0x0C23
#define GL_DOUBLEBUFFER                   0x0C32
#define GL_STEREO                         0x0C33
#define GL_LINE_SMOOTH_HINT               0x0C52
#define GL_POLYGON_SMOOTH_HINT            0x0C53
#define GL_UNPACK_SWAP_BYTES              0x0CF0
#define GL_UNPACK_LSB_FIRST               0x0CF1
#define GL_UNPACK_ROW_LENGTH              0x0CF2
#define GL_UNPACK_SKIP_ROWS               0x0CF3
#define GL_UNPACK_SKIP_PIXELS             0x0CF4
#define GL_UNPACK_ALIGNMENT               0x0CF5
#define GL_PACK_SWAP_BYTES                0x0D00
#define GL_PACK_LSB_FIRST                 0x0D01
#define GL_PACK_ROW_LENGTH                0x0D02
#define GL_PACK_SKIP_ROWS                 0x0D03
#define GL_PACK_SKIP_PIXELS               0x0D04
#define GL_PACK_ALIGNMENT                 0x0D05
#define GL_MAX_TEXTURE_SIZE               0x0D33
#define GL_MAX_VIEWPORT_DIMS              0x0D3A
#define GL_SUBPIXEL_BITS                  0x0D50
#define GL_TEXTURE_1D                     0x0DE0
#define GL_TEXTURE_2D                     0x0DE1
#define GL_TEXTURE_WIDTH                  0x1000
#define GL_TEXTURE_HEIGHT                 0x1001
#define GL_TEXTURE_BORDER_COLOR           0x1004
#define GL_DONT_CARE                      0x1100
#define GL_FASTEST                        0x1101
#define GL_NICEST                         0x1102
#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_CLEAR                          0x1500
#define GL_AND                            0x1501
#define GL_AND_REVERSE                    0x1502
#define GL_COPY                           0x1503
#define GL_AND_INVERTED                   0x1504
#define GL_NOOP                           0x1505
#define GL_XOR                            0x1506
#define GL_OR                             0x1507
#define GL_NOR                            0x1508
#define GL_EQUIV                          0x1509
#define GL_INVERT                         0x150A
#define GL_OR_REVERSE                     0x150B
#define GL_COPY_INVERTED                  0x150C
#define GL_OR_INVERTED                    0x150D
#define GL_NAND                           0x150E
#define GL_SET                            0x150F
#define GL_TEXTURE                        0x1702
#define GL_COLOR                          0x1800
#define GL_DEPTH                          0x1801
#define GL_STENCIL                        0x1802
#define GL_STENCIL_INDEX                  0x1901
#define GL_DEPTH_COMPONENT                0x1902
#define GL_RED                            0x1903
#define GL_GREEN                          0x1904
#define GL_BLUE                           0x1905
#define GL_ALPHA                          0x1906
#define GL_RGB                            0x1907
#define GL_RGBA                           0x1908
#define GL_POINT                          0x1B00
#define GL_LINE                           0x1B01
#define GL_FILL                           0x1B02
#define GL_KEEP                           0x1E00
#define GL_REPLACE                        0x1E01
#define GL_INCR                           0x1E02
#define GL_DECR                           0x1E03
#define GL_VENDOR                         0x1F00
#define GL_RENDERER                       0x1F01
#define GL_VERSION                        0x1F02
#define GL_EXTENSIONS                     0x1F03
#define GL_NEAREST                        0x2600
#define GL_LINEAR                         0x2601
#define GL_NEAREST_MIPMAP_NEAREST         0x2700
#define GL_LINEAR_MIPMAP_NEAREST          0x2701
#define GL_NEAREST_MIPMAP_LINEAR          0x2702
#define GL_LINEAR_MIPMAP_LINEAR           0x2703
#define GL_TEXTURE_MAG_FILTER             0x2800
#define GL_TEXTURE_MIN_FILTER             0x2801
#define GL_TEXTURE_WRAP_S                 0x2802
#define GL_TEXTURE_WRAP_T                 0x2803
#define GL_REPEAT                         0x2901
typedef void (APIENTRYP PFNGLCULLFACEPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLFRONTFACEPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLHINTPROC) (GLenum target, GLenum mode);
typedef void (APIENTRYP PFNGLLINEWIDTHPROC) (GLfloat width);
typedef void (APIENTRYP PFNGLPOINTSIZEPROC) (GLfloat size);
typedef void (APIENTRYP PFNGLPOLYGONMODEPROC) (GLenum face, GLenum mode);
typedef void (APIENTRYP PFNGLSCISSORPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC) (GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC) (GLenum target, GLenum pname, const GLfloat* params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC) (GLenum target, GLenum pname, const GLint* params);
typedef void (APIENTRYP PFNGLTEXIMAGE1DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLDRAWBUFFERPROC) (GLenum buf);
typedef void (APIENTRYP PFNGLCLEARPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLCLEARCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC) (GLint s);
typedef void (APIENTRYP PFNGLCLEARDEPTHPROC) (GLdouble depth);
typedef void (APIENTRYP PFNGLSTENCILMASKPROC) (GLuint mask);
typedef void (APIENTRYP PFNGLCOLORMASKPROC) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (APIENTRYP PFNGLDEPTHMASKPROC) (GLboolean flag);
typedef void (APIENTRYP PFNGLDISABLEPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLENABLEPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLFINISHPROC) (void);
typedef void (APIENTRYP PFNGLFLUSHPROC) (void);
typedef void (APIENTRYP PFNGLBLENDFUNCPROC) (GLenum sfactor, GLenum dfactor);
typedef void (APIENTRYP PFNGLLOGICOPPROC) (GLenum opcode);
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC) (GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILOPPROC) (GLenum fail, GLenum zfail, GLenum zpass);
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC) (GLenum func);
typedef void (APIENTRYP PFNGLPIXELSTOREFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLREADBUFFERPROC) (GLenum src);
typedef void (APIENTRYP PFNGLREADPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels);
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC) (GLenum pname, GLboolean* data);
typedef void (APIENTRYP PFNGLGETDOUBLEVPROC) (GLenum pname, GLdouble* data);
typedef GLenum(APIENTRYP PFNGLGETERRORPROC) (void);
typedef void (APIENTRYP PFNGLGETFLOATVPROC) (GLenum pname, GLfloat* data);
typedef void (APIENTRYP PFNGLGETINTEGERVPROC) (GLenum pname, GLint* data);
typedef const GLubyte* (APIENTRYP PFNGLGETSTRINGPROC) (GLenum name);
typedef void (APIENTRYP PFNGLGETTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC) (GLenum target, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC) (GLenum target, GLint level, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC) (GLenum target, GLint level, GLenum pname, GLint* params);
typedef GLboolean(APIENTRYP PFNGLISENABLEDPROC) (GLenum cap);
typedef void (APIENTRYP PFNGLDEPTHRANGEPROC) (GLdouble n, GLdouble f);
typedef void (APIENTRYP PFNGLVIEWPORTPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_VERSION_1_0 */

#ifdef FORGE_GL_VERSION(1, 1)
typedef khronos_float_t GLclampf;
typedef double GLclampd;
#define GL_COLOR_LOGIC_OP                 0x0BF2
#define GL_POLYGON_OFFSET_UNITS           0x2A00
#define GL_POLYGON_OFFSET_POINT           0x2A01
#define GL_POLYGON_OFFSET_LINE            0x2A02
#define GL_POLYGON_OFFSET_FILL            0x8037
#define GL_POLYGON_OFFSET_FACTOR          0x8038
#define GL_TEXTURE_BINDING_1D             0x8068
#define GL_TEXTURE_BINDING_2D             0x8069
#define GL_TEXTURE_INTERNAL_FORMAT        0x1003
#define GL_TEXTURE_RED_SIZE               0x805C
#define GL_TEXTURE_GREEN_SIZE             0x805D
#define GL_TEXTURE_BLUE_SIZE              0x805E
#define GL_TEXTURE_ALPHA_SIZE             0x805F
#define GL_DOUBLE                         0x140A
#define GL_PROXY_TEXTURE_1D               0x8063
#define GL_PROXY_TEXTURE_2D               0x8064
#define GL_R3_G3_B2                       0x2A10
#define GL_RGB4                           0x804F
#define GL_RGB5                           0x8050
#define GL_RGB8                           0x8051
#define GL_RGB10                          0x8052
#define GL_RGB12                          0x8053
#define GL_RGB16                          0x8054
#define GL_RGBA2                          0x8055
#define GL_RGBA4                          0x8056
#define GL_RGB5_A1                        0x8057
#define GL_RGBA8                          0x8058
#define GL_RGB10_A2                       0x8059
#define GL_RGBA12                         0x805A
#define GL_RGBA16                         0x805B
#define GL_VERTEX_ARRAY                   0x8074
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC) (GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC) (GLenum mode, GLsizei count, GLenum type, const void* indices);
typedef void (APIENTRYP PFNGLGETPOINTERVPROC) (GLenum pname, void** params);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC) (GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC) (GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC) (GLsizei n, const GLuint* textures);
typedef void (APIENTRYP PFNGLGENTEXTURESPROC) (GLsizei n, GLuint* textures);
typedef GLboolean(APIENTRYP PFNGLISTEXTUREPROC) (GLuint texture);
#endif /* GL_VERSION_1_1 */

#ifdef FORGE_GL_VERSION(1, 2)
#define GL_VERSION_1_2 1
#define GL_UNSIGNED_BYTE_3_3_2            0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4         0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1         0x8034
#define GL_UNSIGNED_INT_8_8_8_8           0x8035
#define GL_UNSIGNED_INT_10_10_10_2        0x8036
#define GL_TEXTURE_BINDING_3D             0x806A
#define GL_PACK_SKIP_IMAGES               0x806B
#define GL_PACK_IMAGE_HEIGHT              0x806C
#define GL_UNPACK_SKIP_IMAGES             0x806D
#define GL_UNPACK_IMAGE_HEIGHT            0x806E
#define GL_TEXTURE_3D                     0x806F
#define GL_PROXY_TEXTURE_3D               0x8070
#define GL_TEXTURE_DEPTH                  0x8071
#define GL_TEXTURE_WRAP_R                 0x8072
#define GL_MAX_3D_TEXTURE_SIZE            0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV        0x8362
#define GL_UNSIGNED_SHORT_5_6_5           0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV       0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV     0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV     0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV       0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV    0x8368
#define GL_BGR                            0x80E0
#define GL_BGRA                           0x80E1
#define GL_MAX_ELEMENTS_VERTICES          0x80E8
#define GL_MAX_ELEMENTS_INDICES           0x80E9
#define GL_CLAMP_TO_EDGE                  0x812F
#define GL_TEXTURE_MIN_LOD                0x813A
#define GL_TEXTURE_MAX_LOD                0x813B
#define GL_TEXTURE_BASE_LEVEL             0x813C
#define GL_TEXTURE_MAX_LEVEL              0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE        0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY  0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE        0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY  0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE       0x846E
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices);
typedef void (APIENTRYP PFNGLTEXIMAGE3DPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#endif /* GL_VERSION_1_2 */

#ifdef FORGE_GL_VERSION(1, 3)
#define GL_VERSION_1_3 1
#define GL_TEXTURE0                       0x84C0
#define GL_TEXTURE1                       0x84C1
#define GL_TEXTURE2                       0x84C2
#define GL_TEXTURE3                       0x84C3
#define GL_TEXTURE4                       0x84C4
#define GL_TEXTURE5                       0x84C5
#define GL_TEXTURE6                       0x84C6
#define GL_TEXTURE7                       0x84C7
#define GL_TEXTURE8                       0x84C8
#define GL_TEXTURE9                       0x84C9
#define GL_TEXTURE10                      0x84CA
#define GL_TEXTURE11                      0x84CB
#define GL_TEXTURE12                      0x84CC
#define GL_TEXTURE13                      0x84CD
#define GL_TEXTURE14                      0x84CE
#define GL_TEXTURE15                      0x84CF
#define GL_TEXTURE16                      0x84D0
#define GL_TEXTURE17                      0x84D1
#define GL_TEXTURE18                      0x84D2
#define GL_TEXTURE19                      0x84D3
#define GL_TEXTURE20                      0x84D4
#define GL_TEXTURE21                      0x84D5
#define GL_TEXTURE22                      0x84D6
#define GL_TEXTURE23                      0x84D7
#define GL_TEXTURE24                      0x84D8
#define GL_TEXTURE25                      0x84D9
#define GL_TEXTURE26                      0x84DA
#define GL_TEXTURE27                      0x84DB
#define GL_TEXTURE28                      0x84DC
#define GL_TEXTURE29                      0x84DD
#define GL_TEXTURE30                      0x84DE
#define GL_TEXTURE31                      0x84DF
#define GL_ACTIVE_TEXTURE                 0x84E0
#define GL_MULTISAMPLE                    0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE       0x809E
#define GL_SAMPLE_ALPHA_TO_ONE            0x809F
#define GL_SAMPLE_COVERAGE                0x80A0
#define GL_SAMPLE_BUFFERS                 0x80A8
#define GL_SAMPLES                        0x80A9
#define GL_SAMPLE_COVERAGE_VALUE          0x80AA
#define GL_SAMPLE_COVERAGE_INVERT         0x80AB
#define GL_TEXTURE_CUBE_MAP               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE      0x851C
#define GL_COMPRESSED_RGB                 0x84ED
#define GL_COMPRESSED_RGBA                0x84EE
#define GL_TEXTURE_COMPRESSION_HINT       0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE  0x86A0
#define GL_TEXTURE_COMPRESSED             0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS     0x86A3
#define GL_CLAMP_TO_BORDER                0x812D
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC) (GLenum texture);
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC) (GLfloat value, GLboolean invert);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint level, void* img);
#endif /* GL_VERSION_1_3 */

#ifdef FORGE_GL_VERSION(1, 4)
#define GL_VERSION_1_4 1
#define GL_BLEND_DST_RGB                  0x80C8
#define GL_BLEND_SRC_RGB                  0x80C9
#define GL_BLEND_DST_ALPHA                0x80CA
#define GL_BLEND_SRC_ALPHA                0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE      0x8128
#define GL_DEPTH_COMPONENT16              0x81A5
#define GL_DEPTH_COMPONENT24              0x81A6
#define GL_DEPTH_COMPONENT32              0x81A7
#define GL_MIRRORED_REPEAT                0x8370
#define GL_MAX_TEXTURE_LOD_BIAS           0x84FD
#define GL_TEXTURE_LOD_BIAS               0x8501
#define GL_INCR_WRAP                      0x8507
#define GL_DECR_WRAP                      0x8508
#define GL_TEXTURE_DEPTH_SIZE             0x884A
#define GL_TEXTURE_COMPARE_MODE           0x884C
#define GL_TEXTURE_COMPARE_FUNC           0x884D
#define GL_BLEND_COLOR                    0x8005
#define GL_BLEND_EQUATION                 0x8009
#define GL_CONSTANT_COLOR                 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR       0x8002
#define GL_CONSTANT_ALPHA                 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA       0x8004
#define GL_FUNC_ADD                       0x8006
#define GL_FUNC_REVERSE_SUBTRACT          0x800B
#define GL_FUNC_SUBTRACT                  0x800A
#define GL_MIN                            0x8007
#define GL_MAX                            0x8008
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSPROC) (GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSPROC) (GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFPROC) (GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERFVPROC) (GLenum pname, const GLfloat* params);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIPROC) (GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPOINTPARAMETERIVPROC) (GLenum pname, const GLint* params);
typedef void (APIENTRYP PFNGLBLENDCOLORPROC) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC) (GLenum mode);
#endif /* GL_VERSION_1_4 */

#ifdef FORGE_GL_VERSION(1, 5)
#define GL_VERSION_1_5 1
typedef khronos_ssize_t GLsizeiptr;
typedef khronos_intptr_t GLintptr;
#define GL_BUFFER_SIZE                    0x8764
#define GL_BUFFER_USAGE                   0x8765
#define GL_QUERY_COUNTER_BITS             0x8864
#define GL_CURRENT_QUERY                  0x8865
#define GL_QUERY_RESULT                   0x8866
#define GL_QUERY_RESULT_AVAILABLE         0x8867
#define GL_ARRAY_BUFFER                   0x8892
#define GL_ELEMENT_ARRAY_BUFFER           0x8893
#define GL_ARRAY_BUFFER_BINDING           0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING   0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY                      0x88B8
#define GL_WRITE_ONLY                     0x88B9
#define GL_READ_WRITE                     0x88BA
#define GL_BUFFER_ACCESS                  0x88BB
#define GL_BUFFER_MAPPED                  0x88BC
#define GL_BUFFER_MAP_POINTER             0x88BD
#define GL_STREAM_DRAW                    0x88E0
#define GL_STREAM_READ                    0x88E1
#define GL_STREAM_COPY                    0x88E2
#define GL_STATIC_DRAW                    0x88E4
#define GL_STATIC_READ                    0x88E5
#define GL_STATIC_COPY                    0x88E6
#define GL_DYNAMIC_DRAW                   0x88E8
#define GL_DYNAMIC_READ                   0x88E9
#define GL_DYNAMIC_COPY                   0x88EA
#define GL_SAMPLES_PASSED                 0x8914
#define GL_SRC1_ALPHA                     0x8589
typedef void (APIENTRYP PFNGLGENQUERIESPROC) (GLsizei n, GLuint* ids);
typedef void (APIENTRYP PFNGLDELETEQUERIESPROC) (GLsizei n, const GLuint* ids);
typedef GLboolean(APIENTRYP PFNGLISQUERYPROC) (GLuint id);
typedef void (APIENTRYP PFNGLBEGINQUERYPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTIVPROC) (GLuint id, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUIVPROC) (GLuint id, GLenum pname, GLuint* params);
typedef void (APIENTRYP PFNGLBINDBUFFERPROC) (GLenum target, GLuint buffer);
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC) (GLsizei n, const GLuint* buffers);
typedef void (APIENTRYP PFNGLGENBUFFERSPROC) (GLsizei n, GLuint* buffers);
typedef GLboolean(APIENTRYP PFNGLISBUFFERPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLBUFFERDATAPROC) (GLenum target, GLsizeiptr size, const void* data, GLenum usage);
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
typedef void (APIENTRYP PFNGLGETBUFFERSUBDATAPROC) (GLenum target, GLintptr offset, GLsizeiptr size, void* data);
typedef void* (APIENTRYP PFNGLMAPBUFFERPROC) (GLenum target, GLenum access);
typedef GLboolean(APIENTRYP PFNGLUNMAPBUFFERPROC) (GLenum target);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETBUFFERPOINTERVPROC) (GLenum target, GLenum pname, void** params);
#endif /* GL_VERSION_1_5 */

#ifdef FORGE_GL_VERSION(2, 0)
typedef char GLchar;
typedef khronos_int16_t GLshort;
typedef khronos_int8_t GLbyte;
typedef khronos_uint16_t GLushort;
#define GL_BLEND_EQUATION_RGB             0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED    0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE       0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE     0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE       0x8625
#define GL_CURRENT_VERTEX_ATTRIB          0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE      0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER    0x8645
#define GL_STENCIL_BACK_FUNC              0x8800
#define GL_STENCIL_BACK_FAIL              0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL   0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS   0x8803
#define GL_MAX_DRAW_BUFFERS               0x8824
#define GL_DRAW_BUFFER0                   0x8825
#define GL_DRAW_BUFFER1                   0x8826
#define GL_DRAW_BUFFER2                   0x8827
#define GL_DRAW_BUFFER3                   0x8828
#define GL_DRAW_BUFFER4                   0x8829
#define GL_DRAW_BUFFER5                   0x882A
#define GL_DRAW_BUFFER6                   0x882B
#define GL_DRAW_BUFFER7                   0x882C
#define GL_DRAW_BUFFER8                   0x882D
#define GL_DRAW_BUFFER9                   0x882E
#define GL_DRAW_BUFFER10                  0x882F
#define GL_DRAW_BUFFER11                  0x8830
#define GL_DRAW_BUFFER12                  0x8831
#define GL_DRAW_BUFFER13                  0x8832
#define GL_DRAW_BUFFER14                  0x8833
#define GL_DRAW_BUFFER15                  0x8834
#define GL_BLEND_EQUATION_ALPHA           0x883D
#define GL_MAX_VERTEX_ATTRIBS             0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS        0x8872
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS  0x8B4A
#define GL_MAX_VARYING_FLOATS             0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE                    0x8B4F
#define GL_FLOAT_VEC2                     0x8B50
#define GL_FLOAT_VEC3                     0x8B51
#define GL_FLOAT_VEC4                     0x8B52
#define GL_INT_VEC2                       0x8B53
#define GL_INT_VEC3                       0x8B54
#define GL_INT_VEC4                       0x8B55
#define GL_BOOL                           0x8B56
#define GL_BOOL_VEC2                      0x8B57
#define GL_BOOL_VEC3                      0x8B58
#define GL_BOOL_VEC4                      0x8B59
#define GL_FLOAT_MAT2                     0x8B5A
#define GL_FLOAT_MAT3                     0x8B5B
#define GL_FLOAT_MAT4                     0x8B5C
#define GL_SAMPLER_1D                     0x8B5D
#define GL_SAMPLER_2D                     0x8B5E
#define GL_SAMPLER_3D                     0x8B5F
#define GL_SAMPLER_CUBE                   0x8B60
#define GL_SAMPLER_1D_SHADOW              0x8B61
#define GL_SAMPLER_2D_SHADOW              0x8B62
#define GL_DELETE_STATUS                  0x8B80
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_VALIDATE_STATUS                0x8B83
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_ATTACHED_SHADERS               0x8B85
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADER_SOURCE_LENGTH           0x8B88
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C
#define GL_CURRENT_PROGRAM                0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN      0x8CA0
#define GL_LOWER_LEFT                     0x8CA1
#define GL_UPPER_LEFT                     0x8CA2
#define GL_STENCIL_BACK_REF               0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK        0x8CA4
#define GL_STENCIL_BACK_WRITEMASK         0x8CA5
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLDRAWBUFFERSPROC) (GLsizei n, const GLenum* bufs);
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC) (GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC) (GLenum face, GLuint mask);
typedef void (APIENTRYP PFNGLATTACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC) (GLuint program, GLuint index, const GLchar* name);
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC) (GLuint shader);
typedef GLuint(APIENTRYP PFNGLCREATEPROGRAMPROC) (void);
typedef GLuint(APIENTRYP PFNGLCREATESHADERPROC) (GLenum type);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLDELETESHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLDETACHSHADERPROC) (GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint index);
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name);
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC) (GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders);
typedef GLint(APIENTRYP PFNGLGETATTRIBLOCATIONPROC) (GLuint program, const GLchar* name);
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC) (GLuint program, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC) (GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (APIENTRYP PFNGLGETSHADERIVPROC) (GLuint shader, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC) (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC) (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source);
typedef GLint(APIENTRYP PFNGLGETUNIFORMLOCATIONPROC) (GLuint program, const GLchar* name);
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC) (GLuint program, GLint location, GLfloat* params);
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC) (GLuint program, GLint location, GLint* params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBDVPROC) (GLuint index, GLenum pname, GLdouble* params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC) (GLuint index, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC) (GLuint index, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint index, GLenum pname, void** pointer);
typedef GLboolean(APIENTRYP PFNGLISPROGRAMPROC) (GLuint program);
typedef GLboolean(APIENTRYP PFNGLISSHADERPROC) (GLuint shader);
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC) (GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length);
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLUNIFORM1FPROC) (GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLUNIFORM2FPROC) (GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLUNIFORM3FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLUNIFORM4FPROC) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLUNIFORM1IPROC) (GLint location, GLint v0);
typedef void (APIENTRYP PFNGLUNIFORM2IPROC) (GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLUNIFORM3IPROC) (GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLUNIFORM4IPROC) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC) (GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC) (GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC) (GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC) (GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC) (GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC) (GLuint program);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC) (GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC) (GLuint index, const GLfloat* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SPROC) (GLuint index, GLshort x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1SVPROC) (GLuint index, const GLshort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC) (GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC) (GLuint index, const GLfloat* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SPROC) (GLuint index, GLshort x, GLshort y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2SVPROC) (GLuint index, const GLshort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC) (GLuint index, const GLfloat* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SPROC) (GLuint index, GLshort x, GLshort y, GLshort z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3SVPROC) (GLuint index, const GLshort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NBVPROC) (GLuint index, const GLbyte* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NIVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NSVPROC) (GLuint index, const GLshort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBPROC) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUBVPROC) (GLuint index, const GLubyte* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUIVPROC) (GLuint index, const GLuint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4NUSVPROC) (GLuint index, const GLushort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4BVPROC) (GLuint index, const GLbyte* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC) (GLuint index, const GLfloat* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4IVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SPROC) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4SVPROC) (GLuint index, const GLshort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UBVPROC) (GLuint index, const GLubyte* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4UIVPROC) (GLuint index, const GLuint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4USVPROC) (GLuint index, const GLushort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
#endif /* GL_VERSION_2_0 */

#ifdef FORGE_GL_VERSION(2, 1)
#define GL_VERSION_2_1 1
#define GL_PIXEL_PACK_BUFFER              0x88EB
#define GL_PIXEL_UNPACK_BUFFER            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING    0x88EF
#define GL_FLOAT_MAT2x3                   0x8B65
#define GL_FLOAT_MAT2x4                   0x8B66
#define GL_FLOAT_MAT3x2                   0x8B67
#define GL_FLOAT_MAT3x4                   0x8B68
#define GL_FLOAT_MAT4x2                   0x8B69
#define GL_FLOAT_MAT4x3                   0x8B6A
#define GL_SRGB                           0x8C40
#define GL_SRGB8                          0x8C41
#define GL_SRGB_ALPHA                     0x8C42
#define GL_SRGB8_ALPHA8                   0x8C43
#define GL_COMPRESSED_SRGB                0x8C48
#define GL_COMPRESSED_SRGB_ALPHA          0x8C49
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
#endif /* GL_VERSION_2_1 */

#ifdef FORGE_GL_VERSION(3, 0)
typedef khronos_uint16_t GLhalf;
#define GL_COMPARE_REF_TO_TEXTURE         0x884E
#define GL_CLIP_DISTANCE0                 0x3000
#define GL_CLIP_DISTANCE1                 0x3001
#define GL_CLIP_DISTANCE2                 0x3002
#define GL_CLIP_DISTANCE3                 0x3003
#define GL_CLIP_DISTANCE4                 0x3004
#define GL_CLIP_DISTANCE5                 0x3005
#define GL_CLIP_DISTANCE6                 0x3006
#define GL_CLIP_DISTANCE7                 0x3007
#define GL_MAX_CLIP_DISTANCES             0x0D32
#define GL_MAJOR_VERSION                  0x821B
#define GL_MINOR_VERSION                  0x821C
#define GL_NUM_EXTENSIONS                 0x821D
#define GL_CONTEXT_FLAGS                  0x821E
#define GL_COMPRESSED_RED                 0x8225
#define GL_COMPRESSED_RG                  0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_RGBA32F                        0x8814
#define GL_RGB32F                         0x8815
#define GL_RGBA16F                        0x881A
#define GL_RGB16F                         0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER    0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS       0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET       0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET       0x8905
#define GL_CLAMP_READ_COLOR               0x891C
#define GL_FIXED_ONLY                     0x891D
#define GL_MAX_VARYING_COMPONENTS         0x8B4B
#define GL_TEXTURE_1D_ARRAY               0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY         0x8C19
#define GL_TEXTURE_2D_ARRAY               0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY         0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY       0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY       0x8C1D
#define GL_R11F_G11F_B10F                 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV   0x8C3B
#define GL_RGB9_E5                        0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV       0x8C3E
#define GL_TEXTURE_SHARED_SIZE            0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS    0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED           0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD             0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS            0x8C8C
#define GL_SEPARATE_ATTRIBS               0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER      0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI                       0x8D70
#define GL_RGB32UI                        0x8D71
#define GL_RGBA16UI                       0x8D76
#define GL_RGB16UI                        0x8D77
#define GL_RGBA8UI                        0x8D7C
#define GL_RGB8UI                         0x8D7D
#define GL_RGBA32I                        0x8D82
#define GL_RGB32I                         0x8D83
#define GL_RGBA16I                        0x8D88
#define GL_RGB16I                         0x8D89
#define GL_RGBA8I                         0x8D8E
#define GL_RGB8I                          0x8D8F
#define GL_RED_INTEGER                    0x8D94
#define GL_GREEN_INTEGER                  0x8D95
#define GL_BLUE_INTEGER                   0x8D96
#define GL_RGB_INTEGER                    0x8D98
#define GL_RGBA_INTEGER                   0x8D99
#define GL_BGR_INTEGER                    0x8D9A
#define GL_BGRA_INTEGER                   0x8D9B
#define GL_SAMPLER_1D_ARRAY               0x8DC0
#define GL_SAMPLER_2D_ARRAY               0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW        0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW        0x8DC4
#define GL_SAMPLER_CUBE_SHADOW            0x8DC5
#define GL_UNSIGNED_INT_VEC2              0x8DC6
#define GL_UNSIGNED_INT_VEC3              0x8DC7
#define GL_UNSIGNED_INT_VEC4              0x8DC8
#define GL_INT_SAMPLER_1D                 0x8DC9
#define GL_INT_SAMPLER_2D                 0x8DCA
#define GL_INT_SAMPLER_3D                 0x8DCB
#define GL_INT_SAMPLER_CUBE               0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY           0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY           0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D        0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D        0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D        0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE      0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY  0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY  0x8DD7
#define GL_QUERY_WAIT                     0x8E13
#define GL_QUERY_NO_WAIT                  0x8E14
#define GL_QUERY_BY_REGION_WAIT           0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT        0x8E16
#define GL_BUFFER_ACCESS_FLAGS            0x911F
#define GL_BUFFER_MAP_LENGTH              0x9120
#define GL_BUFFER_MAP_OFFSET              0x9121
#define GL_DEPTH_COMPONENT32F             0x8CAC
#define GL_DEPTH32F_STENCIL8              0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION  0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT            0x8218
#define GL_FRAMEBUFFER_UNDEFINED          0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT       0x821A
#define GL_MAX_RENDERBUFFER_SIZE          0x84E8
#define GL_DEPTH_STENCIL                  0x84F9
#define GL_UNSIGNED_INT_24_8              0x84FA
#define GL_DEPTH24_STENCIL8               0x88F0
#define GL_TEXTURE_STENCIL_SIZE           0x88F1
#define GL_TEXTURE_RED_TYPE               0x8C10
#define GL_TEXTURE_GREEN_TYPE             0x8C11
#define GL_TEXTURE_BLUE_TYPE              0x8C12
#define GL_TEXTURE_ALPHA_TYPE             0x8C13
#define GL_TEXTURE_DEPTH_TYPE             0x8C16
#define GL_UNSIGNED_NORMALIZED            0x8C17
#define GL_FRAMEBUFFER_BINDING            0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING       0x8CA6
#define GL_RENDERBUFFER_BINDING           0x8CA7
#define GL_READ_FRAMEBUFFER               0x8CA8
#define GL_DRAW_FRAMEBUFFER               0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING       0x8CAA
#define GL_RENDERBUFFER_SAMPLES           0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE           0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED        0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS          0x8CDF
#define GL_COLOR_ATTACHMENT0              0x8CE0
#define GL_COLOR_ATTACHMENT1              0x8CE1
#define GL_COLOR_ATTACHMENT2              0x8CE2
#define GL_COLOR_ATTACHMENT3              0x8CE3
#define GL_COLOR_ATTACHMENT4              0x8CE4
#define GL_COLOR_ATTACHMENT5              0x8CE5
#define GL_COLOR_ATTACHMENT6              0x8CE6
#define GL_COLOR_ATTACHMENT7              0x8CE7
#define GL_COLOR_ATTACHMENT8              0x8CE8
#define GL_COLOR_ATTACHMENT9              0x8CE9
#define GL_COLOR_ATTACHMENT10             0x8CEA
#define GL_COLOR_ATTACHMENT11             0x8CEB
#define GL_COLOR_ATTACHMENT12             0x8CEC
#define GL_COLOR_ATTACHMENT13             0x8CED
#define GL_COLOR_ATTACHMENT14             0x8CEE
#define GL_COLOR_ATTACHMENT15             0x8CEF
#define GL_COLOR_ATTACHMENT16             0x8CF0
#define GL_COLOR_ATTACHMENT17             0x8CF1
#define GL_COLOR_ATTACHMENT18             0x8CF2
#define GL_COLOR_ATTACHMENT19             0x8CF3
#define GL_COLOR_ATTACHMENT20             0x8CF4
#define GL_COLOR_ATTACHMENT21             0x8CF5
#define GL_COLOR_ATTACHMENT22             0x8CF6
#define GL_COLOR_ATTACHMENT23             0x8CF7
#define GL_COLOR_ATTACHMENT24             0x8CF8
#define GL_COLOR_ATTACHMENT25             0x8CF9
#define GL_COLOR_ATTACHMENT26             0x8CFA
#define GL_COLOR_ATTACHMENT27             0x8CFB
#define GL_COLOR_ATTACHMENT28             0x8CFC
#define GL_COLOR_ATTACHMENT29             0x8CFD
#define GL_COLOR_ATTACHMENT30             0x8CFE
#define GL_COLOR_ATTACHMENT31             0x8CFF
#define GL_DEPTH_ATTACHMENT               0x8D00
#define GL_STENCIL_ATTACHMENT             0x8D20
#define GL_FRAMEBUFFER                    0x8D40
#define GL_RENDERBUFFER                   0x8D41
#define GL_RENDERBUFFER_WIDTH             0x8D42
#define GL_RENDERBUFFER_HEIGHT            0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT   0x8D44
#define GL_STENCIL_INDEX1                 0x8D46
#define GL_STENCIL_INDEX4                 0x8D47
#define GL_STENCIL_INDEX8                 0x8D48
#define GL_STENCIL_INDEX16                0x8D49
#define GL_RENDERBUFFER_RED_SIZE          0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE        0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE         0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE        0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE        0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE      0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES                    0x8D57
#define GL_FRAMEBUFFER_SRGB               0x8DB9
#define GL_HALF_FLOAT                     0x140B
#define GL_MAP_READ_BIT                   0x0001
#define GL_MAP_WRITE_BIT                  0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT       0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT      0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT         0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT         0x0020
#define GL_COMPRESSED_RED_RGTC1           0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1    0x8DBC
#define GL_COMPRESSED_RG_RGTC2            0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2     0x8DBE
#define GL_RG                             0x8227
#define GL_RG_INTEGER                     0x8228
#define GL_R8                             0x8229
#define GL_R16                            0x822A
#define GL_RG8                            0x822B
#define GL_RG16                           0x822C
#define GL_R16F                           0x822D
#define GL_R32F                           0x822E
#define GL_RG16F                          0x822F
#define GL_RG32F                          0x8230
#define GL_R8I                            0x8231
#define GL_R8UI                           0x8232
#define GL_R16I                           0x8233
#define GL_R16UI                          0x8234
#define GL_R32I                           0x8235
#define GL_R32UI                          0x8236
#define GL_RG8I                           0x8237
#define GL_RG8UI                          0x8238
#define GL_RG16I                          0x8239
#define GL_RG16UI                         0x823A
#define GL_RG32I                          0x823B
#define GL_RG32UI                         0x823C
#define GL_VERTEX_ARRAY_BINDING           0x85B5
typedef void (APIENTRYP PFNGLCOLORMASKIPROC) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef void (APIENTRYP PFNGLGETBOOLEANI_VPROC) (GLenum target, GLuint index, GLboolean* data);
typedef void (APIENTRYP PFNGLGETINTEGERI_VPROC) (GLenum target, GLuint index, GLint* data);
typedef void (APIENTRYP PFNGLENABLEIPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEIPROC) (GLenum target, GLuint index);
typedef GLboolean(APIENTRYP PFNGLISENABLEDIPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLBEGINTRANSFORMFEEDBACKPROC) (GLenum primitiveMode);
typedef void (APIENTRYP PFNGLENDTRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLBINDBUFFERRANGEPROC) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLBINDBUFFERBASEPROC) (GLenum target, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKVARYINGSPROC) (GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name);
typedef void (APIENTRYP PFNGLCLAMPCOLORPROC) (GLenum target, GLenum clamp);
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERPROC) (GLuint id, GLenum mode);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERPROC) (void);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIIVPROC) (GLuint index, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIUIVPROC) (GLuint index, GLenum pname, GLuint* params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IPROC) (GLuint index, GLint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IPROC) (GLuint index, GLint x, GLint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IPROC) (GLuint index, GLint x, GLint y, GLint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IPROC) (GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIPROC) (GLuint index, GLuint x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIPROC) (GLuint index, GLuint x, GLuint y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIPROC) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1IVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2IVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3IVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4IVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI1UIVPROC) (GLuint index, const GLuint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI2UIVPROC) (GLuint index, const GLuint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI3UIVPROC) (GLuint index, const GLuint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UIVPROC) (GLuint index, const GLuint* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4BVPROC) (GLuint index, const GLbyte* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4SVPROC) (GLuint index, const GLshort* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4UBVPROC) (GLuint index, const GLubyte* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBI4USVPROC) (GLuint index, const GLushort* v);
typedef void (APIENTRYP PFNGLGETUNIFORMUIVPROC) (GLuint program, GLint location, GLuint* params);
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONPROC) (GLuint program, GLuint color, const GLchar* name);
typedef GLint(APIENTRYP PFNGLGETFRAGDATALOCATIONPROC) (GLuint program, const GLchar* name);
typedef void (APIENTRYP PFNGLUNIFORM1UIPROC) (GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLUNIFORM2UIPROC) (GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLUNIFORM3UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLUNIFORM4UIPROC) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLUNIFORM1UIVPROC) (GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLUNIFORM2UIVPROC) (GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLUNIFORM3UIVPROC) (GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLUNIFORM4UIVPROC) (GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, const GLint* params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, const GLuint* params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVPROC) (GLenum target, GLenum pname, GLuint* params);
typedef void (APIENTRYP PFNGLCLEARBUFFERIVPROC) (GLenum buffer, GLint drawbuffer, const GLint* value);
typedef void (APIENTRYP PFNGLCLEARBUFFERUIVPROC) (GLenum buffer, GLint drawbuffer, const GLuint* value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFVPROC) (GLenum buffer, GLint drawbuffer, const GLfloat* value);
typedef void (APIENTRYP PFNGLCLEARBUFFERFIPROC) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef const GLubyte* (APIENTRYP PFNGLGETSTRINGIPROC) (GLenum name, GLuint index);
typedef GLboolean(APIENTRYP PFNGLISRENDERBUFFERPROC) (GLuint renderbuffer);
typedef void (APIENTRYP PFNGLBINDRENDERBUFFERPROC) (GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLDELETERENDERBUFFERSPROC) (GLsizei n, const GLuint* renderbuffers);
typedef void (APIENTRYP PFNGLGENRENDERBUFFERSPROC) (GLsizei n, GLuint* renderbuffers);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEPROC) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef GLboolean(APIENTRYP PFNGLISFRAMEBUFFERPROC) (GLuint framebuffer);
typedef void (APIENTRYP PFNGLBINDFRAMEBUFFERPROC) (GLenum target, GLuint framebuffer);
typedef void (APIENTRYP PFNGLDELETEFRAMEBUFFERSPROC) (GLsizei n, const GLuint* framebuffers);
typedef void (APIENTRYP PFNGLGENFRAMEBUFFERSPROC) (GLsizei n, GLuint* framebuffers);
typedef GLenum(APIENTRYP PFNGLCHECKFRAMEBUFFERSTATUSPROC) (GLenum target);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE1DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE2DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURE3DPROC) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLFRAMEBUFFERRENDERBUFFERPROC) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLenum target, GLenum attachment, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGENERATEMIPMAPPROC) (GLenum target);
typedef void (APIENTRYP PFNGLBLITFRAMEBUFFERPROC) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void* (APIENTRYP PFNGLMAPBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDBUFFERRANGEPROC) (GLenum target, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLBINDVERTEXARRAYPROC) (GLuint array);
typedef void (APIENTRYP PFNGLDELETEVERTEXARRAYSPROC) (GLsizei n, const GLuint* arrays);
typedef void (APIENTRYP PFNGLGENVERTEXARRAYSPROC) (GLsizei n, GLuint* arrays);
typedef GLboolean(APIENTRYP PFNGLISVERTEXARRAYPROC) (GLuint array);
#endif /* GL_VERSION_3_0 */

#ifdef FORGE_GL_VERSION(3, 1)
#define GL_VERSION_3_1 1
#define GL_SAMPLER_2D_RECT                0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW         0x8B64
#define GL_SAMPLER_BUFFER                 0x8DC2
#define GL_INT_SAMPLER_2D_RECT            0x8DCD
#define GL_INT_SAMPLER_BUFFER             0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT   0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER    0x8DD8
#define GL_TEXTURE_BUFFER                 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE        0x8C2B
#define GL_TEXTURE_BINDING_BUFFER         0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE              0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE      0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE        0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE     0x84F8
#define GL_R8_SNORM                       0x8F94
#define GL_RG8_SNORM                      0x8F95
#define GL_RGB8_SNORM                     0x8F96
#define GL_RGBA8_SNORM                    0x8F97
#define GL_R16_SNORM                      0x8F98
#define GL_RG16_SNORM                     0x8F99
#define GL_RGB16_SNORM                    0x8F9A
#define GL_RGBA16_SNORM                   0x8F9B
#define GL_SIGNED_NORMALIZED              0x8F9C
#define GL_PRIMITIVE_RESTART              0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX        0x8F9E
#define GL_COPY_READ_BUFFER               0x8F36
#define GL_COPY_WRITE_BUFFER              0x8F37
#define GL_UNIFORM_BUFFER                 0x8A11
#define GL_UNIFORM_BUFFER_BINDING         0x8A28
#define GL_UNIFORM_BUFFER_START           0x8A29
#define GL_UNIFORM_BUFFER_SIZE            0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS      0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS    0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS    0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS    0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS    0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE         0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS          0x8A36
#define GL_UNIFORM_TYPE                   0x8A37
#define GL_UNIFORM_SIZE                   0x8A38
#define GL_UNIFORM_NAME_LENGTH            0x8A39
#define GL_UNIFORM_BLOCK_INDEX            0x8A3A
#define GL_UNIFORM_OFFSET                 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE           0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE          0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR           0x8A3E
#define GL_UNIFORM_BLOCK_BINDING          0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE        0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH      0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS  0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX                  0xFFFFFFFFu
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDPROC) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount);
typedef void (APIENTRYP PFNGLTEXBUFFERPROC) (GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLPRIMITIVERESTARTINDEXPROC) (GLuint index);
typedef void (APIENTRYP PFNGLCOPYBUFFERSUBDATAPROC) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETUNIFORMINDICESPROC) (GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMSIVPROC) (GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMNAMEPROC) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName);
typedef GLuint(APIENTRYP PFNGLGETUNIFORMBLOCKINDEXPROC) (GLuint program, const GLchar* uniformBlockName);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVPROC) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName);
typedef void (APIENTRYP PFNGLUNIFORMBLOCKBINDINGPROC) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
#endif /* GL_VERSION_3_1 */

#ifdef FORGE_GL_VERSION(3, 2)
#define GL_VERSION_3_2 1
typedef struct __GLsync* GLsync;
typedef khronos_uint64_t GLuint64;
typedef khronos_int64_t GLint64;
#define GL_CONTEXT_CORE_PROFILE_BIT       0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY                0x000A
#define GL_LINE_STRIP_ADJACENCY           0x000B
#define GL_TRIANGLES_ADJACENCY            0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY       0x000D
#define GL_PROGRAM_POINT_SIZE             0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER                0x8DD9
#define GL_GEOMETRY_VERTICES_OUT          0x8916
#define GL_GEOMETRY_INPUT_TYPE            0x8917
#define GL_GEOMETRY_OUTPUT_TYPE           0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES   0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS   0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS  0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS  0x9125
#define GL_CONTEXT_PROFILE_MASK           0x9126
#define GL_DEPTH_CLAMP                    0x864F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION        0x8E4D
#define GL_LAST_VERTEX_CONVENTION         0x8E4E
#define GL_PROVOKING_VERTEX               0x8E4F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS      0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT        0x9111
#define GL_OBJECT_TYPE                    0x9112
#define GL_SYNC_CONDITION                 0x9113
#define GL_SYNC_STATUS                    0x9114
#define GL_SYNC_FLAGS                     0x9115
#define GL_SYNC_FENCE                     0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE     0x9117
#define GL_UNSIGNALED                     0x9118
#define GL_SIGNALED                       0x9119
#define GL_ALREADY_SIGNALED               0x911A
#define GL_TIMEOUT_EXPIRED                0x911B
#define GL_CONDITION_SATISFIED            0x911C
#define GL_WAIT_FAILED                    0x911D
#define GL_TIMEOUT_IGNORED                0xFFFFFFFFFFFFFFFFull
#define GL_SYNC_FLUSH_COMMANDS_BIT        0x00000001
#define GL_SAMPLE_POSITION                0x8E50
#define GL_SAMPLE_MASK                    0x8E51
#define GL_SAMPLE_MASK_VALUE              0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS          0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE         0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE   0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY   0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES                0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE         0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE     0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY   0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES      0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES      0x910F
#define GL_MAX_INTEGER_SAMPLES            0x9110
typedef void (APIENTRYP PFNGLDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) (GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex);
typedef void (APIENTRYP PFNGLPROVOKINGVERTEXPROC) (GLenum mode);
typedef GLsync(APIENTRYP PFNGLFENCESYNCPROC) (GLenum condition, GLbitfield flags);
typedef GLboolean(APIENTRYP PFNGLISSYNCPROC) (GLsync sync);
typedef void (APIENTRYP PFNGLDELETESYNCPROC) (GLsync sync);
typedef GLenum(APIENTRYP PFNGLCLIENTWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLWAITSYNCPROC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (APIENTRYP PFNGLGETINTEGER64VPROC) (GLenum pname, GLint64* data);
typedef void (APIENTRYP PFNGLGETSYNCIVPROC) (GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values);
typedef void (APIENTRYP PFNGLGETINTEGER64I_VPROC) (GLenum target, GLuint index, GLint64* data);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERI64VPROC) (GLenum target, GLenum pname, GLint64* params);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLTEXIMAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXIMAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLGETMULTISAMPLEFVPROC) (GLenum pname, GLuint index, GLfloat* val);
typedef void (APIENTRYP PFNGLSAMPLEMASKIPROC) (GLuint maskNumber, GLbitfield mask);
#endif /* GL_VERSION_3_2 */

#ifdef FORGE_GL_VERSION(3, 3)
#define GL_VERSION_3_3 1
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR    0x88FE
#define GL_SRC1_COLOR                     0x88F9
#define GL_ONE_MINUS_SRC1_COLOR           0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA           0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS   0x88FC
#define GL_ANY_SAMPLES_PASSED             0x8C2F
#define GL_SAMPLER_BINDING                0x8919
#define GL_RGB10_A2UI                     0x906F
#define GL_TEXTURE_SWIZZLE_R              0x8E42
#define GL_TEXTURE_SWIZZLE_G              0x8E43
#define GL_TEXTURE_SWIZZLE_B              0x8E44
#define GL_TEXTURE_SWIZZLE_A              0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA           0x8E46
#define GL_TIME_ELAPSED                   0x88BF
#define GL_TIMESTAMP                      0x8E28
#define GL_INT_2_10_10_10_REV             0x8D9F
typedef void (APIENTRYP PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) (GLuint program, GLuint colorNumber, GLuint index, const GLchar* name);
typedef GLint(APIENTRYP PFNGLGETFRAGDATAINDEXPROC) (GLuint program, const GLchar* name);
typedef void (APIENTRYP PFNGLGENSAMPLERSPROC) (GLsizei count, GLuint* samplers);
typedef void (APIENTRYP PFNGLDELETESAMPLERSPROC) (GLsizei count, const GLuint* samplers);
typedef GLboolean(APIENTRYP PFNGLISSAMPLERPROC) (GLuint sampler);
typedef void (APIENTRYP PFNGLBINDSAMPLERPROC) (GLuint unit, GLuint sampler);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIPROC) (GLuint sampler, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, const GLint* param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFPROC) (GLuint sampler, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, const GLfloat* param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, const GLint* param);
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, const GLuint* param);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIVPROC) (GLuint sampler, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVPROC) (GLuint sampler, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERFVPROC) (GLuint sampler, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVPROC) (GLuint sampler, GLenum pname, GLuint* params);
typedef void (APIENTRYP PFNGLQUERYCOUNTERPROC) (GLuint id, GLenum target);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTI64VPROC) (GLuint id, GLenum pname, GLint64* params);
typedef void (APIENTRYP PFNGLGETQUERYOBJECTUI64VPROC) (GLuint id, GLenum pname, GLuint64* params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORPROC) (GLuint index, GLuint divisor);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP1UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP2UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP3UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIPROC) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef void (APIENTRYP PFNGLVERTEXATTRIBP4UIVPROC) (GLuint index, GLenum type, GLboolean normalized, const GLuint* value);
#endif /* GL_VERSION_3_3 */

#ifdef FORGE_GL_VERSION(4, 0)
#define GL_VERSION_4_0 1
#define GL_SAMPLE_SHADING                 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE       0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY         0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY   0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY         0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW  0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY     0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
#define GL_DRAW_INDIRECT_BUFFER           0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING   0x8F43
#define GL_GEOMETRY_SHADER_INVOCATIONS    0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS             0x8E71
#define GL_DOUBLE_VEC2                    0x8FFC
#define GL_DOUBLE_VEC3                    0x8FFD
#define GL_DOUBLE_VEC4                    0x8FFE
#define GL_DOUBLE_MAT2                    0x8F46
#define GL_DOUBLE_MAT3                    0x8F47
#define GL_DOUBLE_MAT4                    0x8F48
#define GL_DOUBLE_MAT2x3                  0x8F49
#define GL_DOUBLE_MAT2x4                  0x8F4A
#define GL_DOUBLE_MAT3x2                  0x8F4B
#define GL_DOUBLE_MAT3x4                  0x8F4C
#define GL_DOUBLE_MAT4x2                  0x8F4D
#define GL_DOUBLE_MAT4x3                  0x8F4E
#define GL_ACTIVE_SUBROUTINES             0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS     0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH   0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES                0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES     0x8E4A
#define GL_COMPATIBLE_SUBROUTINES         0x8E4B
#define GL_PATCHES                        0x000E
#define GL_PATCH_VERTICES                 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL      0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL      0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES   0x8E75
#define GL_TESS_GEN_MODE                  0x8E76
#define GL_TESS_GEN_SPACING               0x8E77
#define GL_TESS_GEN_VERTEX_ORDER          0x8E78
#define GL_TESS_GEN_POINT_MODE            0x8E79
#define GL_ISOLINES                       0x8E7A
#define GL_FRACTIONAL_ODD                 0x8E7B
#define GL_FRACTIONAL_EVEN                0x8E7C
#define GL_MAX_PATCH_VERTICES             0x8E7D
#define GL_MAX_TESS_GEN_LEVEL             0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS      0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER         0x8E87
#define GL_TESS_CONTROL_SHADER            0x8E88
#define GL_TRANSFORM_FEEDBACK             0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING     0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGPROC) (GLfloat value);
typedef void (APIENTRYP PFNGLBLENDEQUATIONIPROC) (GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCIPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef void (APIENTRYP PFNGLDRAWARRAYSINDIRECTPROC) (GLenum mode, const void* indirect);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void* indirect);
typedef void (APIENTRYP PFNGLUNIFORM1DPROC) (GLint location, GLdouble x);
typedef void (APIENTRYP PFNGLUNIFORM2DPROC) (GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLUNIFORM3DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLUNIFORM4DPROC) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLUNIFORM1DVPROC) (GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORM2DVPROC) (GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORM3DVPROC) (GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORM4DVPROC) (GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3X4DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X2DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4X3DVPROC) (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLGETUNIFORMDVPROC) (GLuint program, GLint location, GLdouble* params);
typedef GLint(APIENTRYP PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) (GLuint program, GLenum shadertype, const GLchar* name);
typedef GLuint(APIENTRYP PFNGLGETSUBROUTINEINDEXPROC) (GLuint program, GLenum shadertype, const GLchar* name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
typedef void (APIENTRYP PFNGLGETACTIVESUBROUTINENAMEPROC) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
typedef void (APIENTRYP PFNGLUNIFORMSUBROUTINESUIVPROC) (GLenum shadertype, GLsizei count, const GLuint* indices);
typedef void (APIENTRYP PFNGLGETUNIFORMSUBROUTINEUIVPROC) (GLenum shadertype, GLint location, GLuint* params);
typedef void (APIENTRYP PFNGLGETPROGRAMSTAGEIVPROC) (GLuint program, GLenum shadertype, GLenum pname, GLint* values);
typedef void (APIENTRYP PFNGLPATCHPARAMETERIPROC) (GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLPATCHPARAMETERFVPROC) (GLenum pname, const GLfloat* values);
typedef void (APIENTRYP PFNGLBINDTRANSFORMFEEDBACKPROC) (GLenum target, GLuint id);
typedef void (APIENTRYP PFNGLDELETETRANSFORMFEEDBACKSPROC) (GLsizei n, const GLuint* ids);
typedef void (APIENTRYP PFNGLGENTRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint* ids);
typedef GLboolean(APIENTRYP PFNGLISTRANSFORMFEEDBACKPROC) (GLuint id);
typedef void (APIENTRYP PFNGLPAUSETRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLRESUMETRANSFORMFEEDBACKPROC) (void);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKPROC) (GLenum mode, GLuint id);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) (GLenum mode, GLuint id, GLuint stream);
typedef void (APIENTRYP PFNGLBEGINQUERYINDEXEDPROC) (GLenum target, GLuint index, GLuint id);
typedef void (APIENTRYP PFNGLENDQUERYINDEXEDPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLGETQUERYINDEXEDIVPROC) (GLenum target, GLuint index, GLenum pname, GLint* params);
#endif /* GL_VERSION_4_0 */

#ifdef FORGE_GL_VERSION(4, 1)
#define GL_VERSION_4_1 1
#define GL_FIXED                          0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT                      0x8DF0
#define GL_MEDIUM_FLOAT                   0x8DF1
#define GL_HIGH_FLOAT                     0x8DF2
#define GL_LOW_INT                        0x8DF3
#define GL_MEDIUM_INT                     0x8DF4
#define GL_HIGH_INT                       0x8DF5
#define GL_SHADER_COMPILER                0x8DFA
#define GL_SHADER_BINARY_FORMATS          0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS      0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS     0x8DFB
#define GL_MAX_VARYING_VECTORS            0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS   0x8DFD
#define GL_RGB565                         0x8D62
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH          0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS     0x87FE
#define GL_PROGRAM_BINARY_FORMATS         0x87FF
#define GL_VERTEX_SHADER_BIT              0x00000001
#define GL_FRAGMENT_SHADER_BIT            0x00000002
#define GL_GEOMETRY_SHADER_BIT            0x00000004
#define GL_TESS_CONTROL_SHADER_BIT        0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT     0x00000010
#define GL_ALL_SHADER_BITS                0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE              0x8258
#define GL_ACTIVE_PROGRAM                 0x8259
#define GL_PROGRAM_PIPELINE_BINDING       0x825A
#define GL_MAX_VIEWPORTS                  0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS         0x825C
#define GL_VIEWPORT_BOUNDS_RANGE          0x825D
#define GL_LAYER_PROVOKING_VERTEX         0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX               0x8260
typedef void (APIENTRYP PFNGLRELEASESHADERCOMPILERPROC) (void);
typedef void (APIENTRYP PFNGLSHADERBINARYPROC) (GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length);
typedef void (APIENTRYP PFNGLGETSHADERPRECISIONFORMATPROC) (GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision);
typedef void (APIENTRYP PFNGLDEPTHRANGEFPROC) (GLfloat n, GLfloat f);
typedef void (APIENTRYP PFNGLCLEARDEPTHFPROC) (GLfloat d);
typedef void (APIENTRYP PFNGLGETPROGRAMBINARYPROC) (GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary);
typedef void (APIENTRYP PFNGLPROGRAMBINARYPROC) (GLuint program, GLenum binaryFormat, const void* binary, GLsizei length);
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIPROC) (GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLUSEPROGRAMSTAGESPROC) (GLuint pipeline, GLbitfield stages, GLuint program);
typedef void (APIENTRYP PFNGLACTIVESHADERPROGRAMPROC) (GLuint pipeline, GLuint program);
typedef GLuint(APIENTRYP PFNGLCREATESHADERPROGRAMVPROC) (GLenum type, GLsizei count, const GLchar* const* strings);
typedef void (APIENTRYP PFNGLBINDPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPIPELINESPROC) (GLsizei n, const GLuint* pipelines);
typedef void (APIENTRYP PFNGLGENPROGRAMPIPELINESPROC) (GLsizei n, GLuint* pipelines);
typedef GLboolean(APIENTRYP PFNGLISPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEIVPROC) (GLuint pipeline, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IPROC) (GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FPROC) (GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DPROC) (GLuint program, GLint location, GLdouble v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIPROC) (GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IPROC) (GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DPROC) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPIPELINEPROC) (GLuint pipeline);
typedef void (APIENTRYP PFNGLGETPROGRAMPIPELINEINFOLOGPROC) (GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DPROC) (GLuint index, GLdouble x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DPROC) (GLuint index, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DPROC) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4DVPROC) (GLuint index, const GLdouble* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLPOINTERPROC) (GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLDVPROC) (GLuint index, GLenum pname, GLdouble* params);
typedef void (APIENTRYP PFNGLVIEWPORTARRAYVPROC) (GLuint first, GLsizei count, const GLfloat* v);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFPROC) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
typedef void (APIENTRYP PFNGLVIEWPORTINDEXEDFVPROC) (GLuint index, const GLfloat* v);
typedef void (APIENTRYP PFNGLSCISSORARRAYVPROC) (GLuint first, GLsizei count, const GLint* v);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDPROC) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSCISSORINDEXEDVPROC) (GLuint index, const GLint* v);
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYVPROC) (GLuint first, GLsizei count, const GLdouble* v);
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDPROC) (GLuint index, GLdouble n, GLdouble f);
typedef void (APIENTRYP PFNGLGETFLOATI_VPROC) (GLenum target, GLuint index, GLfloat* data);
typedef void (APIENTRYP PFNGLGETDOUBLEI_VPROC) (GLenum target, GLuint index, GLdouble* data);
#endif /* GL_VERSION_4_1 */

#ifdef FORGE_GL_VERSION(4, 2)
#define GL_VERSION_4_2 1
#define GL_COPY_READ_BUFFER_BINDING       0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING      0x8F37
#define GL_TRANSFORM_FEEDBACK_ACTIVE      0x8E24
#define GL_TRANSFORM_FEEDBACK_PAUSED      0x8E23
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH  0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH  0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE   0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH    0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT   0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH    0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE     0x912E
#define GL_NUM_SAMPLE_COUNTS              0x9380
#define GL_MIN_MAP_BUFFER_ALIGNMENT       0x90BC
#define GL_ATOMIC_COUNTER_BUFFER          0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING  0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START    0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE     0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS     0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS   0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS   0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS   0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS  0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER    0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT      0x00000002
#define GL_UNIFORM_BARRIER_BIT            0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT      0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT            0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT       0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT     0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT      0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT        0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT     0x00001000
#define GL_ALL_BARRIER_BITS               0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS                0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME             0x8F3A
#define GL_IMAGE_BINDING_LEVEL            0x8F3B
#define GL_IMAGE_BINDING_LAYERED          0x8F3C
#define GL_IMAGE_BINDING_LAYER            0x8F3D
#define GL_IMAGE_BINDING_ACCESS           0x8F3E
#define GL_IMAGE_1D                       0x904C
#define GL_IMAGE_2D                       0x904D
#define GL_IMAGE_3D                       0x904E
#define GL_IMAGE_2D_RECT                  0x904F
#define GL_IMAGE_CUBE                     0x9050
#define GL_IMAGE_BUFFER                   0x9051
#define GL_IMAGE_1D_ARRAY                 0x9052
#define GL_IMAGE_2D_ARRAY                 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY           0x9054
#define GL_IMAGE_2D_MULTISAMPLE           0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY     0x9056
#define GL_INT_IMAGE_1D                   0x9057
#define GL_INT_IMAGE_2D                   0x9058
#define GL_INT_IMAGE_3D                   0x9059
#define GL_INT_IMAGE_2D_RECT              0x905A
#define GL_INT_IMAGE_CUBE                 0x905B
#define GL_INT_IMAGE_BUFFER               0x905C
#define GL_INT_IMAGE_1D_ARRAY             0x905D
#define GL_INT_IMAGE_2D_ARRAY             0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY       0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE       0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D          0x9062
#define GL_UNSIGNED_INT_IMAGE_2D          0x9063
#define GL_UNSIGNED_INT_IMAGE_3D          0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT     0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE        0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER      0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY    0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY    0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES              0x906D
#define GL_IMAGE_BINDING_FORMAT           0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS      0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS    0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS    0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS    0x90CF
#define GL_COMPRESSED_RGBA_BPTC_UNORM     0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#define GL_TEXTURE_IMMUTABLE_FORMAT       0x912F
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATIVPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params);
typedef void (APIENTRYP PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) (GLuint program, GLuint bufferIndex, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTUREPROC) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef void (APIENTRYP PFNGLMEMORYBARRIERPROC) (GLbitfield barriers);
typedef void (APIENTRYP PFNGLTEXSTORAGE1DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) (GLenum mode, GLuint id, GLsizei instancecount);
typedef void (APIENTRYP PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
#endif /* GL_VERSION_4_2 */

#ifdef FORGE_GL_VERSION(4, 3)
#define GL_VERSION_4_3 1
typedef void (APIENTRY* GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
#define GL_NUM_SHADING_LANGUAGE_VERSIONS  0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG       0x874E
#define GL_COMPRESSED_RGB8_ETC2           0x9274
#define GL_COMPRESSED_SRGB8_ETC2          0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC      0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_R11_EAC             0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC      0x9271
#define GL_COMPRESSED_RG11_EAC            0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC     0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX  0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX              0x8D6B
#define GL_COMPUTE_SHADER                 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS     0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS     0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS    0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT   0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE    0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE        0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER       0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER_BIT             0x00000020
#define GL_DEBUG_OUTPUT_SYNCHRONOUS       0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION        0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM      0x8245
#define GL_DEBUG_SOURCE_API               0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM     0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER   0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY       0x8249
#define GL_DEBUG_SOURCE_APPLICATION       0x824A
#define GL_DEBUG_SOURCE_OTHER             0x824B
#define GL_DEBUG_TYPE_ERROR               0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR  0x824E
#define GL_DEBUG_TYPE_PORTABILITY         0x824F
#define GL_DEBUG_TYPE_PERFORMANCE         0x8250
#define GL_DEBUG_TYPE_OTHER               0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH       0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES      0x9144
#define GL_DEBUG_LOGGED_MESSAGES          0x9145
#define GL_DEBUG_SEVERITY_HIGH            0x9146
#define GL_DEBUG_SEVERITY_MEDIUM          0x9147
#define GL_DEBUG_SEVERITY_LOW             0x9148
#define GL_DEBUG_TYPE_MARKER              0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP          0x8269
#define GL_DEBUG_TYPE_POP_GROUP           0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION    0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH    0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH        0x826D
#define GL_BUFFER                         0x82E0
#define GL_SHADER                         0x82E1
#define GL_PROGRAM                        0x82E2
#define GL_QUERY                          0x82E3
#define GL_PROGRAM_PIPELINE               0x82E4
#define GL_SAMPLER                        0x82E6
#define GL_MAX_LABEL_LENGTH               0x82E8
#define GL_DEBUG_OUTPUT                   0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT         0x00000002
#define GL_MAX_UNIFORM_LOCATIONS          0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH      0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT     0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS     0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES    0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH          0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT         0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS         0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES        0x9318
#define GL_INTERNALFORMAT_SUPPORTED       0x826F
#define GL_INTERNALFORMAT_PREFERRED       0x8270
#define GL_INTERNALFORMAT_RED_SIZE        0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE      0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE       0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE      0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE      0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE    0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE     0x8277
#define GL_INTERNALFORMAT_RED_TYPE        0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE      0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE       0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE      0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE      0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE    0x827D
#define GL_MAX_WIDTH                      0x827E
#define GL_MAX_HEIGHT                     0x827F
#define GL_MAX_DEPTH                      0x8280
#define GL_MAX_LAYERS                     0x8281
#define GL_MAX_COMBINED_DIMENSIONS        0x8282
#define GL_COLOR_COMPONENTS               0x8283
#define GL_DEPTH_COMPONENTS               0x8284
#define GL_STENCIL_COMPONENTS             0x8285
#define GL_COLOR_RENDERABLE               0x8286
#define GL_DEPTH_RENDERABLE               0x8287
#define GL_STENCIL_RENDERABLE             0x8288
#define GL_FRAMEBUFFER_RENDERABLE         0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND              0x828B
#define GL_READ_PIXELS                    0x828C
#define GL_READ_PIXELS_FORMAT             0x828D
#define GL_READ_PIXELS_TYPE               0x828E
#define GL_TEXTURE_IMAGE_FORMAT           0x828F
#define GL_TEXTURE_IMAGE_TYPE             0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT       0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE         0x8292
#define GL_MIPMAP                         0x8293
#define GL_MANUAL_GENERATE_MIPMAP         0x8294
#define GL_AUTO_GENERATE_MIPMAP           0x8295
#define GL_COLOR_ENCODING                 0x8296
#define GL_SRGB_READ                      0x8297
#define GL_SRGB_WRITE                     0x8298
#define GL_FILTER                         0x829A
#define GL_VERTEX_TEXTURE                 0x829B
#define GL_TESS_CONTROL_TEXTURE           0x829C
#define GL_TESS_EVALUATION_TEXTURE        0x829D
#define GL_GEOMETRY_TEXTURE               0x829E
#define GL_FRAGMENT_TEXTURE               0x829F
#define GL_COMPUTE_TEXTURE                0x82A0
#define GL_TEXTURE_SHADOW                 0x82A1
#define GL_TEXTURE_GATHER                 0x82A2
#define GL_TEXTURE_GATHER_SHADOW          0x82A3
#define GL_SHADER_IMAGE_LOAD              0x82A4
#define GL_SHADER_IMAGE_STORE             0x82A5
#define GL_SHADER_IMAGE_ATOMIC            0x82A6
#define GL_IMAGE_TEXEL_SIZE               0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS      0x82A8
#define GL_IMAGE_PIXEL_FORMAT             0x82A9
#define GL_IMAGE_PIXEL_TYPE               0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE  0x82B3
#define GL_CLEAR_BUFFER                   0x82B4
#define GL_TEXTURE_VIEW                   0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS       0x82B6
#define GL_FULL_SUPPORT                   0x82B7
#define GL_CAVEAT_SUPPORT                 0x82B8
#define GL_IMAGE_CLASS_4_X_32             0x82B9
#define GL_IMAGE_CLASS_2_X_32             0x82BA
#define GL_IMAGE_CLASS_1_X_32             0x82BB
#define GL_IMAGE_CLASS_4_X_16             0x82BC
#define GL_IMAGE_CLASS_2_X_16             0x82BD
#define GL_IMAGE_CLASS_1_X_16             0x82BE
#define GL_IMAGE_CLASS_4_X_8              0x82BF
#define GL_IMAGE_CLASS_2_X_8              0x82C0
#define GL_IMAGE_CLASS_1_X_8              0x82C1
#define GL_IMAGE_CLASS_11_11_10           0x82C2
#define GL_IMAGE_CLASS_10_10_10_2         0x82C3
#define GL_VIEW_CLASS_128_BITS            0x82C4
#define GL_VIEW_CLASS_96_BITS             0x82C5
#define GL_VIEW_CLASS_64_BITS             0x82C6
#define GL_VIEW_CLASS_48_BITS             0x82C7
#define GL_VIEW_CLASS_32_BITS             0x82C8
#define GL_VIEW_CLASS_24_BITS             0x82C9
#define GL_VIEW_CLASS_16_BITS             0x82CA
#define GL_VIEW_CLASS_8_BITS              0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB       0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA      0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA      0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA      0x82CF
#define GL_VIEW_CLASS_RGTC1_RED           0x82D0
#define GL_VIEW_CLASS_RGTC2_RG            0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM          0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT          0x82D3
#define GL_UNIFORM                        0x92E1
#define GL_UNIFORM_BLOCK                  0x92E2
#define GL_PROGRAM_INPUT                  0x92E3
#define GL_PROGRAM_OUTPUT                 0x92E4
#define GL_BUFFER_VARIABLE                0x92E5
#define GL_SHADER_STORAGE_BLOCK           0x92E6
#define GL_VERTEX_SUBROUTINE              0x92E8
#define GL_TESS_CONTROL_SUBROUTINE        0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE     0x92EA
#define GL_GEOMETRY_SUBROUTINE            0x92EB
#define GL_FRAGMENT_SUBROUTINE            0x92EC
#define GL_COMPUTE_SUBROUTINE             0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM      0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM    0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM    0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM     0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING     0x92F4
#define GL_ACTIVE_RESOURCES               0x92F5
#define GL_MAX_NAME_LENGTH                0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES       0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH                    0x92F9
#define GL_TYPE                           0x92FA
#define GL_ARRAY_SIZE                     0x92FB
#define GL_OFFSET                         0x92FC
#define GL_BLOCK_INDEX                    0x92FD
#define GL_ARRAY_STRIDE                   0x92FE
#define GL_MATRIX_STRIDE                  0x92FF
#define GL_IS_ROW_MAJOR                   0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX    0x9301
#define GL_BUFFER_BINDING                 0x9302
#define GL_BUFFER_DATA_SIZE               0x9303
#define GL_NUM_ACTIVE_VARIABLES           0x9304
#define GL_ACTIVE_VARIABLES               0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER    0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER  0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER  0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER   0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE           0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE         0x930D
#define GL_LOCATION                       0x930E
#define GL_LOCATION_INDEX                 0x930F
#define GL_IS_PER_PATCH                   0x92E7
#define GL_SHADER_STORAGE_BUFFER          0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING  0x90D3
#define GL_SHADER_STORAGE_BUFFER_START    0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE     0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE  0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT     0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE     0x90EA
#define GL_TEXTURE_BUFFER_OFFSET          0x919D
#define GL_TEXTURE_BUFFER_SIZE            0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_TEXTURE_VIEW_MIN_LEVEL         0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS        0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER         0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS        0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS       0x82DF
#define GL_VERTEX_ATTRIB_BINDING          0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET  0x82D5
#define GL_VERTEX_BINDING_DIVISOR         0x82D6
#define GL_VERTEX_BINDING_OFFSET          0x82D7
#define GL_VERTEX_BINDING_STRIDE          0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS     0x82DA
#define GL_VERTEX_BINDING_BUFFER          0x8F4F
typedef void (APIENTRYP PFNGLCLEARBUFFERDATAPROC) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data);
typedef void (APIENTRYP PFNGLCLEARBUFFERSUBDATAPROC) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEINDIRECTPROC) (GLintptr indirect);
typedef void (APIENTRYP PFNGLCOPYIMAGESUBDATAPROC) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVPROC) (GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETINTERNALFORMATI64VPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params);
typedef void (APIENTRYP PFNGLINVALIDATETEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLINVALIDATETEXIMAGEPROC) (GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLINVALIDATEBUFFERDATAPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLINVALIDATEFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum* attachments);
typedef void (APIENTRYP PFNGLINVALIDATESUBFRAMEBUFFERPROC) (GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTPROC) (GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTPROC) (GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLGETPROGRAMINTERFACEIVPROC) (GLuint program, GLenum programInterface, GLenum pname, GLint* params);
typedef GLuint(APIENTRYP PFNGLGETPROGRAMRESOURCEINDEXPROC) (GLuint program, GLenum programInterface, const GLchar* name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCENAMEPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEIVPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params);
typedef GLint(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONPROC) (GLuint program, GLenum programInterface, const GLchar* name);
typedef GLint(APIENTRYP PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) (GLuint program, GLenum programInterface, const GLchar* name);
typedef void (APIENTRYP PFNGLSHADERSTORAGEBLOCKBINDINGPROC) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
typedef void (APIENTRYP PFNGLTEXBUFFERRANGEPROC) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DMULTISAMPLEPROC) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTUREVIEWPROC) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERPROC) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATPROC) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXATTRIBBINDINGPROC) (GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXBINDINGDIVISORPROC) (GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKPROC) (GLDEBUGPROC callback, const void* userParam);
typedef GLuint(APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC) (GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
typedef void (APIENTRYP PFNGLPUSHDEBUGGROUPPROC) (GLenum source, GLuint id, GLsizei length, const GLchar* message);
typedef void (APIENTRYP PFNGLPOPDEBUGGROUPPROC) (void);
typedef void (APIENTRYP PFNGLOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei length, const GLchar* label);
typedef void (APIENTRYP PFNGLGETOBJECTLABELPROC) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label);
typedef void (APIENTRYP PFNGLOBJECTPTRLABELPROC) (const void* ptr, GLsizei length, const GLchar* label);
typedef void (APIENTRYP PFNGLGETOBJECTPTRLABELPROC) (const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label);
#endif /* GL_VERSION_4_3 */

#ifdef FORGE_GL_VERSION(4, 4)
#define GL_VERSION_4_4 1
#define GL_MAX_VERTEX_ATTRIB_STRIDE       0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_TEXTURE_BUFFER_BINDING         0x8C2A
#define GL_MAP_PERSISTENT_BIT             0x0040
#define GL_MAP_COHERENT_BIT               0x0080
#define GL_DYNAMIC_STORAGE_BIT            0x0100
#define GL_CLIENT_STORAGE_BIT             0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE       0x821F
#define GL_BUFFER_STORAGE_FLAGS           0x8220
#define GL_CLEAR_TEXTURE                  0x9365
#define GL_LOCATION_COMPONENT             0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
#define GL_QUERY_BUFFER                   0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT       0x00008000
#define GL_QUERY_BUFFER_BINDING           0x9193
#define GL_QUERY_RESULT_NO_WAIT           0x9194
#define GL_MIRROR_CLAMP_TO_EDGE           0x8743
typedef void (APIENTRYP PFNGLBUFFERSTORAGEPROC) (GLenum target, GLsizeiptr size, const void* data, GLbitfield flags);
typedef void (APIENTRYP PFNGLCLEARTEXIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, const void* data);
typedef void (APIENTRYP PFNGLCLEARTEXSUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data);
typedef void (APIENTRYP PFNGLBINDBUFFERSBASEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint* buffers);
typedef void (APIENTRYP PFNGLBINDBUFFERSRANGEPROC) (GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes);
typedef void (APIENTRYP PFNGLBINDTEXTURESPROC) (GLuint first, GLsizei count, const GLuint* textures);
typedef void (APIENTRYP PFNGLBINDSAMPLERSPROC) (GLuint first, GLsizei count, const GLuint* samplers);
typedef void (APIENTRYP PFNGLBINDIMAGETEXTURESPROC) (GLuint first, GLsizei count, const GLuint* textures);
typedef void (APIENTRYP PFNGLBINDVERTEXBUFFERSPROC) (GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
#endif /* GL_VERSION_4_4 */

#ifdef FORGE_GL_VERSION(4, 5)
#define GL_VERSION_4_5 1
#define GL_CONTEXT_LOST                   0x0507
#define GL_NEGATIVE_ONE_TO_ONE            0x935E
#define GL_ZERO_TO_ONE                    0x935F
#define GL_CLIP_ORIGIN                    0x935C
#define GL_CLIP_DEPTH_MODE                0x935D
#define GL_QUERY_WAIT_INVERTED            0x8E17
#define GL_QUERY_NO_WAIT_INVERTED         0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED  0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#define GL_MAX_CULL_DISTANCES             0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_TEXTURE_TARGET                 0x1006
#define GL_QUERY_TARGET                   0x82EA
#define GL_GUILTY_CONTEXT_RESET           0x8253
#define GL_INNOCENT_CONTEXT_RESET         0x8254
#define GL_UNKNOWN_CONTEXT_RESET          0x8255
#define GL_RESET_NOTIFICATION_STRATEGY    0x8256
#define GL_LOSE_CONTEXT_ON_RESET          0x8252
#define GL_NO_RESET_NOTIFICATION          0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
#define GL_CONTEXT_RELEASE_BEHAVIOR       0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC
typedef void (APIENTRYP PFNGLCLIPCONTROLPROC) (GLenum origin, GLenum depth);
typedef void (APIENTRYP PFNGLCREATETRANSFORMFEEDBACKSPROC) (GLsizei n, GLuint* ids);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC) (GLuint xfb, GLuint index, GLuint buffer);
typedef void (APIENTRYP PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC) (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKIVPROC) (GLuint xfb, GLenum pname, GLint* param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI_VPROC) (GLuint xfb, GLenum pname, GLuint index, GLint* param);
typedef void (APIENTRYP PFNGLGETTRANSFORMFEEDBACKI64_VPROC) (GLuint xfb, GLenum pname, GLuint index, GLint64* param);
typedef void (APIENTRYP PFNGLCREATEBUFFERSPROC) (GLsizei n, GLuint* buffers);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEPROC) (GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags);
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAPROC) (GLuint buffer, GLsizeiptr size, const void* data, GLenum usage);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data);
typedef void (APIENTRYP PFNGLCOPYNAMEDBUFFERSUBDATAPROC) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAPROC) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
typedef void* (APIENTRYP PFNGLMAPNAMEDBUFFERPROC) (GLuint buffer, GLenum access);
typedef void* (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef GLboolean(APIENTRYP PFNGLUNMAPNAMEDBUFFERPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVPROC) (GLuint buffer, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERI64VPROC) (GLuint buffer, GLenum pname, GLint64* params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVPROC) (GLuint buffer, GLenum pname, void** params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, void* data);
typedef void (APIENTRYP PFNGLCREATEFRAMEBUFFERSPROC) (GLsizei n, GLuint* framebuffers);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC) (GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC) (GLuint framebuffer, GLenum buf);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC) (GLuint framebuffer, GLsizei n, const GLenum* bufs);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC) (GLuint framebuffer, GLenum src);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC) (GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments);
typedef void (APIENTRYP PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC) (GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERIVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFVPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value);
typedef void (APIENTRYP PFNGLCLEARNAMEDFRAMEBUFFERFIPROC) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (APIENTRYP PFNGLBLITNAMEDFRAMEBUFFERPROC) (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLenum(APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC) (GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC) (GLuint framebuffer, GLenum pname, GLint* param);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLCREATERENDERBUFFERSPROC) (GLsizei n, GLuint* renderbuffers);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEPROC) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC) (GLuint renderbuffer, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLCREATETEXTURESPROC) (GLenum target, GLsizei n, GLuint* textures);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERPROC) (GLuint texture, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEPROC) (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DPROC) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DPROC) (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFPROC) (GLuint texture, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVPROC) (GLuint texture, GLenum pname, const GLfloat* param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIPROC) (GLuint texture, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVPROC) (GLuint texture, GLenum pname, const GLint* params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVPROC) (GLuint texture, GLenum pname, const GLuint* params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVPROC) (GLuint texture, GLenum pname, const GLint* param);
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPPROC) (GLuint texture);
typedef void (APIENTRYP PFNGLBINDTEXTUREUNITPROC) (GLuint unit, GLuint texture);
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEPROC) (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC) (GLuint texture, GLint level, GLsizei bufSize, void* pixels);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVPROC) (GLuint texture, GLint level, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVPROC) (GLuint texture, GLint level, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVPROC) (GLuint texture, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVPROC) (GLuint texture, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVPROC) (GLuint texture, GLenum pname, GLuint* params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVPROC) (GLuint texture, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLCREATEVERTEXARRAYSPROC) (GLsizei n, GLuint* arrays);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLVERTEXARRAYELEMENTBUFFERPROC) (GLuint vaobj, GLuint buffer);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERPROC) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBUFFERSPROC) (GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBBINDINGPROC) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBIFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYATTRIBLFORMATPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDINGDIVISORPROC) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYIVPROC) (GLuint vaobj, GLenum pname, GLint* param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXEDIVPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint* param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINDEXED64IVPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint64* param);
typedef void (APIENTRYP PFNGLCREATESAMPLERSPROC) (GLsizei n, GLuint* samplers);
typedef void (APIENTRYP PFNGLCREATEPROGRAMPIPELINESPROC) (GLsizei n, GLuint* pipelines);
typedef void (APIENTRYP PFNGLCREATEQUERIESPROC) (GLenum target, GLsizei n, GLuint* ids);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTI64VPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTIVPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUI64VPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLGETQUERYBUFFEROBJECTUIVPROC) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
typedef void (APIENTRYP PFNGLMEMORYBARRIERBYREGIONPROC) (GLbitfield barriers);
typedef void (APIENTRYP PFNGLGETTEXTURESUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels);
typedef GLenum(APIENTRYP PFNGLGETGRAPHICSRESETSTATUSPROC) (void);
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEPROC) (GLenum target, GLint lod, GLsizei bufSize, void* pixels);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVPROC) (GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVPROC) (GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVPROC) (GLuint program, GLint location, GLsizei bufSize, GLint* params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint* params);
typedef void (APIENTRYP PFNGLREADNPIXELSPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data);
typedef void (APIENTRYP PFNGLTEXTUREBARRIERPROC) (void);
#endif /* GL_VERSION_4_5 */

#ifdef FORGE_GL_VERSION(4, 6)
#define GL_VERSION_4_6 1
#define GL_SHADER_BINARY_FORMAT_SPIR_V    0x9551
#define GL_SPIR_V_BINARY                  0x9552
#define GL_PARAMETER_BUFFER               0x80EE
#define GL_PARAMETER_BUFFER_BINDING       0x80EF
#define GL_CONTEXT_FLAG_NO_ERROR_BIT      0x00000008
#define GL_VERTICES_SUBMITTED             0x82EE
#define GL_PRIMITIVES_SUBMITTED           0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS      0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES    0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS    0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS     0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES      0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES     0x82F7
#define GL_POLYGON_OFFSET_CLAMP           0x8E1B
#define GL_SPIR_V_EXTENSIONS              0x9553
#define GL_NUM_SPIR_V_EXTENSIONS          0x9554
#define GL_TEXTURE_MAX_ANISOTROPY         0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY     0x84FF
#define GL_TRANSFORM_FEEDBACK_OVERFLOW    0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW 0x82ED
typedef void (APIENTRYP PFNGLSPECIALIZESHADERPROC) (GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue);
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC) (GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC) (GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPPROC) (GLfloat factor, GLfloat units, GLfloat clamp);
#endif /* GL_VERSION_4_6 */

#ifdef FORGE_ARB_ES3_2_compatibility
#define GL_PRIMITIVE_BOUNDING_BOX_ARB     0x92BE
#define GL_MULTISAMPLE_LINE_WIDTH_RANGE_ARB 0x9381
#define GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY_ARB 0x9382
typedef void (APIENTRYP PFNGLPRIMITIVEBOUNDINGBOXARBPROC) (GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#endif /* FORGE_ARB_ES3_2_compatibility */

#ifdef FORGE_ARB_bindless_texture
typedef khronos_uint64_t GLuint64EXT;
#define GL_UNSIGNED_INT64_ARB             0x140F
typedef GLuint64(APIENTRYP PFNGLGETTEXTUREHANDLEARBPROC) (GLuint texture);
typedef GLuint64(APIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC) (GLuint texture, GLuint sampler);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC) (GLuint64 handle);
typedef GLuint64(APIENTRYP PFNGLGETIMAGEHANDLEARBPROC) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle, GLenum access);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC) (GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC) (GLint location, GLsizei count, const GLuint64* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC) (GLuint program, GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64* values);
typedef GLboolean(APIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef GLboolean(APIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC) (GLuint index, GLuint64EXT x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC) (GLuint index, const GLuint64EXT* v);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC) (GLuint index, GLenum pname, GLuint64EXT* params);
#endif /* FORGE_ARB_bindless_texture */

#ifdef FORGE_ARB_cl_event
struct _cl_context;
struct _cl_event;
#define GL_SYNC_CL_EVENT_ARB              0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB     0x8241
typedef GLsync(APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC) (struct _cl_context* context, struct _cl_event* event, GLbitfield flags);
#endif /* FORGE_ARB_cl_event */

#ifdef FORGE_ARB_compute_variable_group_size
#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB 0x9344
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB 0x90EB
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB 0x9345
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB 0x91BF
typedef void (APIENTRYP PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#endif /* FORGE_ARB_compute_variable_group_size */

#ifdef FORGE_ARB_debug_output
typedef void (APIENTRY* GLDEBUGPROCARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB   0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB    0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB  0x8245
#define GL_DEBUG_SOURCE_API_ARB           0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB   0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB   0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB         0x824B
#define GL_DEBUG_TYPE_ERROR_ARB           0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB 0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB     0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB     0x8250
#define GL_DEBUG_TYPE_OTHER_ARB           0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB   0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB  0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB      0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB        0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB      0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB         0x9148
typedef void (APIENTRYP PFNGLDEBUGMESSAGECONTROLARBPROC) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled);
typedef void (APIENTRYP PFNGLDEBUGMESSAGEINSERTARBPROC) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf);
typedef void (APIENTRYP PFNGLDEBUGMESSAGECALLBACKARBPROC) (GLDEBUGPROCARB callback, const void* userParam);
typedef GLuint(APIENTRYP PFNGLGETDEBUGMESSAGELOGARBPROC) (GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog);
#endif /* FORGE_ARB_debug_output */

#ifdef FORGE_ARB_draw_buffers_blend
typedef void (APIENTRYP PFNGLBLENDEQUATIONIARBPROC) (GLuint buf, GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEIARBPROC) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCIARBPROC) (GLuint buf, GLenum src, GLenum dst);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEIARBPROC) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
#endif /* FORGE_ARB_draw_buffers_blend */

#ifdef FORGE_ARB_draw_instanced
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDARBPROC) (GLenum mode, GLint first, GLsizei count, GLsizei primcount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDARBPROC) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount);
#endif /* FORGE_ARB_draw_instanced */

#ifdef FORGE_ARB_geometry_shader4
#define GL_LINES_ADJACENCY_ARB            0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB       0x000B
#define GL_TRIANGLES_ADJACENCY_ARB        0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB   0x000D
#define GL_PROGRAM_POINT_SIZE_ARB         0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB 0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB 0x8DA9
#define GL_GEOMETRY_SHADER_ARB            0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB      0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB        0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB       0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB 0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB 0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB 0x8DE1
typedef void (APIENTRYP PFNGLPROGRAMPARAMETERIARBPROC) (GLuint program, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREARBPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTURELAYERARBPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREFACEARBPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
#endif /* FORGE_ARB_geometry_shader4 */

#ifdef FORGE_ARB_gl_spirv
#define GL_SHADER_BINARY_FORMAT_SPIR_V_ARB 0x9551
#define GL_SPIR_V_BINARY_ARB              0x9552
typedef void (APIENTRYP PFNGLSPECIALIZESHADERARBPROC) (GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue);
#endif /* FORGE_ARB_gl_spirv */

#ifdef FORGE_ARB_gpu_shader_int64
#define GL_INT64_ARB                      0x140E
#define GL_INT64_VEC2_ARB                 0x8FE9
#define GL_INT64_VEC3_ARB                 0x8FEA
#define GL_INT64_VEC4_ARB                 0x8FEB
#define GL_UNSIGNED_INT64_VEC2_ARB        0x8FF5
#define GL_UNSIGNED_INT64_VEC3_ARB        0x8FF6
#define GL_UNSIGNED_INT64_VEC4_ARB        0x8FF7
typedef void (APIENTRYP PFNGLUNIFORM1I64ARBPROC) (GLint location, GLint64 x);
typedef void (APIENTRYP PFNGLUNIFORM2I64ARBPROC) (GLint location, GLint64 x, GLint64 y);
typedef void (APIENTRYP PFNGLUNIFORM3I64ARBPROC) (GLint location, GLint64 x, GLint64 y, GLint64 z);
typedef void (APIENTRYP PFNGLUNIFORM4I64ARBPROC) (GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
typedef void (APIENTRYP PFNGLUNIFORM1I64VARBPROC) (GLint location, GLsizei count, const GLint64* value);
typedef void (APIENTRYP PFNGLUNIFORM2I64VARBPROC) (GLint location, GLsizei count, const GLint64* value);
typedef void (APIENTRYP PFNGLUNIFORM3I64VARBPROC) (GLint location, GLsizei count, const GLint64* value);
typedef void (APIENTRYP PFNGLUNIFORM4I64VARBPROC) (GLint location, GLsizei count, const GLint64* value);
typedef void (APIENTRYP PFNGLUNIFORM1UI64ARBPROC) (GLint location, GLuint64 x);
typedef void (APIENTRYP PFNGLUNIFORM2UI64ARBPROC) (GLint location, GLuint64 x, GLuint64 y);
typedef void (APIENTRYP PFNGLUNIFORM3UI64ARBPROC) (GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
typedef void (APIENTRYP PFNGLUNIFORM4UI64ARBPROC) (GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
typedef void (APIENTRYP PFNGLUNIFORM1UI64VARBPROC) (GLint location, GLsizei count, const GLuint64* value);
typedef void (APIENTRYP PFNGLUNIFORM2UI64VARBPROC) (GLint location, GLsizei count, const GLuint64* value);
typedef void (APIENTRYP PFNGLUNIFORM3UI64VARBPROC) (GLint location, GLsizei count, const GLuint64* value);
typedef void (APIENTRYP PFNGLUNIFORM4UI64VARBPROC) (GLint location, GLsizei count, const GLuint64* value);
typedef void (APIENTRYP PFNGLGETUNIFORMI64VARBPROC) (GLuint program, GLint location, GLint64* params);
typedef void (APIENTRYP PFNGLGETUNIFORMUI64VARBPROC) (GLuint program, GLint location, GLuint64* params);
typedef void (APIENTRYP PFNGLGETNUNIFORMI64VARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLint64* params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUI64VARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint64* params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64ARBPROC) (GLuint program, GLint location, GLint64 x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64ARBPROC) (GLuint program, GLint location, GLint64 x, GLint64 y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64ARBPROC) (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64ARBPROC) (GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLint64* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLint64* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLint64* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLint64* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64ARBPROC) (GLuint program, GLint location, GLuint64 x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64ARBPROC) (GLuint program, GLint location, GLuint64 x, GLuint64 y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64ARBPROC) (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64ARBPROC) (GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64VARBPROC) (GLuint program, GLint location, GLsizei count, const GLuint64* value);
#endif /* FORGE_ARB_gpu_shader_int64 */

#ifdef FORGE_ARB_indirect_parameters
#define GL_PARAMETER_BUFFER_ARB           0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB   0x80EF
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC) (GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC) (GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif /* FORGE_ARB_indirect_parameters */

#ifdef FORGE_ARB_instanced_arrays
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB 0x88FE
typedef void (APIENTRYP PFNGLVERTEXATTRIBDIVISORARBPROC) (GLuint index, GLuint divisor);
#endif /* FORGE_ARB_instanced_arrays */

#ifdef FORGE_ARB_internalformat_query2
#define GL_SRGB_DECODE_ARB                0x8299
#define GL_VIEW_CLASS_EAC_R11             0x9383
#define GL_VIEW_CLASS_EAC_RG11            0x9384
#define GL_VIEW_CLASS_ETC2_RGB            0x9385
#define GL_VIEW_CLASS_ETC2_RGBA           0x9386
#define GL_VIEW_CLASS_ETC2_EAC_RGBA       0x9387
#define GL_VIEW_CLASS_ASTC_4x4_RGBA       0x9388
#define GL_VIEW_CLASS_ASTC_5x4_RGBA       0x9389
#define GL_VIEW_CLASS_ASTC_5x5_RGBA       0x938A
#define GL_VIEW_CLASS_ASTC_6x5_RGBA       0x938B
#define GL_VIEW_CLASS_ASTC_6x6_RGBA       0x938C
#define GL_VIEW_CLASS_ASTC_8x5_RGBA       0x938D
#define GL_VIEW_CLASS_ASTC_8x6_RGBA       0x938E
#define GL_VIEW_CLASS_ASTC_8x8_RGBA       0x938F
#define GL_VIEW_CLASS_ASTC_10x5_RGBA      0x9390
#define GL_VIEW_CLASS_ASTC_10x6_RGBA      0x9391
#define GL_VIEW_CLASS_ASTC_10x8_RGBA      0x9392
#define GL_VIEW_CLASS_ASTC_10x10_RGBA     0x9393
#define GL_VIEW_CLASS_ASTC_12x10_RGBA     0x9394
#define GL_VIEW_CLASS_ASTC_12x12_RGBA     0x9395
#endif /* FORGE_ARB_internalformat_query2 */

#ifdef FORGE_ARB_parallel_shader_compile
#define GL_MAX_SHADER_COMPILER_THREADS_ARB 0x91B0
#define GL_COMPLETION_STATUS_ARB          0x91B1
typedef void (APIENTRYP PFNGLMAXSHADERCOMPILERTHREADSARBPROC) (GLuint count);
#endif /* FORGE_ARB_parallel_shader_compile */

#ifdef FORGE_ARB_pipeline_statistics_query
#define GL_VERTICES_SUBMITTED_ARB         0x82EE
#define GL_PRIMITIVES_SUBMITTED_ARB       0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS_ARB  0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB  0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB 0x82F7
#endif /* FORGE_ARB_pipeline_statistics_query */

#ifdef FORGE_ARB_pixel_buffer_object
#define GL_PIXEL_PACK_BUFFER_ARB          0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB        0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB  0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB 0x88EF
#endif /* FORGE_ARB_pixel_buffer_object */

#ifdef FORGE_ARB_robustness
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB 0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB      0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB       0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB     0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB      0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define GL_NO_RESET_NOTIFICATION_ARB      0x8261
typedef GLenum(APIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC) (void);
typedef void (APIENTRYP PFNGLGETNTEXIMAGEARBPROC) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* img);
typedef void (APIENTRYP PFNGLREADNPIXELSARBPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data);
typedef void (APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC) (GLenum target, GLint lod, GLsizei bufSize, void* img);
typedef void (APIENTRYP PFNGLGETNUNIFORMFVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
typedef void (APIENTRYP PFNGLGETNUNIFORMIVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLint* params);
typedef void (APIENTRYP PFNGLGETNUNIFORMUIVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLuint* params);
typedef void (APIENTRYP PFNGLGETNUNIFORMDVARBPROC) (GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
#endif /* FORGE_ARB_robustness */

#ifdef FORGE_ARB_sample_locations
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_ARB 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_ARB 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_ARB 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_ARB 0x9340
#define GL_SAMPLE_LOCATION_ARB            0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_ARB 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_ARB 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_ARB 0x9343
typedef void (APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC) (GLenum target, GLuint start, GLsizei count, const GLfloat* v);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC) (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v);
typedef void (APIENTRYP PFNGLEVALUATEDEPTHVALUESARBPROC) (void);
#endif /* FORGE_ARB_sample_locations */

#ifdef FORGE_ARB_sample_shading
#define GL_SAMPLE_SHADING_ARB             0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB   0x8C37
typedef void (APIENTRYP PFNGLMINSAMPLESHADINGARBPROC) (GLfloat value);
#endif /* FORGE_ARB_sample_shading */

#ifdef FORGE_ARB_shading_language_include
#define GL_SHADER_INCLUDE_ARB             0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB        0x8DE9
#define GL_NAMED_STRING_TYPE_ARB          0x8DEA
typedef void (APIENTRYP PFNGLNAMEDSTRINGARBPROC) (GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string);
typedef void (APIENTRYP PFNGLDELETENAMEDSTRINGARBPROC) (GLint namelen, const GLchar* name);
typedef void (APIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC) (GLuint shader, GLsizei count, const GLchar* const* path, const GLint* length);
typedef GLboolean(APIENTRYP PFNGLISNAMEDSTRINGARBPROC) (GLint namelen, const GLchar* name);
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGARBPROC) (GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string);
typedef void (APIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC) (GLint namelen, const GLchar* name, GLenum pname, GLint* params);
#endif /* FORGE_ARB_shading_language_include */

#ifdef FORGE_ARB_sparse_buffer
#define GL_SPARSE_STORAGE_BIT_ARB         0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB    0x82F8
typedef void (APIENTRYP PFNGLBUFFERPAGECOMMITMENTARBPROC) (GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
#endif /* FORGE_ARB_sparse_buffer */

#ifdef FORGE_ARB_sparse_texture
#define GL_TEXTURE_SPARSE_ARB             0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB    0x91A7
#define GL_NUM_SPARSE_LEVELS_ARB          0x91AA
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB     0x91A8
#define GL_VIRTUAL_PAGE_SIZE_X_ARB        0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB        0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB        0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB    0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB 0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB 0x919A
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB 0x91A9
typedef void (APIENTRYP PFNGLTEXPAGECOMMITMENTARBPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#endif /* FORGE_ARB_sparse_texture */

#ifdef FORGE_ARB_texture_border_clamp
#define GL_CLAMP_TO_BORDER_ARB            0x812D
#endif /* FORGE_ARB_texture_border_clamp */

#ifdef FORGE_ARB_texture_buffer_object
#define GL_TEXTURE_BUFFER_ARB             0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB    0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB     0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB 0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB      0x8C2E
typedef void (APIENTRYP PFNGLTEXBUFFERARBPROC) (GLenum target, GLenum internalformat, GLuint buffer);
#endif /* FORGE_ARB_texture_buffer_object */

#ifdef FORGE_ARB_texture_compression_bptc
#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB 0x8E8F
#endif /* FORGE_ARB_texture_compression_bptc */

#ifdef FORGE_ARB_texture_cube_map_array
#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB     0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB     0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB 0x900F
#endif /* FORGE_ARB_texture_cube_map_array */

#ifdef FORGE_ARB_texture_filter_minmax
#define GL_TEXTURE_REDUCTION_MODE_ARB     0x9366
#define GL_WEIGHTED_AVERAGE_ARB           0x9367
#endif /* FORGE_ARB_texture_filter_minmax */

#ifdef FORGE_ARB_texture_gather
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB 0x8F9F
#endif /* FORGE_ARB_texture_gather */

#ifdef FORGE_ARB_texture_mirrored_repeat
#define GL_MIRRORED_REPEAT_ARB            0x8370
#endif /* FORGE_ARB_texture_mirrored_repeat */

#ifdef FORGE_ARB_transform_feedback_overflow_query
#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB 0x82ED
#endif /* FORGE_ARB_transform_feedback_overflow_query */

#ifdef FORGE_ARB_viewport_array
typedef void (APIENTRYP PFNGLDEPTHRANGEARRAYDVNVPROC) (GLuint first, GLsizei count, const GLdouble* v);
typedef void (APIENTRYP PFNGLDEPTHRANGEINDEXEDDNVPROC) (GLuint index, GLdouble n, GLdouble f);
#endif /* FORGE_ARB_viewport_array */

#ifdef FORGE_KHR_blend_equation_advanced
#define GL_MULTIPLY_KHR                   0x9294
#define GL_SCREEN_KHR                     0x9295
#define GL_OVERLAY_KHR                    0x9296
#define GL_DARKEN_KHR                     0x9297
#define GL_LIGHTEN_KHR                    0x9298
#define GL_COLORDODGE_KHR                 0x9299
#define GL_COLORBURN_KHR                  0x929A
#define GL_HARDLIGHT_KHR                  0x929B
#define GL_SOFTLIGHT_KHR                  0x929C
#define GL_DIFFERENCE_KHR                 0x929E
#define GL_EXCLUSION_KHR                  0x92A0
#define GL_HSL_HUE_KHR                    0x92AD
#define GL_HSL_SATURATION_KHR             0x92AE
#define GL_HSL_COLOR_KHR                  0x92AF
#define GL_HSL_LUMINOSITY_KHR             0x92B0
typedef void (APIENTRYP PFNGLBLENDBARRIERKHRPROC) (void);
#endif /* FORGE_KHR_blend_equation_advanced */

#ifdef FORGE_KHR_blend_equation_advanced_coherent
#define GL_BLEND_ADVANCED_COHERENT_KHR    0x9285
#endif /* FORGE_KHR_blend_equation_advanced_coherent */

#ifdef FORGE_KHR_no_error
#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR  0x00000008
#endif /* FORGE_KHR_no_error */

#ifdef FORGE_KHR_parallel_shader_compile
#define GL_MAX_SHADER_COMPILER_THREADS_KHR 0x91B0
#define GL_COMPLETION_STATUS_KHR          0x91B1
typedef void (APIENTRYP PFNGLMAXSHADERCOMPILERTHREADSKHRPROC) (GLuint count);
#endif /* FORGE_KHR_parallel_shader_compile */

#ifdef FORGE_KHR_robustness
#define GL_CONTEXT_ROBUST_ACCESS          0x90F3
#endif /* FORGE_KHR_robustness */

#ifdef FORGE_KHR_shader_subgroup
#define GL_SUBGROUP_SIZE_KHR              0x9532
#define GL_SUBGROUP_SUPPORTED_STAGES_KHR  0x9533
#define GL_SUBGROUP_SUPPORTED_FEATURES_KHR 0x9534
#define GL_SUBGROUP_QUAD_ALL_STAGES_KHR   0x9535
#define GL_SUBGROUP_FEATURE_BASIC_BIT_KHR 0x00000001
#define GL_SUBGROUP_FEATURE_VOTE_BIT_KHR  0x00000002
#define GL_SUBGROUP_FEATURE_ARITHMETIC_BIT_KHR 0x00000004
#define GL_SUBGROUP_FEATURE_BALLOT_BIT_KHR 0x00000008
#define GL_SUBGROUP_FEATURE_SHUFFLE_BIT_KHR 0x00000010
#define GL_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT_KHR 0x00000020
#define GL_SUBGROUP_FEATURE_CLUSTERED_BIT_KHR 0x00000040
#define GL_SUBGROUP_FEATURE_QUAD_BIT_KHR  0x00000080
#endif /* FORGE_KHR_shader_subgroup */

#ifdef FORGE_KHR_texture_compression_astc_hdr
#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR   0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR   0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR   0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR   0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR   0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR   0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR   0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR   0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR  0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR  0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR  0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR 0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR 0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR 0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR 0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR 0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR 0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR 0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR 0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR 0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR 0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR 0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR 0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR 0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR 0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR 0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR 0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR 0x93DD
#endif /* FORGE_KHR_texture_compression_astc_hdr */

#ifdef FORGE_AMD_framebuffer_multisample_advanced
#define GL_RENDERBUFFER_STORAGE_SAMPLES_AMD 0x91B2
#define GL_MAX_COLOR_FRAMEBUFFER_SAMPLES_AMD 0x91B3
#define GL_MAX_COLOR_FRAMEBUFFER_STORAGE_SAMPLES_AMD 0x91B4
#define GL_MAX_DEPTH_STENCIL_FRAMEBUFFER_SAMPLES_AMD 0x91B5
#define GL_NUM_SUPPORTED_MULTISAMPLE_MODES_AMD 0x91B6
#define GL_SUPPORTED_MULTISAMPLE_MODES_AMD 0x91B7
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC) (GLenum target, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC) (GLuint renderbuffer, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height);
#endif /* FORGE_AMD_framebuffer_multisample_advanced */

#ifdef FORGE_AMD_performance_monitor
#define GL_COUNTER_TYPE_AMD               0x8BC0
#define GL_COUNTER_RANGE_AMD              0x8BC1
#define GL_UNSIGNED_INT64_AMD             0x8BC2
#define GL_PERCENTAGE_AMD                 0x8BC3
#define GL_PERFMON_RESULT_AVAILABLE_AMD   0x8BC4
#define GL_PERFMON_RESULT_SIZE_AMD        0x8BC5
#define GL_PERFMON_RESULT_AMD             0x8BC6
typedef void (APIENTRYP PFNGLGETPERFMONITORGROUPSAMDPROC) (GLint* numGroups, GLsizei groupsSize, GLuint* groups);
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERSAMDPROC) (GLuint group, GLint* numCounters, GLint* maxActiveCounters, GLsizei counterSize, GLuint* counters);
typedef void (APIENTRYP PFNGLGETPERFMONITORGROUPSTRINGAMDPROC) (GLuint group, GLsizei bufSize, GLsizei* length, GLchar* groupString);
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC) (GLuint group, GLuint counter, GLsizei bufSize, GLsizei* length, GLchar* counterString);
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERINFOAMDPROC) (GLuint group, GLuint counter, GLenum pname, void* data);
typedef void (APIENTRYP PFNGLGENPERFMONITORSAMDPROC) (GLsizei n, GLuint* monitors);
typedef void (APIENTRYP PFNGLDELETEPERFMONITORSAMDPROC) (GLsizei n, GLuint* monitors);
typedef void (APIENTRYP PFNGLSELECTPERFMONITORCOUNTERSAMDPROC) (GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint* counterList);
typedef void (APIENTRYP PFNGLBEGINPERFMONITORAMDPROC) (GLuint monitor);
typedef void (APIENTRYP PFNGLENDPERFMONITORAMDPROC) (GLuint monitor);
typedef void (APIENTRYP PFNGLGETPERFMONITORCOUNTERDATAAMDPROC) (GLuint monitor, GLenum pname, GLsizei dataSize, GLuint* data, GLint* bytesWritten);
#endif /* FORGE_AMD_performance_monitor */

#ifdef FORGE_APPLE_rgb_422
#define GL_RGB_422_APPLE                  0x8A1F
#define GL_UNSIGNED_SHORT_8_8_APPLE       0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE   0x85BB
#define GL_RGB_RAW_422_APPLE              0x8A51
#endif /* FORGE_APPLE_rgb_422 */

#ifdef FORGE_EXT_EGL_image_storage
typedef void* GLeglImageOES;
typedef void (APIENTRYP PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC) (GLenum target, GLeglImageOES image, const GLint* attrib_list);
typedef void (APIENTRYP PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC) (GLuint texture, GLeglImageOES image, const GLint* attrib_list);
#endif /* FORGE_EXT_EGL_image_storage */

#ifdef FORGE_EXT_debug_label
#define GL_PROGRAM_PIPELINE_OBJECT_EXT    0x8A4F
#define GL_PROGRAM_OBJECT_EXT             0x8B40
#define GL_SHADER_OBJECT_EXT              0x8B48
#define GL_BUFFER_OBJECT_EXT              0x9151
#define GL_QUERY_OBJECT_EXT               0x9153
#define GL_VERTEX_ARRAY_OBJECT_EXT        0x9154
typedef void (APIENTRYP PFNGLLABELOBJECTEXTPROC) (GLenum type, GLuint object, GLsizei length, const GLchar* label);
typedef void (APIENTRYP PFNGLGETOBJECTLABELEXTPROC) (GLenum type, GLuint object, GLsizei bufSize, GLsizei* length, GLchar* label);
#endif /* FORGE_EXT_debug_label */

#ifdef FORGE_EXT_debug_marker
typedef void (APIENTRYP PFNGLINSERTEVENTMARKEREXTPROC) (GLsizei length, const GLchar* marker);
typedef void (APIENTRYP PFNGLPUSHGROUPMARKEREXTPROC) (GLsizei length, const GLchar* marker);
typedef void (APIENTRYP PFNGLPOPGROUPMARKEREXTPROC) (void);
#endif /* FORGE_EXT_debug_marker */

#ifdef FORGE_EXT_direct_state_access
#define GL_PROGRAM_MATRIX_EXT             0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT   0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT 0x8E2F
typedef void (APIENTRYP PFNGLMATRIXLOADFEXTPROC) (GLenum mode, const GLfloat* m);
typedef void (APIENTRYP PFNGLMATRIXLOADDEXTPROC) (GLenum mode, const GLdouble* m);
typedef void (APIENTRYP PFNGLMATRIXMULTFEXTPROC) (GLenum mode, const GLfloat* m);
typedef void (APIENTRYP PFNGLMATRIXMULTDEXTPROC) (GLenum mode, const GLdouble* m);
typedef void (APIENTRYP PFNGLMATRIXLOADIDENTITYEXTPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLMATRIXROTATEFEXTPROC) (GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLMATRIXROTATEDEXTPROC) (GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLMATRIXSCALEFEXTPROC) (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLMATRIXSCALEDEXTPROC) (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLMATRIXTRANSLATEFEXTPROC) (GLenum mode, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLMATRIXTRANSLATEDEXTPROC) (GLenum mode, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLMATRIXFRUSTUMEXTPROC) (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLMATRIXORTHOEXTPROC) (GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLMATRIXPOPEXTPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLMATRIXPUSHEXTPROC) (GLenum mode);
typedef void (APIENTRYP PFNGLCLIENTATTRIBDEFAULTEXTPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC) (GLbitfield mask);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLfloat* params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLint* params);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLCOPYTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETTEXTUREIMAGEEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLTEXTUREIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLBINDMULTITEXTUREEXTPROC) (GLenum texunit, GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLMULTITEXCOORDPOINTEREXTPROC) (GLenum texunit, GLint size, GLenum type, GLsizei stride, const void* pointer);
typedef void (APIENTRYP PFNGLMULTITEXENVFEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLMULTITEXENVFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
typedef void (APIENTRYP PFNGLMULTITEXENVIEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLMULTITEXENVIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint* params);
typedef void (APIENTRYP PFNGLMULTITEXGENDEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
typedef void (APIENTRYP PFNGLMULTITEXGENDVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params);
typedef void (APIENTRYP PFNGLMULTITEXGENFEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLMULTITEXGENFVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params);
typedef void (APIENTRYP PFNGLMULTITEXGENIEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLMULTITEXGENIVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, const GLint* params);
typedef void (APIENTRYP PFNGLGETMULTITEXENVFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETMULTITEXENVIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETMULTITEXGENDVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLdouble* params);
typedef void (APIENTRYP PFNGLGETMULTITEXGENFVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETMULTITEXGENIVEXTPROC) (GLenum texunit, GLenum coord, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint* params);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERFEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLfloat* params);
typedef void (APIENTRYP PFNGLMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLCOPYMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (APIENTRYP PFNGLCOPYMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETMULTITEXIMAGEEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat* params);
typedef void (APIENTRYP PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLMULTITEXIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels);
typedef void (APIENTRYP PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEINDEXEDEXTPROC) (GLenum array, GLuint index);
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC) (GLenum array, GLuint index);
typedef void (APIENTRYP PFNGLGETFLOATINDEXEDVEXTPROC) (GLenum target, GLuint index, GLfloat* data);
typedef void (APIENTRYP PFNGLGETDOUBLEINDEXEDVEXTPROC) (GLenum target, GLuint index, GLdouble* data);
typedef void (APIENTRYP PFNGLGETPOINTERINDEXEDVEXTPROC) (GLenum target, GLuint index, void** data);
typedef void (APIENTRYP PFNGLENABLEINDEXEDEXTPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEINDEXEDEXTPROC) (GLenum target, GLuint index);
typedef GLboolean(APIENTRYP PFNGLISENABLEDINDEXEDEXTPROC) (GLenum target, GLuint index);
typedef void (APIENTRYP PFNGLGETINTEGERINDEXEDVEXTPROC) (GLenum target, GLuint index, GLint* data);
typedef void (APIENTRYP PFNGLGETBOOLEANINDEXEDVEXTPROC) (GLenum target, GLuint index, GLboolean* data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC) (GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* bits);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC) (GLuint texture, GLenum target, GLint lod, void* img);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* bits);
typedef void (APIENTRYP PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC) (GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* bits);
typedef void (APIENTRYP PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC) (GLenum texunit, GLenum target, GLint lod, void* img);
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEFEXTPROC) (GLenum mode, const GLfloat* m);
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSEDEXTPROC) (GLenum mode, const GLdouble* m);
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEFEXTPROC) (GLenum mode, const GLfloat* m);
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSEDEXTPROC) (GLenum mode, const GLdouble* m);
typedef void (APIENTRYP PFNGLNAMEDBUFFERDATAEXTPROC) (GLuint buffer, GLsizeiptr size, const void* data, GLenum usage);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data);
typedef void* (APIENTRYP PFNGLMAPNAMEDBUFFEREXTPROC) (GLuint buffer, GLenum access);
typedef GLboolean(APIENTRYP PFNGLUNMAPNAMEDBUFFEREXTPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC) (GLuint buffer, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPOINTERVEXTPROC) (GLuint buffer, GLenum pname, void** params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, void* data);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FEXTPROC) (GLuint program, GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FEXTPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FEXTPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FEXTPROC) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IEXTPROC) (GLuint program, GLint location, GLint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IEXTPROC) (GLuint program, GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IEXTPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IEXTPROC) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4FVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4IVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef void (APIENTRYP PFNGLTEXTUREBUFFEREXTPROC) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLMULTITEXBUFFEREXTPROC) (GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLint* params);
typedef void (APIENTRYP PFNGLTEXTUREPARAMETERIUIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, const GLuint* params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETTEXTUREPARAMETERIUIVEXTPROC) (GLuint texture, GLenum target, GLenum pname, GLuint* params);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLint* params);
typedef void (APIENTRYP PFNGLMULTITEXPARAMETERIUIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, const GLuint* params);
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETMULTITEXPARAMETERIUIVEXTPROC) (GLenum texunit, GLenum target, GLenum pname, GLuint* params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIEXTPROC) (GLuint program, GLint location, GLuint v0);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIEXTPROC) (GLuint program, GLint location, GLuint v0, GLuint v1);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIEXTPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIEXTPROC) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UIVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLuint* value);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat* params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC) (GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLint* params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLint* params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC) (GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLuint* params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint* params);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLint* params);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC) (GLuint program, GLenum target, GLuint index, GLuint* params);
typedef void (APIENTRYP PFNGLENABLECLIENTSTATEIEXTPROC) (GLenum array, GLuint index);
typedef void (APIENTRYP PFNGLDISABLECLIENTSTATEIEXTPROC) (GLenum array, GLuint index);
typedef void (APIENTRYP PFNGLGETFLOATI_VEXTPROC) (GLenum pname, GLuint index, GLfloat* params);
typedef void (APIENTRYP PFNGLGETDOUBLEI_VEXTPROC) (GLenum pname, GLuint index, GLdouble* params);
typedef void (APIENTRYP PFNGLGETPOINTERI_VEXTPROC) (GLenum pname, GLuint index, void** params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMSTRINGEXTPROC) (GLuint program, GLenum target, GLenum format, GLsizei len, const void* string);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC) (GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLdouble* params);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC) (GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC) (GLuint program, GLenum target, GLuint index, const GLfloat* params);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC) (GLuint program, GLenum target, GLuint index, GLdouble* params);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC) (GLuint program, GLenum target, GLuint index, GLfloat* params);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMIVEXTPROC) (GLuint program, GLenum target, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGETNAMEDPROGRAMSTRINGEXTPROC) (GLuint program, GLenum target, GLenum pname, void* string);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC) (GLuint renderbuffer, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC) (GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
typedef GLenum(APIENTRYP PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC) (GLuint framebuffer, GLenum target);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLGENERATETEXTUREMIPMAPEXTPROC) (GLuint texture, GLenum target);
typedef void (APIENTRYP PFNGLGENERATEMULTITEXMIPMAPEXTPROC) (GLenum texunit, GLenum target);
typedef void (APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC) (GLuint framebuffer, GLenum mode);
typedef void (APIENTRYP PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC) (GLuint framebuffer, GLsizei n, const GLenum* bufs);
typedef void (APIENTRYP PFNGLFRAMEBUFFERREADBUFFEREXTPROC) (GLuint framebuffer, GLenum mode);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
typedef void (APIENTRYP PFNGLTEXTURERENDERBUFFEREXTPROC) (GLuint texture, GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLMULTITEXRENDERBUFFEREXTPROC) (GLenum texunit, GLenum target, GLuint renderbuffer);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYCOLOROFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYINDEXOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYNORMALOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYEXTPROC) (GLuint vaobj, GLenum array);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYEXTPROC) (GLuint vaobj, GLenum array);
typedef void (APIENTRYP PFNGLENABLEVERTEXARRAYATTRIBEXTPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC) (GLuint vaobj, GLuint index);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINTEGERVEXTPROC) (GLuint vaobj, GLenum pname, GLint* param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYPOINTERVEXTPROC) (GLuint vaobj, GLenum pname, void** param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC) (GLuint vaobj, GLuint index, GLenum pname, GLint* param);
typedef void (APIENTRYP PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC) (GLuint vaobj, GLuint index, GLenum pname, void** param);
typedef void* (APIENTRYP PFNGLMAPNAMEDBUFFERRANGEEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (APIENTRYP PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC) (GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef void (APIENTRYP PFNGLNAMEDBUFFERSTORAGEEXTPROC) (GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERDATAEXTPROC) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data);
typedef void (APIENTRYP PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC) (GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC) (GLuint framebuffer, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC) (GLuint framebuffer, GLenum pname, GLint* params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DEXTPROC) (GLuint program, GLint location, GLdouble x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DEXTPROC) (GLuint program, GLint location, GLdouble x, GLdouble y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DEXTPROC) (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DEXTPROC) (GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1DVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2DVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3DVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4DVEXTPROC) (GLuint program, GLint location, GLsizei count, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC) (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value);
typedef void (APIENTRYP PFNGLTEXTUREBUFFERRANGEEXTPROC) (GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE1DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DEXTPROC) (GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC) (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC) (GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef void (APIENTRYP PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC) (GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef void (APIENTRYP PFNGLTEXTUREPAGECOMMITMENTEXTPROC) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
typedef void (APIENTRYP PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC) (GLuint vaobj, GLuint index, GLuint divisor);
#endif /* FORGE_EXT_direct_state_access */

#ifdef FORGE_EXT_draw_instanced
typedef void (APIENTRYP PFNGLDRAWARRAYSINSTANCEDEXTPROC) (GLenum mode, GLint start, GLsizei count, GLsizei primcount);
typedef void (APIENTRYP PFNGLDRAWELEMENTSINSTANCEDEXTPROC) (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei primcount);
#endif /* FORGE_EXT_draw_instanced */

#ifdef FORGE_EXT_polygon_offset_clamp
#define GL_POLYGON_OFFSET_CLAMP_EXT       0x8E1B
typedef void (APIENTRYP PFNGLPOLYGONOFFSETCLAMPEXTPROC) (GLfloat factor, GLfloat units, GLfloat clamp);
#endif /* FORGE_EXT_polygon_offset_clamp */

#ifdef FORGE_EXT_raster_multisample
#define GL_RASTER_MULTISAMPLE_EXT         0x9327
#define GL_RASTER_SAMPLES_EXT             0x9328
#define GL_MAX_RASTER_SAMPLES_EXT         0x9329
#define GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT 0x932A
#define GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT 0x932B
#define GL_EFFECTIVE_RASTER_SAMPLES_EXT   0x932C
typedef void (APIENTRYP PFNGLRASTERSAMPLESEXTPROC) (GLuint samples, GLboolean fixedsamplelocations);
#endif /* FORGE_EXT_raster_multisample */

#ifdef FORGE_EXT_separate_shader_objects
#define GL_ACTIVE_PROGRAM_EXT             0x8B8D
typedef void (APIENTRYP PFNGLUSESHADERPROGRAMEXTPROC) (GLenum type, GLuint program);
typedef void (APIENTRYP PFNGLACTIVEPROGRAMEXTPROC) (GLuint program);
typedef GLuint(APIENTRYP PFNGLCREATESHADERPROGRAMEXTPROC) (GLenum type, const GLchar* string);
#endif /* FORGE_EXT_separate_shader_objects */

#ifdef FORGE_EXT_shader_framebuffer_fetch
#define GL_FRAGMENT_SHADER_DISCARDS_SAMPLES_EXT 0x8A52
#endif /* FORGE_EXT_shader_framebuffer_fetch */

#ifdef FORGE_EXT_shader_framebuffer_fetch_non_coherent
#define GL_EXT_shader_framebuffer_fetch_non_coherent 1
typedef void (APIENTRYP PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC) (void);
#endif /* FORGE_EXT_shader_framebuffer_fetch_non_coherent */

#ifdef FORGE_EXT_texture_compression_s3tc
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT   0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT  0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT  0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT  0x83F3
#endif /* FORGE_EXT_texture_compression_s3tc */

#ifdef FORGE_EXT_texture_filter_minmax
#define GL_TEXTURE_REDUCTION_MODE_EXT     0x9366
#define GL_WEIGHTED_AVERAGE_EXT           0x9367
#endif /* FORGE_EXT_texture_filter_minmax */

#ifdef FORGE_EXT_texture_sRGB_R8
#define GL_SR8_EXT                        0x8FBD
#endif /* FORGE_EXT_texture_sRGB_R8 */

#ifdef FORGE_EXT_texture_sRGB_RG8
#define GL_SRG8_EXT                       0x8FBE
#endif /* FORGE_EXT_texture_sRGB_RG8 */

#ifdef FORGE_EXT_texture_sRGB_decode
#define GL_TEXTURE_SRGB_DECODE_EXT        0x8A48
#define GL_DECODE_EXT                     0x8A49
#define GL_SKIP_DECODE_EXT                0x8A4A
#endif /* FORGE_EXT_texture_sRGB_decode */

#ifdef FORGE_EXT_texture_storage
#define GL_TEXTURE_IMMUTABLE_FORMAT_EXT   0x912F
#define GL_ALPHA8_EXT                     0x803C
#define GL_LUMINANCE8_EXT                 0x8040
#define GL_LUMINANCE8_ALPHA8_EXT          0x8045
#define GL_RGBA32F_EXT                    0x8814
#define GL_RGB32F_EXT                     0x8815
#define GL_ALPHA32F_EXT                   0x8816
#define GL_LUMINANCE32F_EXT               0x8818
#define GL_LUMINANCE_ALPHA32F_EXT         0x8819
#define GL_RGBA16F_EXT                    0x881A
#define GL_RGB16F_EXT                     0x881B
#define GL_ALPHA16F_EXT                   0x881C
#define GL_LUMINANCE16F_EXT               0x881E
#define GL_LUMINANCE_ALPHA16F_EXT         0x881F
#define GL_RGB10_A2_EXT                   0x8059
#define GL_RGB10_EXT                      0x8052
#define GL_BGRA8_EXT                      0x93A1
#define GL_R8_EXT                         0x8229
#define GL_RG8_EXT                        0x822B
#define GL_R32F_EXT                       0x822E
#define GL_RG32F_EXT                      0x8230
#define GL_R16F_EXT                       0x822D
#define GL_RG16F_EXT                      0x822F
typedef void (APIENTRYP PFNGLTEXSTORAGE1DEXTPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef void (APIENTRYP PFNGLTEXSTORAGE2DEXTPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLTEXSTORAGE3DEXTPROC) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
#endif /* FORGE_EXT_texture_storage */

#ifdef FORGE_EXT_window_rectangles
#define GL_INCLUSIVE_EXT                  0x8F10
#define GL_EXCLUSIVE_EXT                  0x8F11
#define GL_WINDOW_RECTANGLE_EXT           0x8F12
#define GL_WINDOW_RECTANGLE_MODE_EXT      0x8F13
#define GL_MAX_WINDOW_RECTANGLES_EXT      0x8F14
#define GL_NUM_WINDOW_RECTANGLES_EXT      0x8F15
typedef void (APIENTRYP PFNGLWINDOWRECTANGLESEXTPROC) (GLenum mode, GLsizei count, const GLint* box);
#endif /* FORGE_EXT_window_rectangles */

#ifdef FORGE_INTEL_blackhole_render
#define GL_BLACKHOLE_RENDER_INTEL         0x83FC
#endif /* FORGE_INTEL_blackhole_render */

#ifdef FORGE_INTEL_conservative_rasterization
#define GL_CONSERVATIVE_RASTERIZATION_INTEL 0x83FE
#endif /* FORGE_INTEL_conservative_rasterization */

#ifdef FORGE_INTEL_framebuffer_CMAA
typedef void (APIENTRYP PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC) (void);
#endif /* FORGE_INTEL_framebuffer_CMAA */

#ifdef FORGE_INTEL_performance_query
#define GL_PERFQUERY_SINGLE_CONTEXT_INTEL 0x00000000
#define GL_PERFQUERY_GLOBAL_CONTEXT_INTEL 0x00000001
#define GL_PERFQUERY_WAIT_INTEL           0x83FB
#define GL_PERFQUERY_FLUSH_INTEL          0x83FA
#define GL_PERFQUERY_DONOT_FLUSH_INTEL    0x83F9
#define GL_PERFQUERY_COUNTER_EVENT_INTEL  0x94F0
#define GL_PERFQUERY_COUNTER_DURATION_NORM_INTEL 0x94F1
#define GL_PERFQUERY_COUNTER_DURATION_RAW_INTEL 0x94F2
#define GL_PERFQUERY_COUNTER_THROUGHPUT_INTEL 0x94F3
#define GL_PERFQUERY_COUNTER_RAW_INTEL    0x94F4
#define GL_PERFQUERY_COUNTER_TIMESTAMP_INTEL 0x94F5
#define GL_PERFQUERY_COUNTER_DATA_UINT32_INTEL 0x94F8
#define GL_PERFQUERY_COUNTER_DATA_UINT64_INTEL 0x94F9
#define GL_PERFQUERY_COUNTER_DATA_FLOAT_INTEL 0x94FA
#define GL_PERFQUERY_COUNTER_DATA_DOUBLE_INTEL 0x94FB
#define GL_PERFQUERY_COUNTER_DATA_BOOL32_INTEL 0x94FC
#define GL_PERFQUERY_QUERY_NAME_LENGTH_MAX_INTEL 0x94FD
#define GL_PERFQUERY_COUNTER_NAME_LENGTH_MAX_INTEL 0x94FE
#define GL_PERFQUERY_COUNTER_DESC_LENGTH_MAX_INTEL 0x94FF
#define GL_PERFQUERY_GPA_EXTENDED_COUNTERS_INTEL 0x9500
typedef void (APIENTRYP PFNGLBEGINPERFQUERYINTELPROC) (GLuint queryHandle);
typedef void (APIENTRYP PFNGLCREATEPERFQUERYINTELPROC) (GLuint queryId, GLuint* queryHandle);
typedef void (APIENTRYP PFNGLDELETEPERFQUERYINTELPROC) (GLuint queryHandle);
typedef void (APIENTRYP PFNGLENDPERFQUERYINTELPROC) (GLuint queryHandle);
typedef void (APIENTRYP PFNGLGETFIRSTPERFQUERYIDINTELPROC) (GLuint* queryId);
typedef void (APIENTRYP PFNGLGETNEXTPERFQUERYIDINTELPROC) (GLuint queryId, GLuint* nextQueryId);
typedef void (APIENTRYP PFNGLGETPERFCOUNTERINFOINTELPROC) (GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar* counterName, GLuint counterDescLength, GLchar* counterDesc, GLuint* counterOffset, GLuint* counterDataSize, GLuint* counterTypeEnum, GLuint* counterDataTypeEnum, GLuint64* rawCounterMaxValue);
typedef void (APIENTRYP PFNGLGETPERFQUERYDATAINTELPROC) (GLuint queryHandle, GLuint flags, GLsizei dataSize, void* data, GLuint* bytesWritten);
typedef void (APIENTRYP PFNGLGETPERFQUERYIDBYNAMEINTELPROC) (GLchar* queryName, GLuint* queryId);
typedef void (APIENTRYP PFNGLGETPERFQUERYINFOINTELPROC) (GLuint queryId, GLuint queryNameLength, GLchar* queryName, GLuint* dataSize, GLuint* noCounters, GLuint* noInstances, GLuint* capsMask);
#endif /* FORGE_INTEL_performance_query */

#ifdef FORGE_MESA_framebuffer_flip_x
#define GL_FRAMEBUFFER_FLIP_X_MESA        0x8BBC
#endif /* FORGE_MESA_framebuffer_flip_x */

#ifdef FORGE_MESA_framebuffer_flip_y
#define GL_FRAMEBUFFER_FLIP_Y_MESA        0x8BBB
typedef void (APIENTRYP PFNGLFRAMEBUFFERPARAMETERIMESAPROC) (GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC) (GLenum target, GLenum pname, GLint* params);
#endif /* FORGE_MESA_framebuffer_flip_y */

#ifdef FORGE_MESA_framebuffer_swap_xy
#define GL_FRAMEBUFFER_SWAP_XY_MESA       0x8BBD
#endif /* FORGE_MESA_framebuffer_swap_xy */

#ifdef FORGE_NV_bindless_multi_draw_indirect
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC) (GLenum mode, const void* indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC) (GLenum mode, GLenum type, const void* indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
#endif /* FORGE_NV_bindless_multi_draw_indirect */

#ifdef FORGE_NV_bindless_multi_draw_indirect_count
typedef void (APIENTRYP PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC) (GLenum mode, const void* indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
typedef void (APIENTRYP PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC) (GLenum mode, GLenum type, const void* indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
#endif /* FORGE_NV_bindless_multi_draw_indirect_count */

#ifdef FORGE_NV_bindless_texture
typedef GLuint64 (APIENTRYP PFNGLGETTEXTUREHANDLENVPROC) (GLuint texture);
typedef GLuint64 (APIENTRYP PFNGLGETTEXTURESAMPLERHANDLENVPROC) (GLuint texture, GLuint sampler);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTNVPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC) (GLuint64 handle);
typedef GLuint64(APIENTRYP PFNGLGETIMAGEHANDLENVPROC) (GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTNVPROC) (GLuint64 handle, GLenum access);
typedef void (APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC) (GLuint64 handle);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64NVPROC) (GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLUNIFORMHANDLEUI64VNVPROC) (GLint location, GLsizei count, const GLuint64* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC) (GLuint program, GLint location, GLuint64 value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64* values);
typedef GLboolean(APIENTRYP PFNGLISTEXTUREHANDLERESIDENTNVPROC) (GLuint64 handle);
typedef GLboolean(APIENTRYP PFNGLISIMAGEHANDLERESIDENTNVPROC) (GLuint64 handle);
#endif /* FORGE_NV_bindless_texture */

#ifdef FORGE_NV_blend_equation_advanced
#define GL_BLEND_OVERLAP_NV               0x9281
#define GL_BLEND_PREMULTIPLIED_SRC_NV     0x9280
#define GL_BLUE_NV                        0x1905
#define GL_COLORBURN_NV                   0x929A
#define GL_COLORDODGE_NV                  0x9299
#define GL_CONJOINT_NV                    0x9284
#define GL_CONTRAST_NV                    0x92A1
#define GL_DARKEN_NV                      0x9297
#define GL_DIFFERENCE_NV                  0x929E
#define GL_DISJOINT_NV                    0x9283
#define GL_DST_ATOP_NV                    0x928F
#define GL_DST_IN_NV                      0x928B
#define GL_DST_NV                         0x9287
#define GL_DST_OUT_NV                     0x928D
#define GL_DST_OVER_NV                    0x9289
#define GL_EXCLUSION_NV                   0x92A0
#define GL_GREEN_NV                       0x1904
#define GL_HARDLIGHT_NV                   0x929B
#define GL_HARDMIX_NV                     0x92A9
#define GL_HSL_COLOR_NV                   0x92AF
#define GL_HSL_HUE_NV                     0x92AD
#define GL_HSL_LUMINOSITY_NV              0x92B0
#define GL_HSL_SATURATION_NV              0x92AE
#define GL_INVERT_OVG_NV                  0x92B4
#define GL_INVERT_RGB_NV                  0x92A3
#define GL_LIGHTEN_NV                     0x9298
#define GL_LINEARBURN_NV                  0x92A5
#define GL_LINEARDODGE_NV                 0x92A4
#define GL_LINEARLIGHT_NV                 0x92A7
#define GL_MINUS_CLAMPED_NV               0x92B3
#define GL_MINUS_NV                       0x929F
#define GL_MULTIPLY_NV                    0x9294
#define GL_OVERLAY_NV                     0x9296
#define GL_PINLIGHT_NV                    0x92A8
#define GL_PLUS_CLAMPED_ALPHA_NV          0x92B2
#define GL_PLUS_CLAMPED_NV                0x92B1
#define GL_PLUS_DARKER_NV                 0x9292
#define GL_PLUS_NV                        0x9291
#define GL_RED_NV                         0x1903
#define GL_SCREEN_NV                      0x9295
#define GL_SOFTLIGHT_NV                   0x929C
#define GL_SRC_ATOP_NV                    0x928E
#define GL_SRC_IN_NV                      0x928A
#define GL_SRC_NV                         0x9286
#define GL_SRC_OUT_NV                     0x928C
#define GL_SRC_OVER_NV                    0x9288
#define GL_UNCORRELATED_NV                0x9282
#define GL_VIVIDLIGHT_NV                  0x92A6
#define GL_XOR_NV                         0x1506
typedef void (APIENTRYP PFNGLBLENDPARAMETERINVPROC) (GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLBLENDBARRIERNVPROC) (void);
#endif /* FORGE_NV_blend_equation_advanced */

#ifdef FORGE_NV_blend_equation_advanced_coherent
#define GL_BLEND_ADVANCED_COHERENT_NV     0x9285
#endif /* FORGE_NV_blend_equation_advanced_coherent */

#ifdef FORGE_NV_blend_minmax_factor
#define GL_FACTOR_MIN_AMD                 0x901C
#define GL_FACTOR_MAX_AMD                 0x901D
#endif /* FORGE_NV_blend_minmax_factor */

#ifdef FORGE_NV_clip_space_w_scaling
#define GL_VIEWPORT_POSITION_W_SCALE_NV   0x937C
#define GL_VIEWPORT_POSITION_W_SCALE_X_COEFF_NV 0x937D
#define GL_VIEWPORT_POSITION_W_SCALE_Y_COEFF_NV 0x937E
typedef void (APIENTRYP PFNGLVIEWPORTPOSITIONWSCALENVPROC) (GLuint index, GLfloat xcoeff, GLfloat ycoeff);
#endif /* FORGE_NV_clip_space_w_scaling */

#ifdef FORGE_NV_command_list
#define GL_TERMINATE_SEQUENCE_COMMAND_NV  0x0000
#define GL_NOP_COMMAND_NV                 0x0001
#define GL_DRAW_ELEMENTS_COMMAND_NV       0x0002
#define GL_DRAW_ARRAYS_COMMAND_NV         0x0003
#define GL_DRAW_ELEMENTS_STRIP_COMMAND_NV 0x0004
#define GL_DRAW_ARRAYS_STRIP_COMMAND_NV   0x0005
#define GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV 0x0006
#define GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV 0x0007
#define GL_ELEMENT_ADDRESS_COMMAND_NV     0x0008
#define GL_ATTRIBUTE_ADDRESS_COMMAND_NV   0x0009
#define GL_UNIFORM_ADDRESS_COMMAND_NV     0x000A
#define GL_BLEND_COLOR_COMMAND_NV         0x000B
#define GL_STENCIL_REF_COMMAND_NV         0x000C
#define GL_LINE_WIDTH_COMMAND_NV          0x000D
#define GL_POLYGON_OFFSET_COMMAND_NV      0x000E
#define GL_ALPHA_REF_COMMAND_NV           0x000F
#define GL_VIEWPORT_COMMAND_NV            0x0010
#define GL_SCISSOR_COMMAND_NV             0x0011
#define GL_FRONT_FACE_COMMAND_NV          0x0012
typedef void (APIENTRYP PFNGLCREATESTATESNVPROC) (GLsizei n, GLuint* states);
typedef void (APIENTRYP PFNGLDELETESTATESNVPROC) (GLsizei n, const GLuint* states);
typedef GLboolean(APIENTRYP PFNGLISSTATENVPROC) (GLuint state);
typedef void (APIENTRYP PFNGLSTATECAPTURENVPROC) (GLuint state, GLenum mode);
typedef GLuint(APIENTRYP PFNGLGETCOMMANDHEADERNVPROC) (GLenum tokenID, GLuint size);
typedef GLushort(APIENTRYP PFNGLGETSTAGEINDEXNVPROC) (GLenum shadertype);
typedef void (APIENTRYP PFNGLDRAWCOMMANDSNVPROC) (GLenum primitiveMode, GLuint buffer, const GLintptr* indirects, const GLsizei* sizes, GLuint count);
typedef void (APIENTRYP PFNGLDRAWCOMMANDSADDRESSNVPROC) (GLenum primitiveMode, const GLuint64* indirects, const GLsizei* sizes, GLuint count);
typedef void (APIENTRYP PFNGLDRAWCOMMANDSSTATESNVPROC) (GLuint buffer, const GLintptr* indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count);
typedef void (APIENTRYP PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC) (const GLuint64* indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count);
typedef void (APIENTRYP PFNGLCREATECOMMANDLISTSNVPROC) (GLsizei n, GLuint* lists);
typedef void (APIENTRYP PFNGLDELETECOMMANDLISTSNVPROC) (GLsizei n, const GLuint* lists);
typedef GLboolean(APIENTRYP PFNGLISCOMMANDLISTNVPROC) (GLuint list);
typedef void (APIENTRYP PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC) (GLuint list, GLuint segment, const void** indirects, const GLsizei* sizes, const GLuint* states, const GLuint* fbos, GLuint count);
typedef void (APIENTRYP PFNGLCOMMANDLISTSEGMENTSNVPROC) (GLuint list, GLuint segments);
typedef void (APIENTRYP PFNGLCOMPILECOMMANDLISTNVPROC) (GLuint list);
typedef void (APIENTRYP PFNGLCALLCOMMANDLISTNVPROC) (GLuint list);
#endif /* FORGE_NV_command_list */

#ifdef FORGE_NV_conditional_render
#define GL_QUERY_WAIT_NV                  0x8E13
#define GL_QUERY_NO_WAIT_NV               0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV        0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV     0x8E16
typedef void (APIENTRYP PFNGLBEGINCONDITIONALRENDERNVPROC) (GLuint id, GLenum mode);
typedef void (APIENTRYP PFNGLENDCONDITIONALRENDERNVPROC) (void);
#endif /* FORGE_NV_conditional_render */

#ifdef FORGE_NV_conservative_raster
#define GL_CONSERVATIVE_RASTERIZATION_NV  0x9346
#define GL_SUBPIXEL_PRECISION_BIAS_X_BITS_NV 0x9347
#define GL_SUBPIXEL_PRECISION_BIAS_Y_BITS_NV 0x9348
#define GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV 0x9349
typedef void (APIENTRYP PFNGLSUBPIXELPRECISIONBIASNVPROC) (GLuint xbits, GLuint ybits);
#endif /* FORGE_NV_conservative_raster */

#ifdef FORGE_NV_conservative_raster_dilate
#define GL_CONSERVATIVE_RASTER_DILATE_NV  0x9379
#define GL_CONSERVATIVE_RASTER_DILATE_RANGE_NV 0x937A
#define GL_CONSERVATIVE_RASTER_DILATE_GRANULARITY_NV 0x937B
typedef void (APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERFNVPROC) (GLenum pname, GLfloat value);
#endif /* FORGE_NV_conservative_raster_dilate */

#ifdef FORGE_NV_conservative_raster_pre_snap
#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_NV 0x9550
#endif /* FORGE_NV_conservative_raster_pre_snap */

#ifdef FORGE_NV_conservative_raster_pre_snap_triangles
#define GL_CONSERVATIVE_RASTER_MODE_NV    0x954D
#define GL_CONSERVATIVE_RASTER_MODE_POST_SNAP_NV 0x954E
#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_TRIANGLES_NV 0x954F
typedef void (APIENTRYP PFNGLCONSERVATIVERASTERPARAMETERINVPROC) (GLenum pname, GLint param);
#endif /* FORGE_NV_conservative_raster_pre_snap_triangles */

#ifdef FORGE_NV_depth_buffer_float
#define GL_DEPTH_COMPONENT32F_NV          0x8DAB
#define GL_DEPTH32F_STENCIL8_NV           0x8DAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV 0x8DAD
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV     0x8DAF
typedef void (APIENTRYP PFNGLDEPTHRANGEDNVPROC) (GLdouble zNear, GLdouble zFar);
typedef void (APIENTRYP PFNGLCLEARDEPTHDNVPROC) (GLdouble depth);
typedef void (APIENTRYP PFNGLDEPTHBOUNDSDNVPROC) (GLdouble zmin, GLdouble zmax);
#endif /* FORGE_NV_depth_buffer_float */

#ifdef FORGE_NV_draw_vulkan_image
typedef void (APIENTRY* GLVULKANPROCNV)(void);
typedef void (APIENTRYP PFNGLDRAWVKIMAGENVPROC) (GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
typedef GLVULKANPROCNV(APIENTRYP PFNGLGETVKPROCADDRNVPROC) (const GLchar* name);
typedef void (APIENTRYP PFNGLWAITVKSEMAPHORENVPROC) (GLuint64 vkSemaphore);
typedef void (APIENTRYP PFNGLSIGNALVKSEMAPHORENVPROC) (GLuint64 vkSemaphore);
typedef void (APIENTRYP PFNGLSIGNALVKFENCENVPROC) (GLuint64 vkFence);
#endif /* FORGE_NV_draw_vulkan_image */

#ifdef FORGE_NV_fill_rectangle
#define GL_FILL_RECTANGLE_NV              0x933C
#endif /* FORGE_NV_fill_rectangle */

#ifdef FORGE_NV_fragment_coverage_to_color
#define GL_FRAGMENT_COVERAGE_TO_COLOR_NV  0x92DD
#define GL_FRAGMENT_COVERAGE_COLOR_NV     0x92DE
typedef void (APIENTRYP PFNGLFRAGMENTCOVERAGECOLORNVPROC) (GLuint color);
#endif /* FORGE_NV_fragment_coverage_to_color */

#ifdef FORGE_NV_framebuffer_mixed_samples
#define GL_COVERAGE_MODULATION_TABLE_NV   0x9331
#define GL_COLOR_SAMPLES_NV               0x8E20
#define GL_DEPTH_SAMPLES_NV               0x932D
#define GL_STENCIL_SAMPLES_NV             0x932E
#define GL_MIXED_DEPTH_SAMPLES_SUPPORTED_NV 0x932F
#define GL_MIXED_STENCIL_SAMPLES_SUPPORTED_NV 0x9330
#define GL_COVERAGE_MODULATION_NV         0x9332
#define GL_COVERAGE_MODULATION_TABLE_SIZE_NV 0x9333
typedef void (APIENTRYP PFNGLCOVERAGEMODULATIONTABLENVPROC) (GLsizei n, const GLfloat* v);
typedef void (APIENTRYP PFNGLGETCOVERAGEMODULATIONTABLENVPROC) (GLsizei bufSize, GLfloat* v);
typedef void (APIENTRYP PFNGLCOVERAGEMODULATIONNVPROC) (GLenum components);
#endif /* FORGE_NV_framebuffer_mixed_samples */

#ifdef FORGE_NV_framebuffer_multisample_coverage
#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV 0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV  0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV 0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV  0x8E12
typedef void (APIENTRYP PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC) (GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
#endif /* FORGE_NV_framebuffer_multisample_coverage */

#ifdef FORGE_NV_gpu_shader5
typedef khronos_int64_t GLint64EXT;
#define GL_INT64_NV                       0x140E
#define GL_UNSIGNED_INT64_NV              0x140F
#define GL_INT8_NV                        0x8FE0
#define GL_INT8_VEC2_NV                   0x8FE1
#define GL_INT8_VEC3_NV                   0x8FE2
#define GL_INT8_VEC4_NV                   0x8FE3
#define GL_INT16_NV                       0x8FE4
#define GL_INT16_VEC2_NV                  0x8FE5
#define GL_INT16_VEC3_NV                  0x8FE6
#define GL_INT16_VEC4_NV                  0x8FE7
#define GL_INT64_VEC2_NV                  0x8FE9
#define GL_INT64_VEC3_NV                  0x8FEA
#define GL_INT64_VEC4_NV                  0x8FEB
#define GL_UNSIGNED_INT8_NV               0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV          0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV          0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV          0x8FEF
#define GL_UNSIGNED_INT16_NV              0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV         0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV         0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV         0x8FF3
#define GL_UNSIGNED_INT64_VEC2_NV         0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV         0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV         0x8FF7
#define GL_FLOAT16_NV                     0x8FF8
#define GL_FLOAT16_VEC2_NV                0x8FF9
#define GL_FLOAT16_VEC3_NV                0x8FFA
#define GL_FLOAT16_VEC4_NV                0x8FFB
typedef void (APIENTRYP PFNGLUNIFORM1I64NVPROC) (GLint location, GLint64EXT x);
typedef void (APIENTRYP PFNGLUNIFORM2I64NVPROC) (GLint location, GLint64EXT x, GLint64EXT y);
typedef void (APIENTRYP PFNGLUNIFORM3I64NVPROC) (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (APIENTRYP PFNGLUNIFORM4I64NVPROC) (GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (APIENTRYP PFNGLUNIFORM1I64VNVPROC) (GLint location, GLsizei count, const GLint64EXT* value);
typedef void (APIENTRYP PFNGLUNIFORM2I64VNVPROC) (GLint location, GLsizei count, const GLint64EXT* value);
typedef void (APIENTRYP PFNGLUNIFORM3I64VNVPROC) (GLint location, GLsizei count, const GLint64EXT* value);
typedef void (APIENTRYP PFNGLUNIFORM4I64VNVPROC) (GLint location, GLsizei count, const GLint64EXT* value);
typedef void (APIENTRYP PFNGLUNIFORM1UI64NVPROC) (GLint location, GLuint64EXT x);
typedef void (APIENTRYP PFNGLUNIFORM2UI64NVPROC) (GLint location, GLuint64EXT x, GLuint64EXT y);
typedef void (APIENTRYP PFNGLUNIFORM3UI64NVPROC) (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (APIENTRYP PFNGLUNIFORM4UI64NVPROC) (GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (APIENTRYP PFNGLUNIFORM1UI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (APIENTRYP PFNGLUNIFORM2UI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (APIENTRYP PFNGLUNIFORM3UI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (APIENTRYP PFNGLUNIFORM4UI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (APIENTRYP PFNGLGETUNIFORMI64VNVPROC) (GLuint program, GLint location, GLint64EXT* params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64NVPROC) (GLuint program, GLint location, GLint64EXT x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64NVPROC) (GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64NVPROC) (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64NVPROC) (GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1I64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2I64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3I64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4I64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLint64EXT* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64NVPROC) (GLuint program, GLint location, GLuint64EXT x);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64NVPROC) (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64NVPROC) (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64NVPROC) (GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM1UI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM2UI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM3UI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORM4UI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
#endif /* FORGE_NV_gpu_shader5 */

#ifdef FORGE_NV_internalformat_sample_query
#define GL_MULTISAMPLES_NV                0x9371
#define GL_SUPERSAMPLE_SCALE_X_NV         0x9372
#define GL_SUPERSAMPLE_SCALE_Y_NV         0x9373
#define GL_CONFORMANT_NV                  0x9374
typedef void (APIENTRYP PFNGLGETINTERNALFORMATSAMPLEIVNVPROC) (GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei count, GLint* params);
#endif /* FORGE_NV_internalformat_sample_query */

#ifdef FORGE_NV_memory_attachment
#define GL_ATTACHED_MEMORY_OBJECT_NV      0x95A4
#define GL_ATTACHED_MEMORY_OFFSET_NV      0x95A5
#define GL_MEMORY_ATTACHABLE_ALIGNMENT_NV 0x95A6
#define GL_MEMORY_ATTACHABLE_SIZE_NV      0x95A7
#define GL_MEMORY_ATTACHABLE_NV           0x95A8
#define GL_DETACHED_MEMORY_INCARNATION_NV 0x95A9
#define GL_DETACHED_TEXTURES_NV           0x95AA
#define GL_DETACHED_BUFFERS_NV            0x95AB
#define GL_MAX_DETACHED_TEXTURES_NV       0x95AC
#define GL_MAX_DETACHED_BUFFERS_NV        0x95AD
typedef void (APIENTRYP PFNGLGETMEMORYOBJECTDETACHEDRESOURCESUIVNVPROC) (GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint* params);
typedef void (APIENTRYP PFNGLRESETMEMORYOBJECTPARAMETERNVPROC) (GLuint memory, GLenum pname);
typedef void (APIENTRYP PFNGLTEXATTACHMEMORYNVPROC) (GLenum target, GLuint memory, GLuint64 offset);
typedef void (APIENTRYP PFNGLBUFFERATTACHMEMORYNVPROC) (GLenum target, GLuint memory, GLuint64 offset);
typedef void (APIENTRYP PFNGLTEXTUREATTACHMEMORYNVPROC) (GLuint texture, GLuint memory, GLuint64 offset);
typedef void (APIENTRYP PFNGLNAMEDBUFFERATTACHMEMORYNVPROC) (GLuint buffer, GLuint memory, GLuint64 offset);
#endif /* FORGE_NV_memory_attachment */

#ifdef FORGE_NV_memory_object_sparse
typedef void (APIENTRYP PFNGLBUFFERPAGECOMMITMENTMEMNVPROC) (GLenum target, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit);
typedef void (APIENTRYP PFNGLTEXPAGECOMMITMENTMEMNVPROC) (GLenum target, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit);
typedef void (APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTMEMNVPROC) (GLuint buffer, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit);
typedef void (APIENTRYP PFNGLTEXTUREPAGECOMMITMENTMEMNVPROC) (GLuint texture, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit);
#endif /* FORGE_NV_memory_object_sparse */

#ifdef FORGE_NV_mesh_shader
#define GL_NV_mesh_shader 1
#define GL_MESH_SHADER_NV                 0x9559
#define GL_TASK_SHADER_NV                 0x955A
#define GL_MAX_MESH_UNIFORM_BLOCKS_NV     0x8E60
#define GL_MAX_MESH_TEXTURE_IMAGE_UNITS_NV 0x8E61
#define GL_MAX_MESH_IMAGE_UNIFORMS_NV     0x8E62
#define GL_MAX_MESH_UNIFORM_COMPONENTS_NV 0x8E63
#define GL_MAX_MESH_ATOMIC_COUNTER_BUFFERS_NV 0x8E64
#define GL_MAX_MESH_ATOMIC_COUNTERS_NV    0x8E65
#define GL_MAX_MESH_SHADER_STORAGE_BLOCKS_NV 0x8E66
#define GL_MAX_COMBINED_MESH_UNIFORM_COMPONENTS_NV 0x8E67
#define GL_MAX_TASK_UNIFORM_BLOCKS_NV     0x8E68
#define GL_MAX_TASK_TEXTURE_IMAGE_UNITS_NV 0x8E69
#define GL_MAX_TASK_IMAGE_UNIFORMS_NV     0x8E6A
#define GL_MAX_TASK_UNIFORM_COMPONENTS_NV 0x8E6B
#define GL_MAX_TASK_ATOMIC_COUNTER_BUFFERS_NV 0x8E6C
#define GL_MAX_TASK_ATOMIC_COUNTERS_NV    0x8E6D
#define GL_MAX_TASK_SHADER_STORAGE_BLOCKS_NV 0x8E6E
#define GL_MAX_COMBINED_TASK_UNIFORM_COMPONENTS_NV 0x8E6F
#define GL_MAX_MESH_WORK_GROUP_INVOCATIONS_NV 0x95A2
#define GL_MAX_TASK_WORK_GROUP_INVOCATIONS_NV 0x95A3
#define GL_MAX_MESH_TOTAL_MEMORY_SIZE_NV  0x9536
#define GL_MAX_TASK_TOTAL_MEMORY_SIZE_NV  0x9537
#define GL_MAX_MESH_OUTPUT_VERTICES_NV    0x9538
#define GL_MAX_MESH_OUTPUT_PRIMITIVES_NV  0x9539
#define GL_MAX_TASK_OUTPUT_COUNT_NV       0x953A
#define GL_MAX_DRAW_MESH_TASKS_COUNT_NV   0x953D
#define GL_MAX_MESH_VIEWS_NV              0x9557
#define GL_MESH_OUTPUT_PER_VERTEX_GRANULARITY_NV 0x92DF
#define GL_MESH_OUTPUT_PER_PRIMITIVE_GRANULARITY_NV 0x9543
#define GL_MAX_MESH_WORK_GROUP_SIZE_NV    0x953B
#define GL_MAX_TASK_WORK_GROUP_SIZE_NV    0x953C
#define GL_MESH_WORK_GROUP_SIZE_NV        0x953E
#define GL_TASK_WORK_GROUP_SIZE_NV        0x953F
#define GL_MESH_VERTICES_OUT_NV           0x9579
#define GL_MESH_PRIMITIVES_OUT_NV         0x957A
#define GL_MESH_OUTPUT_TYPE_NV            0x957B
#define GL_UNIFORM_BLOCK_REFERENCED_BY_MESH_SHADER_NV 0x959C
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TASK_SHADER_NV 0x959D
#define GL_REFERENCED_BY_MESH_SHADER_NV   0x95A0
#define GL_REFERENCED_BY_TASK_SHADER_NV   0x95A1
#define GL_MESH_SHADER_BIT_NV             0x00000040
#define GL_TASK_SHADER_BIT_NV             0x00000080
#define GL_MESH_SUBROUTINE_NV             0x957C
#define GL_TASK_SUBROUTINE_NV             0x957D
#define GL_MESH_SUBROUTINE_UNIFORM_NV     0x957E
#define GL_TASK_SUBROUTINE_UNIFORM_NV     0x957F
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_MESH_SHADER_NV 0x959E
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TASK_SHADER_NV 0x959F
typedef void (APIENTRYP PFNGLDRAWMESHTASKSNVPROC) (GLuint first, GLuint count);
typedef void (APIENTRYP PFNGLDRAWMESHTASKSINDIRECTNVPROC) (GLintptr indirect);
typedef void (APIENTRYP PFNGLMULTIDRAWMESHTASKSINDIRECTNVPROC) (GLintptr indirect, GLsizei drawcount, GLsizei stride);
typedef void (APIENTRYP PFNGLMULTIDRAWMESHTASKSINDIRECTCOUNTNVPROC) (GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
#endif /* FORGE_NV_mesh_shader */

#ifdef FORGE_NV_path_rendering
#define GL_PATH_FORMAT_SVG_NV             0x9070
#define GL_PATH_FORMAT_PS_NV              0x9071
#define GL_STANDARD_FONT_NAME_NV          0x9072
#define GL_SYSTEM_FONT_NAME_NV            0x9073
#define GL_FILE_NAME_NV                   0x9074
#define GL_PATH_STROKE_WIDTH_NV           0x9075
#define GL_PATH_END_CAPS_NV               0x9076
#define GL_PATH_INITIAL_END_CAP_NV        0x9077
#define GL_PATH_TERMINAL_END_CAP_NV       0x9078
#define GL_PATH_JOIN_STYLE_NV             0x9079
#define GL_PATH_MITER_LIMIT_NV            0x907A
#define GL_PATH_DASH_CAPS_NV              0x907B
#define GL_PATH_INITIAL_DASH_CAP_NV       0x907C
#define GL_PATH_TERMINAL_DASH_CAP_NV      0x907D
#define GL_PATH_DASH_OFFSET_NV            0x907E
#define GL_PATH_CLIENT_LENGTH_NV          0x907F
#define GL_PATH_FILL_MODE_NV              0x9080
#define GL_PATH_FILL_MASK_NV              0x9081
#define GL_PATH_FILL_COVER_MODE_NV        0x9082
#define GL_PATH_STROKE_COVER_MODE_NV      0x9083
#define GL_PATH_STROKE_MASK_NV            0x9084
#define GL_COUNT_UP_NV                    0x9088
#define GL_COUNT_DOWN_NV                  0x9089
#define GL_PATH_OBJECT_BOUNDING_BOX_NV    0x908A
#define GL_CONVEX_HULL_NV                 0x908B
#define GL_BOUNDING_BOX_NV                0x908D
#define GL_TRANSLATE_X_NV                 0x908E
#define GL_TRANSLATE_Y_NV                 0x908F
#define GL_TRANSLATE_2D_NV                0x9090
#define GL_TRANSLATE_3D_NV                0x9091
#define GL_AFFINE_2D_NV                   0x9092
#define GL_AFFINE_3D_NV                   0x9094
#define GL_TRANSPOSE_AFFINE_2D_NV         0x9096
#define GL_TRANSPOSE_AFFINE_3D_NV         0x9098
#define GL_UTF8_NV                        0x909A
#define GL_UTF16_NV                       0x909B
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV 0x909C
#define GL_PATH_COMMAND_COUNT_NV          0x909D
#define GL_PATH_COORD_COUNT_NV            0x909E
#define GL_PATH_DASH_ARRAY_COUNT_NV       0x909F
#define GL_PATH_COMPUTED_LENGTH_NV        0x90A0
#define GL_PATH_FILL_BOUNDING_BOX_NV      0x90A1
#define GL_PATH_STROKE_BOUNDING_BOX_NV    0x90A2
#define GL_SQUARE_NV                      0x90A3
#define GL_ROUND_NV                       0x90A4
#define GL_TRIANGULAR_NV                  0x90A5
#define GL_BEVEL_NV                       0x90A6
#define GL_MITER_REVERT_NV                0x90A7
#define GL_MITER_TRUNCATE_NV              0x90A8
#define GL_SKIP_MISSING_GLYPH_NV          0x90A9
#define GL_USE_MISSING_GLYPH_NV           0x90AA
#define GL_PATH_ERROR_POSITION_NV         0x90AB
#define GL_ACCUM_ADJACENT_PAIRS_NV        0x90AD
#define GL_ADJACENT_PAIRS_NV              0x90AE
#define GL_FIRST_TO_REST_NV               0x90AF
#define GL_PATH_GEN_MODE_NV               0x90B0
#define GL_PATH_GEN_COEFF_NV              0x90B1
#define GL_PATH_GEN_COMPONENTS_NV         0x90B3
#define GL_PATH_STENCIL_FUNC_NV           0x90B7
#define GL_PATH_STENCIL_REF_NV            0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV     0x90B9
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV 0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV 0x90BE
#define GL_PATH_COVER_DEPTH_FUNC_NV       0x90BF
#define GL_PATH_DASH_OFFSET_RESET_NV      0x90B4
#define GL_MOVE_TO_RESETS_NV              0x90B5
#define GL_MOVE_TO_CONTINUES_NV           0x90B6
#define GL_CLOSE_PATH_NV                  0x00
#define GL_MOVE_TO_NV                     0x02
#define GL_RELATIVE_MOVE_TO_NV            0x03
#define GL_LINE_TO_NV                     0x04
#define GL_RELATIVE_LINE_TO_NV            0x05
#define GL_HORIZONTAL_LINE_TO_NV          0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV 0x07
#define GL_VERTICAL_LINE_TO_NV            0x08
#define GL_RELATIVE_VERTICAL_LINE_TO_NV   0x09
#define GL_QUADRATIC_CURVE_TO_NV          0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV 0x0B
#define GL_CUBIC_CURVE_TO_NV              0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO_NV     0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV   0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV 0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO_NV       0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV 0x11
#define GL_SMALL_CCW_ARC_TO_NV            0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV   0x13
#define GL_SMALL_CW_ARC_TO_NV             0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV    0x15
#define GL_LARGE_CCW_ARC_TO_NV            0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV   0x17
#define GL_LARGE_CW_ARC_TO_NV             0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV    0x19
#define GL_RESTART_PATH_NV                0xF0
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV    0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV     0xF4
#define GL_RECT_NV                        0xF6
#define GL_CIRCULAR_CCW_ARC_TO_NV         0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV          0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV     0xFC
#define GL_ARC_TO_NV                      0xFE
#define GL_RELATIVE_ARC_TO_NV             0xFF
#define GL_BOLD_BIT_NV                    0x01
#define GL_ITALIC_BIT_NV                  0x02
#define GL_GLYPH_WIDTH_BIT_NV             0x01
#define GL_GLYPH_HEIGHT_BIT_NV            0x02
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV 0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV 0x08
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV 0x10
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV 0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV 0x40
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV 0x80
#define GL_GLYPH_HAS_KERNING_BIT_NV       0x100
#define GL_FONT_X_MIN_BOUNDS_BIT_NV       0x00010000
#define GL_FONT_Y_MIN_BOUNDS_BIT_NV       0x00020000
#define GL_FONT_X_MAX_BOUNDS_BIT_NV       0x00040000
#define GL_FONT_Y_MAX_BOUNDS_BIT_NV       0x00080000
#define GL_FONT_UNITS_PER_EM_BIT_NV       0x00100000
#define GL_FONT_ASCENDER_BIT_NV           0x00200000
#define GL_FONT_DESCENDER_BIT_NV          0x00400000
#define GL_FONT_HEIGHT_BIT_NV             0x00800000
#define GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV  0x01000000
#define GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV 0x02000000
#define GL_FONT_UNDERLINE_POSITION_BIT_NV 0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_BIT_NV 0x08000000
#define GL_FONT_HAS_KERNING_BIT_NV        0x10000000
#define GL_ROUNDED_RECT_NV                0xE8
#define GL_RELATIVE_ROUNDED_RECT_NV       0xE9
#define GL_ROUNDED_RECT2_NV               0xEA
#define GL_RELATIVE_ROUNDED_RECT2_NV      0xEB
#define GL_ROUNDED_RECT4_NV               0xEC
#define GL_RELATIVE_ROUNDED_RECT4_NV      0xED
#define GL_ROUNDED_RECT8_NV               0xEE
#define GL_RELATIVE_ROUNDED_RECT8_NV      0xEF
#define GL_RELATIVE_RECT_NV               0xF7
#define GL_FONT_GLYPHS_AVAILABLE_NV       0x9368
#define GL_FONT_TARGET_UNAVAILABLE_NV     0x9369
#define GL_FONT_UNAVAILABLE_NV            0x936A
#define GL_FONT_UNINTELLIGIBLE_NV         0x936B
#define GL_CONIC_CURVE_TO_NV              0x1A
#define GL_RELATIVE_CONIC_CURVE_TO_NV     0x1B
#define GL_FONT_NUM_GLYPH_INDICES_BIT_NV  0x20000000
#define GL_STANDARD_FONT_FORMAT_NV        0x936C
#define GL_PATH_PROJECTION_NV             0x1701
#define GL_PATH_MODELVIEW_NV              0x1700
#define GL_PATH_MODELVIEW_STACK_DEPTH_NV  0x0BA3
#define GL_PATH_MODELVIEW_MATRIX_NV       0x0BA6
#define GL_PATH_MAX_MODELVIEW_STACK_DEPTH_NV 0x0D36
#define GL_PATH_TRANSPOSE_MODELVIEW_MATRIX_NV 0x84E3
#define GL_PATH_PROJECTION_STACK_DEPTH_NV 0x0BA4
#define GL_PATH_PROJECTION_MATRIX_NV      0x0BA7
#define GL_PATH_MAX_PROJECTION_STACK_DEPTH_NV 0x0D38
#define GL_PATH_TRANSPOSE_PROJECTION_MATRIX_NV 0x84E4
#define GL_FRAGMENT_INPUT_NV              0x936D
typedef GLuint(APIENTRYP PFNGLGENPATHSNVPROC) (GLsizei range);
typedef void (APIENTRYP PFNGLDELETEPATHSNVPROC) (GLuint path, GLsizei range);
typedef GLboolean(APIENTRYP PFNGLISPATHNVPROC) (GLuint path);
typedef void (APIENTRYP PFNGLPATHCOMMANDSNVPROC) (GLuint path, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const void* coords);
typedef void (APIENTRYP PFNGLPATHCOORDSNVPROC) (GLuint path, GLsizei numCoords, GLenum coordType, const void* coords);
typedef void (APIENTRYP PFNGLPATHSUBCOMMANDSNVPROC) (GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const void* coords);
typedef void (APIENTRYP PFNGLPATHSUBCOORDSNVPROC) (GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void* coords);
typedef void (APIENTRYP PFNGLPATHSTRINGNVPROC) (GLuint path, GLenum format, GLsizei length, const void* pathString);
typedef void (APIENTRYP PFNGLPATHGLYPHSNVPROC) (GLuint firstPathName, GLenum fontTarget, const void* fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void* charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFNGLPATHGLYPHRANGENVPROC) (GLuint firstPathName, GLenum fontTarget, const void* fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFNGLWEIGHTPATHSNVPROC) (GLuint resultPath, GLsizei numPaths, const GLuint* paths, const GLfloat* weights);
typedef void (APIENTRYP PFNGLCOPYPATHNVPROC) (GLuint resultPath, GLuint srcPath);
typedef void (APIENTRYP PFNGLINTERPOLATEPATHSNVPROC) (GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
typedef void (APIENTRYP PFNGLTRANSFORMPATHNVPROC) (GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat* transformValues);
typedef void (APIENTRYP PFNGLPATHPARAMETERIVNVPROC) (GLuint path, GLenum pname, const GLint* value);
typedef void (APIENTRYP PFNGLPATHPARAMETERINVPROC) (GLuint path, GLenum pname, GLint value);
typedef void (APIENTRYP PFNGLPATHPARAMETERFVNVPROC) (GLuint path, GLenum pname, const GLfloat* value);
typedef void (APIENTRYP PFNGLPATHPARAMETERFNVPROC) (GLuint path, GLenum pname, GLfloat value);
typedef void (APIENTRYP PFNGLPATHDASHARRAYNVPROC) (GLuint path, GLsizei dashCount, const GLfloat* dashArray);
typedef void (APIENTRYP PFNGLPATHSTENCILFUNCNVPROC) (GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLPATHSTENCILDEPTHOFFSETNVPROC) (GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFNGLSTENCILFILLPATHNVPROC) (GLuint path, GLenum fillMode, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILSTROKEPATHNVPROC) (GLuint path, GLint reference, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILFILLPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat* transformValues);
typedef void (APIENTRYP PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat* transformValues);
typedef void (APIENTRYP PFNGLPATHCOVERDEPTHFUNCNVPROC) (GLenum func);
typedef void (APIENTRYP PFNGLCOVERFILLPATHNVPROC) (GLuint path, GLenum coverMode);
typedef void (APIENTRYP PFNGLCOVERSTROKEPATHNVPROC) (GLuint path, GLenum coverMode);
typedef void (APIENTRYP PFNGLCOVERFILLPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
typedef void (APIENTRYP PFNGLCOVERSTROKEPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
typedef void (APIENTRYP PFNGLGETPATHPARAMETERIVNVPROC) (GLuint path, GLenum pname, GLint* value);
typedef void (APIENTRYP PFNGLGETPATHPARAMETERFVNVPROC) (GLuint path, GLenum pname, GLfloat* value);
typedef void (APIENTRYP PFNGLGETPATHCOMMANDSNVPROC) (GLuint path, GLubyte* commands);
typedef void (APIENTRYP PFNGLGETPATHCOORDSNVPROC) (GLuint path, GLfloat* coords);
typedef void (APIENTRYP PFNGLGETPATHDASHARRAYNVPROC) (GLuint path, GLfloat* dashArray);
typedef void (APIENTRYP PFNGLGETPATHMETRICSNVPROC) (GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLsizei stride, GLfloat* metrics);
typedef void (APIENTRYP PFNGLGETPATHMETRICRANGENVPROC) (GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat* metrics);
typedef void (APIENTRYP PFNGLGETPATHSPACINGNVPROC) (GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat* returnedSpacing);
typedef GLboolean(APIENTRYP PFNGLISPOINTINFILLPATHNVPROC) (GLuint path, GLuint mask, GLfloat x, GLfloat y);
typedef GLboolean(APIENTRYP PFNGLISPOINTINSTROKEPATHNVPROC) (GLuint path, GLfloat x, GLfloat y);
typedef GLfloat(APIENTRYP PFNGLGETPATHLENGTHNVPROC) (GLuint path, GLsizei startSegment, GLsizei numSegments);
typedef GLboolean(APIENTRYP PFNGLPOINTALONGPATHNVPROC) (GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat* x, GLfloat* y, GLfloat* tangentX, GLfloat* tangentY);
typedef void (APIENTRYP PFNGLMATRIXLOAD3X2FNVPROC) (GLenum matrixMode, const GLfloat* m);
typedef void (APIENTRYP PFNGLMATRIXLOAD3X3FNVPROC) (GLenum matrixMode, const GLfloat* m);
typedef void (APIENTRYP PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC) (GLenum matrixMode, const GLfloat* m);
typedef void (APIENTRYP PFNGLMATRIXMULT3X2FNVPROC) (GLenum matrixMode, const GLfloat* m);
typedef void (APIENTRYP PFNGLMATRIXMULT3X3FNVPROC) (GLenum matrixMode, const GLfloat* m);
typedef void (APIENTRYP PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC) (GLenum matrixMode, const GLfloat* m);
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHNVPROC) (GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC) (GLuint path, GLint reference, GLuint mask, GLenum coverMode);
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
typedef void (APIENTRYP PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC) (GLsizei numPaths, GLenum pathNameType, const void* paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat* transformValues);
typedef GLenum(APIENTRYP PFNGLPATHGLYPHINDEXRANGENVPROC) (GLenum fontTarget, const void* fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint* baseAndCount);
typedef GLenum(APIENTRYP PFNGLPATHGLYPHINDEXARRAYNVPROC) (GLuint firstPathName, GLenum fontTarget, const void* fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef GLenum(APIENTRYP PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC) (GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void* fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef void (APIENTRYP PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC) (GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat* coeffs);
typedef void (APIENTRYP PFNGLGETPROGRAMRESOURCEFVNVPROC) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLfloat* params);
#endif /* FORGE_NV_path_rendering */

#ifdef FORGE_NV_path_rendering_shared_edge
#define GL_SHARED_EDGE_NV                 0xC0
#endif /* FORGE_NV_path_rendering_shared_edge */

#ifdef FORGE_NV_primitive_shading_rate
#define GL_SHADING_RATE_IMAGE_PER_PRIMITIVE_NV 0x95B1
#define GL_SHADING_RATE_IMAGE_PALETTE_COUNT_NV 0x95B2
#endif /* FORGE_NV_primitive_shading_rate */

#ifdef FORGE_NV_representative_fragment_test
#define GL_REPRESENTATIVE_FRAGMENT_TEST_NV 0x937F
#endif /* FORGE_NV_representative_fragment_test */

#ifdef FORGE_NV_sample_locations
#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_NV 0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_NV 0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_NV 0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_NV 0x9340
#define GL_SAMPLE_LOCATION_NV             0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_NV 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_NV 0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_NV 0x9343
typedef void (APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC) (GLenum target, GLuint start, GLsizei count, const GLfloat* v);
typedef void (APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC) (GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v);
typedef void (APIENTRYP PFNGLRESOLVEDEPTHVALUESNVPROC) (void);
#endif /* FORGE_NV_sample_locations */

#ifdef FORGE_NV_scissor_exclusive
#define GL_SCISSOR_TEST_EXCLUSIVE_NV      0x9555
#define GL_SCISSOR_BOX_EXCLUSIVE_NV       0x9556
typedef void (APIENTRYP PFNGLSCISSOREXCLUSIVENVPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSCISSOREXCLUSIVEARRAYVNVPROC) (GLuint first, GLsizei count, const GLint* v);
#endif /* FORGE_NV_scissor_exclusive */

#ifdef FORGE_NV_scissor_exclusive
#define GL_BUFFER_GPU_ADDRESS_NV          0x8F1D
#define GL_GPU_ADDRESS_NV                 0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV   0x8F35
typedef void (APIENTRYP PFNGLMAKEBUFFERRESIDENTNVPROC) (GLenum target, GLenum access);
typedef void (APIENTRYP PFNGLMAKEBUFFERNONRESIDENTNVPROC) (GLenum target);
typedef GLboolean(APIENTRYP PFNGLISBUFFERRESIDENTNVPROC) (GLenum target);
typedef void (APIENTRYP PFNGLMAKENAMEDBUFFERRESIDENTNVPROC) (GLuint buffer, GLenum access);
typedef void (APIENTRYP PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC) (GLuint buffer);
typedef GLboolean(APIENTRYP PFNGLISNAMEDBUFFERRESIDENTNVPROC) (GLuint buffer);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERUI64VNVPROC) (GLenum target, GLenum pname, GLuint64EXT* params);
typedef void (APIENTRYP PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC) (GLuint buffer, GLenum pname, GLuint64EXT* params);
typedef void (APIENTRYP PFNGLGETINTEGERUI64VNVPROC) (GLenum value, GLuint64EXT* result);
typedef void (APIENTRYP PFNGLUNIFORMUI64NVPROC) (GLint location, GLuint64EXT value);
typedef void (APIENTRYP PFNGLUNIFORMUI64VNVPROC) (GLint location, GLsizei count, const GLuint64EXT* value);
typedef void (APIENTRYP PFNGLGETUNIFORMUI64VNVPROC) (GLuint program, GLint location, GLuint64EXT* params);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMUI64NVPROC) (GLuint program, GLint location, GLuint64EXT value);
typedef void (APIENTRYP PFNGLPROGRAMUNIFORMUI64VNVPROC) (GLuint program, GLint location, GLsizei count, const GLuint64EXT* value);
#endif /* FORGE_NV_scissor_exclusive */

#ifdef FORGE_NV_shader_buffer_store
#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV 0x00000010
#endif /* FORGE_NV_shader_buffer_store */

#ifdef FORGE_NV_shader_subgroup_partitioned
#define GL_SUBGROUP_FEATURE_PARTITIONED_BIT_NV 0x00000100
#endif /* FORGE_NV_shader_subgroup_partitioned */

#ifdef FORGE_NV_shader_thread_group
#define GL_WARP_SIZE_NV                   0x9339
#define GL_WARPS_PER_SM_NV                0x933A
#define GL_SM_COUNT_NV                    0x933B
#endif /* FORGE_NV_shader_thread_group */

#ifdef FORGE_NV_shading_rate_image
#define GL_SHADING_RATE_IMAGE_NV          0x9563
#define GL_SHADING_RATE_NO_INVOCATIONS_NV 0x9564
#define GL_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV 0x9565
#define GL_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV 0x9566
#define GL_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV 0x9567
#define GL_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV 0x9568
#define GL_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV 0x9569
#define GL_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV 0x956A
#define GL_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV 0x956B
#define GL_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV 0x956C
#define GL_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV 0x956D
#define GL_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV 0x956E
#define GL_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV 0x956F
#define GL_SHADING_RATE_IMAGE_BINDING_NV  0x955B
#define GL_SHADING_RATE_IMAGE_TEXEL_WIDTH_NV 0x955C
#define GL_SHADING_RATE_IMAGE_TEXEL_HEIGHT_NV 0x955D
#define GL_SHADING_RATE_IMAGE_PALETTE_SIZE_NV 0x955E
#define GL_MAX_COARSE_FRAGMENT_SAMPLES_NV 0x955F
#define GL_SHADING_RATE_SAMPLE_ORDER_DEFAULT_NV 0x95AE
#define GL_SHADING_RATE_SAMPLE_ORDER_PIXEL_MAJOR_NV 0x95AF
#define GL_SHADING_RATE_SAMPLE_ORDER_SAMPLE_MAJOR_NV 0x95B0
typedef void (APIENTRYP PFNGLBINDSHADINGRATEIMAGENVPROC) (GLuint texture);
typedef void (APIENTRYP PFNGLGETSHADINGRATEIMAGEPALETTENVPROC) (GLuint viewport, GLuint entry, GLenum* rate);
typedef void (APIENTRYP PFNGLGETSHADINGRATESAMPLELOCATIONIVNVPROC) (GLenum rate, GLuint samples, GLuint index, GLint* location);
typedef void (APIENTRYP PFNGLSHADINGRATEIMAGEBARRIERNVPROC) (GLboolean synchronize);
typedef void (APIENTRYP PFNGLSHADINGRATEIMAGEPALETTENVPROC) (GLuint viewport, GLuint first, GLsizei count, const GLenum* rates);
typedef void (APIENTRYP PFNGLSHADINGRATESAMPLEORDERNVPROC) (GLenum order);
typedef void (APIENTRYP PFNGLSHADINGRATESAMPLEORDERCUSTOMNVPROC) (GLenum rate, GLuint samples, const GLint* locations);
#endif /* FORGE_NV_shading_rate_image */

#ifdef FORGE_NV_texture_barrier
typedef void (APIENTRYP PFNGLTEXTUREBARRIERNVPROC) (void);
#endif /* FORGE_NV_texture_barrier */

#ifdef FORGE_NV_uniform_buffer_unified_memory
#define GL_UNIFORM_BUFFER_UNIFIED_NV      0x936E
#define GL_UNIFORM_BUFFER_ADDRESS_NV      0x936F
#define GL_UNIFORM_BUFFER_LENGTH_NV       0x9370
#endif /* FORGE_NV_uniform_buffer_unified_memory */

#ifdef FORGE_NV_vertex_attrib_integer_64bit
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1I64NVPROC) (GLuint index, GLint64EXT x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2I64NVPROC) (GLuint index, GLint64EXT x, GLint64EXT y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3I64NVPROC) (GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4I64NVPROC) (GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1I64VNVPROC) (GLuint index, const GLint64EXT* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2I64VNVPROC) (GLuint index, const GLint64EXT* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3I64VNVPROC) (GLuint index, const GLint64EXT* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4I64VNVPROC) (GLuint index, const GLint64EXT* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64NVPROC) (GLuint index, GLuint64EXT x);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2UI64NVPROC) (GLuint index, GLuint64EXT x, GLuint64EXT y);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3UI64NVPROC) (GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4UI64NVPROC) (GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL1UI64VNVPROC) (GLuint index, const GLuint64EXT* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL2UI64VNVPROC) (GLuint index, const GLuint64EXT* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL3UI64VNVPROC) (GLuint index, const GLuint64EXT* v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBL4UI64VNVPROC) (GLuint index, const GLuint64EXT* v);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLI64VNVPROC) (GLuint index, GLenum pname, GLint64EXT* params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBLUI64VNVPROC) (GLuint index, GLenum pname, GLuint64EXT* params);
typedef void (APIENTRYP PFNGLVERTEXATTRIBLFORMATNVPROC) (GLuint index, GLint size, GLenum type, GLsizei stride);
#endif /* FORGE_NV_vertex_attrib_integer_64bit */

#ifdef FORGE_NV_vertex_buffer_unified_memory
#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV 0x8F1E
#define GL_ELEMENT_ARRAY_UNIFIED_NV       0x8F1F
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV 0x8F20
#define GL_VERTEX_ARRAY_ADDRESS_NV        0x8F21
#define GL_NORMAL_ARRAY_ADDRESS_NV        0x8F22
#define GL_COLOR_ARRAY_ADDRESS_NV         0x8F23
#define GL_INDEX_ARRAY_ADDRESS_NV         0x8F24
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV 0x8F25
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV     0x8F26
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV 0x8F27
#define GL_FOG_COORD_ARRAY_ADDRESS_NV     0x8F28
#define GL_ELEMENT_ARRAY_ADDRESS_NV       0x8F29
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV  0x8F2A
#define GL_VERTEX_ARRAY_LENGTH_NV         0x8F2B
#define GL_NORMAL_ARRAY_LENGTH_NV         0x8F2C
#define GL_COLOR_ARRAY_LENGTH_NV          0x8F2D
#define GL_INDEX_ARRAY_LENGTH_NV          0x8F2E
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV  0x8F2F
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV      0x8F30
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV 0x8F31
#define GL_FOG_COORD_ARRAY_LENGTH_NV      0x8F32
#define GL_ELEMENT_ARRAY_LENGTH_NV        0x8F33
#define GL_DRAW_INDIRECT_UNIFIED_NV       0x8F40
#define GL_DRAW_INDIRECT_ADDRESS_NV       0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV        0x8F42
typedef void (APIENTRYP PFNGLBUFFERADDRESSRANGENVPROC) (GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
typedef void (APIENTRYP PFNGLVERTEXFORMATNVPROC) (GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLNORMALFORMATNVPROC) (GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLCOLORFORMATNVPROC) (GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLINDEXFORMATNVPROC) (GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLTEXCOORDFORMATNVPROC) (GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLEDGEFLAGFORMATNVPROC) (GLsizei stride);
typedef void (APIENTRYP PFNGLSECONDARYCOLORFORMATNVPROC) (GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLFOGCOORDFORMATNVPROC) (GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBFORMATNVPROC) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
typedef void (APIENTRYP PFNGLVERTEXATTRIBIFORMATNVPROC) (GLuint index, GLint size, GLenum type, GLsizei stride);
typedef void (APIENTRYP PFNGLGETINTEGERUI64I_VNVPROC) (GLenum value, GLuint index, GLuint64EXT* result);
#endif /* FORGE_NV_vertex_buffer_unified_memory */

#ifdef FORGE_NV_viewport_swizzle
#define GL_VIEWPORT_SWIZZLE_POSITIVE_X_NV 0x9350
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_X_NV 0x9351
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Y_NV 0x9352
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Y_NV 0x9353
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Z_NV 0x9354
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Z_NV 0x9355
#define GL_VIEWPORT_SWIZZLE_POSITIVE_W_NV 0x9356
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_W_NV 0x9357
#define GL_VIEWPORT_SWIZZLE_X_NV          0x9358
#define GL_VIEWPORT_SWIZZLE_Y_NV          0x9359
#define GL_VIEWPORT_SWIZZLE_Z_NV          0x935A
#define GL_VIEWPORT_SWIZZLE_W_NV          0x935B
typedef void (APIENTRYP PFNGLVIEWPORTSWIZZLENVPROC) (GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
#endif /* FORGE_NV_viewport_swizzle */

#ifdef FORGE_OVR_multiview
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_OVR 0x9630
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_OVR 0x9632
#define GL_MAX_VIEWS_OVR                  0x9631
#define GL_FRAMEBUFFER_INCOMPLETE_VIEW_TARGETS_OVR 0x9633
typedef void (APIENTRYP PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
#endif /* FORGE_OVR_multiview */

/**
 * 
 * 
 * Function declerations
 * 
 * 
 */

#ifdef FORGE_GL_VERSION(1, 0)
	FORGE_GL_DECL_FUNCTION(PFNGLCULLFACEPROC, glCullFace)               
	FORGE_GL_DECL_FUNCTION(PFNGLFRONTFACEPROC, glFrontFace)              
	FORGE_GL_DECL_FUNCTION(PFNGLHINTPROC, glHint)                   
	FORGE_GL_DECL_FUNCTION(PFNGLLINEWIDTHPROC, glLineWidth)              
	FORGE_GL_DECL_FUNCTION(PFNGLPOINTSIZEPROC, glPointSize)              
	FORGE_GL_DECL_FUNCTION(PFNGLPOLYGONMODEPROC, glPolygonMode)            
	FORGE_GL_DECL_FUNCTION(PFNGLSCISSORPROC, glScissor)                
	FORGE_GL_DECL_FUNCTION(PFNGLTEXPARAMETERFPROC, glTexParameterf)          
	FORGE_GL_DECL_FUNCTION(PFNGLTEXPARAMETERFVPROC, glTexParameterfv)         
	FORGE_GL_DECL_FUNCTION(PFNGLTEXPARAMETERIPROC, glTexParameteri)          
	FORGE_GL_DECL_FUNCTION(PFNGLTEXPARAMETERIVPROC, glTexParameteriv)         
	FORGE_GL_DECL_FUNCTION(PFNGLTEXIMAGE1DPROC, glTexImage1D)             
	FORGE_GL_DECL_FUNCTION(PFNGLTEXIMAGE2DPROC, glTexImage2D)             
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWBUFFERPROC, glDrawBuffer)             
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARPROC, glClear)                  
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARCOLORPROC, glClearColor)            
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARSTENCILPROC, glClearStencil)           
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARDEPTHPROC, glClearDepth)             
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILMASKPROC, glStencilMask)            
	FORGE_GL_DECL_FUNCTION(PFNGLCOLORMASKPROC, glColorMask)              
	FORGE_GL_DECL_FUNCTION(PFNGLDEPTHMASKPROC, glDepthMask)              
	FORGE_GL_DECL_FUNCTION(PFNGLDISABLEPROC, glDisable)                
	FORGE_GL_DECL_FUNCTION(PFNGLENABLEPROC, glEnable)                 
	FORGE_GL_DECL_FUNCTION(PFNGLFINISHPROC, glFinish)                 
	FORGE_GL_DECL_FUNCTION(PFNGLFLUSHPROC, glFlush)                  
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDFUNCPROC, glBlendFunc)              
	FORGE_GL_DECL_FUNCTION(PFNGLLOGICOPPROC, glLogicOp)                
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILFUNCPROC, glStencilFunc)            
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILOPPROC, glStencilOp)              
	FORGE_GL_DECL_FUNCTION(PFNGLDEPTHFUNCPROC, glDepthFunc)              
	FORGE_GL_DECL_FUNCTION(PFNGLPIXELSTOREFPROC, glPixelStoref)            
	FORGE_GL_DECL_FUNCTION(PFNGLPIXELSTOREIPROC, glPixelStorei)            
	FORGE_GL_DECL_FUNCTION(PFNGLREADPIXELSPROC, glReadPixels)             
	FORGE_GL_DECL_FUNCTION(PFNGLGETBOOLEANVPROC, glGetBooleanv)            
	FORGE_GL_DECL_FUNCTION(PFNGLGETDOUBLEVPROC, glGetDoublev)             
	FORGE_GL_DECL_FUNCTION(PFNGLGETERRORPROC, glGetError)               
	FORGE_GL_DECL_FUNCTION(PFNGLGETFLOATVPROC, glGetFloatv)              
	FORGE_GL_DECL_FUNCTION(PFNGLGETINTEGERVPROC, glGetIntegerv)            
	FORGE_GL_DECL_FUNCTION(PFNGLGETSTRINGPROC, glGetString)              
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXIMAGEPROC, glGetTexImage)            
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXPARAMETERFVPROC, glGetTexParameterfv)      
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXPARAMETERIVPROC, glGetTexParameteriv)      
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXLEVELPARAMETERFVPROC, glGetTexLevelParameterfv) 
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXLEVELPARAMETERIVPROC, glGetTexLevelParameteriv) 
	FORGE_GL_DECL_FUNCTION(PFNGLISENABLEDPROC, glIsEnabled)              
	FORGE_GL_DECL_FUNCTION(PFNGLDEPTHRANGEPROC, glDepthRange)             
	FORGE_GL_DECL_FUNCTION(PFNGLVIEWPORTPROC, glViewport)
#endif /* GL_VERSION_1_0 */

#ifdef FORGE_GL_VERSION(1, 1)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWARRAYSPROC, glDrawArrays)       
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWELEMENTSPROC, glDrawElements)     
	FORGE_GL_DECL_FUNCTION(PFNGLGETPOINTERVPROC, glGetPointerv)      
	FORGE_GL_DECL_FUNCTION(PFNGLPOLYGONOFFSETPROC, glPolygonOffset)     
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXIMAGE1DPROC, glCopyTexImage1D)    
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXIMAGE2DPROC, glCopyTexImage2D)    
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXSUBIMAGE1DPROC, glCopyTexSubImage1D) 
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXSUBIMAGE2DPROC, glCopyTexSubImage2D) 
	FORGE_GL_DECL_FUNCTION(PFNGLTEXSUBIMAGE1DPROC, glTexSubImage1D)     
	FORGE_GL_DECL_FUNCTION(PFNGLTEXSUBIMAGE2DPROC, glTexSubImage2D)     
	FORGE_GL_DECL_FUNCTION(PFNGLBINDTEXTUREPROC, glBindTexture)       
	FORGE_GL_DECL_FUNCTION(PFNGLDELETETEXTURESPROC, glDeleteTextures)    
	FORGE_GL_DECL_FUNCTION(PFNGLGENTEXTURESPROC, glGenTextures)       
	FORGE_GL_DECL_FUNCTION(PFNGLISTEXTUREPROC, glIsTexture)
#endif /* GL_VERSION_1_1 */

#ifdef FORGE_GL_VERSION(1, 2)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWRANGEELEMENTSPROC, glDrawRangeElements) 
	FORGE_GL_DECL_FUNCTION(PFNGLTEXIMAGE3DPROC, glTexImage3D)        
	FORGE_GL_DECL_FUNCTION(PFNGLTEXSUBIMAGE3DPROC, glTexSubImage3D)     
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXSUBIMAGE3DPROC, glCopyTexSubImage3D)
#endif /* GL_VERSION_1_2 */

#ifdef FORGE_GL_VERSION(1, 3)
	FORGE_GL_DECL_FUNCTION(PFNGLACTIVETEXTUREPROC, glActiveTexture)
	FORGE_GL_DECL_FUNCTION(PFNGLSAMPLECOVERAGEPROC, glSampleCoverage)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXIMAGE3DPROC, glCompressedTexImage3D)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXIMAGE2DPROC, glCompressedTexImage2D)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXIMAGE1DPROC, glCompressedTexImage1D) 
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC, glCompressedTexSubImage3D)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC, glCompressedTexSubImage2D)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC, glCompressedTexSubImage1D)
	FORGE_GL_DECL_FUNCTION(PFNGLGETCOMPRESSEDTEXIMAGEPROC, glGetCompressedTexImage)
#endif /* GL_VERSION_1_3 */

#ifdef FORGE_GL_VERSION(1, 4)
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDFUNCSEPARATEPROC, glBlendFuncSeparate)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWARRAYSPROC, glMultiDrawArrays)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWELEMENTSPROC, glMultiDrawElements)
	FORGE_GL_DECL_FUNCTION(PFNGLPOINTPARAMETERFPROC, glPointParameterf)
	FORGE_GL_DECL_FUNCTION(PFNGLPOINTPARAMETERFVPROC, glPointParameterfv)
	FORGE_GL_DECL_FUNCTION(PFNGLPOINTPARAMETERIPROC, glPointParameteri)
	FORGE_GL_DECL_FUNCTION(PFNGLPOINTPARAMETERIVPROC, glPointParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDCOLORPROC, glBlendColor)
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDEQUATIONPROC, glBlendEquation)
#endif /* GL_VERSION_1_4 */

#ifdef FORGE_GL_VERSION(1, 5)
	FORGE_GL_DECL_FUNCTION(PFNGLGENQUERIESPROC, glGenQueries)       
	FORGE_GL_DECL_FUNCTION(PFNGLDELETEQUERIESPROC, glDeleteQueries)
	FORGE_GL_DECL_FUNCTION(PFNGLISQUERYPROC, glIsQuery)
	FORGE_GL_DECL_FUNCTION(PFNGLBEGINQUERYPROC, glBeginQuery)
	FORGE_GL_DECL_FUNCTION(PFNGLENDQUERYPROC, glEndQuery)
	FORGE_GL_DECL_FUNCTION(PFNGLGETQUERYIVPROC, glGetQueryiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETQUERYOBJECTIVPROC, glGetQueryObjectiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETQUERYOBJECTUIVPROC, glGetQueryObjectuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDBUFFERPROC, glBindBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETEBUFFERSPROC, glDeleteBuffers)
	FORGE_GL_DECL_FUNCTION(PFNGLGENBUFFERSPROC, glGenBuffers)
	FORGE_GL_DECL_FUNCTION(PFNGLISBUFFERPROC, glIsBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLBUFFERDATAPROC, glBufferData)
	FORGE_GL_DECL_FUNCTION(PFNGLBUFFERSUBDATAPROC, glBufferSubData)
	FORGE_GL_DECL_FUNCTION(PFNGLGETBUFFERSUBDATAPROC, glGetBufferSubData)
	FORGE_GL_DECL_FUNCTION(PFNGLMAPBUFFERPROC, glMapBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLUNMAPBUFFERPROC, glUnmapBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLGETBUFFERPARAMETERIVPROC, glGetBufferParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETBUFFERPOINTERVPROC, glGetBufferPointerv)
#endif /* GL_VERSION_1_5 */

#ifdef FORGE_GL_VERSION(2, 0)
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDEQUATIONSEPARATEPROC, glBlendEquationSeparate)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWBUFFERSPROC, glDrawBuffers)
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILOPSEPARATEPROC, glStencilOpSeparate)
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILFUNCSEPARATEPROC, glStencilFuncSeparate)
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILMASKSEPARATEPROC, glStencilMaskSeparate)
	FORGE_GL_DECL_FUNCTION(PFNGLATTACHSHADERPROC, glAttachShader)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDATTRIBLOCATIONPROC, glBindAttribLocation)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPILESHADERPROC, glCompileShader)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATEPROGRAMPROC, glCreateProgram)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATESHADERPROC, glCreateShader)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETEPROGRAMPROC, glDeleteProgram)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETESHADERPROC, glDeleteShader)
	FORGE_GL_DECL_FUNCTION(PFNGLDETACHSHADERPROC, glDetachShader)
	FORGE_GL_DECL_FUNCTION(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray)
	FORGE_GL_DECL_FUNCTION(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray)
	FORGE_GL_DECL_FUNCTION(PFNGLGETACTIVEATTRIBPROC, glGetActiveAttrib)
	FORGE_GL_DECL_FUNCTION(PFNGLGETACTIVEUNIFORMPROC, glGetActiveUniform)
	FORGE_GL_DECL_FUNCTION(PFNGLGETATTACHEDSHADERSPROC, glGetAttachedShaders)
	FORGE_GL_DECL_FUNCTION(PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMIVPROC, glGetProgramiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSHADERIVPROC, glGetShaderiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSHADERSOURCEPROC, glGetShaderSource)
	FORGE_GL_DECL_FUNCTION(PFNGLGETUNIFORMLOCATIONPROC, glGetUniformLocation)
	FORGE_GL_DECL_FUNCTION(PFNGLGETUNIFORMFVPROC, glGetUniformfv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETUNIFORMIVPROC, glGetUniformiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXATTRIBDVPROC, glGetVertexAttribdv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXATTRIBFVPROC, glGetVertexAttribfv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXATTRIBIVPROC, glGetVertexAttribiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXATTRIBPOINTERVPROC, glGetVertexAttribPointerv)
	FORGE_GL_DECL_FUNCTION(PFNGLISPROGRAMPROC, glIsProgram)
	FORGE_GL_DECL_FUNCTION(PFNGLISSHADERPROC, glIsShader)
	FORGE_GL_DECL_FUNCTION(PFNGLLINKPROGRAMPROC, glLinkProgram)
	FORGE_GL_DECL_FUNCTION(PFNGLSHADERSOURCEPROC, glShaderSource)
	FORGE_GL_DECL_FUNCTION(PFNGLUSEPROGRAMPROC, glUseProgram)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1FPROC, glUniform1f)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2FPROC, glUniform2f)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3FPROC, glUniform3f)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4FPROC, glUniform4f)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1IPROC, glUniform1i)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2IPROC, glUniform2i)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3IPROC, glUniform3i)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4IPROC, glUniform4i)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1FVPROC, glUniform1fv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2FVPROC, glUniform2fv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3FVPROC, glUniform3fv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4FVPROC, glUniform4fv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1IVPROC, glUniform1iv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2IVPROC, glUniform2iv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3IVPROC, glUniform3iv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4IVPROC, glUniform4iv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX2FVPROC, glUniformMatrix2fv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX3FVPROC, glUniformMatrix3fv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX4FVPROC, glUniformMatrix4fv)
	FORGE_GL_DECL_FUNCTION(PFNGLVALIDATEPROGRAMPROC, glValidateProgram)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB1DPROC, glVertexAttrib1d)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB1DVPROC, glVertexAttrib1dv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB1FPROC, glVertexAttrib1f)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB1FVPROC, glVertexAttrib1fv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB1SPROC, glVertexAttrib1s)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB1SVPROC, glVertexAttrib1sv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB2DPROC, glVertexAttrib2d)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB2DVPROC, glVertexAttrib2dv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB2FPROC, glVertexAttrib2f)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB2FVPROC, glVertexAttrib2fv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB2SPROC, glVertexAttrib2s)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB2SVPROC, glVertexAttrib2sv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB3DPROC, glVertexAttrib3d)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB3DVPROC, glVertexAttrib3dv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB3FPROC, glVertexAttrib3f)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB3FVPROC, glVertexAttrib3fv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB3SPROC, glVertexAttrib3s)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB3SVPROC, glVertexAttrib3sv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4NBVPROC, glVertexAttrib4Nbv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4NIVPROC, glVertexAttrib4Niv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4NSVPROC, glVertexAttrib4Nsv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4NUBPROC, glVertexAttrib4Nub)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4NUBVPROC, glVertexAttrib4Nubv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4NUIVPROC, glVertexAttrib4Nuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4NUSVPROC, glVertexAttrib4Nusv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4BVPROC, glVertexAttrib4bv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4DPROC, glVertexAttrib4d)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4DVPROC, glVertexAttrib4dv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4FPROC, glVertexAttrib4f)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4FVPROC, glVertexAttrib4fv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4IVPROC, glVertexAttrib4iv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4SPROC, glVertexAttrib4s)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4SVPROC, glVertexAttrib4sv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4UBVPROC, glVertexAttrib4ubv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4UIVPROC, glVertexAttrib4uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIB4USVPROC, glVertexAttrib4usv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer)
#endif /* GL_VERSION_2_0 */

#ifdef FORGE_GL_VERSION(2, 1)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX2X3FVPROC, glUniformMatrix2x3fv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX3X2FVPROC, glUniformMatrix3x2fv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX2X4FVPROC, glUniformMatrix2x4fv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX4X2FVPROC, glUniformMatrix4x2fv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX3X4FVPROC, glUniformMatrix3x4fv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX4X3FVPROC, glUniformMatrix4x3fv)
#endif /* GL_VERSION_2_1 */

#ifdef FORGE_GL_VERSION(3, 0)
	FORGE_GL_DECL_FUNCTION(PFNGLCOLORMASKIPROC, glColorMaski)
	FORGE_GL_DECL_FUNCTION(PFNGLGETBOOLEANI_VPROC, glGetBooleani_v)
	FORGE_GL_DECL_FUNCTION(PFNGLGETINTEGERI_VPROC, glGetIntegeri_v)
	FORGE_GL_DECL_FUNCTION(PFNGLENABLEIPROC, glEnablei)
	FORGE_GL_DECL_FUNCTION(PFNGLDISABLEIPROC, glDisablei)
	FORGE_GL_DECL_FUNCTION(PFNGLISENABLEDIPROC, glIsEnabledi)
	FORGE_GL_DECL_FUNCTION(PFNGLBEGINTRANSFORMFEEDBACKPROC, glBeginTransformFeedback)
	FORGE_GL_DECL_FUNCTION(PFNGLENDTRANSFORMFEEDBACKPROC, glEndTransformFeedback)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDBUFFERRANGEPROC, glBindBufferRange)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDBUFFERBASEPROC, glBindBufferBase)
	FORGE_GL_DECL_FUNCTION(PFNGLTRANSFORMFEEDBACKVARYINGSPROC, glTransformFeedbackVaryings)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC, glGetTransformFeedbackVarying)
	FORGE_GL_DECL_FUNCTION(PFNGLCLAMPCOLORPROC, glClampColor)
	FORGE_GL_DECL_FUNCTION(PFNGLBEGINCONDITIONALRENDERPROC, glBeginConditionalRender)
	FORGE_GL_DECL_FUNCTION(PFNGLENDCONDITIONALRENDERPROC, glEndConditionalRender)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBIPOINTERPROC, glVertexAttribIPointer)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXATTRIBIIVPROC, glGetVertexAttribIiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXATTRIBIUIVPROC, glGetVertexAttribIuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI1IPROC, glVertexAttribI1i)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI2IPROC, glVertexAttribI2i)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI3IPROC, glVertexAttribI3i)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI4IPROC, glVertexAttribI4i)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI1UIPROC, glVertexAttribI1ui)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI2UIPROC, glVertexAttribI2ui)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI3UIPROC, glVertexAttribI3ui)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI4UIPROC, glVertexAttribI4ui)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI1IVPROC, glVertexAttribI1iv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI2IVPROC, glVertexAttribI2iv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI3IVPROC, glVertexAttribI3iv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI4IVPROC, glVertexAttribI4iv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI1UIVPROC, glVertexAttribI1uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI2UIVPROC, glVertexAttribI2uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI3UIVPROC, glVertexAttribI3uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI4UIVPROC, glVertexAttribI4uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI4BVPROC, glVertexAttribI4bv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI4SVPROC, glVertexAttribI4sv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI4UBVPROC, glVertexAttribI4ubv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBI4USVPROC, glVertexAttribI4usv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETUNIFORMUIVPROC, glGetUniformuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDFRAGDATALOCATIONPROC, glBindFragDataLocation)
	FORGE_GL_DECL_FUNCTION(PFNGLGETFRAGDATALOCATIONPROC, glGetFragDataLocation)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1UIPROC, glUniform1ui)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2UIPROC, glUniform2ui)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3UIPROC, glUniform3ui)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4UIPROC, glUniform4ui)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1UIVPROC, glUniform1uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2UIVPROC, glUniform2uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3UIVPROC, glUniform3uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4UIVPROC, glUniform4uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXPARAMETERIIVPROC, glTexParameterIiv)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXPARAMETERIUIVPROC, glTexParameterIuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXPARAMETERIIVPROC, glGetTexParameterIiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXPARAMETERIUIVPROC, glGetTexParameterIuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARBUFFERIVPROC, glClearBufferiv)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARBUFFERUIVPROC, glClearBufferuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARBUFFERFVPROC, glClearBufferfv)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARBUFFERFIPROC, glClearBufferfi)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSTRINGIPROC, glGetStringi)
	FORGE_GL_DECL_FUNCTION(PFNGLISRENDERBUFFERPROC, glIsRenderbuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETERENDERBUFFERSPROC, glDeleteRenderbuffers)
	FORGE_GL_DECL_FUNCTION(PFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers)
	FORGE_GL_DECL_FUNCTION(PFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage)
	FORGE_GL_DECL_FUNCTION(PFNGLGETRENDERBUFFERPARAMETERIVPROC, glGetRenderbufferParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLISFRAMEBUFFERPROC, glIsFramebuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffers)
	FORGE_GL_DECL_FUNCTION(PFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers)
	FORGE_GL_DECL_FUNCTION(PFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERTEXTURE1DPROC, glFramebufferTexture1D)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERTEXTURE3DPROC, glFramebufferTexture3D)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetFramebufferAttachmentParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLGENERATEMIPMAPPROC, glGenerateMipmap)
	FORGE_GL_DECL_FUNCTION(PFNGLBLITFRAMEBUFFERPROC, glBlitFramebuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, glRenderbufferStorageMultisample)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERTEXTURELAYERPROC, glFramebufferTextureLayer)
	FORGE_GL_DECL_FUNCTION(PFNGLMAPBUFFERRANGEPROC, glMapBufferRange)
	FORGE_GL_DECL_FUNCTION(PFNGLFLUSHMAPPEDBUFFERRANGEPROC, glFlushMappedBufferRange)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDVERTEXARRAYPROC, glBindVertexArray)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays)
	FORGE_GL_DECL_FUNCTION(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays)
	FORGE_GL_DECL_FUNCTION(PFNGLISVERTEXARRAYPROC, glIsVertexArray)
#endif /* GL_VERSION_3_0 */

#ifdef FORGE_GL_VERSION(3, 1)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWARRAYSINSTANCEDPROC, glDrawArraysInstanced)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWELEMENTSINSTANCEDPROC, glDrawElementsInstanced)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXBUFFERPROC, glTexBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLPRIMITIVERESTARTINDEXPROC, glPrimitiveRestartIndex)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYBUFFERSUBDATAPROC, glCopyBufferSubData)
	FORGE_GL_DECL_FUNCTION(PFNGLGETUNIFORMINDICESPROC, glGetUniformIndices)
	FORGE_GL_DECL_FUNCTION(PFNGLGETACTIVEUNIFORMSIVPROC, glGetActiveUniformsiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETACTIVEUNIFORMNAMEPROC, glGetActiveUniformName)
	FORGE_GL_DECL_FUNCTION(PFNGLGETUNIFORMBLOCKINDEXPROC, glGetUniformBlockIndex)
	FORGE_GL_DECL_FUNCTION(PFNGLGETACTIVEUNIFORMBLOCKIVPROC, glGetActiveUniformBlockiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC, glGetActiveUniformBlockName)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMBLOCKBINDINGPROC, glUniformBlockBinding)
#endif /* GL_VERSION_3_1 */

#ifdef FORGE_GL_VERSION(3, 2)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWELEMENTSBASEVERTEXPROC, glDrawElementsBaseVertex)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC, glDrawRangeElementsBaseVertex)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC, glDrawElementsInstancedBaseVertex)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC, glMultiDrawElementsBaseVertex)
	FORGE_GL_DECL_FUNCTION(PFNGLPROVOKINGVERTEXPROC, glProvokingVertex)
	FORGE_GL_DECL_FUNCTION(PFNGLFENCESYNCPROC, glFenceSync)
	FORGE_GL_DECL_FUNCTION(PFNGLISSYNCPROC, glIsSync)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETESYNCPROC, glDeleteSync)
	FORGE_GL_DECL_FUNCTION(PFNGLCLIENTWAITSYNCPROC, glClientWaitSync)
	FORGE_GL_DECL_FUNCTION(PFNGLWAITSYNCPROC, glWaitSync)
	FORGE_GL_DECL_FUNCTION(PFNGLGETINTEGER64VPROC, glGetInteger64v)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSYNCIVPROC, glGetSynciv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETINTEGER64I_VPROC, glGetInteger64i_v)
	FORGE_GL_DECL_FUNCTION(PFNGLGETBUFFERPARAMETERI64VPROC, glGetBufferParameteri64v)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERTEXTUREPROC, glFramebufferTexture)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXIMAGE2DMULTISAMPLEPROC, glTexImage2DMultisample)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXIMAGE3DMULTISAMPLEPROC, glTexImage3DMultisample)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTISAMPLEFVPROC, glGetMultisamplefv)
	FORGE_GL_DECL_FUNCTION(PFNGLSAMPLEMASKIPROC, glSampleMaski)
#endif /* GL_VERSION_3_2 */

#ifdef FORGE_GL_VERSION(3, 3)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDFRAGDATALOCATIONINDEXEDPROC, glBindFragDataLocationIndexed)
	FORGE_GL_DECL_FUNCTION(PFNGLGETFRAGDATAINDEXPROC, glGetFragDataIndex)
	FORGE_GL_DECL_FUNCTION(PFNGLGENSAMPLERSPROC, glGenSamplers)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETESAMPLERSPROC, glDeleteSamplers)
	FORGE_GL_DECL_FUNCTION(PFNGLISSAMPLERPROC, glIsSampler)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDSAMPLERPROC, glBindSampler)
	FORGE_GL_DECL_FUNCTION(PFNGLSAMPLERPARAMETERIPROC, glSamplerParameteri)
	FORGE_GL_DECL_FUNCTION(PFNGLSAMPLERPARAMETERIVPROC, glSamplerParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLSAMPLERPARAMETERFPROC, glSamplerParameterf)
	FORGE_GL_DECL_FUNCTION(PFNGLSAMPLERPARAMETERFVPROC, glSamplerParameterfv)
	FORGE_GL_DECL_FUNCTION(PFNGLSAMPLERPARAMETERIIVPROC, glSamplerParameterIiv)
	FORGE_GL_DECL_FUNCTION(PFNGLSAMPLERPARAMETERIUIVPROC, glSamplerParameterIuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSAMPLERPARAMETERIVPROC, glGetSamplerParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSAMPLERPARAMETERIIVPROC, glGetSamplerParameterIiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSAMPLERPARAMETERFVPROC, glGetSamplerParameterfv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSAMPLERPARAMETERIUIVPROC, glGetSamplerParameterIuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLQUERYCOUNTERPROC, glQueryCounter)
	FORGE_GL_DECL_FUNCTION(PFNGLGETQUERYOBJECTI64VPROC, glGetQueryObjecti64v)
	FORGE_GL_DECL_FUNCTION(PFNGLGETQUERYOBJECTUI64VPROC, glGetQueryObjectui64v)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBDIVISORPROC, glVertexAttribDivisor)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBP1UIPROC, glVertexAttribP1ui)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBP1UIVPROC, glVertexAttribP1uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBP2UIPROC, glVertexAttribP2ui)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBP2UIVPROC, glVertexAttribP2uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBP3UIPROC, glVertexAttribP3ui)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBP3UIVPROC, glVertexAttribP3uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBP4UIPROC, glVertexAttribP4ui)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBP4UIVPROC, glVertexAttribP4uiv)
#endif /* GL_VERSION_3_3 */

#ifdef FORGE_GL_VERSION(4, 0)
	FORGE_GL_DECL_FUNCTION(PFNGLMINSAMPLESHADINGPROC, glMinSampleShading)
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDEQUATIONIPROC, glBlendEquationi)
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDEQUATIONSEPARATEIPROC, glBlendEquationSeparatei)
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDFUNCIPROC, glBlendFunci)
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDFUNCSEPARATEIPROC, glBlendFuncSeparatei)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWARRAYSINDIRECTPROC, glDrawArraysIndirect)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWELEMENTSINDIRECTPROC, glDrawElementsIndirect)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1DPROC, glUniform1d)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2DPROC, glUniform2d)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3DPROC, glUniform3d)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4DPROC, glUniform4d)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1DVPROC, glUniform1dv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2DVPROC, glUniform2dv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3DVPROC, glUniform3dv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4DVPROC, glUniform4dv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX2DVPROC, glUniformMatrix2dv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX3DVPROC, glUniformMatrix3dv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX4DVPROC, glUniformMatrix4dv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX2X3DVPROC, glUniformMatrix2x3dv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX2X4DVPROC, glUniformMatrix2x4dv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX3X2DVPROC, glUniformMatrix3x2dv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX3X4DVPROC, glUniformMatrix3x4dv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX4X2DVPROC, glUniformMatrix4x2dv)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMMATRIX4X3DVPROC, glUniformMatrix4x3dv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETUNIFORMDVPROC, glGetUniformdv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC, glGetSubroutineUniformLocation)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSUBROUTINEINDEXPROC, glGetSubroutineIndex)
	FORGE_GL_DECL_FUNCTION(PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC, glGetActiveSubroutineUniformiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC, glGetActiveSubroutineUniformName)
	FORGE_GL_DECL_FUNCTION(PFNGLGETACTIVESUBROUTINENAMEPROC, glGetActiveSubroutineName)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMSUBROUTINESUIVPROC, glUniformSubroutinesuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETUNIFORMSUBROUTINEUIVPROC, glGetUniformSubroutineuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMSTAGEIVPROC, glGetProgramStageiv)
	FORGE_GL_DECL_FUNCTION(PFNGLPATCHPARAMETERIPROC, glPatchParameteri)
	FORGE_GL_DECL_FUNCTION(PFNGLPATCHPARAMETERFVPROC, glPatchParameterfv)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDTRANSFORMFEEDBACKPROC, glBindTransformFeedback)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETETRANSFORMFEEDBACKSPROC, glDeleteTransformFeedbacks)
	FORGE_GL_DECL_FUNCTION(PFNGLGENTRANSFORMFEEDBACKSPROC, glGenTransformFeedbacks)
	FORGE_GL_DECL_FUNCTION(PFNGLISTRANSFORMFEEDBACKPROC, glIsTransformFeedback)
	FORGE_GL_DECL_FUNCTION(PFNGLPAUSETRANSFORMFEEDBACKPROC, glPauseTransformFeedback)
	FORGE_GL_DECL_FUNCTION(PFNGLRESUMETRANSFORMFEEDBACKPROC, glResumeTransformFeedback)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWTRANSFORMFEEDBACKPROC, glDrawTransformFeedback)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC, glDrawTransformFeedbackStream)
	FORGE_GL_DECL_FUNCTION(PFNGLBEGINQUERYINDEXEDPROC, glBeginQueryIndexed)
	FORGE_GL_DECL_FUNCTION(PFNGLENDQUERYINDEXEDPROC, glEndQueryIndexed)
	FORGE_GL_DECL_FUNCTION(PFNGLGETQUERYINDEXEDIVPROC, glGetQueryIndexediv)
#endif /* GL_VERSION_4_0 */

#ifdef FORGE_GL_VERSION(4, 1)
	FORGE_GL_DECL_FUNCTION(PFNGLRELEASESHADERCOMPILERPROC, glReleaseShaderCompiler)
	FORGE_GL_DECL_FUNCTION(PFNGLSHADERBINARYPROC, glShaderBinary)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSHADERPRECISIONFORMATPROC, glGetShaderPrecisionFormat)
	FORGE_GL_DECL_FUNCTION(PFNGLDEPTHRANGEFPROC, glDepthRangef)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARDEPTHFPROC, glClearDepthf)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMBINARYPROC, glGetProgramBinary)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMBINARYPROC, glProgramBinary)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMPARAMETERIPROC, glProgramParameteri)
	FORGE_GL_DECL_FUNCTION(PFNGLUSEPROGRAMSTAGESPROC, glUseProgramStages)
	FORGE_GL_DECL_FUNCTION(PFNGLACTIVESHADERPROGRAMPROC, glActiveShaderProgram)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATESHADERPROGRAMVPROC, glCreateShaderProgramv)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDPROGRAMPIPELINEPROC, glBindProgramPipeline)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETEPROGRAMPIPELINESPROC, glDeleteProgramPipelines)
	FORGE_GL_DECL_FUNCTION(PFNGLGENPROGRAMPIPELINESPROC, glGenProgramPipelines)
	FORGE_GL_DECL_FUNCTION(PFNGLISPROGRAMPIPELINEPROC, glIsProgramPipeline)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMPIPELINEIVPROC, glGetProgramPipelineiv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1IPROC, glProgramUniform1i)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1IVPROC, glProgramUniform1iv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1FPROC, glProgramUniform1f)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1FVPROC, glProgramUniform1fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1DPROC, glProgramUniform1d)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1DVPROC, glProgramUniform1dv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1UIPROC, glProgramUniform1ui)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1UIVPROC, glProgramUniform1uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2IPROC, glProgramUniform2i)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2IVPROC, glProgramUniform2iv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2FPROC, glProgramUniform2f)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2FVPROC, glProgramUniform2fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2DPROC, glProgramUniform2d)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2DVPROC, glProgramUniform2dv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2UIPROC, glProgramUniform2ui)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2UIVPROC, glProgramUniform2uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3IPROC, glProgramUniform3i)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3IVPROC, glProgramUniform3iv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3FPROC, glProgramUniform3f)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3FVPROC, glProgramUniform3fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3DPROC, glProgramUniform3d)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3DVPROC, glProgramUniform3dv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3UIPROC, glProgramUniform3ui)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3UIVPROC, glProgramUniform3uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4IPROC, glProgramUniform4i)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4IVPROC, glProgramUniform4iv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4FPROC, glProgramUniform4f)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4FVPROC, glProgramUniform4fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4DPROC, glProgramUniform4d)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4DVPROC, glProgramUniform4dv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4UIPROC, glProgramUniform4ui)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4UIVPROC, glProgramUniform4uiv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX2FVPROC, glProgramUniformMatrix2fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX3FVPROC, glProgramUniformMatrix3fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX4FVPROC, glProgramUniformMatrix4fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX2DVPROC, glProgramUniformMatrix2dv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX3DVPROC, glProgramUniformMatrix3dv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX4DVPROC, glProgramUniformMatrix4dv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC, glProgramUniformMatrix2x3fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC, glProgramUniformMatrix3x2fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC, glProgramUniformMatrix2x4fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC, glProgramUniformMatrix4x2fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC, glProgramUniformMatrix3x4fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC, glProgramUniformMatrix4x3fv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC, glProgramUniformMatrix2x3dv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC, glProgramUniformMatrix3x2dv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC, glProgramUniformMatrix2x4dv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC, glProgramUniformMatrix4x2dv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC, glProgramUniformMatrix3x4dv)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC, glProgramUniformMatrix4x3dv)
	FORGE_GL_DECL_FUNCTION(PFNGLVALIDATEPROGRAMPIPELINEPROC, glValidateProgramPipeline)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMPIPELINEINFOLOGPROC, glGetProgramPipelineInfoLog)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL1DPROC, glVertexAttribL1d)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL2DPROC, glVertexAttribL2d)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL3DPROC, glVertexAttribL3d)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL4DPROC, glVertexAttribL4d)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL1DVPROC, glVertexAttribL1dv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL2DVPROC, glVertexAttribL2dv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL3DVPROC, glVertexAttribL3dv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL4DVPROC, glVertexAttribL4dv)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBLPOINTERPROC, glVertexAttribLPointer)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXATTRIBLDVPROC, glGetVertexAttribLdv)
	FORGE_GL_DECL_FUNCTION(PFNGLVIEWPORTARRAYVPROC, glViewportArrayv)
	FORGE_GL_DECL_FUNCTION(PFNGLVIEWPORTINDEXEDFPROC, glViewportIndexedf)
	FORGE_GL_DECL_FUNCTION(PFNGLVIEWPORTINDEXEDFVPROC, glViewportIndexedfv)
	FORGE_GL_DECL_FUNCTION(PFNGLSCISSORARRAYVPROC, glScissorArrayv)
	FORGE_GL_DECL_FUNCTION(PFNGLSCISSORINDEXEDPROC, glScissorIndexed)
	FORGE_GL_DECL_FUNCTION(PFNGLSCISSORINDEXEDVPROC, glScissorIndexedv)
	FORGE_GL_DECL_FUNCTION(PFNGLDEPTHRANGEARRAYVPROC, glDepthRangeArrayv)
	FORGE_GL_DECL_FUNCTION(PFNGLDEPTHRANGEINDEXEDPROC, glDepthRangeIndexed)
	FORGE_GL_DECL_FUNCTION(PFNGLGETFLOATI_VPROC, glGetFloati_v)
	FORGE_GL_DECL_FUNCTION(PFNGLGETDOUBLEI_VPROC, glGetDoublei_v)
#endif /* GL_VERSION_4_1 */

#ifdef FORGE_GL_VERSION(4, 2)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC, glDrawArraysInstancedBaseInstance)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC, glDrawElementsInstancedBaseInstance)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC, glDrawElementsInstancedBaseVertexBaseInstance)
	FORGE_GL_DECL_FUNCTION(PFNGLGETINTERNALFORMATIVPROC, glGetInternalformativ)
	FORGE_GL_DECL_FUNCTION(PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC, glGetActiveAtomicCounterBufferiv)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDIMAGETEXTUREPROC, glBindImageTexture)
	FORGE_GL_DECL_FUNCTION(PFNGLMEMORYBARRIERPROC, glMemoryBarrier)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXSTORAGE1DPROC, glTexStorage1D)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXSTORAGE2DPROC, glTexStorage2D)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXSTORAGE3DPROC, glTexStorage3D)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC, glDrawTransformFeedbackInstanced)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC, glDrawTransformFeedbackStreamInstanced)
#endif /* GL_VERSION_4_2 */

#ifdef FORGE_GL_VERSION(4, 3)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARBUFFERDATAPROC, glClearBufferData)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARBUFFERSUBDATAPROC, glClearBufferSubData)
	FORGE_GL_DECL_FUNCTION(PFNGLDISPATCHCOMPUTEPROC, glDispatchCompute)
	FORGE_GL_DECL_FUNCTION(PFNGLDISPATCHCOMPUTEINDIRECTPROC, glDispatchComputeIndirect)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYIMAGESUBDATAPROC, glCopyImageSubData)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERPARAMETERIPROC, glFramebufferParameteri)
	FORGE_GL_DECL_FUNCTION(PFNGLGETFRAMEBUFFERPARAMETERIVPROC, glGetFramebufferParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETINTERNALFORMATI64VPROC, glGetInternalformati64v)
	FORGE_GL_DECL_FUNCTION(PFNGLINVALIDATETEXSUBIMAGEPROC, glInvalidateTexSubImage)
	FORGE_GL_DECL_FUNCTION(PFNGLINVALIDATETEXIMAGEPROC, glInvalidateTexImage)
	FORGE_GL_DECL_FUNCTION(PFNGLINVALIDATEBUFFERSUBDATAPROC, glInvalidateBufferSubData)
	FORGE_GL_DECL_FUNCTION(PFNGLINVALIDATEBUFFERDATAPROC, glInvalidateBufferData)
	FORGE_GL_DECL_FUNCTION(PFNGLINVALIDATEFRAMEBUFFERPROC, glInvalidateFramebuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLINVALIDATESUBFRAMEBUFFERPROC, glInvalidateSubFramebuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWARRAYSINDIRECTPROC, glMultiDrawArraysIndirect)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWELEMENTSINDIRECTPROC, glMultiDrawElementsIndirect)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMINTERFACEIVPROC, glGetProgramInterfaceiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMRESOURCEINDEXPROC, glGetProgramResourceIndex)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMRESOURCENAMEPROC, glGetProgramResourceName)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMRESOURCEIVPROC, glGetProgramResourceiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMRESOURCELOCATIONPROC, glGetProgramResourceLocation)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC, glGetProgramResourceLocationIndex)
	FORGE_GL_DECL_FUNCTION(PFNGLSHADERSTORAGEBLOCKBINDINGPROC, glShaderStorageBlockBinding)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXBUFFERRANGEPROC, glTexBufferRange)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXSTORAGE2DMULTISAMPLEPROC, glTexStorage2DMultisample)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXSTORAGE3DMULTISAMPLEPROC, glTexStorage3DMultisample)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREVIEWPROC, glTextureView)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDVERTEXBUFFERPROC, glBindVertexBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBFORMATPROC, glVertexAttribFormat)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBIFORMATPROC, glVertexAttribIFormat)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBLFORMATPROC, glVertexAttribLFormat)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBBINDINGPROC, glVertexAttribBinding)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXBINDINGDIVISORPROC, glVertexBindingDivisor)
	FORGE_GL_DECL_FUNCTION(PFNGLDEBUGMESSAGECONTROLPROC, glDebugMessageControl)
	FORGE_GL_DECL_FUNCTION(PFNGLDEBUGMESSAGEINSERTPROC, glDebugMessageInsert)
	FORGE_GL_DECL_FUNCTION(PFNGLDEBUGMESSAGECALLBACKPROC, glDebugMessageCallback)
	FORGE_GL_DECL_FUNCTION(PFNGLGETDEBUGMESSAGELOGPROC, glGetDebugMessageLog)
	FORGE_GL_DECL_FUNCTION(PFNGLPUSHDEBUGGROUPPROC, glPushDebugGroup)
	FORGE_GL_DECL_FUNCTION(PFNGLPOPDEBUGGROUPPROC, glPopDebugGroup)
	FORGE_GL_DECL_FUNCTION(PFNGLOBJECTLABELPROC, glObjectLabel)
	FORGE_GL_DECL_FUNCTION(PFNGLGETOBJECTLABELPROC, glGetObjectLabel)
	FORGE_GL_DECL_FUNCTION(PFNGLOBJECTPTRLABELPROC, glObjectPtrLabel)
	FORGE_GL_DECL_FUNCTION(PFNGLGETOBJECTPTRLABELPROC, glGetObjectPtrLabel)
#endif /* GL_VERSION_4_3 */

#ifdef FORGE_GL_VERSION(4, 4)
	FORGE_GL_DECL_FUNCTION(PFNGLBUFFERSTORAGEPROC, glBufferStorage)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARTEXIMAGEPROC, glClearTexImage)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARTEXSUBIMAGEPROC, glClearTexSubImage)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDBUFFERSBASEPROC, glBindBuffersBase)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDBUFFERSRANGEPROC, glBindBuffersRange)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDTEXTURESPROC, glBindTextures)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDSAMPLERSPROC, glBindSamplers)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDIMAGETEXTURESPROC, glBindImageTextures)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDVERTEXBUFFERSPROC, glBindVertexBuffers)
#endif /* GL_VERSION_4_4 */

#ifdef FORGE_GL_VERSION(4, 5)
	FORGE_GL_DECL_FUNCTION(PFNGLCLIPCONTROLPROC, glClipControl)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATETRANSFORMFEEDBACKSPROC, glCreateTransformFeedbacks)
	FORGE_GL_DECL_FUNCTION(PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC, glTransformFeedbackBufferBase)
	FORGE_GL_DECL_FUNCTION(PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC, glTransformFeedbackBufferRange)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTRANSFORMFEEDBACKIVPROC, glGetTransformFeedbackiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTRANSFORMFEEDBACKI_VPROC, glGetTransformFeedbacki_v)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTRANSFORMFEEDBACKI64_VPROC, glGetTransformFeedbacki64_v)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATEBUFFERSPROC, glCreateBuffers)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDBUFFERSTORAGEPROC, glNamedBufferStorage)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDBUFFERDATAPROC, glNamedBufferData)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDBUFFERSUBDATAPROC, glNamedBufferSubData)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYNAMEDBUFFERSUBDATAPROC, glCopyNamedBufferSubData)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARNAMEDBUFFERDATAPROC, glClearNamedBufferData)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARNAMEDBUFFERSUBDATAPROC, glClearNamedBufferSubData)
	FORGE_GL_DECL_FUNCTION(PFNGLMAPNAMEDBUFFERPROC, glMapNamedBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLMAPNAMEDBUFFERRANGEPROC, glMapNamedBufferRange)
	FORGE_GL_DECL_FUNCTION(PFNGLUNMAPNAMEDBUFFERPROC, glUnmapNamedBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC, glFlushMappedNamedBufferRange)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDBUFFERPARAMETERIVPROC, glGetNamedBufferParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDBUFFERPARAMETERI64VPROC, glGetNamedBufferParameteri64v)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDBUFFERPOINTERVPROC, glGetNamedBufferPointerv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDBUFFERSUBDATAPROC, glGetNamedBufferSubData)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATEFRAMEBUFFERSPROC, glCreateFramebuffers)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC, glNamedFramebufferRenderbuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC, glNamedFramebufferParameteri)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERTEXTUREPROC, glNamedFramebufferTexture)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC, glNamedFramebufferTextureLayer)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC, glNamedFramebufferDrawBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC, glNamedFramebufferDrawBuffers)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC, glNamedFramebufferReadBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC, glInvalidateNamedFramebufferData)
	FORGE_GL_DECL_FUNCTION(PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC, glInvalidateNamedFramebufferSubData)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARNAMEDFRAMEBUFFERIVPROC, glClearNamedFramebufferiv)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC, glClearNamedFramebufferuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARNAMEDFRAMEBUFFERFVPROC, glClearNamedFramebufferfv)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARNAMEDFRAMEBUFFERFIPROC, glClearNamedFramebufferfi)
	FORGE_GL_DECL_FUNCTION(PFNGLBLITNAMEDFRAMEBUFFERPROC, glBlitNamedFramebuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC, glCheckNamedFramebufferStatus)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC, glGetNamedFramebufferParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC, glGetNamedFramebufferAttachmentParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATERENDERBUFFERSPROC, glCreateRenderbuffers)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDRENDERBUFFERSTORAGEPROC, glNamedRenderbufferStorage)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC, glNamedRenderbufferStorageMultisample)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC, glGetNamedRenderbufferParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATETEXTURESPROC, glCreateTextures)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREBUFFERPROC, glTextureBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREBUFFERRANGEPROC, glTextureBufferRange)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESTORAGE1DPROC, glTextureStorage1D)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESTORAGE2DPROC, glTextureStorage2D)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESTORAGE3DPROC, glTextureStorage3D)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC, glTextureStorage2DMultisample)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC, glTextureStorage3DMultisample)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESUBIMAGE1DPROC, glTextureSubImage1D)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESUBIMAGE2DPROC, glTextureSubImage2D)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESUBIMAGE3DPROC, glTextureSubImage3D)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC, glCompressedTextureSubImage1D)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC, glCompressedTextureSubImage2D)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC, glCompressedTextureSubImage3D)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXTURESUBIMAGE1DPROC, glCopyTextureSubImage1D)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXTURESUBIMAGE2DPROC, glCopyTextureSubImage2D)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXTURESUBIMAGE3DPROC, glCopyTextureSubImage3D)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPARAMETERFPROC, glTextureParameterf)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPARAMETERFVPROC, glTextureParameterfv)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPARAMETERIPROC, glTextureParameteri)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPARAMETERIIVPROC, glTextureParameterIiv)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPARAMETERIUIVPROC, glTextureParameterIuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPARAMETERIVPROC, glTextureParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLGENERATETEXTUREMIPMAPPROC, glGenerateTextureMipmap)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDTEXTUREUNITPROC, glBindTextureUnit)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTUREIMAGEPROC, glGetTextureImage)
	FORGE_GL_DECL_FUNCTION(PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC, glGetCompressedTextureImage)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTURELEVELPARAMETERFVPROC, glGetTextureLevelParameterfv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTURELEVELPARAMETERIVPROC, glGetTextureLevelParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTUREPARAMETERFVPROC, glGetTextureParameterfv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTUREPARAMETERIIVPROC, glGetTextureParameterIiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTUREPARAMETERIUIVPROC, glGetTextureParameterIuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTUREPARAMETERIVPROC, glGetTextureParameteriv)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATEVERTEXARRAYSPROC, glCreateVertexArrays)
	FORGE_GL_DECL_FUNCTION(PFNGLDISABLEVERTEXARRAYATTRIBPROC, glDisableVertexArrayAttrib)
	FORGE_GL_DECL_FUNCTION(PFNGLENABLEVERTEXARRAYATTRIBPROC, glEnableVertexArrayAttrib)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYELEMENTBUFFERPROC, glVertexArrayElementBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYVERTEXBUFFERPROC, glVertexArrayVertexBuffer)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYVERTEXBUFFERSPROC, glVertexArrayVertexBuffers)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYATTRIBBINDINGPROC, glVertexArrayAttribBinding)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYATTRIBFORMATPROC, glVertexArrayAttribFormat)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYATTRIBIFORMATPROC, glVertexArrayAttribIFormat)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYATTRIBLFORMATPROC, glVertexArrayAttribLFormat)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYBINDINGDIVISORPROC, glVertexArrayBindingDivisor)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXARRAYIVPROC, glGetVertexArrayiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXARRAYINDEXEDIVPROC, glGetVertexArrayIndexediv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXARRAYINDEXED64IVPROC, glGetVertexArrayIndexed64iv)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATESAMPLERSPROC, glCreateSamplers)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATEPROGRAMPIPELINESPROC, glCreateProgramPipelines)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATEQUERIESPROC, glCreateQueries)
	FORGE_GL_DECL_FUNCTION(PFNGLGETQUERYBUFFEROBJECTI64VPROC, glGetQueryBufferObjecti64v)
	FORGE_GL_DECL_FUNCTION(PFNGLGETQUERYBUFFEROBJECTIVPROC, glGetQueryBufferObjectiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETQUERYBUFFEROBJECTUI64VPROC, glGetQueryBufferObjectui64v)
	FORGE_GL_DECL_FUNCTION(PFNGLGETQUERYBUFFEROBJECTUIVPROC, glGetQueryBufferObjectuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLMEMORYBARRIERBYREGIONPROC, glMemoryBarrierByRegion)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTURESUBIMAGEPROC, glGetTextureSubImage)
	FORGE_GL_DECL_FUNCTION(PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC, glGetCompressedTextureSubImage)
	FORGE_GL_DECL_FUNCTION(PFNGLGETGRAPHICSRESETSTATUSPROC, glGetGraphicsResetStatus)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNCOMPRESSEDTEXIMAGEPROC, glGetnCompressedTexImage)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNTEXIMAGEPROC, glGetnTexImage)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNUNIFORMDVPROC, glGetnUniformdv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNUNIFORMFVPROC, glGetnUniformfv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNUNIFORMIVPROC, glGetnUniformiv)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNUNIFORMUIVPROC, glGetnUniformuiv)
	FORGE_GL_DECL_FUNCTION(PFNGLREADNPIXELSPROC, glReadnPixels)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREBARRIERPROC, glTextureBarrier)
#endif /* GL_VERSION_4_5 */

#ifdef FORGE_GL_VERSION(4, 6)
	FORGE_GL_DECL_FUNCTION(PFNGLSPECIALIZESHADERPROC, glSpecializeShader)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC, glMultiDrawArraysIndirectCount)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC, glMultiDrawElementsIndirectCount)
	FORGE_GL_DECL_FUNCTION(PFNGLPOLYGONOFFSETCLAMPPROC, glPolygonOffsetClamp)
#endif /* GL_VERSION_4_6 */

#ifdef FORGE_ARB_ES3_2_compatibility
	FORGE_GL_DECL_FUNCTION(PFNGLPRIMITIVEBOUNDINGBOXARBPROC, glPrimitiveBoundingBoxARB)
#endif /* FORGE_ARB_ES3_2_compatibility */

#ifdef FORGE_ARB_bindless_texture
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTUREHANDLEARBPROC, glGetTextureHandleARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTURESAMPLERHANDLEARBPROC, glGetTextureSamplerHandleARB)
	FORGE_GL_DECL_FUNCTION(PFNGLMAKETEXTUREHANDLERESIDENTARBPROC, glMakeTextureHandleResidentARB)
	FORGE_GL_DECL_FUNCTION(PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC, glMakeTextureHandleNonResidentARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETIMAGEHANDLEARBPROC, glGetImageHandleARB)
	FORGE_GL_DECL_FUNCTION(PFNGLMAKEIMAGEHANDLERESIDENTARBPROC, glMakeImageHandleResidentARB)
	FORGE_GL_DECL_FUNCTION(PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC, glMakeImageHandleNonResidentARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMHANDLEUI64ARBPROC, glUniformHandleui64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMHANDLEUI64VARBPROC, glUniformHandleui64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC, glProgramUniformHandleui64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC, glProgramUniformHandleui64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLISTEXTUREHANDLERESIDENTARBPROC, glIsTextureHandleResidentARB)
	FORGE_GL_DECL_FUNCTION(PFNGLISIMAGEHANDLERESIDENTARBPROC, glIsImageHandleResidentARB)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL1UI64ARBPROC, glVertexAttribL1ui64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL1UI64VARBPROC, glVertexAttribL1ui64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXATTRIBLUI64VARBPROC, glGetVertexAttribLui64vARB)
#endif /* FORGE_ARB_bindless_texture */

#ifdef FORGE_ARB_cl_event
	FORGE_GL_DECL_FUNCTION(PFNGLCREATESYNCFROMCLEVENTARBPROC, glCreateSyncFromCLeventARB)
#endif /* FORGE_ARB_cl_event */

#ifdef FORGE_ARB_compute_variable_group_size
	FORGE_GL_DECL_FUNCTION(PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC, glDispatchComputeGroupSizeARB)
#endif /* FORGE_ARB_compute_variable_group_size */

#ifdef FORGE_ARB_debug_output
	FORGE_GL_DECL_FUNCTION(PFNGLDEBUGMESSAGECONTROLARBPROC, glDebugMessageControlARB)
	FORGE_GL_DECL_FUNCTION(PFNGLDEBUGMESSAGEINSERTARBPROC, glDebugMessageInsertARB)
	FORGE_GL_DECL_FUNCTION(PFNGLDEBUGMESSAGECALLBACKARBPROC, glDebugMessageCallbackARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETDEBUGMESSAGELOGARBPROC, glGetDebugMessageLogARB)
#endif /* FORGE_ARB_debug_output */

#ifdef FORGE_ARB_draw_buffers_blend
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDEQUATIONIARBPROC, glBlendEquationiARB)
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDEQUATIONSEPARATEIARBPROC, glBlendEquationSeparateiARB)
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDFUNCIARBPROC, glBlendFunciARB)
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDFUNCSEPARATEIARBPROC, glBlendFuncSeparateiARB)
#endif /* FORGE_ARB_draw_buffers_blend */

#ifdef FORGE_ARB_draw_instanced
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWARRAYSINSTANCEDARBPROC, glDrawArraysInstancedARB)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWELEMENTSINSTANCEDARBPROC, glDrawElementsInstancedARB)
#endif /* FORGE_ARB_draw_instanced */

#ifdef FORGE_ARB_geometry_shader4
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMPARAMETERIARBPROC, glProgramParameteriARB)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERTEXTUREARBPROC, glFramebufferTextureARB)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERTEXTURELAYERARBPROC, glFramebufferTextureLayerARB)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERTEXTUREFACEARBPROC, glFramebufferTextureFaceARB)
#endif /* FORGE_ARB_geometry_shader4 */

#ifdef FORGE_ARB_gl_spirv
	FORGE_GL_DECL_FUNCTION(PFNGLSPECIALIZESHADERARBPROC, glSpecializeShaderARB)
#endif /* FORGE_ARB_gl_spirv */

#ifdef FORGE_ARB_gpu_shader_int64
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1I64ARBPROC, glUniform1i64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2I64ARBPROC, glUniform2i64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3I64ARBPROC, glUniform3i64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4I64ARBPROC, glUniform4i64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1I64VARBPROC, glUniform1i64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2I64VARBPROC, glUniform2i64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3I64VARBPROC, glUniform3i64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4I64VARBPROC, glUniform4i64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1UI64ARBPROC, glUniform1ui64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2UI64ARBPROC, glUniform2ui64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3UI64ARBPROC, glUniform3ui64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4UI64ARBPROC, glUniform4ui64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1UI64VARBPROC, glUniform1ui64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2UI64VARBPROC, glUniform2ui64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3UI64VARBPROC, glUniform3ui64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4UI64VARBPROC, glUniform4ui64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETUNIFORMI64VARBPROC, glGetUniformi64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETUNIFORMUI64VARBPROC, glGetUniformui64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNUNIFORMI64VARBPROC, glGetnUniformi64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNUNIFORMUI64VARBPROC, glGetnUniformui64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1I64ARBPROC, glProgramUniform1i64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2I64ARBPROC, glProgramUniform2i64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3I64ARBPROC, glProgramUniform3i64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4I64ARBPROC, glProgramUniform4i64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1I64VARBPROC, glProgramUniform1i64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2I64VARBPROC, glProgramUniform2i64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3I64VARBPROC, glProgramUniform3i64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4I64VARBPROC, glProgramUniform4i64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1UI64ARBPROC, glProgramUniform1ui64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2UI64ARBPROC, glProgramUniform2ui64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3UI64ARBPROC, glProgramUniform3ui64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4UI64ARBPROC, glProgramUniform4ui64ARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1UI64VARBPROC, glProgramUniform1ui64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2UI64VARBPROC, glProgramUniform2ui64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3UI64VARBPROC, glProgramUniform3ui64vARB)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4UI64VARBPROC, glProgramUniform4ui64vARB)
#endif /* FORGE_ARB_gpu_shader_int64 */

#ifdef FORGE_ARB_indirect_parameters
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC, glMultiDrawArraysIndirectCountARB)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC, glMultiDrawElementsIndirectCountARB)
#endif /* FORGE_ARB_indirect_parameters */

#ifdef FORGE_ARB_instanced_arrays
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBDIVISORARBPROC, glVertexAttribDivisorARB)
#endif /* FORGE_ARB_instanced_arrays */

#ifdef FORGE_ARB_parallel_shader_compile
	FORGE_GL_DECL_FUNCTION(PFNGLMAXSHADERCOMPILERTHREADSARBPROC, glMaxShaderCompilerThreadsARB)
#endif /* FORGE_ARB_parallel_shader_compile */

#ifdef FORGE_ARB_robustness
	FORGE_GL_DECL_FUNCTION(PFNGLGETGRAPHICSRESETSTATUSARBPROC, glGetGraphicsResetStatusARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNTEXIMAGEARBPROC, glGetnTexImageARB)
	FORGE_GL_DECL_FUNCTION(PFNGLREADNPIXELSARBPROC, glReadnPixelsARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC, glGetnCompressedTexImageARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNUNIFORMFVARBPROC, glGetnUniformfvARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNUNIFORMIVARBPROC, glGetnUniformivARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNUNIFORMUIVARBPROC, glGetnUniformuivARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNUNIFORMDVARBPROC, glGetnUniformdvARB)
#endif /* FORGE_ARB_robustness */

#ifdef FORGE_ARB_sample_locations
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC, glFramebufferSampleLocationsfvARB)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC, glNamedFramebufferSampleLocationsfvARB)
	FORGE_GL_DECL_FUNCTION(PFNGLEVALUATEDEPTHVALUESARBPROC, glEvaluateDepthValuesARB)
#endif /* FORGE_ARB_sample_locations */

#ifdef FORGE_ARB_sample_shading
	FORGE_GL_DECL_FUNCTION(PFNGLMINSAMPLESHADINGARBPROC, glMinSampleShadingARB)
#endif /* FORGE_ARB_sample_shading */

#ifdef FORGE_ARB_shading_language_include
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDSTRINGARBPROC, glNamedStringARB)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETENAMEDSTRINGARBPROC, glDeleteNamedStringARB)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPILESHADERINCLUDEARBPROC, glCompileShaderIncludeARB)
	FORGE_GL_DECL_FUNCTION(PFNGLISNAMEDSTRINGARBPROC, glIsNamedStringARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDSTRINGARBPROC, glGetNamedStringARB)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDSTRINGIVARBPROC, glGetNamedStringivARB)
#endif /* FORGE_ARB_shading_language_include */

#ifdef FORGE_ARB_sparse_buffer
	FORGE_GL_DECL_FUNCTION(PFNGLBUFFERPAGECOMMITMENTARBPROC, glBufferPageCommitmentARB)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC, glNamedBufferPageCommitmentEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC, glNamedBufferPageCommitmentARB)
#endif /* FORGE_ARB_sparse_buffer */

#ifdef FORGE_ARB_sparse_texture
	FORGE_GL_DECL_FUNCTION(PFNGLTEXPAGECOMMITMENTARBPROC, glTexPageCommitmentARB)
#endif /* FORGE_ARB_sparse_texture */

#ifdef FORGE_ARB_texture_buffer_object
	FORGE_GL_DECL_FUNCTION(PFNGLTEXBUFFERARBPROC, glTexBufferARB)
#endif /* FORGE_ARB_texture_buffer_object */

#ifdef FORGE_ARB_viewport_array
	FORGE_GL_DECL_FUNCTION(PFNGLDEPTHRANGEARRAYDVNVPROC, glDepthRangeArraydvNV)
	FORGE_GL_DECL_FUNCTION(PFNGLDEPTHRANGEINDEXEDDNVPROC, glDepthRangeIndexeddNV)
#endif /* FORGE_ARB_viewport_array */

#ifdef FORGE_KHR_blend_equation_advanced
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDBARRIERKHRPROC, glBlendBarrierKHR)
#endif /* FORGE_KHR_blend_equation_advanced */

#ifdef FORGE_KHR_parallel_shader_compile
	FORGE_GL_DECL_FUNCTION(PFNGLMAXSHADERCOMPILERTHREADSKHRPROC, glMaxShaderCompilerThreadsKHR)
#endif /* FORGE_KHR_parallel_shader_compile */

#ifdef FORGE_AMD_framebuffer_multisample_advanced
	FORGE_GL_DECL_FUNCTION(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC, glRenderbufferStorageMultisampleAdvancedAMD)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC, glNamedRenderbufferStorageMultisampleAdvancedAMD)
#endif /* FORGE_AMD_framebuffer_multisample_advanced */

#ifdef FORGE_AMD_performance_monitor
	FORGE_GL_DECL_FUNCTION(PFNGLGETPERFMONITORGROUPSAMDPROC, glGetPerfMonitorGroupsAMD)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPERFMONITORCOUNTERSAMDPROC, glGetPerfMonitorCountersAMD)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPERFMONITORGROUPSTRINGAMDPROC, glGetPerfMonitorGroupStringAMD)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC, glGetPerfMonitorCounterStringAMD)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPERFMONITORCOUNTERINFOAMDPROC, glGetPerfMonitorCounterInfoAMD)
	FORGE_GL_DECL_FUNCTION(PFNGLGENPERFMONITORSAMDPROC, glGenPerfMonitorsAMD)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETEPERFMONITORSAMDPROC, glDeletePerfMonitorsAMD)
	FORGE_GL_DECL_FUNCTION(PFNGLSELECTPERFMONITORCOUNTERSAMDPROC, glSelectPerfMonitorCountersAMD)
	FORGE_GL_DECL_FUNCTION(PFNGLBEGINPERFMONITORAMDPROC, glBeginPerfMonitorAMD)
	FORGE_GL_DECL_FUNCTION(PFNGLENDPERFMONITORAMDPROC, glEndPerfMonitorAMD)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPERFMONITORCOUNTERDATAAMDPROC, glGetPerfMonitorCounterDataAMD)
#endif /* FORGE_AMD_performance_monitor */

#ifdef FORGE_EXT_EGL_image_storage
	FORGE_GL_DECL_FUNCTION(PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC, glEGLImageTargetTexStorageEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC, glEGLImageTargetTextureStorageEXT)
#endif /* FORGE_EXT_EGL_image_storage */

#ifdef FORGE_EXT_debug_label
	FORGE_GL_DECL_FUNCTION(PFNGLLABELOBJECTEXTPROC, glLabelObjectEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETOBJECTLABELEXTPROC, glGetObjectLabelEXT)
#endif /* FORGE_EXT_debug_label */

#ifdef FORGE_EXT_debug_marker
	FORGE_GL_DECL_FUNCTION(PFNGLINSERTEVENTMARKEREXTPROC, glInsertEventMarkerEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPUSHGROUPMARKEREXTPROC, glPushGroupMarkerEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPOPGROUPMARKEREXTPROC, glPopGroupMarkerEXT)
#endif /* FORGE_EXT_debug_marker */

#ifdef FORGE_EXT_direct_state_access
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXLOADFEXTPROC, glMatrixLoadfEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXLOADDEXTPROC, glMatrixLoaddEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXMULTFEXTPROC, glMatrixMultfEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXMULTDEXTPROC, glMatrixMultdEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXLOADIDENTITYEXTPROC, glMatrixLoadIdentityEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXROTATEFEXTPROC, glMatrixRotatefEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXROTATEDEXTPROC, glMatrixRotatedEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXSCALEFEXTPROC, glMatrixScalefEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXSCALEDEXTPROC, glMatrixScaledEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXTRANSLATEFEXTPROC, glMatrixTranslatefEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXTRANSLATEDEXTPROC, glMatrixTranslatedEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXFRUSTUMEXTPROC, glMatrixFrustumEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXORTHOEXTPROC, glMatrixOrthoEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXPOPEXTPROC, glMatrixPopEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXPUSHEXTPROC, glMatrixPushEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCLIENTATTRIBDEFAULTEXTPROC, glClientAttribDefaultEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC, glPushClientAttribDefaultEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPARAMETERFEXTPROC, glTextureParameterfEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPARAMETERFVEXTPROC, glTextureParameterfvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPARAMETERIEXTPROC, glTextureParameteriEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPARAMETERIVEXTPROC, glTextureParameterivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREIMAGE1DEXTPROC, glTextureImage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREIMAGE2DEXTPROC, glTextureImage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESUBIMAGE1DEXTPROC, glTextureSubImage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESUBIMAGE2DEXTPROC, glTextureSubImage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXTUREIMAGE1DEXTPROC, glCopyTextureImage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXTUREIMAGE2DEXTPROC, glCopyTextureImage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC, glCopyTextureSubImage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC, glCopyTextureSubImage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTUREIMAGEEXTPROC, glGetTextureImageEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTUREPARAMETERFVEXTPROC, glGetTextureParameterfvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTUREPARAMETERIVEXTPROC, glGetTextureParameterivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC, glGetTextureLevelParameterfvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC, glGetTextureLevelParameterivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREIMAGE3DEXTPROC, glTextureImage3DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESUBIMAGE3DEXTPROC, glTextureSubImage3DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC, glCopyTextureSubImage3DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLBINDMULTITEXTUREEXTPROC, glBindMultiTextureEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXCOORDPOINTEREXTPROC, glMultiTexCoordPointerEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXENVFEXTPROC, glMultiTexEnvfEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXENVFVEXTPROC, glMultiTexEnvfvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXENVIEXTPROC, glMultiTexEnviEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXENVIVEXTPROC, glMultiTexEnvivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXGENDEXTPROC, glMultiTexGendEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXGENDVEXTPROC, glMultiTexGendvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXGENFEXTPROC, glMultiTexGenfEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXGENFVEXTPROC, glMultiTexGenfvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXGENIEXTPROC, glMultiTexGeniEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXGENIVEXTPROC, glMultiTexGenivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTITEXENVFVEXTPROC, glGetMultiTexEnvfvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTITEXENVIVEXTPROC, glGetMultiTexEnvivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTITEXGENDVEXTPROC, glGetMultiTexGendvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTITEXGENFVEXTPROC, glGetMultiTexGenfvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTITEXGENIVEXTPROC, glGetMultiTexGenivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXPARAMETERIEXTPROC, glMultiTexParameteriEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXPARAMETERIVEXTPROC, glMultiTexParameterivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXPARAMETERFEXTPROC, glMultiTexParameterfEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXPARAMETERFVEXTPROC, glMultiTexParameterfvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXIMAGE1DEXTPROC, glMultiTexImage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXIMAGE2DEXTPROC, glMultiTexImage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXSUBIMAGE1DEXTPROC, glMultiTexSubImage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXSUBIMAGE2DEXTPROC, glMultiTexSubImage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYMULTITEXIMAGE1DEXTPROC, glCopyMultiTexImage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYMULTITEXIMAGE2DEXTPROC, glCopyMultiTexImage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC, glCopyMultiTexSubImage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC, glCopyMultiTexSubImage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTITEXIMAGEEXTPROC, glGetMultiTexImageEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTITEXPARAMETERFVEXTPROC, glGetMultiTexParameterfvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTITEXPARAMETERIVEXTPROC, glGetMultiTexParameterivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC, glGetMultiTexLevelParameterfvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC, glGetMultiTexLevelParameterivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXIMAGE3DEXTPROC, glMultiTexImage3DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXSUBIMAGE3DEXTPROC, glMultiTexSubImage3DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC, glCopyMultiTexSubImage3DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLENABLECLIENTSTATEINDEXEDEXTPROC, glEnableClientStateIndexedEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC, glDisableClientStateIndexedEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETFLOATINDEXEDVEXTPROC, glGetFloatIndexedvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETDOUBLEINDEXEDVEXTPROC, glGetDoubleIndexedvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPOINTERINDEXEDVEXTPROC, glGetPointerIndexedvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLENABLEINDEXEDEXTPROC, glEnableIndexedEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLDISABLEINDEXEDEXTPROC, glDisableIndexedEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLISENABLEDINDEXEDEXTPROC, glIsEnabledIndexedEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETINTEGERINDEXEDVEXTPROC, glGetIntegerIndexedvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETBOOLEANINDEXEDVEXTPROC, glGetBooleanIndexedvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC, glCompressedTextureImage3DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC, glCompressedTextureImage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC, glCompressedTextureImage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC, glCompressedTextureSubImage3DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC, glCompressedTextureSubImage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC, glCompressedTextureSubImage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC, glGetCompressedTextureImageEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC, glCompressedMultiTexImage3DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC, glCompressedMultiTexImage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC, glCompressedMultiTexImage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC, glCompressedMultiTexSubImage3DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC, glCompressedMultiTexSubImage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC, glCompressedMultiTexSubImage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC, glGetCompressedMultiTexImageEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXLOADTRANSPOSEFEXTPROC, glMatrixLoadTransposefEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXLOADTRANSPOSEDEXTPROC, glMatrixLoadTransposedEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXMULTTRANSPOSEFEXTPROC, glMatrixMultTransposefEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXMULTTRANSPOSEDEXTPROC, glMatrixMultTransposedEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDBUFFERDATAEXTPROC, glNamedBufferDataEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDBUFFERSUBDATAEXTPROC, glNamedBufferSubDataEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMAPNAMEDBUFFEREXTPROC, glMapNamedBufferEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLUNMAPNAMEDBUFFEREXTPROC, glUnmapNamedBufferEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC, glGetNamedBufferParameterivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDBUFFERPOINTERVEXTPROC, glGetNamedBufferPointervEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDBUFFERSUBDATAEXTPROC, glGetNamedBufferSubDataEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1FEXTPROC, glProgramUniform1fEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2FEXTPROC, glProgramUniform2fEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3FEXTPROC, glProgramUniform3fEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4FEXTPROC, glProgramUniform4fEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1IEXTPROC, glProgramUniform1iEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2IEXTPROC, glProgramUniform2iEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3IEXTPROC, glProgramUniform3iEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4IEXTPROC, glProgramUniform4iEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1FVEXTPROC, glProgramUniform1fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2FVEXTPROC, glProgramUniform2fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3FVEXTPROC, glProgramUniform3fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4FVEXTPROC, glProgramUniform4fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1IVEXTPROC, glProgramUniform1ivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2IVEXTPROC, glProgramUniform2ivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3IVEXTPROC, glProgramUniform3ivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4IVEXTPROC, glProgramUniform4ivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC, glProgramUniformMatrix2fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC, glProgramUniformMatrix3fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC, glProgramUniformMatrix4fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC, glProgramUniformMatrix2x3fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC, glProgramUniformMatrix3x2fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC, glProgramUniformMatrix2x4fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC, glProgramUniformMatrix4x2fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC, glProgramUniformMatrix3x4fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC, glProgramUniformMatrix4x3fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREBUFFEREXTPROC, glTextureBufferEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXBUFFEREXTPROC, glMultiTexBufferEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPARAMETERIIVEXTPROC, glTextureParameterIivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPARAMETERIUIVEXTPROC, glTextureParameterIuivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTUREPARAMETERIIVEXTPROC, glGetTextureParameterIivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTUREPARAMETERIUIVEXTPROC, glGetTextureParameterIuivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXPARAMETERIIVEXTPROC, glMultiTexParameterIivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXPARAMETERIUIVEXTPROC, glMultiTexParameterIuivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTITEXPARAMETERIIVEXTPROC, glGetMultiTexParameterIivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETMULTITEXPARAMETERIUIVEXTPROC, glGetMultiTexParameterIuivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1UIEXTPROC, glProgramUniform1uiEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2UIEXTPROC, glProgramUniform2uiEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3UIEXTPROC, glProgramUniform3uiEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4UIEXTPROC, glProgramUniform4uiEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1UIVEXTPROC, glProgramUniform1uivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2UIVEXTPROC, glProgramUniform2uivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3UIVEXTPROC, glProgramUniform3uivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4UIVEXTPROC, glProgramUniform4uivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC, glNamedProgramLocalParameters4fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC, glNamedProgramLocalParameterI4iEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC, glNamedProgramLocalParameterI4ivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC, glNamedProgramLocalParametersI4ivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC, glNamedProgramLocalParameterI4uiEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC, glNamedProgramLocalParameterI4uivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC, glNamedProgramLocalParametersI4uivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC, glGetNamedProgramLocalParameterIivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC, glGetNamedProgramLocalParameterIuivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLENABLECLIENTSTATEIEXTPROC, glEnableClientStateiEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLDISABLECLIENTSTATEIEXTPROC, glDisableClientStateiEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETFLOATI_VEXTPROC, glGetFloati_vEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETDOUBLEI_VEXTPROC, glGetDoublei_vEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPOINTERI_VEXTPROC, glGetPointeri_vEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDPROGRAMSTRINGEXTPROC, glNamedProgramStringEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC, glNamedProgramLocalParameter4dEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC, glNamedProgramLocalParameter4dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC, glNamedProgramLocalParameter4fEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC, glNamedProgramLocalParameter4fvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC, glGetNamedProgramLocalParameterdvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC, glGetNamedProgramLocalParameterfvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDPROGRAMIVEXTPROC, glGetNamedProgramivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDPROGRAMSTRINGEXTPROC, glGetNamedProgramStringEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC, glNamedRenderbufferStorageEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC, glGetNamedRenderbufferParameterivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC, glNamedRenderbufferStorageMultisampleEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC, glNamedRenderbufferStorageMultisampleCoverageEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC, glCheckNamedFramebufferStatusEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC, glNamedFramebufferTexture1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC, glNamedFramebufferTexture2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC, glNamedFramebufferTexture3DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC, glNamedFramebufferRenderbufferEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC, glGetNamedFramebufferAttachmentParameterivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGENERATETEXTUREMIPMAPEXTPROC, glGenerateTextureMipmapEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGENERATEMULTITEXMIPMAPEXTPROC, glGenerateMultiTexMipmapEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC, glFramebufferDrawBufferEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC, glFramebufferDrawBuffersEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERREADBUFFEREXTPROC, glFramebufferReadBufferEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC, glGetFramebufferParameterivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC, glNamedCopyBufferSubDataEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC, glNamedFramebufferTextureEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC, glNamedFramebufferTextureLayerEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC, glNamedFramebufferTextureFaceEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURERENDERBUFFEREXTPROC, glTextureRenderbufferEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTITEXRENDERBUFFEREXTPROC, glMultiTexRenderbufferEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC, glVertexArrayVertexOffsetEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYCOLOROFFSETEXTPROC, glVertexArrayColorOffsetEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC, glVertexArrayEdgeFlagOffsetEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYINDEXOFFSETEXTPROC, glVertexArrayIndexOffsetEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYNORMALOFFSETEXTPROC, glVertexArrayNormalOffsetEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC, glVertexArrayTexCoordOffsetEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC, glVertexArrayMultiTexCoordOffsetEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC, glVertexArrayFogCoordOffsetEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC, glVertexArraySecondaryColorOffsetEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC, glVertexArrayVertexAttribOffsetEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC, glVertexArrayVertexAttribIOffsetEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLENABLEVERTEXARRAYEXTPROC, glEnableVertexArrayEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLDISABLEVERTEXARRAYEXTPROC, glDisableVertexArrayEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLENABLEVERTEXARRAYATTRIBEXTPROC, glEnableVertexArrayAttribEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC, glDisableVertexArrayAttribEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXARRAYINTEGERVEXTPROC, glGetVertexArrayIntegervEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXARRAYPOINTERVEXTPROC, glGetVertexArrayPointervEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC, glGetVertexArrayIntegeri_vEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC, glGetVertexArrayPointeri_vEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLMAPNAMEDBUFFERRANGEEXTPROC, glMapNamedBufferRangeEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC, glFlushMappedNamedBufferRangeEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDBUFFERSTORAGEEXTPROC, glNamedBufferStorageEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARNAMEDBUFFERDATAEXTPROC, glClearNamedBufferDataEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC, glClearNamedBufferSubDataEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC, glNamedFramebufferParameteriEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC, glGetNamedFramebufferParameterivEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1DEXTPROC, glProgramUniform1dEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2DEXTPROC, glProgramUniform2dEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3DEXTPROC, glProgramUniform3dEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4DEXTPROC, glProgramUniform4dEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1DVEXTPROC, glProgramUniform1dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2DVEXTPROC, glProgramUniform2dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3DVEXTPROC, glProgramUniform3dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4DVEXTPROC, glProgramUniform4dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC, glProgramUniformMatrix2dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC, glProgramUniformMatrix3dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC, glProgramUniformMatrix4dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC, glProgramUniformMatrix2x3dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC, glProgramUniformMatrix2x4dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC, glProgramUniformMatrix3x2dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC, glProgramUniformMatrix3x4dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC, glProgramUniformMatrix4x2dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC, glProgramUniformMatrix4x3dvEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREBUFFERRANGEEXTPROC, glTextureBufferRangeEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESTORAGE1DEXTPROC, glTextureStorage1DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESTORAGE2DEXTPROC, glTextureStorage2DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESTORAGE3DEXTPROC, glTextureStorage3DEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC, glTextureStorage2DMultisampleEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC, glTextureStorage3DMultisampleEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC, glVertexArrayBindVertexBufferEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC, glVertexArrayVertexAttribFormatEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC, glVertexArrayVertexAttribIFormatEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC, glVertexArrayVertexAttribLFormatEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC, glVertexArrayVertexAttribBindingEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC, glVertexArrayVertexBindingDivisorEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC, glVertexArrayVertexAttribLOffsetEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPAGECOMMITMENTEXTPROC, glTexturePageCommitmentEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC, glVertexArrayVertexAttribDivisorEXT)
#endif /* FORGE_EXT_direct_state_access */

#ifdef FORGE_EXT_draw_instanced
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWARRAYSINSTANCEDEXTPROC, glDrawArraysInstancedEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWELEMENTSINSTANCEDEXTPROC, glDrawElementsInstancedEXT)
#endif /* FORGE_EXT_draw_instanced */

#ifdef FORGE_EXT_polygon_offset_clamp
	FORGE_GL_DECL_FUNCTION(PFNGLPOLYGONOFFSETCLAMPEXTPROC, glPolygonOffsetClampEXT)
#endif /* FORGE_EXT_polygon_offset_clamp */

#ifdef FORGE_EXT_raster_multisample
	FORGE_GL_DECL_FUNCTION(PFNGLRASTERSAMPLESEXTPROC, glRasterSamplesEXT)
#endif /* FORGE_EXT_raster_multisample */

#ifdef FORGE_EXT_separate_shader_objects
	FORGE_GL_DECL_FUNCTION(PFNGLUSESHADERPROGRAMEXTPROC, glUseShaderProgramEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLACTIVEPROGRAMEXTPROC, glActiveProgramEXT)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATESHADERPROGRAMEXTPROC, glCreateShaderProgramEXT)
#endif /* FORGE_EXT_separate_shader_objects */

#ifdef FORGE_EXT_shader_framebuffer_fetch_non_coherent
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC, glFramebufferFetchBarrierEXT)
#endif /* FORGE_EXT_shader_framebuffer_fetch_non_coherent */

#ifdef FORGE_EXT_window_rectangles
	FORGE_GL_DECL_FUNCTION(PFNGLWINDOWRECTANGLESEXTPROC, glWindowRectanglesEXT)
#endif /* FORGE_EXT_window_rectangles */

#ifdef FORGE_INTEL_framebuffer_CMAA
	FORGE_GL_DECL_FUNCTION(PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC, glApplyFramebufferAttachmentCMAAINTEL)
#endif /* FORGE_INTEL_framebuffer_CMAA */

#ifdef FORGE_INTEL_performance_query
	FORGE_GL_DECL_FUNCTION(PFNGLBEGINPERFQUERYINTELPROC, glBeginPerfQueryINTEL)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATEPERFQUERYINTELPROC, glCreatePerfQueryINTEL)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETEPERFQUERYINTELPROC, glDeletePerfQueryINTEL)
	FORGE_GL_DECL_FUNCTION(PFNGLENDPERFQUERYINTELPROC, glEndPerfQueryINTEL)
	FORGE_GL_DECL_FUNCTION(PFNGLGETFIRSTPERFQUERYIDINTELPROC, glGetFirstPerfQueryIdINTEL)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNEXTPERFQUERYIDINTELPROC, glGetNextPerfQueryIdINTEL)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPERFCOUNTERINFOINTELPROC, glGetPerfCounterInfoINTEL)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPERFQUERYDATAINTELPROC, glGetPerfQueryDataINTEL)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPERFQUERYIDBYNAMEINTELPROC, glGetPerfQueryIdByNameINTEL)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPERFQUERYINFOINTELPROC, glGetPerfQueryInfoINTEL)
#endif /* FORGE_INTEL_performance_query */

#ifdef FORGE_MESA_framebuffer_flip_y
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERPARAMETERIMESAPROC, glFramebufferParameteriMESA)
	FORGE_GL_DECL_FUNCTION(PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC, glGetFramebufferParameterivMESA)
#endif /* FORGE_MESA_framebuffer_flip_y */

#ifdef FORGE_NV_bindless_multi_draw_indirect
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC, glMultiDrawArraysIndirectBindlessNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC, glMultiDrawElementsIndirectBindlessNV)
#endif /* FORGE_NV_bindless_multi_draw_indirect */

#ifdef FORGE_NV_bindless_multi_draw_indirect_count
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC, glMultiDrawArraysIndirectBindlessCountNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC, glMultiDrawElementsIndirectBindlessCountNV)
#endif /* FORGE_NV_bindless_multi_draw_indirect_count */

#ifdef FORGE_NV_bindless_texture
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTUREHANDLENVPROC, glGetTextureHandleNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETTEXTURESAMPLERHANDLENVPROC, glGetTextureSamplerHandleNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMAKETEXTUREHANDLERESIDENTNVPROC, glMakeTextureHandleResidentNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC, glMakeTextureHandleNonResidentNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETIMAGEHANDLENVPROC, glGetImageHandleNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMAKEIMAGEHANDLERESIDENTNVPROC, glMakeImageHandleResidentNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC, glMakeImageHandleNonResidentNV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMHANDLEUI64NVPROC, glUniformHandleui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMHANDLEUI64VNVPROC, glUniformHandleui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC, glProgramUniformHandleui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC, glProgramUniformHandleui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLISTEXTUREHANDLERESIDENTNVPROC, glIsTextureHandleResidentNV)
	FORGE_GL_DECL_FUNCTION(PFNGLISIMAGEHANDLERESIDENTNVPROC, glIsImageHandleResidentNV)
#endif /* FORGE_NV_bindless_texture */

#ifdef FORGE_NV_blend_equation_advanced
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDPARAMETERINVPROC, glBlendParameteriNV)
	FORGE_GL_DECL_FUNCTION(PFNGLBLENDBARRIERNVPROC, glBlendBarrierNV)
#endif /* FORGE_NV_blend_equation_advanced */

#ifdef FORGE_NV_clip_space_w_scaling
	FORGE_GL_DECL_FUNCTION(PFNGLVIEWPORTPOSITIONWSCALENVPROC, glViewportPositionWScaleNV)
#endif /* FORGE_NV_clip_space_w_scaling */

#ifdef FORGE_NV_command_list
	FORGE_GL_DECL_FUNCTION(PFNGLCREATESTATESNVPROC, glCreateStatesNV)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETESTATESNVPROC, glDeleteStatesNV)
	FORGE_GL_DECL_FUNCTION(PFNGLISSTATENVPROC, glIsStateNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSTATECAPTURENVPROC, glStateCaptureNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETCOMMANDHEADERNVPROC, glGetCommandHeaderNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSTAGEINDEXNVPROC, glGetStageIndexNV)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWCOMMANDSNVPROC, glDrawCommandsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWCOMMANDSADDRESSNVPROC, glDrawCommandsAddressNV)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWCOMMANDSSTATESNVPROC, glDrawCommandsStatesNV)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC, glDrawCommandsStatesAddressNV)
	FORGE_GL_DECL_FUNCTION(PFNGLCREATECOMMANDLISTSNVPROC, glCreateCommandListsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETECOMMANDLISTSNVPROC, glDeleteCommandListsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLISCOMMANDLISTNVPROC, glIsCommandListNV)
	FORGE_GL_DECL_FUNCTION(PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC, glListDrawCommandsStatesClientNV)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMMANDLISTSEGMENTSNVPROC, glCommandListSegmentsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLCOMPILECOMMANDLISTNVPROC, glCompileCommandListNV)
	FORGE_GL_DECL_FUNCTION(PFNGLCALLCOMMANDLISTNVPROC, glCallCommandListNV)
#endif /* FORGE_NV_command_list */

#ifdef FORGE_NV_conditional_render
	FORGE_GL_DECL_FUNCTION(PFNGLBEGINCONDITIONALRENDERNVPROC, glBeginConditionalRenderNV)
	FORGE_GL_DECL_FUNCTION(PFNGLENDCONDITIONALRENDERNVPROC, glEndConditionalRenderNV)
#endif /* FORGE_NV_conditional_render */

#ifdef FORGE_NV_conservative_raster
	FORGE_GL_DECL_FUNCTION(PFNGLSUBPIXELPRECISIONBIASNVPROC, glSubpixelPrecisionBiasNV)
#endif /* FORGE_NV_conservative_raster */

#ifdef FORGE_NV_conservative_raster_dilate
	FORGE_GL_DECL_FUNCTION(PFNGLCONSERVATIVERASTERPARAMETERFNVPROC, glConservativeRasterParameterfNV)
#endif /* FORGE_NV_conservative_raster_dilate */

#ifdef FORGE_NV_conservative_raster_pre_snap_triangles
	FORGE_GL_DECL_FUNCTION(PFNGLCONSERVATIVERASTERPARAMETERINVPROC, glConservativeRasterParameteriNV)
#endif /* FORGE_NV_conservative_raster_pre_snap_triangles */

#ifdef FORGE_NV_depth_buffer_float
	FORGE_GL_DECL_FUNCTION(PFNGLDEPTHRANGEDNVPROC, glDepthRangedNV)
	FORGE_GL_DECL_FUNCTION(PFNGLCLEARDEPTHDNVPROC, glClearDepthdNV)
	FORGE_GL_DECL_FUNCTION(PFNGLDEPTHBOUNDSDNVPROC, glDepthBoundsdNV)
#endif /* FORGE_NV_depth_buffer_float */

#ifdef FORGE_NV_draw_vulkan_image
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWVKIMAGENVPROC, glDrawVkImageNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVKPROCADDRNVPROC, glGetVkProcAddrNV)
	FORGE_GL_DECL_FUNCTION(PFNGLWAITVKSEMAPHORENVPROC, glWaitVkSemaphoreNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSIGNALVKSEMAPHORENVPROC, glSignalVkSemaphoreNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSIGNALVKFENCENVPROC, glSignalVkFenceNV)
#endif /* FORGE_NV_draw_vulkan_image */

#ifdef FORGE_NV_fragment_coverage_to_color
	FORGE_GL_DECL_FUNCTION(PFNGLFRAGMENTCOVERAGECOLORNVPROC, glFragmentCoverageColorNV)
#endif /* FORGE_NV_fragment_coverage_to_color */

#ifdef FORGE_NV_framebuffer_mixed_samples
	FORGE_GL_DECL_FUNCTION(PFNGLCOVERAGEMODULATIONTABLENVPROC, glCoverageModulationTableNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETCOVERAGEMODULATIONTABLENVPROC, glGetCoverageModulationTableNV)
	FORGE_GL_DECL_FUNCTION(PFNGLCOVERAGEMODULATIONNVPROC, glCoverageModulationNV)
#endif /* FORGE_NV_framebuffer_mixed_samples */

#ifdef FORGE_NV_framebuffer_multisample_coverage
	FORGE_GL_DECL_FUNCTION(PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC, glRenderbufferStorageMultisampleCoverageNV)
#endif /* FORGE_NV_framebuffer_multisample_coverage */

#ifdef FORGE_NV_gpu_shader5
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1I64NVPROC, glUniform1i64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2I64NVPROC, glUniform2i64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3I64NVPROC, glUniform3i64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4I64NVPROC, glUniform4i64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1I64VNVPROC, glUniform1i64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2I64VNVPROC, glUniform2i64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3I64VNVPROC, glUniform3i64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4I64VNVPROC, glUniform4i64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1UI64NVPROC, glUniform1ui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2UI64NVPROC, glUniform2ui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3UI64NVPROC, glUniform3ui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4UI64NVPROC, glUniform4ui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM1UI64VNVPROC, glUniform1ui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM2UI64VNVPROC, glUniform2ui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM3UI64VNVPROC, glUniform3ui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORM4UI64VNVPROC, glUniform4ui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETUNIFORMI64VNVPROC, glGetUniformi64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1I64NVPROC, glProgramUniform1i64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2I64NVPROC, glProgramUniform2i64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3I64NVPROC, glProgramUniform3i64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4I64NVPROC, glProgramUniform4i64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1I64VNVPROC, glProgramUniform1i64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2I64VNVPROC, glProgramUniform2i64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3I64VNVPROC, glProgramUniform3i64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4I64VNVPROC, glProgramUniform4i64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1UI64NVPROC, glProgramUniform1ui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2UI64NVPROC, glProgramUniform2ui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3UI64NVPROC, glProgramUniform3ui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4UI64NVPROC, glProgramUniform4ui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM1UI64VNVPROC, glProgramUniform1ui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM2UI64VNVPROC, glProgramUniform2ui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM3UI64VNVPROC, glProgramUniform3ui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORM4UI64VNVPROC, glProgramUniform4ui64vNV)
#endif /* FORGE_NV_gpu_shader5 */

#ifdef FORGE_NV_internalformat_sample_query
	FORGE_GL_DECL_FUNCTION(PFNGLGETINTERNALFORMATSAMPLEIVNVPROC, glGetInternalformatSampleivNV)
#endif /* FORGE_NV_internalformat_sample_query */

#ifdef FORGE_NV_memory_attachment
	FORGE_GL_DECL_FUNCTION(PFNGLGETMEMORYOBJECTDETACHEDRESOURCESUIVNVPROC, glGetMemoryObjectDetachedResourcesuivNV)
	FORGE_GL_DECL_FUNCTION(PFNGLRESETMEMORYOBJECTPARAMETERNVPROC, glResetMemoryObjectParameterNV)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXATTACHMEMORYNVPROC, glTexAttachMemoryNV)
	FORGE_GL_DECL_FUNCTION(PFNGLBUFFERATTACHMEMORYNVPROC, glBufferAttachMemoryNV)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREATTACHMEMORYNVPROC, glTextureAttachMemoryNV)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDBUFFERATTACHMEMORYNVPROC, glNamedBufferAttachMemoryNV)
#endif /* FORGE_NV_memory_attachment */

#ifdef FORGE_NV_memory_object_sparse
	FORGE_GL_DECL_FUNCTION(PFNGLBUFFERPAGECOMMITMENTMEMNVPROC, glBufferPageCommitmentMemNV)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXPAGECOMMITMENTMEMNVPROC, glTexPageCommitmentMemNV)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDBUFFERPAGECOMMITMENTMEMNVPROC, glNamedBufferPageCommitmentMemNV)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREPAGECOMMITMENTMEMNVPROC, glTexturePageCommitmentMemNV)
#endif /* FORGE_NV_memory_object_sparse */

#ifdef FORGE_NV_mesh_shader
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWMESHTASKSNVPROC, glDrawMeshTasksNV)
	FORGE_GL_DECL_FUNCTION(PFNGLDRAWMESHTASKSINDIRECTNVPROC, glDrawMeshTasksIndirectNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWMESHTASKSINDIRECTNVPROC, glMultiDrawMeshTasksIndirectNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMULTIDRAWMESHTASKSINDIRECTCOUNTNVPROC, glMultiDrawMeshTasksIndirectCountNV)
#endif /* FORGE_NV_mesh_shader */

#ifdef FORGE_NV_path_rendering
FORGE_GL_DECL_FUNCTION(PFNGLGENPATHSNVPROC, glGenPathsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLDELETEPATHSNVPROC, glDeletePathsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLISPATHNVPROC, glIsPathNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHCOMMANDSNVPROC, glPathCommandsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHCOORDSNVPROC, glPathCoordsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHSUBCOMMANDSNVPROC, glPathSubCommandsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHSUBCOORDSNVPROC, glPathSubCoordsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHSTRINGNVPROC, glPathStringNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHGLYPHSNVPROC, glPathGlyphsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHGLYPHRANGENVPROC, glPathGlyphRangeNV)
	FORGE_GL_DECL_FUNCTION(PFNGLWEIGHTPATHSNVPROC, glWeightPathsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLCOPYPATHNVPROC, glCopyPathNV)
	FORGE_GL_DECL_FUNCTION(PFNGLINTERPOLATEPATHSNVPROC, glInterpolatePathsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLTRANSFORMPATHNVPROC, glTransformPathNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHPARAMETERIVNVPROC, glPathParameterivNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHPARAMETERINVPROC, glPathParameteriNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHPARAMETERFVNVPROC, glPathParameterfvNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHPARAMETERFNVPROC, glPathParameterfNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHDASHARRAYNVPROC, glPathDashArrayNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHSTENCILFUNCNVPROC, glPathStencilFuncNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHSTENCILDEPTHOFFSETNVPROC, glPathStencilDepthOffsetNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILFILLPATHNVPROC, glStencilFillPathNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILSTROKEPATHNVPROC, glStencilStrokePathNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILFILLPATHINSTANCEDNVPROC, glStencilFillPathInstancedNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC, glStencilStrokePathInstancedNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHCOVERDEPTHFUNCNVPROC, glPathCoverDepthFuncNV)
	FORGE_GL_DECL_FUNCTION(PFNGLCOVERFILLPATHNVPROC, glCoverFillPathNV)
	FORGE_GL_DECL_FUNCTION(PFNGLCOVERSTROKEPATHNVPROC, glCoverStrokePathNV)
	FORGE_GL_DECL_FUNCTION(PFNGLCOVERFILLPATHINSTANCEDNVPROC, glCoverFillPathInstancedNV)
	FORGE_GL_DECL_FUNCTION(PFNGLCOVERSTROKEPATHINSTANCEDNVPROC, glCoverStrokePathInstancedNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPATHPARAMETERIVNVPROC, glGetPathParameterivNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPATHPARAMETERFVNVPROC, glGetPathParameterfvNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPATHCOMMANDSNVPROC, glGetPathCommandsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPATHCOORDSNVPROC, glGetPathCoordsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPATHDASHARRAYNVPROC, glGetPathDashArrayNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPATHMETRICSNVPROC, glGetPathMetricsNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPATHMETRICRANGENVPROC, glGetPathMetricRangeNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPATHSPACINGNVPROC, glGetPathSpacingNV)
	FORGE_GL_DECL_FUNCTION(PFNGLISPOINTINFILLPATHNVPROC, glIsPointInFillPathNV)
	FORGE_GL_DECL_FUNCTION(PFNGLISPOINTINSTROKEPATHNVPROC, glIsPointInStrokePathNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPATHLENGTHNVPROC, glGetPathLengthNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPOINTALONGPATHNVPROC, glPointAlongPathNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXLOAD3X2FNVPROC, glMatrixLoad3x2fNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXLOAD3X3FNVPROC, glMatrixLoad3x3fNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC, glMatrixLoadTranspose3x3fNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXMULT3X2FNVPROC, glMatrixMult3x2fNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXMULT3X3FNVPROC, glMatrixMult3x3fNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC, glMatrixMultTranspose3x3fNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILTHENCOVERFILLPATHNVPROC, glStencilThenCoverFillPathNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC, glStencilThenCoverStrokePathNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC, glStencilThenCoverFillPathInstancedNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC, glStencilThenCoverStrokePathInstancedNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHGLYPHINDEXRANGENVPROC, glPathGlyphIndexRangeNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHGLYPHINDEXARRAYNVPROC, glPathGlyphIndexArrayNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC, glPathMemoryGlyphIndexArrayNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC, glProgramPathFragmentInputGenNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETPROGRAMRESOURCEFVNVPROC, glGetProgramResourcefvNV)
#endif /* FORGE_NV_path_rendering */

#ifdef FORGE_NV_sample_locations
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC, glFramebufferSampleLocationsfvNV)
	FORGE_GL_DECL_FUNCTION(PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC, glNamedFramebufferSampleLocationsfvNV)
	FORGE_GL_DECL_FUNCTION(PFNGLRESOLVEDEPTHVALUESNVPROC, glResolveDepthValuesNV)
#endif /* FORGE_NV_sample_locations */

#ifdef FORGE_NV_scissor_exclusive
	FORGE_GL_DECL_FUNCTION(PFNGLSCISSOREXCLUSIVENVPROC, glScissorExclusiveNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSCISSOREXCLUSIVEARRAYVNVPROC, glScissorExclusiveArrayvNV)
#endif /* FORGE_NV_scissor_exclusive */

#ifdef FORGE_NV_shader_buffer_load
	FORGE_GL_DECL_FUNCTION(PFNGLMAKEBUFFERRESIDENTNVPROC, glMakeBufferResidentNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMAKEBUFFERNONRESIDENTNVPROC, glMakeBufferNonResidentNV)
	FORGE_GL_DECL_FUNCTION(PFNGLISBUFFERRESIDENTNVPROC, glIsBufferResidentNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMAKENAMEDBUFFERRESIDENTNVPROC, glMakeNamedBufferResidentNV)
	FORGE_GL_DECL_FUNCTION(PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC, glMakeNamedBufferNonResidentNV)
	FORGE_GL_DECL_FUNCTION(PFNGLISNAMEDBUFFERRESIDENTNVPROC, glIsNamedBufferResidentNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETBUFFERPARAMETERUI64VNVPROC, glGetBufferParameterui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC, glGetNamedBufferParameterui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETINTEGERUI64VNVPROC, glGetIntegerui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMUI64NVPROC, glUniformui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLUNIFORMUI64VNVPROC, glUniformui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETUNIFORMUI64VNVPROC, glGetUniformui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMUI64NVPROC, glProgramUniformui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLPROGRAMUNIFORMUI64VNVPROC, glProgramUniformui64vNV)
#endif /* FORGE_NV_shader_buffer_load */

#ifdef FORGE_NV_shading_rate_image
	FORGE_GL_DECL_FUNCTION(PFNGLBINDSHADINGRATEIMAGENVPROC, glBindShadingRateImageNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSHADINGRATEIMAGEPALETTENVPROC, glGetShadingRateImagePaletteNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETSHADINGRATESAMPLELOCATIONIVNVPROC, glGetShadingRateSampleLocationivNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSHADINGRATEIMAGEBARRIERNVPROC, glShadingRateImageBarrierNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSHADINGRATEIMAGEPALETTENVPROC, glShadingRateImagePaletteNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSHADINGRATESAMPLEORDERNVPROC, glShadingRateSampleOrderNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSHADINGRATESAMPLEORDERCUSTOMNVPROC, glShadingRateSampleOrderCustomNV)
#endif /* FORGE_NV_shading_rate_image */

#ifdef FORGE_NV_texture_barrier
	FORGE_GL_DECL_FUNCTION(PFNGLTEXTUREBARRIERNVPROC, glTextureBarrierNV)
#endif /* FORGE_NV_texture_barrier */

#ifdef FORGE_NV_vertex_attrib_integer_64bit
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL1I64NVPROC, glVertexAttribL1i64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL2I64NVPROC, glVertexAttribL2i64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL3I64NVPROC, glVertexAttribL3i64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL4I64NVPROC, glVertexAttribL4i64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL1I64VNVPROC, glVertexAttribL1i64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL2I64VNVPROC, glVertexAttribL2i64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL3I64VNVPROC, glVertexAttribL3i64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL4I64VNVPROC, glVertexAttribL4i64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL1UI64NVPROC, glVertexAttribL1ui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL2UI64NVPROC, glVertexAttribL2ui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL3UI64NVPROC, glVertexAttribL3ui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL4UI64NVPROC, glVertexAttribL4ui64NV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL1UI64VNVPROC, glVertexAttribL1ui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL2UI64VNVPROC, glVertexAttribL2ui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL3UI64VNVPROC, glVertexAttribL3ui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBL4UI64VNVPROC, glVertexAttribL4ui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXATTRIBLI64VNVPROC, glGetVertexAttribLi64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETVERTEXATTRIBLUI64VNVPROC, glGetVertexAttribLui64vNV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBLFORMATNVPROC, glVertexAttribLFormatNV)
#endif /* FORGE_NV_vertex_attrib_integer_64bit */

#ifdef FORGE_NV_vertex_buffer_unified_memory
	FORGE_GL_DECL_FUNCTION(PFNGLBUFFERADDRESSRANGENVPROC, glBufferAddressRangeNV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXFORMATNVPROC, glVertexFormatNV)
	FORGE_GL_DECL_FUNCTION(PFNGLNORMALFORMATNVPROC, glNormalFormatNV)
	FORGE_GL_DECL_FUNCTION(PFNGLCOLORFORMATNVPROC, glColorFormatNV)
	FORGE_GL_DECL_FUNCTION(PFNGLINDEXFORMATNVPROC, glIndexFormatNV)
	FORGE_GL_DECL_FUNCTION(PFNGLTEXCOORDFORMATNVPROC, glTexCoordFormatNV)
	FORGE_GL_DECL_FUNCTION(PFNGLEDGEFLAGFORMATNVPROC, glEdgeFlagFormatNV)
	FORGE_GL_DECL_FUNCTION(PFNGLSECONDARYCOLORFORMATNVPROC, glSecondaryColorFormatNV)
	FORGE_GL_DECL_FUNCTION(PFNGLFOGCOORDFORMATNVPROC, glFogCoordFormatNV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBFORMATNVPROC, glVertexAttribFormatNV)
	FORGE_GL_DECL_FUNCTION(PFNGLVERTEXATTRIBIFORMATNVPROC, glVertexAttribIFormatNV)
	FORGE_GL_DECL_FUNCTION(PFNGLGETINTEGERUI64I_VNVPROC, glGetIntegerui64i_vNV)
#endif /* FORGE_NV_vertex_buffer_unified_memory */

#ifdef FORGE_NV_viewport_swizzle
	FORGE_GL_DECL_FUNCTION(PFNGLVIEWPORTSWIZZLENVPROC, glViewportSwizzleNV)
#endif /* FORGE_NV_viewport_swizzle */

#ifdef FORGE_OVR_multiview
	FORGE_GL_DECL_FUNCTION(PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC, glFramebufferTextureMultiviewOVR)
#endif /* FORGE_OVR_multiview */

#endif
