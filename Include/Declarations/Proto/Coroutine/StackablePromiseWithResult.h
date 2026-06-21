#pragma once
#include <variant>


namespace proto::coroutine {

    template <typename TResult, typename TPromiseBase>
    class StackablePromiseWithResult : public TPromiseBase {
    public:
        void unhandled_exception();
        template <typename U>
        void return_value(U&& val);
        TResult get_result();
    protected:
    private:
        std::variant<std::exception_ptr, TResult> result;
    };

    template <typename TPromiseBase>
    class StackablePromiseWithResult<void, TPromiseBase> : public TPromiseBase {
    public:
        void unhandled_exception();
        void return_void();
        void rethrow_if_uncaught();
    protected:
    private:
        std::exception_ptr uncaught_exception = nullptr;
    };

}