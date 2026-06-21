#pragma once
#include "Proto/Coroutine/StackableManagedPromiseBaseConcept.h"
#include "Proto/Coroutine/StackableTaskBase.h"
#include "Proto/Coroutine/StackableManagedTaskAwaiter.h"


namespace proto::coroutine {

    template <StackableManagedPromiseBaseConcept TPromise, typename TResult>
    class StackableManagedTask : public StackableTaskBase<TPromise, TResult> {
    public:
        using StackableTaskBase<TPromise, TResult>::StackableTaskBase;
        ~StackableManagedTask();

        StackableManagedTaskAwaiter<TPromise, TResult> operator co_await() noexcept;
    protected:
    private:
    };

}