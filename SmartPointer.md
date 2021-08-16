# Smart Pointer

Weiminghui Ji	2021-08-15

reference: https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-160

## Summary

Smart Pointers are defined in `std` namespace in the `<memory>` header file.

RAII (Resource Acquisition Is Initialization): Give ownership of any **heap-allocated resource** to a **stack-allocated object** whose destructor contains the code to free the resource.

A smart pointer is a class template that you declare on the stack, and initialize by using a raw pointer that points to a heap-allocated object. After the smart pointer is initialized, it owns the raw pointer. This means that the smart pointer is responsible for deleting the memory that the raw pointer specifies. The smart pointer destructor contains the call to delete, and because the smart pointer is declared on the stack, its destructor is invoked when the smart pointer goes out of scope, even if an exception is thrown somewhere further up the stack.

> Always create smart pointers on a separate line of code, never in a parameter list, so that a subtle resource leak won't occur due to certain parameter list allocation rules.

`ptr.reset()`

`ptr.get()`

`auto ptr2 = std::move(ptr1)`

## C++ Standard Library smart pointers

- `unique_ptr` cannot copy

- `shared_ptr`
- `weak_ptr` lock

