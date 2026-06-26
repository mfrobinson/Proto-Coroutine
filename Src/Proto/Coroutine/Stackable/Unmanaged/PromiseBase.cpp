#include "Proto/Coroutine/Stackable/Unmanaged/PromiseBase.h"


namespace proto::coroutine::stackable::unmanaged {

	std::suspend_never PromiseBase::final_suspend() noexcept {
		return {};
	}

}