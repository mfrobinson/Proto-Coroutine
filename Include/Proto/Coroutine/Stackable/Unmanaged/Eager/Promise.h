#pragma once
#include "Proto/Coroutine/Stackable/Unmanaged/Eager/PromiseBase.h"
#include "Proto/Coroutine/Stackable/PromiseWithResult.h"


namespace proto::coroutine::stackable::unmanaged::eager {

	using Promise = PromiseWithResult<void, PromiseBase>;

}