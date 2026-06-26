#pragma once
#include "Proto/Coroutine/Stackable/Unmanaged/Lazy/PromiseBase.h"
#include "Proto/Coroutine/Stackable/PromiseWithResult.h"


namespace proto::coroutine::stackable::unmanaged::lazy {

	using Promise = PromiseWithResult<void, PromiseBase>;

}