#include "Proto/Coroutine/Stackable/Unmanaged/Lazy/PromiseBase.h"


namespace proto::coroutine::stackable::unmanaged::lazy {

	std::suspend_always PromiseBase::initial_suspend() {
		return {};
	}

}