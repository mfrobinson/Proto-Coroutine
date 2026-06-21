#pragma once
#include "Proto/Coroutine/StackablePromiseWithResult.h"
#include "Proto/Coroutine/StackableUnmanagedPromiseBase.h"


namespace proto::coroutine {

	template <typename TResult>
	using StackableUnmanagedPromise = StackablePromiseWithResult<TResult, StackableUnmanagedPromiseBase>;

}