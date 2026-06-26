#pragma once
#include <concepts>


namespace proto::coroutine::stackable {

	class Promise;

	template <typename TPromise>
	concept PromiseConcept = std::derived_from<TPromise, Promise>;

}