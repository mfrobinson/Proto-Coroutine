#pragma once
#include "Proto/Coroutine/Stackable/Unmanaged/PromiseBase.h"


namespace proto::coroutine::stackable::unmanaged::lazy {

	class PromiseBase : public unmanaged::PromiseBase {
	public:
		using unmanaged::PromiseBase::PromiseBase;

		std::suspend_always initial_suspend();
	protected:
	private:
	};

}