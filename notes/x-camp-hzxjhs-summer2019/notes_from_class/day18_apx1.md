# Appendix 1 for Day 18 (27 July 2019)

## Concepts:
#### Null and Void Pointers
**Explanation**

Pointers are somewhat confusing, but they get really weird when we have some types of information missing...

Pointers can be thought of as holding two pieces of data, specifically they `type` and the `location` (in memory). A normal pointer, like `int num; int* iptr = &num;` holds both of these pieces of data, specifically that there is an `int` at the location stored by `iptr`.

However, we can also have pointers that are missing some data. For example, a `NULL` pointer often has a type but not a value, e.g. it does not store a specific position in memory. We can make a `NULL` pointer like this: `int* iptr = NULL;`.

Additionally, we can have a `void` pointer. In C++, `void` denotes a lack of type, and as such we can have a pointer that does not store type information but does store location information. For example, we can have something like this: `int num; void* vptr = &num;`. Notice that in this situation `vptr` actually does hold a position in memory, but it cannot be dereferenced (`*vptr;` will cause an error) because there is no associated type information. This means that a `void` pointer must be explicitly cast to some other type before it can be used. The compiler has no clue what type to cast it to, and so it is your job as the user of the `void` pointer to figure out what type to cast it to. For our example, we can use something like `int* iptr = static_cast<int*>( vptr );`, at which point we can use `iptr` to read the information at that memory address.

**Void Pointer Uses**

Given that we can only use the value stored in a `void` pointer after we cast it to another type, it may seem that `void` pointers are useless. However, `void` pointers are sometimes used as return types to unknown callback functions, because those return types are not yet known. The provided callback or original template used should also provide a type to cast the `void` pointer to, and that way it is possible to have callbacks with unknown types in a generic class implementation, for example.

Additionally, C makes relatively heavier use of `void` pointers as return types for functions that deal with raw memory, such as `malloc`. However, this does not appear as often in C++, because apparently we are ["supposed to be using `new` anyway"](https://stackoverflow.com/questions/8530080/what-is-a-void-pointer-in-c#comment50705401_8530111), whatever that means.

**Sources**

- [SO - Void pointer?](https://stackoverflow.com/questions/8530080/what-is-a-void-pointer-in-c)
- [SO - Void vs Null pointer](https://stackoverflow.com/questions/4334831/what-is-a-void-pointer-and-what-is-a-null-pointer)
- [LearnCpp.com 6.13 - Void Pointers](https://www.learncpp.com/cpp-tutorial/613-void-pointers/)
