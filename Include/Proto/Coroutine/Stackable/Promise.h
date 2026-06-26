#pragma once
#include <coroutine>


namespace proto::coroutine::stackable {

    namespace managed {
        class PromiseBase;
    }

    class Promise {
    public:
        void set_child(std::coroutine_handle<> child_coroutine_handle, managed::PromiseBase* child_coroutine_promise);
        std::coroutine_handle<> get_deepest_active_handle(std::coroutine_handle<> this_handle);
    protected:
        managed::PromiseBase* child_coroutine_promise = nullptr;
        std::coroutine_handle<> child_coroutine_handle = nullptr;
    private:
    };

}