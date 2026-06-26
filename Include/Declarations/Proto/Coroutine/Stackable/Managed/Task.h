#pragma once
#include "Proto/Coroutine/Stackable/Managed/PromiseBaseConcept.h"
#include "Proto/Coroutine/Stackable/TaskBase.h"
#include "Proto/Coroutine/Stackable/Managed/TaskAwaiter.h"


namespace proto::coroutine::stackable::managed {

    template <PromiseBaseConcept TPromise, typename TResult, typename TAwaiter>
    class Task : public TaskBase<TPromise, TResult> {
    public:
        using TaskBase<TPromise, TResult>::TaskBase;
        ~Task();

        TAwaiter operator co_await() noexcept;
    protected:
    private:
    };

}