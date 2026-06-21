#pragma once
#include "Proto/Coroutine/StackablePromiseConcept.h"
#include <coroutine>


namespace proto::coroutine {

    template <StackablePromiseConcept TPromise, typename TResult>
    class StackableTaskBase {
    public:
        using promise_type = TPromise;
        using handle_type = std::coroutine_handle<promise_type>;

        StackableTaskBase(handle_type handle);
        StackableTaskBase(const StackableTaskBase<TPromise, TResult>&) = delete;
        StackableTaskBase<TPromise, TResult>& operator=(const StackableTaskBase<TPromise, TResult>&) = delete;
        StackableTaskBase(StackableTaskBase<TPromise, TResult>&& other) noexcept;
        StackableTaskBase<TPromise, TResult>& operator=(StackableTaskBase<TPromise, TResult>&& other) noexcept;

        void resume();
    protected:
        handle_type coroutine_handle = nullptr;
    private:
    };

}