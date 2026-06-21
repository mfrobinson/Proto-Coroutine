#pragma once
#include "Declarations/Proto/Coroutine/StackableManagedTaskAwaiterBase.h"


namespace proto::coroutine {
    
    template <StackableManagedPromiseBaseConcept TPromise>
    StackableManagedTaskAwaiterBase<TPromise>::StackableManagedTaskAwaiterBase(std::coroutine_handle<TPromise> child_coroutine_handle) : child_coroutine_handle(child_coroutine_handle) {
        return;
    }
    
    template <StackableManagedPromiseBaseConcept TPromise>
    bool StackableManagedTaskAwaiterBase<TPromise>::await_ready() noexcept {
        return this->child_coroutine_handle.done();
    }
    
    template <StackableManagedPromiseBaseConcept TPromise>
    template <StackablePromiseConcept TParentPromise>
    std::coroutine_handle<TPromise> StackableManagedTaskAwaiterBase<TPromise>::await_suspend(std::coroutine_handle<TParentPromise> parent_coroutine_handle) noexcept {
        StackableManagedPromiseBase& child_stackable_promise = this->child_coroutine_handle.promise();
        StackablePromise& parent_stackable_promise = parent_coroutine_handle.promise();
        
        child_stackable_promise.set_parent(parent_coroutine_handle, &parent_stackable_promise);
        parent_stackable_promise.set_child(this->child_coroutine_handle, &child_stackable_promise);
        
        return this->child_coroutine_handle;
    }

}