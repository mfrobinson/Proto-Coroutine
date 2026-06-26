#pragma once
#include "Proto/Coroutine/Stackable/Managed/Lazy/PromiseBase.h"
#include "Proto/Coroutine/Stackable/PromiseWithResult.h"


namespace proto::coroutine::stackable::managed::lazy {

	template <typename TResult>
	using Promise = PromiseWithResult<TResult, PromiseBase>;

}