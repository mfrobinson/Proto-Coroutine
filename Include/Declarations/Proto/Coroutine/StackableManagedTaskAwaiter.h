#pragma once
#include "Proto/Coroutine/StackableManagedPromiseBaseConcept.h"
#include "Proto/Coroutine/StackableManagedTaskAwaiterBase.h"


namespace proto::coroutine {

    template <StackableManagedPromiseBaseConcept TPromise, typename TResult>
    class StackableManagedTaskAwaiter : public StackableManagedTaskAwaiterBase<TPromise> {
    public:
        using StackableManagedTaskAwaiterBase<TPromise>::StackableManagedTaskAwaiterBase;

        TResult await_resume();
    protected:
    private:
        using StackableManagedTaskAwaiterBase<TPromise>::child_coroutine_handle;
    };

    template <StackableManagedPromiseBaseConcept TPromise>
    class StackableManagedTaskAwaiter<TPromise, void> : public StackableManagedTaskAwaiterBase<TPromise> {
    public:
        using StackableManagedTaskAwaiterBase<TPromise>::StackableManagedTaskAwaiterBase;

        void await_resume();
    protected:
    private:
        using StackableManagedTaskAwaiterBase<TPromise>::child_coroutine_handle;
    };

}