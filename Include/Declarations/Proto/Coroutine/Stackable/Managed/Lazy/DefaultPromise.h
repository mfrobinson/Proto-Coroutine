#pragma once
#include "Proto/Coroutine/Stackable/Managed/Lazy/Promise.h"


namespace proto::coroutine::stackable::managed::lazy {

	template <typename TResult>
	class DefaultTask;

	template <typename TResult>
	class DefaultPromise : public Promise<TResult> {
	public:
		DefaultTask<TResult> get_return_object();
	protected:
	private:
	};

}