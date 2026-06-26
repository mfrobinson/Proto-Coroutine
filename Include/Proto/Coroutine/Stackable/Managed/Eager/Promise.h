#pragma once
#include "Proto/Coroutine/Stackable/Managed/Eager/PromiseBase.h"
#include "Proto/Coroutine/Stackable/PromiseWithResult.h"


namespace proto::coroutine::stackable::managed::eager {

	template <typename TResult>
	using Promise = PromiseWithResult<TResult, PromiseBase>;

}