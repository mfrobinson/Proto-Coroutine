#pragma once
#include "Declarations/Proto/Coroutine/StackableUnmanagedTask.h"
#include <stdexcept>


namespace proto::coroutine {

	template <StackableUnmanagedPromiseBaseConcept TPromise, typename TResult>
	StackableUnmanagedTaskAwaiter<TPromise> StackableUnmanagedTask<TPromise, TResult>::operator co_await() noexcept {
		throw std::runtime_error("Cannot co_await an unmanaged task!");
	}

}