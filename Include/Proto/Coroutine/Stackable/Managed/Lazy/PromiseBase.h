#pragma once
#include "Proto/Coroutine/Stackable/Managed/PromiseBase.h"


namespace proto::coroutine::stackable::managed::lazy {

	class PromiseBase : public managed::PromiseBase {
	public:
		using managed::PromiseBase::PromiseBase;

		std::suspend_always initial_suspend();
	protected:
	private:
	};

}