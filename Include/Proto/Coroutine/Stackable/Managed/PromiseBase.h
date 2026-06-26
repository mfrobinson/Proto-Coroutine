#pragma once
#include "Proto/Coroutine/Stackable/Promise.h"
#include "Proto/Coroutine/Stackable/Managed/PromiseFinalAwaiter.h"
#include <coroutine>


namespace proto::coroutine::stackable::managed {

    class PromiseBase : public ::proto::coroutine::stackable::Promise {
    public:
        PromiseFinalAwaiter final_suspend() noexcept;

        void set_parent(std::coroutine_handle<> parent_coroutine_handle, ::proto::coroutine::stackable::Promise* parent_coroutine_promise);
    protected:
    private:
        using stackable::Promise::child_coroutine_handle;
        using stackable::Promise::child_coroutine_promise;

        std::coroutine_handle<> parent_coroutine_handle;
        ::proto::coroutine::stackable::Promise* parent_coroutine_promise;
    };

}