#ifndef WINDOW_DESC_H
#define WINDOW_DESC_H

#include "Core/Public/Math/TVector.h"
#include "Core/Public/Common/Common.h"

typedef const char* String;

using namespace Forge::Math;

namespace Forge {
	namespace Platform
	{
		class AbstractWindow;

		enum class WindowCursorType
		{
			/**
			 * @brief Standard arrow.
			 */
			FORGE_ENUM_DECL(ARROW, 0x0)

			/**
			 * @brief Crosshair.
			 */
			FORGE_ENUM_DECL(CROSS, 0x1)

			/**
			 * @brief Hand.
			 */
			FORGE_ENUM_DECL(HAND, 0x2)

			/**
			 * @brief Arrow and question mark.
			 */
			FORGE_ENUM_DECL(HELP, 0x3)

			/**
			 * @brief I-beam.
			 */
			FORGE_ENUM_DECL(IBEAM, 0x4)

			/**
			 * @brief Slashed circle.
			 */
			FORGE_ENUM_DECL(NO, 0x5)

			/**
			 * @brief Four-pointed arrow pointing north, south, east, and west.
			 */
			FORGE_ENUM_DECL(SIZE_ALL, 0x6)

			/**
			 * @brief Double-pointed arrow pointing northeast and southwest.
			 */
			FORGE_ENUM_DECL(SIZE_NESW, 0x7)

			/**
			 * @brief Double-pointed arrow pointing north and south.
			 */
			FORGE_ENUM_DECL(SIZE_NS, 0x8)

			/**
			 * @brief Double-pointed arrow pointing northwest and southeast.
			 */
			FORGE_ENUM_DECL(SIZE_NWSE, 0x9)

			/**
			 * @brief Double-pointed arrow pointing west and east.
			 */
			FORGE_ENUM_DECL(SIZE_WE, 0x10)

			/**
			 * @brief Vertical arrow.
			 */
			FORGE_ENUM_DECL(UP_ARROW, 0x11)

			/**
			 * @brief Hourglass.
			 */
			FORGE_ENUM_DECL(WAIT, 0x12)

			/**
			 * @brief Hidden cursor.
			 */
			FORGE_ENUM_DECL(HIDDEN, 0x13)

			MAX
		};

		enum class WindowStartPositionMode
		{
			/**
			 * @brief The position of the window is determined by the position
			 * property.
			 */
			FORGE_ENUM_DECL(MANUAL, 0x0)

			/**
			 * @brief The position of the window is centered on the current
			 * display.
			 */
			FORGE_ENUM_DECL(CENTER_SCREEN, 0x1)

			/**
			 * @brief The position of the window is centered within the bounds of
			 * its parent window.
			 */
			FORGE_ENUM_DECL(CENTER_PARENT, 0x2)

			MAX
		};

		struct WindowDesc
		{
			/**
			 * @brief The window title.
			 */
			String m_window_title;
		
		public:
			/**
			 * @brief The window opacity if transaprency is supported.
			 */
			F32 m_window_opacity = 1.0f;

		public:
			/**
			 * @brief The parent window pointer to this window.
			 */
			AbstractWindow* m_window_parent = nullptr;

		public:
			/**
			 * @brief The type of cursor used by this window. 
			 */
			WindowCursorType m_window_cursor_type = WindowCursorType::ARROW;

			/**
			 * @brief The starting position mode of this window.
			 */
			WindowStartPositionMode m_window_start_position = WindowStartPositionMode::CENTER_SCREEN;

		public:
			/**
			 * @brief The window client size.
			 */
			Vector2 m_client_size = { 640, 480 };

			/**
			 * @brief The window client position in screen coordinates.
			 */
			Vector2 m_client_position = { 100, 400 };
		
		public:
			/**
			 * @brief Is the window initially visible?
			 */
			Bool m_is_visable = true;
			
			/**
			 * @brief Is the window initially focused?
			 */
			Bool m_is_focused = true;

			/**
			 * @brief Is the window resizable?
			 */
			Bool m_is_resizable = true;

			/**
			 * @brief Is the window decorated?
			 */
			Bool m_is_decorated = true;

			/**
			 * @brief Is the window initially minimized?
			 */
			Bool m_is_minimized = false;

			/**
			 * @brief Is the window initially maximized?
			 */
			Bool m_is_maximized = false;
			
			/**
			 * @brief Is the window in fullscreen mode?
			 */
			Bool m_is_fullscreen = false;
			
			/**
			 * @brief Is the window transparent?
			 */
			Bool m_is_transparent = true;

		public:
			/**
			 * @brief Can the window capture input?
			 */
			Bool m_allow_input = true;

			/**
			 * @brief Can the window be minimized?
			 */
			Bool m_allow_minimize = true;

			/**
			 * @brief Can the window be maximized?
			 */
			Bool m_allow_maximize = true;
		};
	}
}

#endif
