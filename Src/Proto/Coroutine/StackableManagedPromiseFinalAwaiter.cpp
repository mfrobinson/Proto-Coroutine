#include "Proto/Coroutine/StackableManagedPromiseFinalAwaiter.h"


namespace proto::coroutine {

	StackableManagedPromiseFinalAwaiter::StackableManagedPromiseFinalAwaiter(std::coroutine_handle<> parent_coroutine) : parent_coroutine(parent_coroutine) {
		return;
	}

	bool StackableManagedPromiseFinalAwaiter::await_ready() noexcept {
		return false;
	}

	std::coroutine_handle<> StackableManagedPromiseFinalAwaiter::await_suspend(std::coroutine_handle<> current_coroutine) noexcept {
		return this->parent_coroutine;
	}

	void StackableManagedPromiseFinalAwaiter::await_resume() noexcept {
		return;
	}

}