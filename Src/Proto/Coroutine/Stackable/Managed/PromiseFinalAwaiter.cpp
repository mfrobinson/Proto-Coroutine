#include "Proto/Coroutine/Stackable/Managed/PromiseFinalAwaiter.h"


namespace proto::coroutine::stackable::managed {

	PromiseFinalAwaiter::PromiseFinalAwaiter(std::coroutine_handle<> parent_coroutine, stackable::Promise* parent_coroutine_promise) : parent_coroutine(parent_coroutine), parent_coroutine_promise(parent_coroutine_promise) {
		return;
	}

	bool PromiseFinalAwaiter::await_ready() noexcept {
		return false;
	}

	std::coroutine_handle<> PromiseFinalAwaiter::await_suspend(std::coroutine_handle<> current_coroutine) noexcept {
		if (this->parent_coroutine_promise != nullptr) this->parent_coroutine_promise->set_child(nullptr, nullptr);
		if (this->parent_coroutine != nullptr) return this->parent_coroutine;
		return std::noop_coroutine();
	}

	void PromiseFinalAwaiter::await_resume() noexcept {
		return;
	}

}