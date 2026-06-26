#pragma once
#include "Proto/Coroutine/Stackable/Unmanaged/Lazy/Promise.h"


namespace proto::coroutine::stackable::unmanaged::lazy {

	class DefaultTask;

	class DefaultPromise : public Promise {
	public:
		DefaultTask get_return_object();
	protected:
	private:
	};

}