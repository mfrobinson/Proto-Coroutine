#pragma once
#include "Proto/Coroutine/Stackable/Promise.h"
//#include "Proto/Coroutine/Stackable/Unmanaged/PromiseFinalAwaiter.h"
#include <coroutine>


namespace proto::coroutine::stackable::unmanaged {

    class PromiseBase : public ::proto::coroutine::stackable::Promise {
    public:
        std::suspend_never final_suspend() noexcept;
    protected:
    private:
        using stackable::Promise::child_coroutine_handle;
        using stackable::Promise::child_coroutine_promise;
    };

}