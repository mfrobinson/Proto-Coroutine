#pragma once
#include "Declarations/Proto/Coroutine/Stackable/Managed/Eager/TaskAwaiterBase.h"


namespace proto::coroutine::stackable::managed::eager {

    template <managed::PromiseBaseConcept TPromise>
    template <stackable::PromiseConcept TParentPromise>
    void TaskAwaiterBase<TPromise>::await_suspend(std::coroutine_handle<TParentPromise> parent_coroutine_handle) noexcept {
        managed::PromiseBase& child_stackable_promise = this->child_coroutine_handle.promise();
        stackable::Promise& parent_stackable_promise = parent_coroutine_handle.promise();

        child_stackable_promise.set_parent(parent_coroutine_handle, &parent_stackable_promise);
        parent_stackable_promise.set_child(this->child_coroutine_handle, &child_stackable_promise);

        return;
    }

}