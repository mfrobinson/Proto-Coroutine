#pragma once
#include "Proto/Coroutine/Stackable/Managed/PromiseBaseConcept.h"


namespace proto::coroutine::stackable::managed {

	template <PromiseBaseConcept TPromise, typename TBase, typename TResult>
	class TaskAwaiter : public TBase {
	public:
		using TBase::TBase;

		TResult await_resume();
	protected:
	private:
		using TBase::child_coroutine_handle;
	};

	template <PromiseBaseConcept TPromise, typename TBase>
	class TaskAwaiter<TPromise, TBase, void> : public TBase {
	public:
		using TBase::TBase;

		void await_resume();
	protected:
	private:
		using TBase::child_coroutine_handle;
	};

}