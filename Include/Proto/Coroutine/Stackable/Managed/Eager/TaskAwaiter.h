#pragma once
#include "Proto/Coroutine/Stackable/Managed/Eager/TaskAwaiterBase.h"
#include "Proto/Coroutine/Stackable/Managed/TaskAwaiter.h"


namespace proto::coroutine::stackable::managed::eager {

	template <managed::PromiseBaseConcept TPromise, typename TResult>
	using TaskAwaiter = managed::TaskAwaiter<TPromise, TaskAwaiterBase<TPromise>, TResult>;

}