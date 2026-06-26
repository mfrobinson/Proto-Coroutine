# 🚀 Stackable C++ Coroutine Framework

A modern C++ framework providing a templated architecture to build and execute **stackable coroutines**.

While the framework is designed with highly extensible templates allowing you to derive and implement custom coroutine structures, it includes robust, production-ready default classes that cover almost every asynchronous and lazy evaluation use-case out of the box.

---

## 🏗️ Architecture & Core Concepts

The framework organises coroutines into a matrix across two main design axes: **Lifetime Management** and **Execution Strategy**.

                           ┌─────────────────────┐
                           │ Stackable Framework │
                           └──────────┰──────────┘
                                      ┃
                 ┏━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━┓
                 ┃                                         ┃
┌────────────────┸─────────────────┐ ┌─────────────────────┸────────────────────┐
│       [Managed Coroutines]       │ │          [Unmanaged Coroutines]          │
│ Lifetime tied to Task destructor │ │ Persist until body finishes execution    │
│ Can optionally return a value    │ │ Void return only (never returns a value) │
└────────────────┰─────────────────┘ └─────────────────────┰────────────────────┘
                 ┃                                         ┃
            ┏━━━━┻━━━━┓                               ┏━━━━┻━━━━┓
        ┌───┸───┐ ┌───┸──┐                        ┌───┸───┐ ┌───┸──┐
        │ Eager │ │ Lazy │                        │ Eager │ │ Lazy │
        └───────┘ └──────┘                        └───────┘ └──────┘

### 1. Lifetime Management: Managed vs. Unmanaged
* **Managed**: The lifetime of the coroutine state is strictly tied to the returned `Task` object. Destroying the `Task` instantly cleans up the coroutine via its destructor. Because they are tracked, they **can optionally return a value** back to the caller.
* **Unmanaged**: These coroutines decouple their lifetime from the initial invocation handle. They persist automatically in the background until they run to completion (reach the end of their body). Consequently, unmanaged coroutines **never return a value**.

### 2. Execution Strategy: Eager vs. Lazy
* **Eager**: The coroutine begins executing its body immediately upon being called.
* **Lazy**: Execution is suspended at the initial suspend point. The body only begins executing when its value is explicitly demanded via the `co_await` keyword on its returned task.

---

## 🛠️ Provided Default Classes

All default coroutines live under the namespace `proto::coroutine::stackable` for clean integration.

| Coroutine Configuration | Fully Qualified Template Class | Return Type |
| :--- | :--- | :--- |
| **Managed + Eager** | `template <typename TResult> proto::coroutine::stackable::managed::eager::DefaultTask` | `TResult` (Can be `void`) |
| **Managed + Lazy** | `template <typename TResult> proto::coroutine::stackable::managed::lazy::DefaultTask` | `TResult` (Can be `void`) |
| **Unmanaged + Eager** | `template <typename TResult> proto::coroutine::stackable::unmanaged::eager::DefaultTask` | `void` |
| **Unmanaged + Lazy** | `template <typename TResult> proto::coroutine::stackable::unmanaged::lazy::DefaultTask` | `void` |

---

## 📦 Installation & CMake Integration

### Requirements
* **Compiler**: A standard compiler with robust **C++20** support or later (GCC 10+, Clang 11+, or MSVC 2019+).
* **Build System**: CMake 3.14 or higher.

### Including the Framework in your own CMake Project
This project can be easily included into a CMake project with `FetchContent`:

```cmake
include(FetchContent)
FetchContent_Declare(
    ProtoCoroutine
    GIT_REPOSITORY https://github.com/mfrobinson/Proto-Coroutine.git
    GIT_TAG master
)
FetchContent_MakeAvailable(ProtoCoroutine)

...

target_link_libraries(${PROJECT_NAME} PUBLIC ProtoCoroutine)
```

## ⚙️ Usage Example

Here is a quick look at how easily you can mix and match the default stackable coroutine tasks:

```cpp
#include <iostream>
#include <Proto/Coroutine/Stackable/Managed/Eager/DefaultPromise.h>
#include <Proto/Coroutine/Stackable/Managed/Lazy/DefaultPromise.h>
#include <Proto/Coroutine/Stackable/Unmanaged/Eager/DefaultTask.h>
#include <Proto/Coroutine/Stackable/Unmanaged/Lazy/DefaultTask.h>

// A Managed, Lazy coroutine returning an integer
proto::coroutine::stackable::managed::lazy::DefaultTask<int> fetch_data() {
    std::cout << "2. Fetching data lazily..." << std::endl;
    co_return 42;
}

// An Unmanaged, Eager background coroutine
proto::coroutine::stackable::unmanaged::eager::DefaultTask run_background_logger() {
    std::cout << "1. Background logger started eagerly!" << std::endl;
    co_await std::suspend_always{}; // Suspends custom execution step
    std::cout << "3. Background logger finishing up." << std::endl;
    co_return;
}

int main() {
    // 1. Fires off immediately
    auto background_logger_task = run_background_logger();

    // 2. Initialised but suspended because it is lazy
    auto lazy_task = fetch_data();

    // 3. Resume the background logger task and let it run to completion
    background_logger_task.resume();

    // 4. Begin running the lazy fetch_data task
    lazy_task.resume();
    return 0;
}
```

---

## 📝 License
Distributed under the Apache-2.0 license. See `LICENSE.txt` for more information.