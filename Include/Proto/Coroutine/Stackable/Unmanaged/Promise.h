#pragma once
#include "Proto/Coroutine/Stackable/PromiseWithResult.h"
#include "Proto/Coroutine/Stackable/Unmanaged/PromiseBase.h"


namespace proto::coroutine::stackable::unmanaged {

	using Promise = PromiseWithResult<void, PromiseBase>;

}