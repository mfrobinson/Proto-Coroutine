#pragma once
#include "Proto/Coroutine/StackablePromiseWithResult.h"
#include "Proto/Coroutine/StackableManagedPromiseBase.h"


namespace proto::coroutine {

	template <typename TResult>
	using StackableManagedPromise = StackablePromiseWithResult<TResult, StackableManagedPromiseBase>;

}