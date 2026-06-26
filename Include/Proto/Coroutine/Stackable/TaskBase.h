#pragma once
#include "Declarations/Proto/Coroutine/Stackable/TaskBase.h"


namespace proto::coroutine::stackable {

	template <PromiseConcept TPromise, typename TResult>
	TaskBase<TPromise, TResult>::TaskBase(handle_type handle) : coroutine_handle(handle) {
		return;
	}

	template <PromiseConcept TPromise, typename TResult>
	TaskBase<TPromise, TResult>::TaskBase(TaskBase<TPromise, TResult>&& other) noexcept : coroutine_handle(std::exchange(other.coroutine_handle, nullptr)) {
		return;
	}

	template <PromiseConcept TPromise, typename TResult>
	TaskBase<TPromise, TResult>& TaskBase<TPromise, TResult>::operator=(TaskBase<TPromise, TResult>&& other) noexcept {
		if (this != &other) {
			if (coroutine_handle) coroutine_handle.destroy();
			coroutine_handle = std::exchange(other.coroutine_handle, nullptr);
		}
		return *this;
	}

	template <PromiseConcept TPromise, typename TResult>
	void TaskBase<TPromise, TResult>::resume() {
		if (coroutine_handle && !coroutine_handle.done()) {
			auto deepest = coroutine_handle.promise().get_deepest_active_handle(coroutine_handle);
			deepest.resume();
		}
	}

}