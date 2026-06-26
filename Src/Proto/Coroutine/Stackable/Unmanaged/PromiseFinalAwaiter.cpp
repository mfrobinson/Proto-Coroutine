#include "Proto/Coroutine/Stackable/Unmanaged/PromiseFinalAwaiter.h"


namespace proto::coroutine::stackable::unmanaged {
	
	PromiseFinalAwaiter::PromiseFinalAwaiter() {
		return;
	}

	bool PromiseFinalAwaiter::await_ready() noexcept {
		return false;
	}

	void PromiseFinalAwaiter::await_suspend(std::coroutine_handle<> current_coroutine) noexcept {
		return;
	}

	void PromiseFinalAwaiter::await_resume() noexcept {
		return;
	}

}