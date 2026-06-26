#pragma once
#include <concepts>


namespace proto::coroutine::stackable::unmanaged {

	class PromiseBase;

	template <typename TPromise>
	concept PromiseBaseConcept = std::derived_from<TPromise, PromiseBase>;

}