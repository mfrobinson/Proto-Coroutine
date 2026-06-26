#pragma once
#include "Proto/Coroutine/Stackable/PromiseConcept.h"
#include "Proto/Coroutine/Stackable/Managed/PromiseBaseConcept.h"
#include <coroutine>


namespace proto::coroutine::stackable::managed {

    template <PromiseBaseConcept TPromise>
    class TaskAwaiterBase {
    public:
        TaskAwaiterBase(std::coroutine_handle<TPromise> child_coroutine_handle);
        bool await_ready() noexcept;
        template <stackable::PromiseConcept TParentPromise>
        std::coroutine_handle<TPromise> await_suspend(std::coroutine_handle<TParentPromise> parent_coroutine_handle) noexcept;
    protected:
        std::coroutine_handle<TPromise> child_coroutine_handle;
    private:
    };

}