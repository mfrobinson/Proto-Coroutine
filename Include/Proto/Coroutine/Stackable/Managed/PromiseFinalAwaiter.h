#pragma once
#include "Proto/Coroutine/Stackable/Promise.h"
#include <coroutine>


namespace proto::coroutine::stackable::managed {

    class PromiseFinalAwaiter {
    public:
        PromiseFinalAwaiter(std::coroutine_handle<> parent_coroutine, stackable::Promise* parent_coroutine_promise);

        bool await_ready() noexcept;
        std::coroutine_handle<> await_suspend(std::coroutine_handle<> current_coroutine) noexcept;
        void await_resume() noexcept;
    protected:
    private:
        std::coroutine_handle<> parent_coroutine;
        stackable::Promise* parent_coroutine_promise;
    };

}