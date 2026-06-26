#pragma once
#include <coroutine>


namespace proto::coroutine::stackable::unmanaged {

    class PromiseFinalAwaiter {
    public:
        PromiseFinalAwaiter();

        bool await_ready() noexcept;
        void await_suspend(std::coroutine_handle<> current_coroutine) noexcept;
        void await_resume() noexcept;
    protected:
    private:
    };

}