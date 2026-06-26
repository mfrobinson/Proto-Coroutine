#pragma once
#include "Proto/Coroutine/Stackable/Managed/Eager/TaskAwaiter.h"
#include "Proto/Coroutine/Stackable/Managed/Task.h"


namespace proto::coroutine::stackable::managed::eager {

	template <managed::PromiseBaseConcept TPromise, typename TResult>
	using Task = managed::Task<TPromise, TResult, TaskAwaiter<TPromise, TResult>>;

}