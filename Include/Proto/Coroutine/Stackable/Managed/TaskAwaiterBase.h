#pragma once
#include "Declarations/Proto/Coroutine/Stackable/Managed/TaskAwaiterBase.h"


namespace proto::coroutine::stackable::managed {
    
    template <managed::PromiseBaseConcept TPromise>
    TaskAwaiterBase<TPromise>::TaskAwaiterBase(std::coroutine_handle<TPromise> child_coroutine_handle) : child_coroutine_handle(child_coroutine_handle) {
        return;
    }
    
    template <managed::PromiseBaseConcept TPromise>
    bool TaskAwaiterBase<TPromise>::await_ready() noexcept {
        return this->child_coroutine_handle.done();
    }
    
    template <managed::PromiseBaseConcept TPromise>
    template <stackable::PromiseConcept TParentPromise>
    std::coroutine_handle<TPromise> TaskAwaiterBase<TPromise>::await_suspend(std::coroutine_handle<TParentPromise> parent_coroutine_handle) noexcept {
        managed::PromiseBase& child_stackable_promise = this->child_coroutine_handle.promise();
        stackable::Promise& parent_stackable_promise = parent_coroutine_handle.promise();
        
        child_stackable_promise.set_parent(parent_coroutine_handle, &parent_stackable_promise);
        parent_stackable_promise.set_child(this->child_coroutine_handle, &child_stackable_promise);
        
        return this->child_coroutine_handle;
    }

}