#pragma once
#include "Declarations/Proto/Coroutine/Stackable/PromiseWithResult.h"
#include <variant>


namespace proto::coroutine::stackable {

    template <typename TResult, typename TPromiseBase>
    void PromiseWithResult<TResult, TPromiseBase>::unhandled_exception() {
        result.template emplace<std::exception_ptr>(std::current_exception());
        return;
    }

    template <typename TResult, typename TPromiseBase>
    template <typename U>
    void PromiseWithResult<TResult, TPromiseBase>::return_value(U&& val) {
        result.template emplace<TResult>(std::forward<U>(val));
    }

    template <typename TResult, typename TPromiseBase>
    TResult PromiseWithResult<TResult, TPromiseBase>::get_result() {
        if (result.index() == 0) std::rethrow_exception(std::get<std::exception_ptr>(result));
        return std::get<TResult>(result);
    }

    template <typename TPromiseBase>
    void PromiseWithResult<void, TPromiseBase>::unhandled_exception() {
        this->uncaught_exception = std::current_exception();
        return;
    }

    template <typename TPromiseBase>
    void PromiseWithResult<void, TPromiseBase>::return_void() {
        return;
    }

    template <typename TPromiseBase>
    void PromiseWithResult<void, TPromiseBase>::rethrow_if_uncaught() {
        if (this->uncaught_exception != nullptr) std::rethrow_exception(this->uncaught_exception);
        return;
    }

}