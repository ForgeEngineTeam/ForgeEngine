#ifndef WINDOWS_PLATFORM_H
#define WINDOWS_PLATFORM_H

#include <Windows.h>

#include <Platform/Public/Base/AbstractPlatform.h>

#if defined(FORGE_PLATFORM_WINDOWS)

namespace Forge {
	namespace Platform
	{
		/**
		 * @brief Windows runtime platform service implemenation.
		 * 
		 * @author Karim Hisham.
		 */
		class FORGE_API WindowsPlatform : public AbstractPlatform, public TSingleton<WindowsPlatform>
		{
		FORGE_CLASS_SINGLETON(WindowsPlatform)

		public:
			ConstCharPtr m_application_window_class = "ForgeEngine";

		public:
			/**
			 * @brief Gets the system memory statistics.
			 *
			 * @returns MemoryStats storing memory statistics.
			 */
			MemoryStats GetMemoryStats(Void) override;

			/**
			 * @brief Gets the current process memory statistics.
			 *
			 * @returns ProcessMemoryStats storing memory statistics.
			 */
			ProcessMemoryStats GetProcessMemoryStats(Void) override;

		public:
			/**
			 * @brief Gets the DPI of the primary display monitor.
			 *
			 * @returns I32 storing the DPI of the primary display monitor.
			 */
			I32 GetPrimaryMonitorDPI(Void) override;

			/**
			 * @brief Gets the size of the primary display monitor in pixels.
			 *
			 * @returns Vector2 storing the size of the primary display monitor.
			 */
			F32 GetPrimiaryMonitorDPIScale(Void) override;

			/**
			 * @brief Gets the size of the primary display monitor in pixels.
			 *
			 * @returns Vector2 storing the size of the primary display monitor.
			 */
			Vector2 GetPrimaryMonitorSize(Void) override;

			/**
			 * @brief Gets the virtual size of all display monitors output
			 * attached.
			 *
			 * @returns Vector2 storing the size of all display monitors.
			 */
			Vector2 GetVirtualMonitorSize(Void) override;

		public:
			/**
			 * @brief Gets the current thread unique identifier.
			 *
			 * @returns U64 storing the thread unique identifier.
			 */
			U64 GetCurrentThreadID(Void) override;

			/**
			 * @brief Gets the current process unique identifier.
			 *
			 * @returns U64 storing the process unique identifier.
			 */
			U64 GetCurrentProcessID(Void) override;

		public:
			/**
			 * @brief Gets the current time as CPU cycles counter.
			 *
			 * @returns U64 storing the CPU cycles counter value.
			 */
			U64 GetSystemTimeCycles(Void) override;

			/**
			 * @brief Gets the current time in seconds.
			 *
			 * @returns U64 storing the time in seconds.
			 */
			F64 GetSystemTimeSeconds(Void) override;

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
			Void GetSystemTimeDate(I32& year, I32& month, I32& week, 
								   I32& day, I32& hour, I32& minute, 
								   I32& second, I32& millisecond) override;

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
			Bool Initialize(VoidPtr handle) override;

			/**
			 * @brief Terminates the runtime platform service.
			 *
			 * This function should be called at the very end of the engine shut down.
			 *
			 * @returns True if platform termination was succesful, otherwise false.
			 */
			Bool Terminate(Void) override;

			/**
			 * @brief Retrieves messages from the platform message queue and
			 * dispatches them to the window associated with the current thread.
			 *
			 * In order to recieve system and input events this function should
			 * be called inside the engine main loop.
			 */
			Bool PumpMessages(Void) override;

		public:
			/**
			 * @brief Indicates to the processor that a cache line will be needed
			 * in the near future..
			 *
			 * @param address The address of the cache line to be loaded.
			 */
			Void PrefetchMemory(VoidPtr address) override;

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
			VoidPtr AllocateMemory(Size size, Size alignment) override;

			/**
			 * @brief Deallocates a block of allocated memory.
			 *
			 * This function deallocates memory on the heap memory segment using
			 * the platform dependant deallocation routine.
			 *
			 * @param address The address of the allocated memory block.
			 */
			Void DeallocateMemory(VoidPtr address) override;

			/**
			 * @brief Allocates a number of pages with a specified size.
			 *
			 * This function allocates pages on the memory using the
			 * platform dependant allocation routine.
			 *
			 * @param count The number of pages to allocate.
			 * @param size The size of the allocated page in bytes.
			 *
			 * @returns VoidPtr storing the address of the allocated pages.
			 */
			VoidPtr AllocatePages(Size count, Size size) override;

			/**
			 * @brief Deallocates a block of allocated pages.
			 *
			 * This function deallocates pages on the memory segment using
			 * the platform dependant deallocation routine.
			 *
			 * @param address The address of the allocated pages.
			 */
			Void DeallocatePages(VoidPtr address) override;

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
			I32 StartProcess(ConstCharPtr filename, ConstCharPtr args, ConstCharPtr working_directory) override;

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
			I32 ExecuteProcess(ConstCharPtr filename, ConstCharPtr args, ConstCharPtr working_directory) override;

		public:
			/**
			 * @brief Creates a platform native window object.
			 *
			 * @param description The window description.
			 *
			 * @returns WindowPtr storing the address of the created window.
			 */
			WindowPtr ConstructWindow(WindowDesc& description) override;

			/**
			 * @brief Creates a platform native window object.
			 *
			 * @param title The window title.
			 *
			 * @returns WindowPtr storing the address of the created window.
			 */
			WindowPtr ConstructWindow(ConstCharPtr title) override;

			/**
			 * @brief Creates a platform native window object.
			 *
			 * @param title The window title.
			 * @param position The window position.
			 *
			 * @returns WindowPtr storing the address of the created window.
			 */
			WindowPtr ConstructWindow(ConstCharPtr title, const Vector2& position) override;

			/**
			 * @brief Creates a platform native window object.
			 *
			 * @param title The window title.
			 * @param position The window position.
			 * @param size The window size.
			 *
			 * @returns WindowPtr storing the address of the created window.
			 */
			WindowPtr ConstructWindow(ConstCharPtr title, const Vector2& position, const Vector2& size) override;

		public:
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
			MessageBoxResult ShowMessageBox(WindowPtr parent, ConstCharPtr text, ConstCharPtr caption, MessageBoxButton button, MessageBoxIcon icon) override;

		public:
			/**
			 * @brief Suspends the execution of the current thread, until the time
			 * out interval elapses.
			 *
			 * @param milliseconds The time interval for which execution is
			 * suspended, in milliseconds.
			 */
			Void Sleep(I32 milliseconds) override;
		};

		using Platform = WindowsPlatform;
		FORGE_TYPEDEF_DECL(Platform)
	}
}

#endif

#endif
