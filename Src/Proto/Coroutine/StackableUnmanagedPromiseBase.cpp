#include "Proto/Coroutine/StackableUnmanagedPromiseBase.h"


namespace proto::coroutine {

	StackableUnmanagedPromiseFinalAwaiter StackableUnmanagedPromiseBase::final_suspend() noexcept {
		return StackableUnmanagedPromiseFinalAwaiter();
	}

}