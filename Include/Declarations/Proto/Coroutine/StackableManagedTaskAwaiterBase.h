#pragma once
#include "Proto/Coroutine/StackablePromiseConcept.h"
#include <coroutine>


namespace proto::coroutine {

    template <StackableManagedPromiseBaseConcept TPromise>
    class StackableManagedTaskAwaiterBase {
    public:
        StackableManagedTaskAwaiterBase(std::coroutine_handle<TPromise> child_coroutine_handle);
        bool await_ready() noexcept;
        template <StackablePromiseConcept TParentPromise>
        std::coroutine_handle<TPromise> await_suspend(std::coroutine_handle<TParentPromise> parent_coroutine_handle) noexcept;
    protected:
        std::coroutine_handle<TPromise> child_coroutine_handle;
    private:
    };

}