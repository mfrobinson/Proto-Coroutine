#include "Proto/Coroutine/Stackable/Managed/Eager/PromiseBase.h"


namespace proto::coroutine::stackable::managed::eager {

	std::suspend_never PromiseBase::initial_suspend() {
		return {};
	}

}