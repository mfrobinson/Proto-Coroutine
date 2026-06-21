#pragma once
#include <concepts>


namespace proto::coroutine {

	class StackablePromise;

	template <typename TPromise>
	concept StackablePromiseConcept = std::derived_from<TPromise, StackablePromise>;

}