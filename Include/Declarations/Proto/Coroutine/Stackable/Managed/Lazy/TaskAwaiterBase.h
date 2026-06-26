#pragma once
#include "Proto/Coroutine/Stackable/Managed/TaskAwaiterBase.h"


namespace proto::coroutine::stackable::managed::lazy {

    template <managed::PromiseBaseConcept TPromise>
    class TaskAwaiterBase : public managed::TaskAwaiterBase<TPromise> {
    public:
        using TaskAwaiterBase<TPromise>::TaskAwaiterBase;

        template <stackable::PromiseConcept TParentPromise>
        std::coroutine_handle<TPromise> await_suspend(std::coroutine_handle<TParentPromise> parent_coroutine_handle) noexcept;
    protected:
    private:
    };

}