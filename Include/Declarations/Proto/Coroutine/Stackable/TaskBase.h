#pragma once
#include "Proto/Coroutine/Stackable/PromiseConcept.h"
#include <coroutine>


namespace proto::coroutine::stackable {

    template <PromiseConcept TPromise, typename TResult>
    class TaskBase {
    public:
        using promise_type = TPromise;
        using handle_type = std::coroutine_handle<promise_type>;

        TaskBase(handle_type handle);
        TaskBase(const TaskBase<TPromise, TResult>&) = delete;
        TaskBase<TPromise, TResult>& operator=(const TaskBase<TPromise, TResult>&) = delete;
        TaskBase(TaskBase<TPromise, TResult>&& other) noexcept;
        TaskBase<TPromise, TResult>& operator=(TaskBase<TPromise, TResult>&& other) noexcept;

        void resume();
    protected:
        handle_type coroutine_handle = nullptr;
    private:
    };

}