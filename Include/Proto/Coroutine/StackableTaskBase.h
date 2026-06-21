#pragma once
#include "Declarations/Proto/Coroutine/StackableTaskBase.h"


namespace proto::coroutine {

	template <StackablePromiseConcept TPromise, typename TResult>
	StackableTaskBase<TPromise, TResult>::StackableTaskBase(handle_type handle) : coroutine_handle(handle) {
		return;
	}

	template <StackablePromiseConcept TPromise, typename TResult>
	StackableTaskBase<TPromise, TResult>::StackableTaskBase(StackableTaskBase<TPromise, TResult>&& other) noexcept : coroutine_handle(std::exchange(other.coroutine_handle, nullptr)) {
		return;
	}

	template <StackablePromiseConcept TPromise, typename TResult>
	StackableTaskBase<TPromise, TResult>& StackableTaskBase<TPromise, TResult>::operator=(StackableTaskBase<TPromise, TResult>&& other) noexcept {
		if (this != &other) {
			if (coroutine_handle) coroutine_handle.destroy();
				coroutine_handle = std::exchange(other.coroutine_handle, nullptr);
			}
		return *this;
	}

	template <StackablePromiseConcept TPromise, typename TResult>
	void StackableTaskBase<TPromise, TResult>::resume() {
		if (coroutine_handle && !coroutine_handle.done()) {
			auto deepest = coroutine_handle.promise().get_deepest_active_handle(coroutine_handle);
			deepest.resume();
		}
	}

}