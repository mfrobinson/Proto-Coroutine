#pragma once
#include <coroutine>


namespace proto::coroutine {

    class StackableManagedPromiseFinalAwaiter {
    public:
        StackableManagedPromiseFinalAwaiter(std::coroutine_handle<> parent_coroutine);

        bool await_ready() noexcept;
        std::coroutine_handle<> await_suspend(std::coroutine_handle<> current_coroutine) noexcept;
        void await_resume() noexcept;
    protected:
    private:
        std::coroutine_handle<> parent_coroutine;
    };

}