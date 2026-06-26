#pragma once
#include "Proto/Coroutine/Stackable/Unmanaged/Lazy/DefaultPromise.h"
#include "Proto/Coroutine/Stackable/Unmanaged/Task.h"


namespace proto::coroutine::stackable::unmanaged::lazy {

	class DefaultTask : public Task<DefaultPromise> {
	public:
		using Task<DefaultPromise>::Task;
		using Task<DefaultPromise>::operator=;
	protected:
	private:
	};

}