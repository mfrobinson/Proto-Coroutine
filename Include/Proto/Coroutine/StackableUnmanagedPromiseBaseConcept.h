#pragma once
#include <concepts>


namespace proto::coroutine {

	class StackableUnmanagedPromiseBase;

	template <typename TPromise>
	concept StackableUnmanagedPromiseBaseConcept = std::derived_from<TPromise, StackableUnmanagedPromiseBase>;

}