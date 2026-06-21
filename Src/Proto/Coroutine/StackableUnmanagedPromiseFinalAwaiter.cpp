#include "Proto/Coroutine/StackableUnmanagedPromiseFinalAwaiter.h"


namespace proto::coroutine {
	
	StackableUnmanagedPromiseFinalAwaiter::StackableUnmanagedPromiseFinalAwaiter() {
		return;
	}

	bool StackableUnmanagedPromiseFinalAwaiter::await_ready() noexcept {
		return false;
	}

	void StackableUnmanagedPromiseFinalAwaiter::await_suspend(std::coroutine_handle<> current_coroutine) noexcept {
		return;
	}

	void StackableUnmanagedPromiseFinalAwaiter::await_resume() noexcept {
		return;
	}

}