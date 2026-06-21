#pragma once
#include <coroutine>


namespace proto::coroutine {

    class StackableManagedPromiseBase;

    class StackablePromise {
    public:
        void set_child(std::coroutine_handle<> child_coroutine_handle, StackableManagedPromiseBase* child_coroutine_promise);
        std::coroutine_handle<> get_deepest_active_handle(std::coroutine_handle<> this_handle);
    protected:
        StackableManagedPromiseBase* child_coroutine_promise = nullptr;
        std::coroutine_handle<> child_coroutine_handle = nullptr;
    private:
    };

}