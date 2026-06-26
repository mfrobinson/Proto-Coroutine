#pragma once
#include "Proto/Coroutine/Stackable/Managed/Eager/Promise.h"


namespace proto::coroutine::stackable::managed::eager {

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