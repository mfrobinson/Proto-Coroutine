#pragma once
#include "Declarations/Proto/Coroutine/StackableUnmanagedTaskAwaiter.h"


namespace proto::coroutine {

	template <StackableUnmanagedPromiseBaseConcept TPromise>
	StackableUnmanagedTaskAwaiter<TPromise>::StackableUnmanagedTaskAwaiter() {
		return;
	}

	template <StackableUnmanagedPromiseBaseConcept TPromise>
	void StackableUnmanagedTaskAwaiter<TPromise>::await_ready() noexcept {
		return;
	}

	template <StackableUnmanagedPromiseBaseConcept TPromise>
	template <StackablePromiseConcept TParentPromise>
	void StackableUnmanagedTaskAwaiter<TPromise>::await_suspend(std::coroutine_handle<TParentPromise> parent_coroutine_handle) noexcept {
		return;
	}

	template <StackableUnmanagedPromiseBaseConcept TPromise>
	void StackableUnmanagedTaskAwaiter<TPromise>::await_resume() noexcept {
		return;
	}

}