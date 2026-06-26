#pragma once
#include <concepts>


namespace proto::coroutine::stackable::managed {

	class PromiseBase;

	template <typename TPromise>
	concept PromiseBaseConcept = std::derived_from<TPromise, PromiseBase>;

}