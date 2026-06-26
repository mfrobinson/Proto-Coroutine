#pragma once
#include "Proto/Coroutine/Stackable/PromiseWithResult.h"
#include "Proto/Coroutine/Stackable/Managed/PromiseBase.h"


namespace proto::coroutine::stackable::managed {

	template <typename TResult>
	using Promise = PromiseWithResult<TResult, PromiseBase>;

}