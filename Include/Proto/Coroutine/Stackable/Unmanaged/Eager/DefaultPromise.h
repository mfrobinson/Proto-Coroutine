#pragma once
#include "Proto/Coroutine/Stackable/Unmanaged/Eager/Promise.h"


namespace proto::coroutine::stackable::unmanaged::eager {

	class DefaultTask;

	class DefaultPromise : public Promise {
	public:
		DefaultTask get_return_object();
	protected:
	private:
	};

}