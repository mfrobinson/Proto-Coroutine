#pragma once
#include <concepts>


namespace proto::coroutine {

	class StackableManagedPromiseBase;

	template <typename TPromise>
	concept StackableManagedPromiseBaseConcept = std::derived_from<TPromise, StackableManagedPromiseBase>;

}