#ifndef ABSTRACT_PLATFORM
#define ABSTRACT_PLATFORM

#include <Platform/Public/Window.h>

#include <Core/Public/Math/TVector.h>

#include <Core/Public/Debug/Debug.h>
#include <Core/Public/Types/Types.h>
#include <Core/Public/Common/Common.h>

#include <Core/Public/Memory/MemoryUtilities.h>
#include <Core/Public/Algorithm/GeneralUtilities.h>

#include <Platform/Public/DynamicLibraryManager.h>

using namespace Forge::Math;
using namespace Forge::Common;
using namespace Forge::Memory;
using namespace Forge::Algorithm;

namespace Forge {
	namespace Platform
	{
		enum class MessageBoxIcon : Byte
		{
			/**
			 * @brief The message box does not contain an icon.
			 */
			FORGE_ENUM_DECL(FORGE_NONE,        0x0)

			/**
			 * @brief The message box contains a stop-sign icon.
			 */
			FORGE_ENUM_DECL(FORGE_ERROR,       0x1)

			/**
			 * @brief The message box contains an exclamation-point icon.
			 */
			FORGE_ENUM_DECL(FORGE_WARNING,     0x2)

			/**
			 * @brief The message box contains an icon consisting of a lowercase
			 * letter i in a circle.
			 */
			FORGE_ENUM_DECL(FORGE_INFORMATION, 0x3)

			MAX
		};
		
		enum class MessageBoxButton : Byte
		{
			/**
			 * @brief The message box contains three push buttons: Abort, Retry,
			 * and Ignore.
			 */
			FORGE_ENUM_DECL(FORGE_ABORT_RETRY_IGNORE, 0x0)

			/**
			 * @brief The message box contains three push buttons: Cancel,
			 * Try Again, and Continue.
			 */
			FORGE_ENUM_DECL(FORGE_CANCEL_TRY_CONTINUE, 0x1)

			/**
			 * @brief The message box contains a help button.
			 */
			FORGE_ENUM_DECL(FORGE_HELP,                0x2)

			/**
			 * @brief The message box contains one push button: OK.
			 */
			FORGE_ENUM_DECL(FORGE_OK,                  0x3)

			/**
			 * @brief The message box contains two push buttons: OK and Cancel.
			 */
			FORGE_ENUM_DECL(FORGE_OK_CANCEL,           0x4)

			/**
			 * @brief The message box contains two push buttons: Retry and Cancel.
			 */
			FORGE_ENUM_DECL(FORGE_RETRY_CANCEL,        0x5)

			/**
			 * @brief The message box contains two push buttons: Yes and No.
			 */
			FORGE_ENUM_DECL(FORGE_YES_NO,              0x6)

			/**
			 * @brief The message box contains three push buttons: Yes, No, and Cancel.
			 */
			FORGE_ENUM_DECL(FORGE_YES_NO_CANCEL,       0x7)

			MAX
		};

		enum class MessageBoxResult : Byte
		{
			/**
			 * @brief The Abort button was selected..
			 */
			FORGE_ENUM_DECL(FORGE_NONE,     0x0)

			/**
			 * @brief The Abort button was selected..
			 */
			FORGE_ENUM_DECL(FORGE_ABORT,    0x0)

			/**
			 * @brief The Cancel button was selected.
			 */
			FORGE_ENUM_DECL(FORGE_CANCEL,   0x1)

			/**
			 * @brief The Continue button was selected.
			 */
			FORGE_ENUM_DECL(FORGE_CONTINUE, 0x2)

			/**
			 * @brief The Ignore button was selected.
			 */
			FORGE_ENUM_DECL(FORGE_IGNORE,   0x3)

			/**
			 * @brief The No button was selected.
			 */
			FORGE_ENUM_DECL(FORGE_NO,       0x4)
			
			/**
			 * The OK button was selected.
			 */
			FORGE_ENUM_DECL(FORGE_OK,       0x5)
			
			/**
			 * @brief The Retry button was selected.
			 */
			FORGE_ENUM_DECL(FORGE_RETRY,    0x6)
			
			/**
			 * @brief The Try Again button was selected.
			 */
			FORGE_ENUM_DECL(FORGE_TRYAGAIN, 0x7)
			
			/**
			 * @brief The Yes button was selected.
			 */
			FORGE_ENUM_DECL(FORGE_YES,      0x8)

			MAX
		};

		enum class PlatformType : Byte
		{
			/**
			 * @brief Running on mac platform.
			 */
			FORGE_ENUM_DECL(FORGE_MAC,     0x0)

			/**
			 * @brief Running on linux platform.
			 */
			FORGE_ENUM_DECL(FORGE_LINUX,   0x1)

			/**
			 * @brief Running on android platform.
			 */
			FORGE_ENUM_DECL(FORGE_ANDROID, 0x2)

			/**
			 * @brief Running on windows platform.
			 */
			FORGE_ENUM_DECL(FORGE_WINDOWS, 0x3)

			MAX
		};

		enum class ArchitectureType : Byte
		{
			/**
			 * @brief Running on x86 32-bit.
			 */
			FORGE_ENUM_DECL(FORGE_X86, 0x0)

			/**
			 * @brief Running on x86 64-bit.
			 */
			FORGE_ENUM_DECL(FORGE_X64, 0x1)

			/**
			 * @brief Running on ARM 32-bit.
			 */
			FORGE_ENUM_DECL(FORGE_ARM, 0x2)

			/**
			 * @brief Running on ARM 64-bit.
			 */
			FORGE_ENUM_DECL(FORGE_ARM64, 0x3)

			MAX
		};

		/**
		 * @brief Abstract base class which provides runtime platform service.
		 * 
		 * This class provides all the necessary functions to call platform
		 * native routines, such as creating new processes and threads,
		 * retreiving info about hardware components, memory managment
		 * etc.
		 * 
		 * @author Karim Hisham.
		 */
		class FORGE_API AbstractPlatform
		{
		public:
			struct CPUInfo
			{
				/**
				 * @brief The number of physical processor cores.
				 */
				U32 processor_core_count = 0;

				/**
				 * @brief The CPU clock speed in Hz.
				 */
				F32 processor_clock_speed = 0.0f;

				/**
				 * @brief The number of logical processor cores.
				 */
				U32 processor_logical_count = 0;

				/**
				 * @brief The number of physical processor packages.
				 */
				U32 processor_package_count = 0;

				/**
				 * @brief The size of L1 processor cache in bytes.
				 */
				F32 processor_l1_cache_size = 0;

				/**
				 * @brief The size of L2 processor cache in bytes.
				 */
				F32 processor_l2_cache_size = 0;

				/**
				 * @brief The size of L3 processor cache in bytes.
				 */
				F32 processor_l3_cache_size = 0;

				/**
				 * @brief The processor cache line size in bytes.
				 */
				F32 processor_cache_line_size = 0;
			};

			struct MemoryStats
			{
				/**
				 * @brief The amount of total physical memory in bytes.
				 */
				U32 total_physical_memory = 0;

				/**
				 * @brief The amount of used physical memory in bytes.
				 */
				U32 used_physical_memory = 0;

				/**
				 * @brief The amount of total virtual memory in bytes.
				 */
				U32 total_virtual_memory = 0;

				/**
				 * @brief The amount of used virtual memory in bytes.
				 */
				U32 used_virtual_memory = 0;
			};

			struct ProcessMemoryStats
			{
				/**
				 * @brief The amount of used physical memory in bytes.
				 */
				U32 used_physical_memory = 0;

				/**
				 * @brief The amount of used virtual memory in bytes.
				 */
				U32 used_virtual_memory = 0;
			};
		
		protected:
			VoidPtr m_instance_handle;

		protected:
			CharPtr m_user_name;
			CharPtr m_locale_name;
			CharPtr m_machine_name;

		protected:
			CPUInfo m_cpu_info;
			MemoryStats m_memory_stats;
			ProcessMemoryStats m_process_memory_stats;

		protected:
			DynamicLibraryManager m_dynamic_library_manager;

		protected:
			TDelegate<Void(WindowPtr)> m_window_close_callback;
			TDelegate<Void(WindowPtr, Bool)> m_window_focus_callback;
			TDelegate<Void(WindowPtr, Bool)> m_window_minimize_callback;
			TDelegate<Void(WindowPtr, Bool)> m_window_maximize_callback;
			TDelegate<Void(WindowPtr, U32, U32)> m_window_move_callback;
			TDelegate<Void(WindowPtr, U32, U32)> m_window_resize_callback;
			TDelegate<Void(WindowPtr, I32, I32)> m_mouse_move_callback;
			TDelegate<Void(WindowPtr, I32, I32)> m_mouse_scroll_callback;
			TDelegate<Void(WindowPtr, I32, I32, I32)> m_mouse_button_callback;
			TDelegate<Void(WindowPtr, I32, I32, I32, I32)> m_keyboard_button_callback;

		public:
			/**
			 * @brief Logs the current system information to a log appender.
			 *
			 * This function should be called after the platform service has
			 * been initialized.
			 */
			Void LogSystemInfo(Void);

			/**
			 * @brief Shows an information message to the user.
			 *
			 * This function creates a platform native message box that displays
			 * the message sent as an information.
			 *
			 * @param message The information message to display.
			 */
			Void Info(ConstCharPtr message);															

			/**
			 * @brief Shows a warning message to the user.
			 *
			 * This function creates a platform native message box that displays
			 * the message sent as a warning.
			 *
			 * @param message The warning message to display.
			 */
			Void Warn(ConstCharPtr message);															

			/**
			 * @brief Shows an error message to the user.
			 *
			 * This function creates a platform native message box that displays
			 * the message sent as an error.
			 *
			 * @param message The error message to display.
			 */
			Void Error(ConstCharPtr message);															

			/**
			 * @brief Shows a fatal message to the user.
			 *
			 * This function creates a platform native message box that displays
			 * the message sent as a fatal error, it then creates a stacktrace
			 * and a minidump to be logged to an appender and exits the program.
			 *
			 * @param message The fatal message to display.
			 * @param context The platform dependent context for stacktrace and
			 * minidump collecting.
			 */
			Void Fatal(ConstCharPtr message, VoidPtr context);											

		public:
			/**
			 * @brief Performs a fatal crash to the program.
			 * 
			 * @param line The source line.
			 * @param file The source file.
			 */
			Void Crash(I32 line, ConstCharPtr file);													

			/**
			 * @brief Performs a fatal crash to the program occured on memory
			 * allocation failure.
			 *
			 * @param line The source line.
			 * @param file The source file.
			 */
			Void OutOfMemory(I32 line, ConstCharPtr file);												

			/**
			 * @brief Performs a fatal crash to the program due to code not being
			 * implemented.
			 *
			 * @param line The source line.
			 * @param file The source file.
			 */
			Void MissingCode(I32 line, ConstCharPtr file);												

			/**
			 * @brief Performs a fatal crash to the program due to an assertion
			 * failure check.
			 *
			 * @param line The source line.
			 * @param file The source file.
			 */
			Void AssertionCheck(I32 line, ConstCharPtr file, ConstCharPtr message);						
			
		public:
			/**
			 * @brief Gets the runtime platform handle.
			 *
			 * @returns VoidPtr storing the platform handle, or nullptr if not
			 * supported.
			 */
			VoidPtr GetPlatformHandle(Void);

		public:
			/**
			 * @brief Gets the current runtime platform type.
			 * 
			 * @returns PlatformType storing the platform type.
			 */
			PlatformType GetPlatformType(Void);

			/**
			 * @brief Gets the current system architecture type.
			 *
			 * @returns ArchitectureType storing the architecture type.
			 */
			ArchitectureType GetArchitectureType(Void);

		public:
			/**
			 * @brief Gets the current user name.
			 *
			 * @return ConstCharPtr storing the current user name.
			 */
			ConstCharPtr GetUserLogName(Void);												

			/**
			 * @brief Gets the computer machine name.
			 *
			 * @return ConstCharPtr storing the computer machine name.
			 */
			ConstCharPtr GetMachineName(Void);												

			/**
			 * @brief Gets the current locale culutre.
			 *
			 * @return ConstCharPtr storing the current locale culture.
			 */
			ConstCharPtr GetUserLocaleName(Void);											

		public:
			/**
			 * @brief Gets the system CPU information.
			 * 
			 * @returns CPUInfo storing CPU information.
			 */
			CPUInfo GetCPUInfo(Void);

		public:
			/**
			 * @brief Gets the system memory statistics.
			 *
			 * @returns MemoryStats storing memory statistics.
			 */
			virtual MemoryStats GetMemoryStats(Void) = 0;

			/**
			 * @brief Gets the current process memory statistics.
			 *
			 * @returns ProcessMemoryStats storing memory statistics.
			 */
			virtual ProcessMemoryStats GetProcessMemoryStats(Void) = 0;

		public:
			/**
			 * @brief Gets the DPI of the primary display monitor.
			 *
			 * @returns I32 storing the DPI of the primary display monitor.
			 */
			virtual I32 GetPrimaryMonitorDPI(Void) = 0;

			/**
			 * @brief Gets the size of the primary display monitor in pixels.
			 *
			 * @returns Vector2 storing the size of the primary display monitor.
			 */
			virtual F32 GetPrimiaryMonitorDPIScale(Void) = 0;

			/**
			 * @brief Gets the size of the primary display monitor in pixels.
			 * 
			 * @returns Vector2 storing the size of the primary display monitor.
			 */
			virtual Vector2 GetPrimaryMonitorSize(Void) = 0;

			/**
			 * @brief Gets the virtual size of all display monitors output
			 * attached.
			 *
			 * @returns Vector2 storing the size of all display monitors.
			 */
			virtual Vector2 GetVirtualMonitorSize(Void) = 0;

		public:
			/**
			 * @brief Gets the current thread unique identifier.
			 * 
			 * @returns U64 storing the thread unique identifier.
			 */
			virtual U64 GetCurrentThreadID(Void) = 0;

			/**
			 * @brief Gets the current process unique identifier.
			 *
			 * @returns U64 storing the process unique identifier.
			 */
			virtual U64 GetCurrentProcessID(Void) = 0;

		public:
			/**
			 * @brief Gets the current time as CPU cycles counter.
			 * 
			 * @returns U64 storing the CPU cycles counter value. 
			 */
			virtual U64 GetSystemTimeCycles(Void) = 0;

			/**
			 * @brief Gets the current time in seconds.
			 *
			 * @returns U64 storing the time in seconds.
			 */
			virtual F64 GetSystemTimeSeconds(Void) = 0;

			/**
			 * @brief Gets the current system time based on the computer
			 * settings.
			 * 
			 * @param year The result year value.
			 * @param month The result month value.
			 * @param week The result week value.
			 * @param day The result day value.
			 * @param hour The result hour value.
			 * @param minute The result minute value.		
			 * @param second The result second value.
			 * @param millisecond The result millisecond value.
			 */
			virtual Void GetSystemTimeDate(I32& year, I32& month, I32& week, 
				                           I32& day, I32& hour, I32& minute, 
										   I32& second, I32& millisecond) = 0;

		public:
			/**
			 * @brief Sets the callback function to call when the window is
			 * closing.
			 *
			 * @param callback The callback function to call at close event.
			 */
			Void SetWindowCloseCallback(TDelegate<Void(WindowPtr)> callback);

			/**
			 * @brief Sets the callback function to call when the window is
			 * focused.
			 *
			 * @param callback The callback function to call at focus event.
			 */
			Void SetWindowFocusCallback(TDelegate<Void(WindowPtr, Bool)> callback);

			/**
			 * @brief Sets the callback function to call when the window is
			 * minimized.
			 *
			 * @param callback The callback function to call at minimize event.
			 */
			Void SetWindowMinimizeCallback(TDelegate<Void(WindowPtr, Bool)> callback);

			/**
			 * @brief Sets the callback function to call when the window is
			 * maximized.
			 *
			 * @param callback The callback function to call at maximize event.
			 */
			Void SetWindowMaximizeCallback(TDelegate<Void(WindowPtr, Bool)> callback);

			/**
			 * @brief Sets the callback function to call when the window is
			 * moved.
			 *
			 * @param callback The callback function to call at move event.
			 */
			Void SetWindowMoveCallback(TDelegate<Void(WindowPtr, U32, U32)> callback);

			/**
			 * @brief Sets the callback function to call when the window is
			 * resized.
			 *
			 * @param callback The callback function to call at resize event.
			 */
			Void SetWindowResizeCallback(TDelegate<Void(WindowPtr, U32, U32)> callback);

			/**
			 * @brief Sets the callback function to call when the mouse cursor is
			 * moved.
			 *
			 * @param callback The callback function to call at mouse cursor move
			 * event.
			 */
			Void SetMouseMoveCallback(TDelegate<Void(WindowPtr, I32, I32)> callback);

			/**
			 * @brief Sets the callback function to call when the mouse cursor is
			 * moved.
			 *
			 * @param callback The callback function to call at mouse cursor move
			 * event.
			 */
			Void SetMouseScrollCallback(TDelegate<Void(WindowPtr, I32, I32)> callback);

			/**
			 * @brief Sets the callback function to call when the mouse cursor is
			 * moved.
			 *
			 * @param callback The callback function to call at mouse cursor move
			 * event.
			 */
			Void SetMouseButtonCallback(TDelegate<Void(WindowPtr, I32, I32, I32)> callback);

			/**
			 * @brief Sets the callback function to call when the mouse cursor is
			 * moved.
			 *
			 * @param callback The callback function to call at mouse cursor move
			 * event.
			 */
			Void SetKeyboardCallback(TDelegate<Void(WindowPtr, I32, I32, I32, I32)> callback);
			
		public:
			/**
			 * @brief Initializes the runtime platform service.
			 *
			 * This function should be called at the very start of the engine start up.
			 *
			 * @param handle The handle of the process if required by the platfrom
			 * service.
			 * 
			 * @returns True if platform initialization was succesful, otherwise false.
			 */
			virtual Bool Initialize(VoidPtr handle) = 0;

			/**
			 * @brief Terminates the runtime platform service.
			 *
			 * This function should be called at the very end of the engine shut down.
			 *
			 * @returns True if platform termination was succesful, otherwise false.
			 */
			virtual Bool Terminate(Void) = 0;

			/**
			 * @brief Retrieves messages from the platform message queue and
			 * dispatches them to the window associated with the current thread.
			 *
			 * this function should be called inside the engine main loop In order
			 * to recieve system and input events.
			 */
			virtual Bool PumpMessages(Void) = 0;

		public:
			/**
			 * @brief Indicates to the processor that a cache line will be needed
			 * in the near future.
			 * 
			 * @param address The address of the cache line to be loaded. 
			 */
			virtual Void PrefetchMemory(VoidPtr address) = 0;

			/**
			 * @brief Allocates a block of memory with a specified alignment
			 * boundry.
			 * 
			 * This function allocates memory on the heap memory segment using the
			 * platform dependant allocation routine.
			 * 
			 * @param size The number of bytes to allocate.
			 * @param alignment The alignment boundry of the allocated memory block.
			 * 
			 * @returns VoidPtr storing the address of the allocated memory block.
			 */
			virtual VoidPtr AllocateMemory(Size size, Size alignment) = 0;

			/**
			 * @brief Deallocates a block of allocated memory.
			 *
			 * This function deallocates memory on the heap memory segment using 
			 * the platform dependant deallocation routine.
			 *
			 * @param address The address of the allocated memory block.
			 */
			virtual Void DeallocateMemory(VoidPtr address) = 0;

			/**
			 * @brief Allocates a number of pages with a specified size.
			 *
			 * This function allocates pages on the virtual memory using the
			 * platform dependant allocation routine.
			 *
			 * @param count The number of pages to allocate.
			 * @param size The size of the allocated page in bytes.
			 *
			 * @returns VoidPtr storing the address of the allocated pages.
			 */
			virtual VoidPtr AllocatePages(Size count, Size size) = 0;

			/**
			 * @brief Deallocates a block of allocated pages.
			 *
			 * This function deallocates pages on the virtual memory segment using
			 * the platform dependant deallocation routine.
			 * 
			 * @param address The address of the allocated pages.
			 */
			virtual Void DeallocatePages(VoidPtr address) = 0;
			
		public:
			/**
			 * @brief Creates a new process that runs simultaneously with the
			 * current process.
			 * 
			 * @param filename The filename of the process to create.
			 * @param args The command line arguments of the process to create.
			 * @param working_directory The working directory of the process.
			 * 
			 * @returns I32 storing the termination status of the created process.
			 */
			virtual I32 StartProcess(ConstCharPtr filename, ConstCharPtr args, ConstCharPtr working_directory) = 0;

			/**
			 * @brief Executes a new process that blocks execution of the current
			 * process until it finishes.
			 *
			 * @param filename The filename of the process to create.
			 * @param args The command line arguments of the process to create.
			 * @param working_directory The working directory of the process.
			 *
			 * @returns I32 storing the termination status of the created process.
			 */
			virtual I32 ExecuteProcess(ConstCharPtr filename, ConstCharPtr args, ConstCharPtr working_directory) = 0;

		public:
			/**
			 * @brief Creates a platform native window object.
			 * 
			 * @param description The window description.
			 * 
			 * @returns WindowPtr storing the address of the created window.
			 */
			virtual WindowPtr ConstructWindow(WindowDesc& description) = 0;

			/**
			 * @brief Creates a platform native window object.
			 *
			 * @param title The window title.
			 *
			 * @returns WindowPtr storing the address of the created window.
			 */
			virtual WindowPtr ConstructWindow(ConstCharPtr title) = 0;

			/**
			 * @brief Creates a platform native window object.
			 *
			 * @param title The window title.
			 * @param position The window position.
			 *
			 * @returns WindowPtr storing the address of the created window.
			 */
			virtual WindowPtr ConstructWindow(ConstCharPtr title, const Vector2& position) = 0;

			/**
			 * @brief Creates a platform native window object.
			 *
			 * @param title The window title.
			 * @param position The window position.
			 * @param size The window size.
			 *
			 * @returns WindowPtr storing the address of the created window.
			 */
			virtual WindowPtr ConstructWindow(ConstCharPtr title, const Vector2& position, const Vector2& size) = 0;

		public:
			/**
			 * @brief Displays a message box with a specified text.
			 * 
			 * @param text The text to display in the message box.
			 * 
			 * @returns MessageBoxResult storing the message box dialog result.
			 */
			MessageBoxResult ShowMessageBox(ConstCharPtr text);

			/**
			 * @brief Displays a message box with a specified text.
			 *
			 * @param parent The parent window to the message box.
			 * @param text The text to display in the message box.
			 *
			 * @returns MessageBoxResult storing the message box dialog result.
			 */
			MessageBoxResult ShowMessageBox(WindowPtr parent, ConstCharPtr text);

			/**
			 * @brief Displays a message box with a specified text and caption.
			 *
			 * @param text The text to display in the message box.
			 * @param caption The caption to display in the message box.
			 *
			 * @returns MessageBoxResult storing the message box dialog result.
			 */
			MessageBoxResult ShowMessageBox(ConstCharPtr text, ConstCharPtr caption);

			/**
			 * @brief Displays a message box with a specified text and caption.
			 *
			 * @param parent The parent window to the message box.
			 * @param text The text to display in the message box.
			 * @param caption The caption to display in the message box.
			 *
			 * @returns MessageBoxResult storing the message box dialog result.
			 */
			MessageBoxResult ShowMessageBox(WindowPtr parent, ConstCharPtr text, ConstCharPtr caption);
			
			/**
			 * @brief Displays a message box with a specified text, caption and
			 * buttons.
			 *
			 * @param text The text to display in the message box.
			 * @param caption The caption to display in the message box.
			 * @param button The button to display in the message box.
			 * 
			 * @returns MessageBoxResult storing the message box dialog result.
			 */
			MessageBoxResult ShowMessageBox(ConstCharPtr text, ConstCharPtr caption, MessageBoxButton button);

			/**
			 * @brief Displays a message box with a specified text, caption and
			 * buttons.
			 *
			 * @param parent The parent window to the message box.
			 * @param text The text to display in the message box.
			 * @param caption The caption to display in the message box.
			 * @param button The button to display in the message box.
			 *
			 * @returns MessageBoxResult storing the message box dialog result.
			 */
			MessageBoxResult ShowMessageBox(WindowPtr parent, ConstCharPtr text, ConstCharPtr caption, MessageBoxButton button);
			
			/**
			 * @brief Displays a message box with a specified text, caption,
			 * buttons and icon.
			 *
			 * @param text The text to display in the message box.
			 * @param caption The caption to display in the message box.
			 * @param button The button to display in the message box.
			 * @param icon The icon to display in the message box.
			 *
			 * @returns MessageBoxResult storing the message box dialog result.
			 */
			MessageBoxResult ShowMessageBox(ConstCharPtr text, ConstCharPtr caption, MessageBoxButton button, MessageBoxIcon icon);

			/**
			 * @brief Displays a message box with a specified text, caption,
			 * buttons and icon.
			 *
			 * @param parent The parent window to the message box.
			 * @param text The text to display in the message box.
			 * @param caption The caption to display in the message box.
			 * @param button The button to display in the message box.
			 * @param icon The icon to display in the message box.
			 *
			 * @returns MessageBoxResult storing the message box dialog result.
			 */
			virtual MessageBoxResult ShowMessageBox(WindowPtr parent, ConstCharPtr text, ConstCharPtr caption, MessageBoxButton button, MessageBoxIcon icon) = 0;

		public:
			/**
			 * @brief Loads a dynamic library into the address space of the 
			 * process.
			 * 
			 * @param filename[in] The filename of the dynamic library to
			 * load.
			 * 
			 * @returns TWeakPtr<AbstractDynamicLibrary> storing the loaded
			 * dynamic library.
			 * 
			 * @throw InvalidIOException if failed to load dynamic library. 
			 */
			virtual TWeakPtr<DynamicLibrary> LoadDynamicLibrary(ConstCharPtr filename);

			/**
			 * @brief Unloads a dynamic library from the address space of the
			 * process.
			 * 
			 * @param dynamic_library[in] The handle of the dynamic library to
			 * unload.
			 * 
			 * @throw InvalidOperationException if the dynamic library is null or not
			 * present in the registry.
			 */
			virtual Void UnloadDynamicLibrary(TWeakPtr<DynamicLibrary> dynamic_library);

		public:
			/**
			 * @brief Suspends the execution of the current process, until the time
			 * out interval elapses.
			 * 
			 * @param milliseconds The time interval for which execution is
			 * suspended, in milliseconds.
			 */
			virtual Void Sleep(I32 milliseconds) = 0;
		};
	}
}

#endif
