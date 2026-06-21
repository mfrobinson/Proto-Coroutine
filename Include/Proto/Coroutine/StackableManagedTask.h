#pragma once
#include "Declarations/Proto/Coroutine/StackableManagedTask.h"


namespace proto::coroutine {

	template <StackableManagedPromiseBaseConcept TPromise, typename TResult>
	StackableManagedTask<TPromise, TResult>::~StackableManagedTask() {
		if (this->coroutine_handle) this->coroutine_handle.destroy();
		return;
	}

	template <StackableManagedPromiseBaseConcept TPromise, typename TResult>
	StackableManagedTaskAwaiter<TPromise, TResult> StackableManagedTask<TPromise, TResult>::operator co_await() noexcept {
		return StackableManagedTaskAwaiter<TPromise, TResult>(this->coroutine_handle);
	}

}