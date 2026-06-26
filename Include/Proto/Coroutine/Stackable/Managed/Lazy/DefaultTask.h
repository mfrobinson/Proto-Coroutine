#pragma once
#include "Declarations/Proto/Coroutine/Stackable/Managed/Lazy/DefaultPromise.h"
#include "Proto/Coroutine/Stackable/Managed/Lazy/Task.h"


namespace proto::coroutine::stackable::managed::lazy {

	template <typename TResult>
	class DefaultTask : public Task<DefaultPromise<TResult>, TResult> {
	public:
		using Task<DefaultPromise<TResult>, TResult>::Task;
		using Task<DefaultPromise<TResult>, TResult>::operator=;
	protected:
	private:
	};

}