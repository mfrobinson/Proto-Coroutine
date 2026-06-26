#pragma once
#include "Proto/Coroutine/Stackable/Managed/PromiseBase.h"


namespace proto::coroutine::stackable::managed::eager {

	class PromiseBase : public managed::PromiseBase {
	public:
		using managed::PromiseBase::PromiseBase;

		std::suspend_never initial_suspend();
	protected:
	private:
	};

}