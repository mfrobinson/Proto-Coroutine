#pragma once
#include "Proto/Coroutine/StackablePromise.h"
#include "Proto/Coroutine/StackableManagedPromiseFinalAwaiter.h"
#include <coroutine>


namespace proto::coroutine {

    class StackableManagedPromiseBase : public StackablePromise {
    public:
        StackableManagedPromiseFinalAwaiter final_suspend() noexcept;

        void set_parent(std::coroutine_handle<> parent_coroutine_handle, StackablePromise* parent_coroutine_promise);
    protected:
    private:
        using StackablePromise::child_coroutine_handle;
        using StackablePromise::child_coroutine_promise;

        std::coroutine_handle<> parent_coroutine_handle;
        StackablePromise* parent_coroutine_promise;
    };

}