#include "Proto/Coroutine/StackablePromise.h"
#include "Proto/Coroutine/StackableManagedPromiseBase.h"


namespace proto::coroutine {

	void StackablePromise::set_child(std::coroutine_handle<> child_coroutine_handle, StackableManagedPromiseBase* child_coroutine_promise) {
		this->child_coroutine_handle = child_coroutine_handle;
		this->child_coroutine_promise = child_coroutine_promise;
		return;
	}

	std::coroutine_handle<> StackablePromise::get_deepest_active_handle(std::coroutine_handle<> this_handle) {
		std::coroutine_handle<> deepest_active_handle = this_handle;
		StackableManagedPromiseBase* child_coroutine_promise = this->child_coroutine_promise;
		std::coroutine_handle<> child_coroutine_handle = this->child_coroutine_handle;
		while (child_coroutine_promise != nullptr) {
			deepest_active_handle = child_coroutine_handle;
			child_coroutine_handle = ((StackablePromise*)child_coroutine_promise)->child_coroutine_handle;
			child_coroutine_promise = ((StackablePromise*)child_coroutine_promise)->child_coroutine_promise;
		}
		return deepest_active_handle;
	}

}