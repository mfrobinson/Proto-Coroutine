#pragma once
#include "Declarations/Proto/Coroutine/StackableManagedTaskAwaiter.h"


namespace proto::coroutine {
	
	template <StackableManagedPromiseBaseConcept TPromise, typename TResult>
	TResult StackableManagedTaskAwaiter<TPromise, TResult>::await_resume() {
		return this->child_coroutine_handle.promise().get_result();
	}

	template <StackableManagedPromiseBaseConcept TPromise>
	void StackableManagedTaskAwaiter<TPromise, void>::await_resume() {
		this->child_coroutine_handle.promise().rethrow_if_uncaught();
		return;
	}

}