#pragma once
#include "Declarations/Proto/Coroutine/StackablePromiseWithResult.h"
#include <variant>


namespace proto::coroutine {

    template <typename TResult, typename TPromiseBase>
    void StackablePromiseWithResult<TResult, TPromiseBase>::unhandled_exception() {
        result.template emplace<std::exception_ptr>(std::current_exception());
        return;
    }

    template <typename TResult, typename TPromiseBase>
    template <typename U>
    void StackablePromiseWithResult<TResult, TPromiseBase>::return_value(U&& val) {
        result.template emplace<TResult>(std::forward<U>(val));
    }

    template <typename TResult, typename TPromiseBase>
    TResult StackablePromiseWithResult<TResult, TPromiseBase>::get_result() {
        if (result.index() == 0) std::rethrow_exception(std::get<std::exception_ptr>(result));
        return std::get<TResult>(result);
    }

    template <typename TPromiseBase>
    void StackablePromiseWithResult<void, TPromiseBase>::unhandled_exception() {
        this->uncaught_exception = std::current_exception();
        return;
    }

    template <typename TPromiseBase>
    void StackablePromiseWithResult<void, TPromiseBase>::return_void() {
        return;
    }

    template <typename TPromiseBase>
    void StackablePromiseWithResult<void, TPromiseBase>::rethrow_if_uncaught() {
        if (this->uncaught_exception != nullptr) std::rethrow_exception(this->uncaught_exception);
        return;
    }

}