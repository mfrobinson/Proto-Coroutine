#include "Proto/Coroutine/Stackable/Unmanaged/Lazy/DefaultPromise.h"
#include "Proto/Coroutine/Stackable/Unmanaged/Lazy/DefaultTask.h"


namespace proto::coroutine::stackable::unmanaged::lazy {

	DefaultTask DefaultPromise::get_return_object() {
		return DefaultTask(std::coroutine_handle<DefaultPromise>::from_promise(*this));
	}

}