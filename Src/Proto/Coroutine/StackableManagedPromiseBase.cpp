#include "Proto/Coroutine/StackableManagedPromiseBase.h"


namespace proto::coroutine {

	StackableManagedPromiseFinalAwaiter StackableManagedPromiseBase::final_suspend() noexcept {
		return StackableManagedPromiseFinalAwaiter(this->parent_coroutine_handle);
	}

	void StackableManagedPromiseBase::set_parent(std::coroutine_handle<> parent_coroutine_handle, StackablePromise* parent_coroutine_promise) {
		this->parent_coroutine_handle = parent_coroutine_handle;
		this->parent_coroutine_promise = parent_coroutine_promise;
		return;
	}

}