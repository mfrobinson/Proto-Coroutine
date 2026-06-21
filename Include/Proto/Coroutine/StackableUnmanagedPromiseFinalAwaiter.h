#pragma once
#include <coroutine>


namespace proto::coroutine {

    class StackableUnmanagedPromiseFinalAwaiter {
    public:
        StackableUnmanagedPromiseFinalAwaiter();

        bool await_ready() noexcept;
        void await_suspend(std::coroutine_handle<> current_coroutine) noexcept;
        void await_resume() noexcept;
    protected:
    private:
    };

}