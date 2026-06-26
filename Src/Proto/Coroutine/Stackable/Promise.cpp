#include "Proto/Coroutine/Stackable/Promise.h"
#include "Proto/Coroutine/Stackable/Managed/PromiseBase.h"


namespace proto::coroutine::stackable {

	void Promise::set_child(std::coroutine_handle<> child_coroutine_handle, managed::PromiseBase* child_coroutine_promise) {
		this->child_coroutine_handle = child_coroutine_handle;
		this->child_coroutine_promise = child_coroutine_promise;
		return;
	}

	std::coroutine_handle<> Promise::get_deepest_active_handle(std::coroutine_handle<> this_handle) {
		std::coroutine_handle<> deepest_active_handle = this_handle;
		managed::PromiseBase* child_coroutine_promise = this->child_coroutine_promise;
		std::coroutine_handle<> child_coroutine_handle = this->child_coroutine_handle;
		while (child_coroutine_promise != nullptr) {
			deepest_active_handle = child_coroutine_handle;
			child_coroutine_handle = ((Promise*)child_coroutine_promise)->child_coroutine_handle;
			child_coroutine_promise = ((Promise*)child_coroutine_promise)->child_coroutine_promise;
		}
		return deepest_active_handle;
	}

}