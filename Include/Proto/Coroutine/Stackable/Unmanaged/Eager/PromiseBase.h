#pragma once
#include "Proto/Coroutine/Stackable/Unmanaged/PromiseBase.h"


namespace proto::coroutine::stackable::unmanaged::eager {

	class PromiseBase : public unmanaged::PromiseBase {
	public:
		using unmanaged::PromiseBase::PromiseBase;

		std::suspend_never initial_suspend();
	protected:
	private:
	};

}