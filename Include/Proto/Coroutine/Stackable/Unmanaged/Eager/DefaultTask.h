#pragma once
#include "Proto/Coroutine/Stackable/Unmanaged/Eager/DefaultPromise.h"
#include "Proto/Coroutine/Stackable/Unmanaged/Task.h"


namespace proto::coroutine::stackable::unmanaged::eager {

	class DefaultTask : public Task<DefaultPromise> {
	public:
		using Task<DefaultPromise>::Task;
		using Task<DefaultPromise>::operator=;
	protected:
	private:
	};

}