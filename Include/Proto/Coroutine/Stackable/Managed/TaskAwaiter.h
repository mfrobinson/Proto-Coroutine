#pragma once
#include "Declarations/Proto/Coroutine/Stackable/Managed/TaskAwaiter.h"


namespace proto::coroutine::stackable::managed {

	template <managed::PromiseBaseConcept TPromise, typename TBase, typename TResult>
	TResult TaskAwaiter<TPromise, TBase, TResult>::await_resume() {
		return this->child_coroutine_handle.promise().get_result();
	}

	template <PromiseBaseConcept TPromise, typename TBase>
	void TaskAwaiter<TPromise, TBase, void>::await_resume() {
		this->child_coroutine_handle.promise().rethrow_if_uncaught();
		return;
	}

}