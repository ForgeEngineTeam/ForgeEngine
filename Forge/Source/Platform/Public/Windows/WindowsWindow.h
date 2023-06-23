#ifndef WINDOWS_WINDOW_H
#define WINDOWS_WINDOW_H

#include <Windows.h>

#include "Platform/Public/Base/AbstractWindow.h"

#if defined(FORGE_PLATFORM_WINDOWS)

namespace Forge {
	namespace Platform
	{
		/**
		 * @brief Windows native window.
		 * 
		 * @author Karim Hisham.
		 */
		class FORGE_API WindowsWindow : public AbstractWindow
		{
		public:
			/**
			 * @brief Default constructor.
			 *
			 * Creates a platform dependant window using a description structure.
			 *
			 * @param description The window description.
			 */
			WindowsWindow(const WindowDesc& description);

			/**
			 * Destructor.
			 */
			~WindowsWindow(Void) = default;

		public:
			/**
			 * @brief Gets the window size including border.
			 *
			 * @returns Vector2 storing the window size including border.
			 */
			Vector2 GetWindowSize(Void) const override;

			/**
			 * @brief Gets the window position in screen coordinates.
			 *
			 * @returns Vector2 storing the window position in screen coordinates.
			 */
			Vector2 GetWindowPosition(Void) const override;

		public:
			/**
			 * @brief Converts client space location into screen space location
			 * and returns the new position.
			 *
			 * @param client_position The client space position to convert.
			 *
			 * @returns Vector2 storing the converted screen space position.
			 */
			Vector2 GetClientToScreen(Vector2 client_position) const override;

			/**
			 * @brief Converts client space location into screen space location
			 * and returns the new position.
			 *
			 * @param client_position The client space position to convert.
			 *
			 * @returns Vector2 storing the converted client space position.
			 */
			Vector2 GetScreenToClient(Vector2 screen_position) const override;

		public:
			/**
			 * @brief Sets the window title.
			 *
			 * @param title The title of the window.
			 */
			Void SetTitle(ConstCharPtr title) override;

		public:
			/**
			 * @brief Sets the window opacity.
			 *
			 * This function is valid only for windows with the is_transparent
			 * flag set to true.
			 *
			 * @param opacity The opacity value of the window
			 */
			Void SetOpacity(F32 opacity) override;

		public:
			/**
			 * @brief Sets the client area size of the window not including border.
			 *
			 * @param size The size of the window client region.
			 */
			Void SetClientSize(const Vector2 size) override;

			/**
			 * @brief Sets the client area position the window not including
			 * border.
			 *
			 * @returns Vector2 storing the client area position of the window not
			 * including border.
			 */
			Void SetClientPosition(const Vector2 position) override;

			/**
			 * @brief Sets the client bounds of the window not including border.
			 *
			 * @param bounds The bounds of the window client region.
			 */
			Void SetClientBounds(const RectangleF32 bounds) override;

		public:
			/**
			 * @brief Sets the window size including border.
			 *
			 * @param size The size of the window.
			 */
			Void SetWindowSize(const Vector2 size) override;

			/**
			 * @brief Sets the window position in screen coordinates.
			 *
			 * @param position The position of the window.
			 */
			Void SetWindowPosition(const Vector2 position) override;

		public:
			/**
			 * @brief Sets the window cursor type.
			 *
			 * @params cursor_type The cursor type of the window.
			 */
			Void SetCursorType(WindowCursorType cursor_type) override;

		public:
			/**
			 * @brief Sets wether the window is resizable or not.
			 *
			 * @param is_resizable The flag wether the window is resizable or not.
			 */
			Void SetIsResizable(Bool is_resizable) override;

			/**
			 * @brief Sets wether the window is resizable or not.
			 *
			 * @param is_resizable The flag wether the window is resizable or not.
			 */
			Void SetIsDecorated(Bool is_decorated) override;

			/**
			 * @brief Sets wether the window is fullscreen or not.
			 *
			 * @param is_fullscreen The flag wether the window is fullscreen or
			 * not.
			 */
			Void SetIsFullscreen(Bool is_fullscreen) override;

			/**
			 * @brief Sets wether the window is transparent or not.
			 *
			 * @param is_transparent The flag wether the window is transparent or not.
			 */
			Void SetIsTransparent(Bool is_transparent) override;

		public:
			/**
			 * @brief Shows the window but does not activate it.
			 */
			Void Show(Void) override;

			/**
			 * @brief Hides the window.
			 */
			Void Hide(Void) override;

			/**
			 * @brief Focuses the window.
			 */
			Void Focus(Void) override;

			/**
			 * @brief Flashes the window.
			 */
			Void Flash(Void) override;

			/**
			 * @brief Minimizes the window.
			 */
			Void Minimize(Void) override;

			/**
			 * @brief Maximizes the window.
			 */
			Void Maximize(Void) override;

			/**
			 * @brief Activate the window.
			 */
			Void Activate(Void) override;

			/**
			 * @brief Deactivate the window.
			 */
			Void Deactivate(Void) override;

			/**
			 * @brief Brings the window to the front of the Z order.
			 *
			 * This functions makes this window the top most window.
			 */
			Void BringToFront(Void) override;

			/**
			 * @brief Closes the window.
			 *
			 * This function destorys the window and frees the native handle.
			 *
			 * @param window_closing_reason The closing reason of the window.
			 */
			Void Close(WindowClosingReason window_closing_reason) override;
		};

		using Window = WindowsWindow;
		FORGE_TYPEDEF_DECL(Window)
	}
}

#endif

#endif
