#pragma once
#include "Proto/Coroutine/StackablePromise.h"
#include "Proto/Coroutine/StackableUnmanagedPromiseFinalAwaiter.h"


namespace proto::coroutine {

    class StackableUnmanagedPromiseBase : public StackablePromise {
    public:
        StackableUnmanagedPromiseFinalAwaiter final_suspend() noexcept;
    protected:
    private:
        using StackablePromise::child_coroutine_handle;
        using StackablePromise::child_coroutine_promise;
    };

}