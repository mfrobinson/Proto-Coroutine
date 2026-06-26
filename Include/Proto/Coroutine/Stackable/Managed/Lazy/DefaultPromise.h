#pragma once
#include "Declarations/Proto/Coroutine/Stackable/Managed/Lazy/DefaultPromise.h"
#include "Proto/Coroutine/Stackable/Managed/Lazy/DefaultTask.h"


namespace proto::coroutine::stackable::managed::lazy {

	template <typename TResult>
	DefaultTask<TResult> DefaultPromise<TResult>::get_return_object() {
		return DefaultTask<TResult>(std::coroutine_handle<DefaultPromise<TResult>>::from_promise(*this));
	}

}