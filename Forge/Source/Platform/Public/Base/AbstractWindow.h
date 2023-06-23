#ifndef ABSTRACT_WINDOW_H
#define ABSTRACT_WINDOW_H

#include <Core/Public/Common/Common.h>
#include <Core/Public/Math/TVector.h>
#include <Core/Public/Math/TRectangle.h>
#include <Core/Public/Types/TDelegate.h>
#include <Core/Public/Memory/MemoryUtilities.h>
#include <Core/Public/Algorithm/GeneralUtilities.h>

#include <Platform/Public/WindowDesc.h>

using namespace Forge::Math;
using namespace Forge::Common;
using namespace Forge::Memory;
using namespace Forge::Algorithm;

namespace Forge {
	namespace Platform
	{
		enum class WindowClosingReason : Byte
		{
			/**
			 * @brief Unknown
			 */
			FORGE_ENUM_DECL(FORGE_UNKNOWN,     0x0)
			
			/**
			 * @brief Window was closed by user.
			 */
			FORGE_ENUM_DECL(FORGE_USER,        0x1)

			/**
			 * @brief Window was closed due to engine exit.
			 */
			FORGE_ENUM_DECL(FORGE_ENGINE_EXIT, 0x2)

			/**
			 * @brief Window was closed due to a close event.
			 */
			FORGE_ENUM_DECL(FORGE_CLOSE_EVENT, 0x3)

			MAX
		};

		/**
		 * @brief Native platform window.
		 * 
		 * @author Karim Hisham.
		 */
		class FORGE_API AbstractWindow
		{
		protected:
			VoidPtr m_window_handle;

		protected:
			WindowDesc m_window_description;

		protected:
			Bool m_is_closing;

		protected:
			Bool m_cache_is_visible;
			Bool m_cache_is_focused;
			Bool m_cache_is_minimized;
			Bool m_cache_is_maximized;

		protected:
			TDelegate<Void(Void)>     m_window_close_callback;
			TDelegate<Void(Bool)>     m_window_focus_callback;
			TDelegate<Void(Bool)>     m_window_minimize_callback;
			TDelegate<Void(Bool)>     m_window_maximize_callback;
			TDelegate<Void(U32, U32)> m_window_move_callback;
			TDelegate<Void(U32, U32)> m_window_resize_callback;

		public:
			/**
			 * @brief Default constructor.
			 * 
			 * Creates a platform dependant window using a description structure.
			 * 
			 * @param description The window description.
			 */
			explicit AbstractWindow(const WindowDesc& description);

			/**
			 * @brief Destructor.
			 */
			virtual ~AbstractWindow(Void) = default;

		public:
			/**
			 * @brief Gets the platform dependant native window handle.
			 *
			 * @returns ConstVoidPtr storing the address of the window handle.
			*/
			ConstVoidPtr GetNativeHandle(Void) const;

			/**
			 * @brief Gets the window description associated with this window.
			 * 
			 * @returns WindowDesc storing this window description.
			 */
			WindowDesc GetWindowDescription(Void) const;

		public:
			/**
			 * @brief Gets the window title.
			 * 
			 * @returns String storing the window title.
			 */
			String GetTitle(Void) const;

		public:
			/**
			 * @brief Gets the window opacity.
			 * 
			 * This function is valid only for windows with the is_transparent
			 * flag set to true.
			 * 
			 * @returns F32 storing the opacity value of the window normalized
			 * between 0 and 1.
			 */
			F32 GetOpacity(Void) const;
			
		public:
			/**
			* @brief Gets the client area size of the window not including border.
			*
			* @returns Vector2 storing the client area size of the window not
			* including border.
			*/
			Vector2 GetClientSize(Void) const;

			/**
			 * @brief Gets the client area position the window not including
			 * border.
			 *
			 * @returns Vector2 storing the client area position of the window not
			 * including border.
			 */
			Vector2 GetClientPosition(Void) const;

			/**
			 * @brief Gets the client bounds of the window not including border.
			 *
			 * @returns Rectangle storing the client bounds of the window not
			 * including border.
			 */
			RectangleF32 GetClientBounds(Void) const;

		public:
			/**
			 * @brief Gets the window size including border.
			 * 
			 * @returns Vector2 storing the window size including border.
			 */
			virtual Vector2 GetWindowSize(Void) const = 0;
	
			/**
			 * @brief Gets the window position in screen coordinates.
			 * 
			 * @returns Vector2 storing the window position in screen coordinates. 
			 */
			virtual Vector2 GetWindowPosition(Void) const = 0;

		public:
			/**
			 * @brief Gets the window cursor type.
			 * 
			 * @returns WindowCursorType storing the window cursor type.
			 */
			WindowCursorType GetCursorType(Void) const;

		public:
			/**
			 * @brief Converts client space location into screen space location
			 * and returns the new position.
			 * 
			 * @param client_position The client space position to convert.
			 * 
			 * @returns Vector2 storing the converted screen space position.
			 */
			virtual Vector2 GetClientToScreen(Vector2 client_position) const = 0;

			/**
			 * @brief Converts client space location into screen space location
			 * and returns the new position.
			 *
			 * @param client_position The client space position to convert.
			 *
			 * @returns Vector2 storing the converted client space position.
			 */
			virtual Vector2 GetScreenToClient(Vector2 screen_position) const = 0;

		public:
			/**
		     * @brief Checks if the window needs to be closed.
		     *
		     * @returns True if the window is closing, otherwise false;
		     */
			Bool IsClosing(Void) const;

		public:
			/**
			 * @brief Checks if the window is visible or hidden.
			 * 
			 * @returns True if the window is visible, otherwise false.
			 */
			Bool IsVisable(Void) const;

			/**
			 * @brief Checks if the window is focused or not.
			 *
			 * @returns True if the window is focused, otherwise false.
			 */
			Bool IsFocused(Void) const;

			/**
			 * @brief Checks if the window is resizable or or not.
			 *
			 * @returns True if the window is resizable, otherwise false.
			 */
			Bool IsResizable(Void) const;

			/**
			 * @brief Checks if the window is decorated or not.
			 *
			 * @returns True if the window is decorated, otherwise false.
			 */
			Bool IsDecorated(Void) const;

			/**
			 * @brief Checks if the window is minimized or maximized.
			 *
			 * @returns True if the window is minimized, otherwise false.
			 */
			Bool IsMinimized(Void) const;

			/**
			 * @brief Checks if the window is maximized or minimized.
			 *
			 * @returns True if the window is maximized, otherwise false.
			 */
			Bool IsMaximized(Void) const;

			/**
			 * @brief Checks if the window is fullscreen or not.
			 *
			 * @returns True if the window is fullscreen, otherwise false.
			 */
			Bool IsFullscreen(Void) const;

			/**
			 * @brief Checks if the window is transparent or opaque.
			 *
			 * @returns True if the window is transparent, otherwise false.
			 */
			Bool IsTransparent(Void) const;

		public:
			/**
			 * @brief Sets the window title.
			 * 
			 * @param title The title of the window.
			 */
			virtual Void SetTitle(ConstCharPtr title) = 0;									

		public:
			/**
			 * @brief Sets the window opacity.
			 *
			 * This function is valid only for windows with the is_transparent
			 * flag set to true.
			 * 
			 * @param opacity The opacity value of the window
			 */
			virtual Void SetOpacity(F32 opacity) = 0;

		public:
			/**
			 * @brief Sets the client area size of the window not including border.
			 *
			 * @param size The size of the window client region.
			 */
			virtual Void SetClientSize(const Vector2 size) = 0;

			/**
			 * @brief Sets the client area position the window not including
			 * border.
			 *
			 * @returns Vector2 storing the client area position of the window not
			 * including border.
			 */
			virtual Void SetClientPosition(const Vector2 position) = 0;

			/**
			 * @brief Sets the client bounds of the window not including border.
			 *
			 * @param bounds The bounds of the window client region.
			 */
			virtual Void SetClientBounds(const RectangleF32 bounds) = 0;

		public:
			/**
			 * @brief Sets the window size including border.
			 * 
			 * @param size The size of the window.
			 */
			virtual Void SetWindowSize(const Vector2 size) = 0;

			/**
			 * @brief Sets the window position in screen coordinates.
			 * 
			 * @param position The position of the window.
			 */
			virtual Void SetWindowPosition(const Vector2 position) = 0;

		public:
			/**
			 * @brief Sets the window cursor type.
			 *
			 * @params cursor_type The cursor type of the window. 
			 */
			virtual Void SetCursorType(WindowCursorType cursor_type) = 0;

		public:
			/**
			 * @brief Sets wether the window is resizable or not.
			 *
			 * @param is_resizable The flag wether the window is resizable or not.
			 */
			virtual Void SetIsResizable(Bool is_resizable) = 0;

			/**
			 * @brief Sets wether the window is resizable or not.
			 *
			 * @param is_resizable The flag wether the window is resizable or not.
			 */
			virtual Void SetIsDecorated(Bool is_decorated) = 0;

			/**
			 * @brief Sets wether the window is fullscreen or not.
			 *
			 * @param is_fullscreen The flag wether the window is fullscreen or
			 * not.
			 */
			virtual Void SetIsFullscreen(Bool is_fullscreen) = 0;

			/**
			 * @brief Sets wether the window is transparent or not.
			 *
			 * @param is_transparent The flag wether the window is transparent or not.
			 */
			virtual Void SetIsTransparent(Bool is_transparent) = 0;

		public:
			/**
			 * @brief Sets the callback function to call when the window is
			 * closing.
			 *
			 * @param callback The callback function to call at close event.
			 */
			Void OnClose(TDelegate<Void(Void)> callback);

			/**
			 * @brief Sets the callback function to call when the window is
			 * focused.
			 *
			 * @param callback The callback function to call at focus event.
			 */
			Void OnFocus(TDelegate<Void(Bool)> callback);

			/**
			 * @brief Sets the callback function to call when the window is
			 * minimized.
			 *
			 * @param callback The callback function to call at minimize event.
			 */
			Void OnMinimize(TDelegate<Void(Bool)> callback);
			
			/**
			 * @brief Sets the callback function to call when the window is
			 * maximized.
			 *
			 * @param callback The callback function to call at maximize event.
			 */
			Void OnMaximize(TDelegate<Void(Bool)> callback);
			
			/**
			 * @brief Sets the callback function to call when the window is
			 * moved.
			 *
			 * @param callback The callback function to call at move event.
			 */
			Void OnMove(TDelegate<Void(U32, U32)> callback);

			/**
			 * @brief Sets the callback function to call when the window is
			 * resized.
			 *
			 * @param callback The callback function to call at resize event.
			 */
			Void OnResize(TDelegate<Void(U32, U32)> callback);

		public:
			/**
			 * @brief Shows the window but does not activate it.
			 */
			virtual Void Show(Void) = 0;

			/**
			 * @brief Hides the window.
			 */
			virtual Void Hide(Void) = 0;
			
			/**
			 * @brief Focuses the window.
			 */
			virtual Void Focus(Void) = 0;

			/**
			 * @brief Flashes the window.
			 */
			virtual Void Flash(Void) = 0;

			/**
			 * @brief Minimizes the window.
			 */
			virtual Void Minimize(Void) = 0;

			/**
			 * @brief Maximizes the window.
			 */
			virtual Void Maximize(Void) = 0;
			
			/**
			 * @brief Activate the window.
			 */
			virtual Void Activate(Void) = 0;

			/**
			 * @brief Deactivate the window.
			 */
			virtual Void Deactivate(Void) = 0;

			/**
			 * @brief Brings the window to the front of the Z order.
			 *
			 * This functions makes this window the top most window.
			 */
			virtual Void BringToFront(Void) = 0;

			/**
			 * @brief Closes the window.
			 * 
			 * This function destorys the window and frees the native handle.
			 * 
			 * @param window_closing_reason The closing reason of the window.
			 */
			virtual Void Close(WindowClosingReason window_closing_reason) = 0;
		};
	}
}

#endif
