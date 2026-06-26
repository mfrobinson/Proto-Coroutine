#pragma once
#include "Declarations/Proto/Coroutine/Stackable/Managed/Eager/DefaultPromise.h"
#include "Proto/Coroutine/Stackable/Managed/Eager/DefaultTask.h"


namespace proto::coroutine::stackable::managed::eager {

	template <typename TResult>
	DefaultTask<TResult> DefaultPromise<TResult>::get_return_object() {
		return DefaultTask<TResult>(std::coroutine_handle<DefaultPromise<TResult>>::from_promise(*this));
	}

}