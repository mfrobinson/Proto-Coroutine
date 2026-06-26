#include "Proto/Coroutine/Stackable/Managed/Lazy/PromiseBase.h"


namespace proto::coroutine::stackable::managed::lazy {

	std::suspend_always PromiseBase::initial_suspend() {
		return {};
	}

}