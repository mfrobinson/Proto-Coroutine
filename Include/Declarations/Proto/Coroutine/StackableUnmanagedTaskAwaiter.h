#pragma once


namespace proto::coroutine {

    template <StackableUnmanagedPromiseBaseConcept TPromise>
    class StackableUnmanagedTaskAwaiter {
    public:
        StackableUnmanagedTaskAwaiter();

        void await_ready() noexcept;

        template <StackablePromiseConcept TParentPromise>
        void await_suspend(std::coroutine_handle<TParentPromise> parent_coroutine_handle) noexcept;

        void await_resume() noexcept;
    protected:
    private:
    };

}