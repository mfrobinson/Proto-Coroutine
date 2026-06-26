#pragma once
#include "Proto/Coroutine/Stackable/Managed/Lazy/TaskAwaiterBase.h"
#include "Proto/Coroutine/Stackable/Managed/TaskAwaiter.h"


namespace proto::coroutine::stackable::managed::lazy {

	template <managed::PromiseBaseConcept TPromise, typename TResult>
	using TaskAwaiter = managed::TaskAwaiter<TPromise, TaskAwaiterBase<TPromise>, TResult>;

}