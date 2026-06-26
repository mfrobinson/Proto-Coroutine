#pragma once
#include "Declarations/Proto/Coroutine/Stackable/Managed/Task.h"


namespace proto::coroutine::stackable::managed {

	template <managed::PromiseBaseConcept TPromise, typename TResult, typename TAwaiter>
	Task<TPromise, TResult, TAwaiter>::~Task() {
		if (this->coroutine_handle) this->coroutine_handle.destroy();
		return;
	}

	template <managed::PromiseBaseConcept TPromise, typename TResult, typename TAwaiter>
	TAwaiter Task<TPromise, TResult, TAwaiter>::operator co_await() noexcept {
		return TAwaiter(this->coroutine_handle);
	}

}