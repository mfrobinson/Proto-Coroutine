#include "Proto/Coroutine/Stackable/Unmanaged/Eager/PromiseBase.h"


namespace proto::coroutine::stackable::unmanaged::eager {

	std::suspend_never PromiseBase::initial_suspend() {
		return {};
	}

}