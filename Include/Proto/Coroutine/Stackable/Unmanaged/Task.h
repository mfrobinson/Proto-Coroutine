#pragma once
#include "Proto/Coroutine/Stackable/Unmanaged/PromiseBaseConcept.h"
#include "Proto/Coroutine/Stackable/TaskBase.h"


namespace proto::coroutine::stackable::unmanaged {

    template <PromiseBaseConcept TPromise>
    class Task : public stackable::TaskBase<TPromise, void> {
    public:
        using TaskBase<TPromise, void>::TaskBase;

        void operator co_await() = delete;
    protected:
    private:
    };

}