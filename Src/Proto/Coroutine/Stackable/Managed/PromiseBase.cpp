#include "Proto/Coroutine/Stackable/Managed/PromiseBase.h"


namespace proto::coroutine::stackable::managed {

	PromiseFinalAwaiter PromiseBase::final_suspend() noexcept {
		return PromiseFinalAwaiter(this->parent_coroutine_handle, this->parent_coroutine_promise);
	}

	void PromiseBase::set_parent(std::coroutine_handle<> parent_coroutine_handle, stackable::Promise* parent_coroutine_promise) {
		this->parent_coroutine_handle = parent_coroutine_handle;
		this->parent_coroutine_promise = parent_coroutine_promise;
		return;
	}

}