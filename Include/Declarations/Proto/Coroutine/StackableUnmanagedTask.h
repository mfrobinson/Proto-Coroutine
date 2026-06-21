#pragma once
#include "Proto/Coroutine/StackableUnmanagedPromiseBaseConcept.h"
#include "Proto/Coroutine/StackableTaskBase.h"
#include "Proto/Coroutine/StackableUnmanagedTaskAwaiter.h"


namespace proto::coroutine {

    template <StackableUnmanagedPromiseBaseConcept TPromise, typename TResult>
    class StackableUnmanagedTask : public StackableTaskBase<TPromise, TResult> {
    public:
        using StackableTaskBase<TPromise, TResult>::StackableTaskBase;

        StackableUnmanagedTaskAwaiter<TPromise> operator co_await() noexcept;
    protected:
    private:
    };

}