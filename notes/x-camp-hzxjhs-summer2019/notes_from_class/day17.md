# Summary for Day 17 (26 July 2019)

## Problems:
|  Page  |  PID  |  Description  |  Status  | Notes |
|-------:|-------|---------------|:--------:|-------|
 4.4 | 9523 | Floyd Warshall | AC | Simple floyd warshall practice
 VJ314632 | 1 | String continuous sequence count | AC | used dp, should have done some weird left-right additiony thing

## Concepts:
#### Const Class Methods
**They are the only methods callable by `const` instances**
If there is a `const` instance of a class, then class methods not marked as `const` cannot be called from the `const` instance. It is similar to having `const` arguments in functions - it may not be absolutely necessary but it is still good practice for portability and complier optimizations.

#### Overloading Operators
**We can overload operators for classes so we can add instances or allow them to be compared**
This is done with something like this:
```C plus plus
class Foo
{
  int bar, baz;
public:
  bool operator< (const Foo& other)
    return this->bar < other.bar;
}
```

These are useful for when users of your class would like to do intuitive things with your class in a similar way as if they were one of the primitive types. Sometimes, other functions and methods will expect you to have these overloaded operators, for example `std::priority_queue` uses the `operator<` for comparison unless an explicit comparison function is provided in the constructor. This overloading, though not always necessary, is a nice touch for usability of classes, and makes code more readable as long as the implementation of the overloaded operators are intuitive. For example, a class like `std::string` has some really nice overloaded operators such as `operator+`, which concatenates two strings. It would not make much sense if this operator was implemented in a way that returned the sum of the ascii values of the characters in the string, although for a different class that implementation may be more useful. This is a good example of the importance of choosing good uses for your methods and functions, so that it is easier to both write and read code that uses them.

#### Function Pointers
**Uses**
Function pointers provide a way to pass a function as an argument to another function or method. This may seem useless at first, but they are actually a really useful feature. They allow a user to further customize a general function, class, or method to a more use-case specific point while reusing basic functionality provided by the original function, class, or method. For example, many STL classes allow the user to provide a function with which to change some part of the functionality of the class itself, such as `std::sort()` which may optionally receive a `comp()` comparison function. This allows `std::sort()` to reuse much of the same quick sort code for sorting objects in an ascending, descending, and even other orders based on various and highly customizable values.

They also allow the implementation of "callback" functions, which are functions that should be run when the original function is finished. These are powerful for asynchronous operations, because it allows functions to be called one after another in the correct order and ensuring all dependent calculations are completed before the next one starts. For example, Javascript makes heavy use of callback functions and this means it is highly versatile and robust when it comes to async and choppy performance, such as on a web browser.

**Example**
Passing a function to another one is relatively simple. An example of this is `std::sort()`, which takes start and end addresses and optionally a `comp()` comparison function. To pass a function to this argument, we simply define a normal function and just pass the name of the function directly to the argument, and the internals of the main function (in this case `std::sort()`) will take care of the rest.

However, creating a function pointer seems somewhat messy at first. We would do something like this:
```c plus plus
#include <bits/stdc++.h>
using namespace std;

void foo (int x)
{
  printf("%d\n", x);
}

int main ()
{
  void (*bar) (int); // create a function pointer called bar that points to a void function that takes one int argument
  bar = &foo; // same as `bar = foo;`, the explicit reference is not needed

  bar( 12 ); // you can call the function through the function pointer directly
  (*bar)( 14 ); // or you can explicitly dereference the pointer if you want

  return 0;
}

```

And to use the function pointer as an argument to a function, for example if we wanted to write our own generic sort function, we could do something like this:
```c plus plus
void generic_sort(int* beg, int* end, bool (*cmp)(int, int) = [](int a, int b){ return a < b } );
```
and inside of that function we could simply call the compare function with something like this:
```c plus plus
if ( cmp( a, b ) ) { /* do something */ }
```
Which ends up not being so bad. However, in C++11 there is this thing called polymorphism and virtual functions, which are somewhat confusing and seem to be tied on classes. I don't understand it, but it seems like a syntactically nicer way to use function pointers, these features are implemented with function pointers anyways. I will look into it.

Primary source:
[cprogramming.com Tutorial](https://www.cprogramming.com/tutorial/function-pointers.html)


## Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 6
