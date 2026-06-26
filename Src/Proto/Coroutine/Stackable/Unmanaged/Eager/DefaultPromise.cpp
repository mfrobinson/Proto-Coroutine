#include "Proto/Coroutine/Stackable/Unmanaged/Eager/DefaultPromise.h"
#include "Proto/Coroutine/Stackable/Unmanaged/Eager/DefaultTask.h"


namespace proto::coroutine::stackable::unmanaged::eager {

	DefaultTask DefaultPromise::get_return_object() {
		return DefaultTask(std::coroutine_handle<DefaultPromise>::from_promise(*this));
	}

}