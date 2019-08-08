# XC1900105AH's Consolidated Camp Notes
**X-Camp @ HangZhou XueJun High School - Summer 2019**

## Problems
| Page | PID | Description | Status |
|-------:|-------|---------------|:--------:|
| 2.13 | 1228 | n queens problem | WA |
|   " | 1227 | connected reigons | WA |
|   " | 7084 | binary tree encoding | AC  |
|   " | 7998 | dp work distribution | WA |
|   " | 1227 | connected reigons | AC |
|   "    | 1228 | n queens | TLE |
|   "    | 7998 | work division | AC |
|   "    | 7999 | work division v2 | AC |
|   "    | 7087 | tree conversion | TLE |
|   " | [1228](../../../problems/2.13/x1228/main.cpp) | n queens | AC |
| c1225 |    1 | counting permutations (similar to 7977) | TLE |
|   " |    2 | permutations with identical digits | WA |
|   " |    3 | permutations without consecutive numbers | TLE |
|   2.14 | 7939 | File I/O | AC |
|   "    | 7940 | File I/O | AC |
|   "    | 7941 | File I/O | AC |
|   "    | 7942 | File I/O | AC |
|   "    | 7943 | File I/O | AC |
|   "    | 7944 | std::err | AC |
|   2.15 | 7200 | Struct 1 | AC |
|   "    | 7201 | Struct 2 | TLE |
|   "    | 7202 | Struct 3 | TLE |
|   "    | 7203 | Struct 2.1 | AC |
|   "    | 7204 | Struct 2.2 | WA |
|   4.4 | 9513 | tree input | TLE |
|   "   | 9517 | guard palace | WA |
| vjudge.net contest 313134 | A | Contest questions listing | AC | N/A |
|  "" | B | Circle surround radius | AC | N/A |
|   "" | C | Chess rooks and king | WA | Don't know how to do |
|   c1204 | 1 | Euclid GCD | AC | N/A |
|   "" | 2 | Merge Sorted Arrays | AC | N/A |
|   "" | 5 | Number Statistics | WIP | Can do, the number limits were written wrong and actually only need to worry about ints up to 10e7. |
|   "" | 6 | Tree Depth and Width | CE | Not sure why it doesn't work |
|   "" | 7 | Maximize Customer Calls | WA | DP got messed up, test case `1 10 2 4 6 9` doesn't work. |
|   "" | 8 | Hamster Whacking Game | WA | Greedy algorithm doesn't work, should probably use DP. |
|   c1204 | 8 | Hampster Whakamole | AC | ACd using heaps after explained in class |
|   VJudge313606 | A | Resturaunt Dishes | WIP | Spend a long time debugging, still doesn't work |
|   "" | B | Min sum of squares pairs | AC | Simply make max different pairs, pattern matching |
|   "" | C | Park wandering | AC | Used  `std::priority_queue` instead of a heap, help from Alex Guo. The issue was I was relying on `queue.top()`, but the top item was changing on a new push because it was implemented as a heap. |
|   dev.xjoi 1207 | 1 | Minimum Lumberjacking | AC | Simple after you understand it, find dist to nearest tree |
|   "" | 2 | Modulus thing? | WIP | Not sure what the problem even means |
|   c1205 | 1 | City Driving Turning | TLE | Used DFS. Not sure why it is too slow... |
|   "" | 2 | Horse Racing Selection | WIP | Should be doable with DP, but my approach was similar to the apple problem, got distracted |
|   4.4 | 9523 | Floyd Warshall | AC | Simple floyd warshall practice |
|   VJ314632 | 1 | String continuous sequence count | AC | used dp, should have done some weird left-right additiony thing |
| dev.xjoi 1210 | 1 | cover dots with line | WA | For some reason I had a really hard time doing the math for this |
| dev.xjoi c1212 | 2 | connecting letters | WIP | Segfaults are annoying |
| dev.xjoi 1216 | 1 | Weird knapsack | WIP | Combines different types of knapsack. I recognize the problem but I don't remember how to do the knapsack DP, so I was unable to do it |
| "" |  2  | Serpentine Matrix addition | WA | didn't start focusing on this problem until too late, originally read problem wrong. Bad at math, will work on more later.  |
| ""  | 3 | Create DAG, shortest path | WIP | Don't know how to test for loops, unable to do topological sort. Will work on more later. |
| p3.16 | 9520 | Depth of a tree | AC | Spent way too much time debugging my edgelist class |
| ""  | 9521  |  Width of a tree | AC  | Wrote pretty quickly with another custom edgelist class |
| ""  |  9522 | Number of children per node in trees | AC | Cheesed through it by counting connections in input format. No actual trees were used |
| ""  | 9524  | Number of leaf nodes  | AC  | Again, no trees used, instead just parsed input |
| xjoi.net 3.16  | 9520 | tree depth | AC | easy with edgelist, dfs |
| ""  | 9521 | tree width |  AC | same as above |
| "" |  9522 | children of each node | AC | cheesed with arrays  |
| ""  |  9524 | number of leaf nodes | AC | same as above |
| ""  | 9500 | parent of each node | CE: TLE | should work, but the compiler time limit exceeded for some reason |
| ""  | 9501 | weights of nodes | AC | used edgelist and dfc |
| xjoi.next 3.17  | 8806 | binary tree father | AC | cheesed with arrays again. |
| dev.xjoi 1211 | 1 | Print directory structure | AC | Used map and iterators and a full on class |
| "" | 3 | Find shortest max distance | WIP | ShenBear says to use a MST and then LCA, but I need to look into those |

## Notes
Jump to section:
1.  [IO](#io)
2.  [Pointers](#pointers)
3.  [Compound Data](#compound-data)
4.  [Tree/Graph Basics](#treegraph-basics)
5.  [Tree/Graph Storage](#treegraph-storage)
6.  [Tree/Graph Algorithms](#treegraph-algorithms)
7.  [Heaps](#heaps)
8.  [Linked Lists](#linked-lists)
9.  [Maps](#maps)
10. [Recursive Algorithms](#recursive-algorithms)
11. [Misc](#misc)
### IO
#### scanf and printf: Faster for big datasets than `cin` and `cout`.
For the most part I have been using `cin` and `cout` for I/O because it is easier to use with C++ `std` library classes and types. However, `scanf` and `printf` are much faster beause they don't have the same amount of call overhead as `cin` and `cout`. This makes them much faster to call, and can significantly speed up a program. However, they do not work well natively with C++ types, like `std::string`. Instead, there are often work arounds to the problems such as in this example:

```C plus plus
#include <bits/stdc++.h>

using namespace std;

int main ()
{
  printf("Hello world!\n");
  printf("`printf` stands for print format. It can format things, similar to Python3 `print` and Java `System.out.format`\n");
  printf("num: %d, char: %c, c-string: \"%s\" and so on.\n", 65, "A", "const char[] (null terminated character sequence");

  string mystr = "something like this!";
  printf("and we can convert c++ strings to c strings with %s\n", mystr.c_str());

  return 0;
}
```
The `scanf` and `printf` syntax take a little getting used to, but it's like learning RegExp:  commit once and use it everywhere.  
Notably, `scanf` has some quirks with characters and invisibles in the input stream. Best to explicitly remove newlines from the input stream when inputting characters with `scanf`, with something like `scanf("%c\n", &mychar);`. If something is really broken, try replacing `scanf` with `cin` to see if the problem gets fixed. If so, maybe some speed reduction is worth a working program.

#### File I/O: `freopen`, `fin`, `fout`, `cerr`
File opening with `freopen` is similar to other programming languages. There are filemodes, and the function returns a pointer to a file stream? It is a little confusing. Some extra sources:
-   [freopen](http://www.cplusplus.com/reference/cstdio/freopen/)
-   [fopen](https://en.cppreference.com/w/cpp/io/c/fopen)
-   [fprintf](http://www.cplusplus.com/reference/cstdio/fprintf/)
-   [cerr](http://www.cplusplus.com/reference/iostream/cerr/)

### Pointers

#### Pointers <a name="pointers-stay-away"></a>
Stay away from them, especially in 2d arrays and with structs.
They are not a good choice for competition/speed coding because they screw up so easily. If you have a signal 11 (segfault), then it's probably the pointer's fault. If your code breaks, its probably the pointer's fault. Just delete them. They can usually be worked around anyways.

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
void generic_sort(  int* beg, int* end,
                    bool (*cmp)(int, int)
                       = [](int a, int b)
                 )
{ return a < b } );
```
and inside of that function we could simply call the compare function with something like this:
```c plus plus
if ( cmp(a, b) ) { /* do something */ }
```
Which ends up not being so bad. However, in C++11 there is this thing called polymorphism and virtual functions, which are somewhat confusing and seem to be tied on classes. I don't understand it, but it seems like a syntactically nicer way to use function pointers, these features are implemented with function pointers anyways. I will look into it.

Primary source:
[cprogramming.com Tutorial](https://www.cprogramming.com/tutorial/function-pointers.html)

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
-   [SO - Void pointer?](https://stackoverflow.com/questions/8530080/what-is-a-void-pointer-in-c)
-   [SO - Void vs Null pointer](https://stackoverflow.com/questions/4334831/what-is-a-void-pointer-and-what-is-a-null-pointer)
-   [LearnCpp.com 6.13 - Void Pointers](https://www.learncpp.com/cpp-tutorial/613-void-pointers/)

### Compound Data
#### Structs
Structs are useful for grouping related pieces of data together. They have many useful applications, such as
-   Grouping things together into an object for better abstraction
-   Allowing multiple data types to be bound into one and used as arguments for functions or elements in arrays
For example, they can be used to create "node" objects for trees or maps, or to pass a "cow" to a "catapult" function, if the particular problem requires it. All said, it is a way of abstracting data and making it easier to work with. Earlier I noted that `struct`s and `class`es are really similar, and what the differance was. Basically, they are technically almost identical but `struct`s are often used as pure data structures, while `class`es are used to create "interfaces" for other pieces of code to interact with. This is a naming convention that most people follow, so this is a framework we can use when reading other people's code and writing our own.

#### Struct vs Class: essentially just a naming convention
They are actually basically the same thing, because the only technical language differences are that:  
1.   struct member variables are public by default (can be overridden to make it the same as a class and vise versa)
1.   struct inheritance "connection?" (i dunno what that should be called) is also public by default, which means by default you can access a parent class private data member through the child struct. Again, this can be overridden with the `private` keyword, and a class can achive struct default behavior in the same way but with a `public` keyword.   

This means that `struct` and `class` are actually pretty much exactly the same thing, (both can have member methods, etc), so they are used as a naming convention. Usually, people use `struct`s when they are grouping together related variables to abstract the primitive types away, while they use `class`es as an "interface" to abstract entire methods or private variables away. The rule of thumb seems to be to use `classes` if there are private data members or methods, because that means that you are creating an "interface" for other pieces of code to interact with, and if you are simply grouping together data then you should use a `struct`

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

#### Inheritance
**Overview**  
If we have multiple classes that have some similar functionality, we can consider using a base class to implement that functionality and simply have the other classes inherit from the base class. They would then be called _derived_ classes.  
For example, say we have a `Animal` class and a `Cat` and `Duck` class. We could have the `Cat` and `Duck` classes inherit from the `Animal` class and reuse some of the implementation through inheritance. See the example below:

**Example**
```c plus plus
class Animal
{
  unsigned legs;
protected:
  string name;
public:
  Animal () { legs = 0; name = "Anonymous"; }
  Animal (const string& n) { name = n; }

  unsigned getLegs const ()
  { return legs; }

  string getName const ()
  { return name; }
}

class Cat : public Animal
{
  int coat_type;
public:
  Cat (const string& n) Animal(n) {}; // Non-default constructor of Animal called

  int getCoatType const ()
  { return coat_type; }
}

class Duck : public Animal
{
public:
  void setName (const string& n)
  { name = n; }
}

int main ()
{
  Cat catto("Danny");

  Duck ducky;
  ducky.setName("Johnathan");

  cout << catto.getName() << endl << ducky.getName(); // Can still call getName() of both derived classes even though that method was not explicitly declared in the derived class implementation itself
}
```
The above example demonstrates some of the most important concepts in class inheritance, which are summarized below:
1. Derived classes inherit all members from the base class, with access more strict or equal to the access specifier (more on that later)
1. Derived classes will call the default constructor of the base class automatically
1. Derived classes can call other constructors of the base class with a constructor of their own, through initialization list member initialization syntax, as seen in `Cat`.
1. Derived classes are unable to access private members of the base class, such as `legs` in base class `Animal`.

**Access Specifiers**  
Derived classes can have different levels of inheritance from their base classes, which is declared through an _access specifier_ before the name of the base class in the inheritance declaration. It looks something like this: `class Derived : public Base { /* declaration*/ }`. When an access specifier is declared, all members of the base class are inherited with that level of access or more strict, meaning a base class `Base` with derived class `Derived` that has an access specifier `protected` (declared `class Derived : protected Base`) will inherit all `public` and `protected` members from `Base` as `protected`, and all `private` data members as `private`.

By default, `struct`s default to a `public` access specifier and `class`es have a `private` access specifier. However, "most use cases of inheritance in C++ should use public inheritance. When other access levels are needed for base classes, they can usually be better represented as member variables instead." ([CPlusPlus.com](http://www.cplusplus.com/doc/tutorial/inheritance/)), so I guess just always use `public`.

**Multiple Inheritance**  
In C++, a class can inherit from multiple base classes. This works the same single inheritance, except multiple default constructors are called. Otherwise, everything behaves approximately as expected.

**Source**  
[CPlusPlus.com](http://www.cplusplus.com/doc/tutorial/inheritance/#inheritance)
    
#### Access to Class Members
**Overview**  
Things defined in classes, such as variables and functions, are known as class _members_. Compound data types such as `class`es and `struct`s can allow different levels of access to their members, specifically `public`, `protected`, and `private`.  
-   `public` members can be accessed from anywhere in the program, including from `int main ()`. All members of struct are `public` by default.
-   `protected` members can only be accessed by other members of the class/instance and by members of derived classes. Outside functions like `int main ()` are not allowed to access protected members, and must read them through an interface `get` method.
-   `private` members can only be accessed by members of the class/instance they were declared in. Members of derived classes cannot access private members, nor can outside functions or classes.

**Example**  
Here is a simple example showing the syntax for different member access declarations:
```c plus plus
class Foo
{
  int private; // Classes have private members by default.
protected:
  string name; // We don't want anybody to be able to modify the name, but members of derived classes should be allowed to.
  void setName (const string& n) { this->name = n; }
public:
  string getName () { return this->name; } // This "interface" function allows anybody to read the name but not write it.
}
```
  
#### Getters/Setters
**Problem**  
in OOP, classes should be a "black box" in meaning they provide an "interface" that abstracts away the inner workings of the implementation. This idea is called "encapsulation", and is one of the core principles of OOP.  Creating a good interface makes using the class much easier for the users and one way to do that is through using private variables. We use private variables because sometimes other parts of the class depend on a variable to reflect a certain relation with another, and we don't want the user of the class to be able to change these variables at will. It could break alot of things.  
However, we might want the users of our class to still be able to access those variables. For example, `std::string` has an internal variable `length` that we as users of the class cannot access directly and change. However, we might still want to be able to easily access the length of a string, and so that class implements a "getter" called `std::string.length()`.  
Additionally, sometimes we want users to be able to change the variables, but with constraints or additional edits. For example, if we have an `Animal` class, we might not want the number of legs to be negative, or the number of heads to be more than 3. Or, perhaps we want to change the name, but also a seperate variable that stores the length of the name. We cannot ensure that a user of the class would change these data members correctly, but we can force things to stay in sync with a "setter", which is a method that takes in an input and sets the value of the private variable if some constraints are met, and throws an error otherwise. 
This seems to work but it seems tedious to have to write "getters" and "setters" for everything that we want to make private, especially when the best practice is to make everything private when possible (to mitigate unintended effects such as when people go screwing around with your variables). This is a problem with many languages and each language has a different way of dealing with it. Here are two examples:

**Other Languages**  
In **Java**, they tend to have getters and setters for everything. They don't have a special syntax for it, but almost everyone uses a naming convention where `get_varname()` is the getter and `set_varname()` is the setter. Although this makes method names look kind of ugly, it is still a decent way to implement getters and setters.  
In **Python** they use these things called properties. Properties are a way of wrapping up getter and setter methods into an interface which users of the class can access directly. They allow all of these to be declared anonymous and only use one name in the namespace, although you need a seperate private variable to store the actual data of the property object. However, this is still a good "pythonic" way to have getter and setter methods without poluting the namespace or using ugly method or variable names.

**C++**  
However, in C++ there does not appear to be a good way to implement getters and setters. People have said that ["The visibility model in C++ is quite broken"](https://stackoverflow.com/questions/14399929/should-i-use-public-or-private-variables#comment20043206_14399929 "Stackoverflow comment by Marc Glisse on Jan 18 '13"), and the best way to implement getters and setters the Java way seems to be naming internal variables something strange, such as `int i_instance_xpos;` or `static c_class_static_var`. In Python, to work around the lack of private class members people use the naming convention of `_varname` to denote something that shouldn't be touched from outside the class, and I see people using `varname_` as the actual data member and a method called `varname ()` for the getter.

It seems like many people disagree with eachother on the topic of getters and setters, and they are among the most controversial topics in C++ I have discovered to date. Here is a summary of the pros and cons that the sides are arguing:

| Pros | Cons |
|------|------|
| Easier modification/maintinance of code in big projects | Additional overhead (not with a good compiler though) |
| Implement constraints/extra logic | Ugly names, poluted namespace |
| Safety of private variables is maintained | Not "C++ OO" (can usually work around with active methods) |
| If non-trivial: better encapsulation/interfacing | Not worth the time for small projectsu |

People seem to be suggesting that getters/setters are common in other languages, specifically C# and Java (due to their ["reliance on reflections and frameworks to build the object"](https://stackoverflow.com/questions/1596432/getter-and-setter-pointers-or-references-and-good-syntax-to-use-in-c#comment1460847_1596487)), but less so in C++ because the constructor is supposed to take care of all that. Getters are kind of okay because maybe people want to read a value they shouldn't be able to write, but if you have a trivial setter that doesn't add any additional logic then maybe the data member itself should just be public. We can also always overload operators to act as better looking setters if it is truly needed.

**Conclusion**  
Getters and setters are not needed in general, especially since we are working on such small snippets of code. When writing a class for a corporation with clients, they are better because they allow easier maintinance and addition of new features without breaking changes from older versions. But usually, OOP strives to create "interfaces" that provides methods to do "actions" and modifies its own internal private variables. So basically:  
For simple data sacks, use structs with a constructor to ensure everything has a sane value. For big (1000+ lines of code) projects, constructors take care of setting everything up. Other objects can call methods that do actions on the instance, but they don't get to control the classes private variables directly. Getters to provide info, not for heavy use. Otherwise, switch to C# or Java.

**Sources**
-   **[CPPC - Private members and encapsulation](http://www.cplusplus.com/forum/beginner/6415/)**
-   **[SO - Overview of the problem](https://stackoverflow.com/questions/3647438/conventions-for-accessor-methods-getters-and-setters-in-c)**
-   [SO - Java Getters and Setters](https://stackoverflow.com/questions/2036970/how-do-getters-and-setters-work)
-   [Programiz - Python \@Property](https://www.programiz.com/python-programming/property)
-   [SO - Implementation of G/Setters](https://stackoverflow.com/questions/1596432/getter-and-setter-pointers-or-references-and-good-syntax-to-use-in-c)
-   [SO - Private variables and use](https://stackoverflow.com/questions/14399929/should-i-use-public-or-private-variables)
-   [SO - Getters/Setters in C++ from a newbie standpoint](https://stackoverflow.com/questions/737409/are-get-and-set-functions-popular-with-c-programmers)
-   [SO - More advanced getters](https://stackoverflow.com/questions/760777/c-getters-setters-coding-style)



### Tree/Graph Basics
#### Binary Search Tree
A binary tree (each node has at most two children) that is ordered
It is organized such that all nodes to the right of a node is greater in value than that node, and all nodes that are to the left are smaller in value. This makes it easy to search the tree because at each node you can simply go to the right if the value you are searching for is larger than the node, or to the left if the target value is smaller.

#### Counted BST: A binary search tree that has a value and count variable stored at each node
This has all of the advantages of a normal BST, except it can hold multiple accounts of each value, by holding a `count` variable along with the `value` variable at each node. This allows the BST to hold the same value multiple times over, and still make searching the tree easy.  
We can also calculate the `weight` of a node as the sum of the weights of the two children nodes, plus the count of the current node. This recursive system allows us to figure out what index a specific number should be if we were printing out all of the values, for example. This "ranking" property is useful for many applications.

#### Tree Balancing
The shorter the tree, the more efficient search will be happen when the tree is balanced.

There are some ways to achieve this, such as:
-   Random Sort: We scramble the data before starting creating the tree
-   Read From a Heap: By combining trees and heaps, we can get more balanced trees
-   AVL: A self balancing tree structure, which uses "rotations" to balance out an unbalanced tree.
    (This is the most effective method to keep your tree balanced)
    See below:

#### Tree Balancing: Rotation
Rotate the tree to keep the BST properties but make the tree more balanced  
AVLs use this kind of method to keep a BST balanced. There are four types of "rotations" that are used to keep a tree like this balanced:
-   Left: Rotate once left. This works when the top two layers have only one child per node.
-   Right: Same as above but on the right.
-   Left-right: When on average there are more than two children per node, we need these combination rotations, which involve rotating a subtree one direction and then rotating the whole tree the other.  
A good resource for AVL tree rotation basics: [Tutorials Point - AVL Tree](https://www.tutorialspoint.com/data_structures_algorithms/avl_tree_algorithm.htm)

#### Reb Black Tree
A Self Balancing BST that is less balanced than AVL but faster to insert/delete  
A red-black tree is a type of self balancing BST. It can be less balanced than AVL, but it wastes less rotations than AVL so we should use this type of tree if the application has lots of insertions/deletions, but AVL if it has relatively more searches. This kind of tree is often used in the backend of the `std` library to implement things like `std::map`.

Red black trees rely on four properties:
1. Every node is colored red or black (can be represented with a `bool`)
2. The root node is always black
3. There are no two adjacent red nodes (no red node can have a red child)
4. Every path from any node to any descendant null nodes must have the same number of black nodes

These properties make it impossible for three nodes in a row to survive. This means that there can never be a chain of three single nodes in a Red-Black tree. This is how these trees ensure balance.

Insertion of red black trees is somewhat complicated. It consists of the following checks and actions:
1. Do normal BST insert
1. If (parent is black)
    1. Easy way out: New leaf node is colored red, everything is ok
1. Otherwise (parent is red)
    1. If (uncle is red)
        1. Grandfather must be black: Property 4
        1. Color parent and uncle black
        1. Color grandfather red
        1. Recurse up the tree with the grandfather as the new "pseudo-leaf" node
    1. Otherwise (uncle is black)
        1. There are now four configurations that the new and parent nodes could be in.
        1. They correspond nicely with the four AVL cases. Essentially, we left/right/left-right/right-left rotate the parent and grandparent, and then swap the colors of the parent and grandparent.

This will keep the black-red tree somewhat balanced, although not as balanced as an AVL tree. However, it wastes little operations in the balancing process which makes insert/delete faster but search slower. This is a good alternative to AVL trees. Further reading:
-   [Geeks for Geeks 1](https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/) 
-   [GfG 2](https://www.geeksforgeeks.org/red-black-tree-set-2-insert/)
-   [visualization](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html)

#### Bipartite Graph
A graph with two sets of nodes, where a set of nodes cannot have a connection inside it  
Useful for some problems. We can find out if a graph is Bipartite by DFSing through it and checking if every connected node has the same "color" as the current node, and by "coloring" each node the opposite color as its ancestor when traversing. I don't know why this structure is useful yet, but it came up in the second problem of the contest today.
Further resources: 
-   [Geeks for Geeks Bigraph Testing](https://www.geeksforgeeks.org/bipartite-graph/)
-   [Example Applications on Stack Exchange](https://cs.stackexchange.com/questions/24057/concrete-and-simple-applications-for-bipartite-graphs)
-   [A Dense Textbook Excerpt from UChicago Math](http://www.math.uchicago.edu/~may/VIGRE/VIGRE2007/REUPapers/FINALAPP/Salvatore.pdf)

  
### Tree/Graph Storage
#### Trie: Multi-level overlapping storage for segment-able types
A trie is a way of storing data that has "overlapping" sections, such as strings. For example, if we would like to store the words `"these"` and `"there"`, we can store the first three identical characters on the same branch and at the `'e'` node we would branch off into the other characters. Each node can be represented with a struct such as the following:
```c ++
const int ALPHABETSIZE = 26;

struct TrieNode
{
  TrieNode children[ALPHABETSIZE];
  bool isLeaf = false; // is this letter the end of a word?
}
```
In this way, we can search the tree in `O(L)` time where `L` is the length of the word. This is significantly faster than a structure such as a Self Balancing BST, where `search`, `insert`, and `delete` are usually `O(L log n)`. They are also often faster than hashing, because while they have the same time complexity, there is no need to compute a hash function or worry about collisions.
Additionally, tries are good for printing the words in alphabetical order because everything is stored in that kind of logical way. They are also good for prefix search, because the structure is put together in a way that highlights words that start the same way.

However, tries take up a lot of storage, because each node must be able to point to `ALPHABETSIZE` children nodes. In these situations, we should prefer to use other data structures such as a Ternary Search Tree, which supports similar operations but is slightly slower than a trie.

A summary of the pros and cons of the trie:

| Pros | Cons |
|------|------|
| O(L) for insert, search, and delete | Takes up massive amounts of memory |
| Easy alphabetical access | _ |
| Easy prefix search | _ |

More resources on tries:
-   [Geeks for Geeks](https://www.geeksforgeeks.org/advantages-trie-data-structure/)
-   [Boston University CS](https://www.cs.bu.edu/teaching/c/tree/trie/)

#### Linked List
We use a set of linked lists to store edges. Each linked list contains the edges that lead from a specific node. We have a head array to store the starts of the linked lists, and when we want to see all of the edges leading from a node, we just go to the start of the linked list, which is stored by the head array. Then, we can traverse the linked list to get all of the edges leading from the original node, and for each edge we can run the same process on the node that that edge points to. This is a fast way to store and process a tree, and is versatile because we can store edges given different criteria. For example, we can store an edge in the linked list of a node not only when that edge leads from the node, but maybe also when it leads to the node. By varying this criteria, we can make this structure useful for many applications.

TLDR: Instead of storing nodes with arrays of other nodes that are pointed to, we store the edges in sets of linked lists so that we don't have to do expensive array expanding operations like `push_back` in vectors. Instead, we simply use linked lists to store edges and add to the end when needed.

### Tree/Graph Algorithms
#### Floyd Warshall Algo: Find all shortest paths in graph:
Determine shortest distances between all nodes on a graph _independent_ of edges.  
On a graph with `n` nodes and `q` edges, Floyd Warshall runs in `O(pow(n, 3))`. This means that Floyd Warshall is suitable for densely connected graphs because the number of connections does not slow down the algorithm.

Essentially, the algorithm takes each pair of nodes in the graph and tries to get from one node to the other through an intermediate node. If the distance from the `start` to `intermediate` plus the distance from `intermediate` to `end` is less than the current best distance from `start` to `end`, then the best distance is updated to reflect the one that goes through the `intermediate` node.

Some articles about the Floyd Warshall Algorithm:
-   [Brilliant](https://brilliant.org/wiki/floyd-warshall-algorithm/)
-   [Geeks for Geeks](https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/)
-   [Tutorials Point Q&A](https://www.tutorialspoint.com/Floyd-Warshall-Algorithm)

#### Topological Sort: Sort DAG into a forward feed linear
Order the nodes of a DAG such that the parents of each node are always before the node itself in the sort  
Essentially, we would like to take a Directed Acyclic Graph (DAG) and place the nodes in order such that when we see the `id` of a node, we are guaranteed to have already seen all of the ancestors of that node.
This is useful for many applications that involve DAGs, such as determining the order to evaluate expressions in spreadsheets or the order to load modules for each dependent piece of new code to be able to run.
There are two main ways that Topological Sort is achieved:
-   Khan's Algorithm (BFS)
    1.  Start by initializing arrays `in_order` and `visited` with enough space to store pointers to each node
    1.  Visit each node, and count how many direct parents it has. Store this value in `in_order`.
    1.  Find a node that has no ancestors and put it in the front of the queue. This will be our first `source` node.
    1.  While we have nodes in the queue, pop the front and take it as `source`:
        1.  For each `child` of `source`:
            1.  If the `in_order` of `child` is `1` and `child` is not `visited`, then put `child` on in the queue and mark it as `visited`.
            1.  Otherwise, subtract `1` from the `in_order` of `child`.
            1.  `in_order` essentially counts how many parents are remaining to put in the sort before we can put `child` in the sort.
        1.  Add `source` to the end of the Topological Sort.

Khan's Algorithm runs in `O(|V|^2+|E|)`, where `|V|` is the number of nodes/vertices and `|E|` is the number of edges.
-   Modified DFS
    This is basically the same as normal DFS over a graph, except we keep track of what has been visited and don't visit it again. Whenever we reach a new node, we put it at the front of the sort, such that for each node `source` it is guaranteed that all of its descendants are already in the sort, behind it.

    This version of DFS runs in `O(|V|+|E|)` time, which is faster than Khan's Algorithm. This is usually the easiest way of creating a Topological Sort.

Further reading can be found:
-   [Geeks for Geeks](https://www.geeksforgeeks.org/topological-sorting/)
-   [UWashington CS](https://courses.cs.washington.edu/courses/cse326/03wi/lectures/RaoLect20.pdf)
-   [HackerEarth](https://www.hackerearth.com/zh/practice/algorithms/graphs/topological-sort/tutorial/)
-   [Tutorial-Horizon - Algorithms](https://algorithms.tutorialhorizon.com/topological-sort/)

#### Dijkstra Basics: An algorithm to find the shortest route on a weighted undirected graph
Dijkstra's algorithm is often an effective one for finding a route on a graph. Here is a summary of [an article about it on Brilliant](https://brilliant.org/wiki/dijkstras-short-path-finder/) about it.

Basically, the algorithm entails visiting the shortest unvisited node from the origin and checking if going to a neighboring node from that node is less costly than whatever was previously stored in the node. If it is, then the neighboring node is updated.

Here is a more detailed set of instructions for the algorithm:
-   Setup
    1.  Give every node an integer `id`, starting from 0.
    1.  Create 2 arrays \<int\> `dist` and \<bool\> `visit`, each capable of holding all elements.
    1.  Initialize all values of `dist` with `infinity`.
    1.  Initialize all values of `visit` with `false`.
    1.  Initialize `dist[start]` with `0`.
-   Execute
    1.  For each `idx` in `visit`
        1.  If `visit[idx]` is `false` and `dist[idx]` is the minimum of `dist`
            1.  `visit[idx]` = false;
            1.  For each `idy` of neighbors
                1.  If `dist[idy]` more than `dist[idx]` + `inbetween` (the distance between nodes `idx` and `idy`)
                    1.  `dist[idy]` = `dist[idx]` + `inbetween`;
    1.  If there are no more `false` values in `visit`
        1.  Return `dist`

Notably, Dijkstra is gaurenteed to find the shortest path from the start to any node, however it is a "blind" search which means it does not consider where the objective is. This makes it useful for computing things like vector fields, but it runs rather slowly for computing the shortest distance to a specific node. There are other algorithms, such as a "greedy best first search" algorithm which tries to estimate the distance between a candidate test node and the objective, and searches in the "direction" of the objective. This means it can get trapped in concave obstacles, but for the most part it runs much faster than Dijkstra.

Additionally, A\* is a combination of Dijkstra and greedy search algorithms. It tends to perform very well in real world applications because it is fast and versatile. A good A\* resource can be found at [theory.stanford.edu](http://theory.stanford.edu/~amitp/GameProgramming/index.html).

#### Bron Kerbosch: Find Maximal Cliques in Graph
**Overview**  
The Bron Kerbosch algorithm operates on three arrays, often called `R`, `P`, and `X`. I like to call them "require", "possible", and "exclude". The names are pretty self explanatory, and what each recursive substep the algoritm finds all maximal cliques that include all nodes in `R`, any subset of nodes in `P`, and none of the nodes in `X`. By starting off with `R = Ø`, `P = Universe`, and `X = Ø`, we find all maximal cliques in the entire graph.

**Definitions**  
Cliques:  
_A clique is any subset of verticies on a graph._

Maximal Clique  
_A maximal clique is a clique which has the following two properties:_  
1. _Every possible pair of verticies in the clique is connected._  
1. _There are no other verticies in the graph that can be added to the clique while the clique maintains the first property._  

_In other words, a maximal clique is a fully connected clique that cannot be added to._  
Notably, these maximal cliques are what the Bron Kerbosch Algorithm finds in a given graph.

Maximum Clique  
_A maximum clique is the lagrest maximal clique in a given graph, by vertex count. There can be multiple maximum cliques in a graph._  
The size of the maximum clique is the answer we are looking for to solve problem 4 from day 17.

**Algorithm**
> Each recursive stage of the basic Bron Kerbosch algorithm finds all maximal cliques that include all nodes in `R`, any subset of nodes in `P`, and none of the nodes in `X`.  

This is implemented in the following way:
```python
def union (A, B):
  return set union of sets `A` and `B`
  
def intersect (A, B):
  return set intersect of sets `A` and `B`
  
def neighbors (v):
  return set of verticies connected to `v`

def BronKerboschBasic (R, P, X):
  if (len(P) == 0 & len(X) == 0):
    return R # report as maximal clique
  for vertex in P:
    BronKerboschBasic( union( R, {vertex} ),
                       intersect(P, neighbors(vertex)),
                       intersect(X, neighbors(vertex)) )
    # move `vertex` from `P` -> `X` so that we don't check cliques 
    #   with `vertex` in them in the future.
    P = intersect ( P, {vertex} )
    X = union     ( X, {vertex} )
    
```

Essentially, in each recursive step we zoom in on the new vertex that may be added to the clique, and recursively search through all possibilities that include this vertex in the clique. If we reach a point in which there are no more verticies that could possibly be added to the clique, and if the vertex that we just addded is not connected to any of the verticies that we have already thrown out from the past iterations on this layer, then we have a new maximal clique and so we report it.  
(If `X != Ø`, then we have already reported this maximal queue so we should just skip it and keep going.)

At each stage of the recursion, the following properties hold:
1. All elements of `R` are connected to eachother - `R` is a valid clique.
2. All elements of `P` are adjacent to every vertex in `R` - `union( R, x )` is a valid clique for all `x` is an element of `P`.

This is why we can recklessly add elements  from `P` to `R` - because we have set up `P` in a way that all elements are elegible to be added to the clique.

Note: _The set `X` is not central to the function of the algorithm. Instead, it exists to ensure that the algorithm does not find maximal cliques that have already been reported. Otherwise, the algorithm would find each maximal clique `n!` times where `n` is the number of verticies in the clique._

**Complexity**  
This algorithm runs in `O(n^m)`, which is somewhat atrocious.  
However, we can improve this time by using more complex methods such as by adding a "pivot", see below.

**Sources<a name="bkbasic-sources"></a>**
-   [Wikipedia](https://en.wikipedia.org/wiki/Bron%E2%80%93Kerbosch_algorithm)
-   [SO - Basic Python Iplm](https://stackoverflow.com/questions/13904636/implementing-bron-kerbosch-algorithm-in-python)
-   [OpenGenus.com Article](https://iq.opengenus.org/bron-kerbosch-algorithm/)
-   [UGlasglow - Report on BK variations](http://www.dcs.gla.ac.uk/~pat/jchoco/clique/enumeration/report.pdf)
-   [UGlasglow - BK Intro Slides](http://www.dcs.gla.ac.uk/~pat/jchoco/clique/enumeration/papers/bronKerbosch.pdf)
-   [SE CS - Basic Bron Kerbosch Time Complexity](https://cs.stackexchange.com/questions/68060/what-is-the-time-complexity-of-the-classic-bron-kerbosch-algorithm-for-finding-c "What is the time complexity of the classic Bron-Kerbosch algorithm for finding cliques?")

#### Bron Kerbosch Algorithm (with pivot) / Tomita
**Explanation**  
[OpenGenus.org](https://iq.opengenus.org/bron-kerbosch-algorithm) (as well as [Wikipedia](https://en.wikipedia.org/wiki/Bron%E2%80%93Kerbosch_algorithm)) says that the above basic version of the algorithm is inefficient because it makes many useless recursive calls that will not result in a maximal clique. We can augment the algorithm by introducing a "pivot" vertex `u`. Then, in each recursive call we only call the next layer of the algorithm on nodes that can result in a maximal clique based on the pivot.  
The pivot is helpful for reducing the size of the search space from a given recursive state by only allowing the algorithm to search verticies that either are `u` or share no neighbors with `u`, because if the new vertex shared a neighbor with `u` then we could also add `u` to the clique. That possibility is already taken care of when we choose the pivot `u` to be the new `v`.  
The above concept is kind of confusing, but the logic can be clearly seen when view like this:  
> Each element of `P` is already able to form a clique with `R`; the only reason we don't simply `return union(R, P)` is because elements of `P` don't necessarily form cliques amongst themselves (i.e. they aren't adjacent to eachother). However, if an element `v` of `P` is a neighbor of the pivot `u`, then we could add both `u` and `v` to `R` and still have a maximal clique. And because this possibility includes `u`, it is already taken care of when we choose `u` to be the new vertex `v`.

The redundant recursive trees that the pivot processs truncates are normally terminated at the bottom of the tree when `P = Ø` and `X != Ø`. Instead of waiting until the end to make sure we aren't redundantly reporting cliques, we can do some of this pruning during the recursion by only splitting down recursive branches if we are sure that they don't interfere with the pivot.

This means that we need to choose a pivot that maximizes the reduction of redundant branches, by choosing a pivot `u` that has the maximum number of neighbors. This is called Tomita`s algorithm, and has Python code like this:

**Example**
```python
def union (A, B):
  return set union of sets `A` and `B`
  
def intersect (A, B):
  return set intersect of sets `A` and `B`
  
def neighbors (v):
  return set of verticies connected to `v`

def BronKerboschBasic (R, P, X):
  if (len(P) == 0 & len(X) == 0):
    return R # report as maximal clique
  u = element of union(P, X) with maximum neighbors
  for vertex in P & not in neighbors(u):
    BronKerboschBasic( union( R, {vertex} ),
                       intersect(P, neighbors(vertex)),
                       intersect(X, neighbors(vertex)) )
    # move `vertex` from `P` -> `X` so that we don't check cliques 
    #   with `vertex` in them in the future.
    P = intersect ( P, {vertex} )
    X = union     ( X, {vertex} )
```
This is essentially the same as the basic Bron Kerbosch algorithm, but we choose a pivot instead of running through every possibility at each stage. (The skipped possibilities will still be processed further in the recursive tree.) 

_We can find the pivot in `P` or `X` because they are pretty much the same thing, but `X` has already been visited. Thus, it doesn't matter if the pivot comes from `P` or `X`, as long as it is one of them._

**Complexity**  
Although specific complexity of this algorithm depends on implementation, a suite of tests run with java implementations found the number of expanded verticies to be reduced by a factor of between 2 and 2000. The times also ranged in terms of performance, sometimes similar to basic Bron Kerbosch and sometimes reduced by a factor of 2. However, based on the desrciption of the process these [tests](http://www.dcs.gla.ac.uk/~pat/jchoco/clique/enumeration/report.pdf "Review of the Bron-Kerbosch algorithm and variations by Alessio Conte") were not highly rigorous and results should be taken with a grain of salt.

**Sources**  
See [the sources under "Bron Kerbosch Algorithm Basic"](#bkbasic-sources)

### Heaps
#### Binary Heaps: A heap that is also a binary tree
We can store this structure in an array, see "Storing Binary Tree/Heaps" below.

To insert, we insert the new node at the bottom of the heap, in the next empty spot of the array. Then, if the new node is out of order compared to its parent, then we simply swap those nodes, and repeat until the heap structure is maintained.

To delete, we remove the top/root node (that's the whole point of a heap anyways, and if for some reason you want to remove something else then just find it first and call it the root of that subtree, the rest of the heap doesn't care.) and fill it's place with the last node, which is one of  the smallest. Then, take the maximum of { the new root `root`, and the original `left` and `right` children }. The `root` is swapped with the largest of those and the process repeats with `root` as the root of the affected subtree.

Heaps can be used in many places, (at least that's what it looks like from the past few days because we have been doing heap problems). Usually, when you need to continually find the least or most of something with limited other restrictions, then you want to use a heap. Especially when there is an order to the information you receive or some kind of ordering to when some actions can be performed, we can take advantage of an "intermediate" heap with limited information to find the least/most value with that particular set of information that is available in that stage of solving the problem. For example, the whackamole problem from Monday was heapable because we could make limited information heaps for each frame of time and only insert hamsters into the heap that would expire in that frame of time. This is one way to make the problem smaller and divide and conquer.

In summary, _heaps are good for maintaining a global min/max, because the min/max can be accessed in `O(1)` and this can be maintained upon insertion/deletion in `O(log n)`. Thus, heaps are good for maintaining a global min/max relatively cheaply._

#### Storing Binary Trees/Heaps: Basically just shove them in an array
Because they are always the same size, if we number the nodes starting at the root going layer by layer left to right, then the child of any node will always be `node*2` and `node*2+1` in the array, and the parent of that node will always be `node/2`. This is much more convenient than storing pointers to the children, or storing edges or some shenanigans like that.

#### Priority Queues
**Theory**

The simplest implementation of priority queues use arrays, because they are easy to understand and use. However, they are not particularly fast (read `O(n)`, insert `O(1)`, delete `O(n)`).

However, priority queues are often implemented with heaps, where whenever a new item is added to the priority queue, it is also added to the heap. Most priority queue implementations use binary heaps because they are relatively simple and fast  (read `O(1)` and insert/delete `O(log n)`). However, we can also use Fibonacci heaps which significantly speed up the insert operation (insert `O(1)`). The `std` library uses Fibonacci heaps to implement `priority_queue` which makes it a good wrapper for any heap and priority queue needs.

**STL Implementation**

Priority queues (defined in the `<queue>` header for C++11) are essentially heaps.
You can `push()` and `pop()`, and access the element with the least sort through `top()`. Here is an example of priority queue usage:
```C plus plus
#include <bits/stdc++.h>
#include <queue> // for priority_queue
#include <vector> // for vector
#include <functional> // for greater
using namespace std;

int main ()
{
  // Create the priority_queue
  priority_queue< int, vector<int>, greater<int> > mypq;
  // Make sure to separate `>` signs to avoid creating an accidental pipe!

  int num;
  scanf("%d", &num);
  for (int i=0; i<num; ++i)
  {
    int t;
    scanf("%d", &t);
    mypq.push(t);
    printf("Minimum so far: %d", mypq.top());
  }

  printf("Global minimum: %d\n", mypq.top());

  mypq.pop();
  printf("Second smallest: %d\n", mypq.top());

  mypq.pop();
  printf("Third smallest: %d\n", mypq.top());

  return 0;
}
```
This example uses most of the basic functions of `priority_queue`.

**Summary**

Priority queues are good for keeping a global minimum/maximum. It can be created in `O(n)` time and the sorted element can be removed in `O(log n)`. It can be used for any applications which require a heap or a queue, or when an actual priority queue is needed. In the real world, it is used for things like CPU Scheduling and graph algorithms such as Dijkstra and Prim's Spanning Tree.

**Extra Reading**

-   [cplusplus.com Reference](http://www.cplusplus.com/reference/queue/priority_queue/)
-   [GfG Priority Queue Introduction](https://www.geeksforgeeks.org/priority-queue-set-1-introduction/)
-   [GfG Applications of Priority Queue](https://www.geeksforgeeks.org/applications-priority-queue/)

### Linked Lists
#### Basic Linked List
**Overview**
A linked list is a data type to store a list of items. It is useful because it has fast insert and iterate, but it is difficult to search or delete from them. They also don't need a continuous portion of memory, which means they can often store more items than a normal array.

**Example**
Here is a sample class implementing linked lists
```c plus plus
class LinkedList
{
public:
  // A Link struct to use as each element in our linked list.
  // It's public so that outside functions can create their own Link objects to add to the list.
  struct Link
  {
    int data;
    Link* next;
    Link ()
      { data=0; next=nullptr; }
    Link (const int d, Link* n)
      { data = d; next = n; }
  };
private:
  Link* head; // This is a pointer to the start of our list.
  // We add to the front of the list, updating the `head` pointer as we go.
public:
  LinkedList () { head = nullptr; }
  ~LinkedList ()
  {
    for (Link* p=head; p != nullptr;)
      pop();
  }
  
  Link* front () const { return head; }
  
  void push (const int data)
  {
    // Create the new link
    Link* p = new Link {data, head}; // Note: doesn't handle bad_alloc
    // It has a value of `data`, and it points to the current
    //  front of the list as its `next` link
    
    // Store the new front of the list
    head = p;
    // "push" the entire list "backwards" and add the new link to the front.
  }
  void pop ()
  {
    // Remove a link from the front of the list
    // First we save the value of what the new head is going to be
    Link* p = head->next;
    // Then we delete the dynamically alocated first link, to free up the memory
    delete head;
    // Finally we update head to reflect the removed node
    head = p;
  }
};
```
**Applications**
Linked lists can be used for applications that require only add and traverse operations, because that is what they are best at. For example, the edge list method for storing trees and graphs uses linked lists.

#### Doubly Linked List
**Overview**  
A doubly linked list is a linked list that is connected in both directions. Instead of only storing a `next` pointer, it also stores a `previous` pointer. This makes the delete operation much faster if only given a pointer to the node to delete because we can directly access the nodes on either side, unlike with a singly linked list where we need some reference to the previous node. This is the primary advantage that the doubly linked list has over its normal variant.  
However, the doubly linked list uses 1.5 times the memory of a singly linked list because it stores an additional `previous` pointer. There are ways to implement a doubly linked list with a single pointer per node through an XOR linked list, but traversal requires the memory addresses of one of the nodes to calculate the address of the other.

**Example**  
Here is an example implementation of a `Node` struct to be used in a doubly linked list:
```c plus plus
#include <iostream>

using namespace std;

template <class Data>
class Dll
{
public:
  struct Node // todo: should this be static? does that make the defined vars also static?
  {
    Node* prev=nullptr;
    Node* next=nullptr;
    Data data;
  };
private:
  const static int cf_maximum_size = 10;
  
  unsigned long long t_size = 0;
  
  Node nodes[cf_maximum_size], *beg=nullptr, *end=nullptr;
public:
  Dll () {};
  
  void pushFront (const Data _d)
  {
    (this->nodes)[t_size].data = _d;
    (this->nodes)[t_size].prev = nullptr;
    if (beg == nullptr)
    {
      end = &((this->nodes)[t_size]); // first node, set the end pointer also
      (this->nodes)[t_size].next = nullptr;
    }
    else
    {
      beg->prev = &((this->nodes)[t_size]);
      (this->nodes)[t_size].next = beg;
    }
    beg = &((this->nodes)[t_size]);
    ++t_size;
  };
  void pushBack (const Data _d)
  {
    (this->nodes)[t_size].data = _d;
    (this->nodes)[t_size].next = nullptr;
    if (end == nullptr)
    {
      (this->nodes)[t_size].prev = nullptr;
      beg = &((this->nodes)[t_size]);
    }
    else
    {
      end->next = &((this->nodes)[t_size]);
      (this->nodes)[t_size].prev = end;
    }
    end = &((this->nodes)[t_size]);
    ++t_size;
  };
  void pushBefore (Node* _n, const Data _d)
  {
    (this->nodes)[t_size].data = _d;
    
    (this->nodes)[t_size].prev = _n->prev;
    _n->prev->next = &((this->nodes)[t_size]);
    
    (this->nodes)[t_size].next = _n;
    _n->prev = &((this->nodes)[t_size]);
    
    ++t_size;
  };
  void pushAfter (Node* _n, const Data _d)
  {
    this->nodes[t_size].data = _d;
    
    (this->nodes)[t_size].next = _n->next;
    _n->next->prev = &((this->nodes)[t_size]);
    
    (this->nodes)[t_size].prev = _n;
    _n->prev = &((this->nodes)[t_size]);
    
    ++t_size;
  };
  
  unsigned long long size () { return this->size; }
  Node* next (Node* cur) { return cur->next; }
  Node* prev (Node* cur) { return this->prev; }
  Node* front () { return this->beg; }
  Node* back ()  { return this->end; }
  void print () {
    for (Node* pt = this->beg; pt != nullptr; pt = pt->next)
      cout << pt->data << " ";
    printf("\n");
  }
};

int main ()
{
  Dll<int> mylist;
  
  mylist.pushFront(2);
  mylist.print();
  
  mylist.pushBack(5);
  mylist.print();
  
  mylist.pushAfter(mylist.front(), 3);
  mylist.print();
  
  mylist.pushBefore(mylist.back(), 4);
  mylist.print();
  
  mylist.pushFront(1);
  mylist.print();
  
  return 0;
}
```
Unfortunately, I was not able to debug `Dll<>::pushBefore()` or `Dll<>::pushAfter()`. However, the `pushFront()` and `pushBack()` functions still work.

**Complexity**  
-   Insert `O(1)` given a pointer to the node by which to insert  
-   Delete `O(1)` given a pointer of the node to delete
-   Read `O(1)` given a pointer to the node with the value
-   Read `O(n)` given an index `n` to read

#### XOR Linked List
**Overview**  
XOR linked list is a version of a doubly linked list that uses a single value to store the memory addresses of both the next and previous nodes. As the name suggests, it takes the XOR of the previous and next memory addresses so that each address can be recovered by XORing the combined address with the address of the previous node.  
This means that two addresses are required at all stages to continue traversing the list, which is one of the primary disadvantages that the XOR linked list has over the normal doubly linked list. Otherwise, the XOR linked list is generally somewhat slower than the doubly linked list because it includes additional relatively cheap but still required XOR operations for each insert, delete, and traverse operation. However, the time complexities are still the same.

**Example**  
Because I don't have the time to provide a fully working example, I will provide a mock up implementation which is most likely highly buggy:
```c plus plus
class Xll
{
  #include <iostream>

  using namespace std;

  const int MAXSZ = 10;

  template<class Data>
  class XLL
  {
  public:
    struct Node
    {
      unsigned long long mem;
      Data dat;
    };
  private:
    const static int maximum_size = MAXSZ;
    Node c_nodes[maximum_size];
    unsigned long long c_len = 0, c_beg = 0, c_end = 0;
  public:
    XLL () {};
    
    void pushFront (Data _d);
    void pushBack (Data _d);
    void pushBefore (unsigned long long position, Data value);
    void pushAfter (unsigned long long position, Data value);
  };

  template<class Data> void XLL<Data>::pushFront (Data _d)
  {
    if (c_beg == c_end) // if empty
      c_nodes[c_len].mem = NULL; // set memory to null, because there is nothing to link to
    else
    {
      c_nodes[c_beg].mem ^= c_len; // xor previous first node memory value with this one to create the xor linked list property in the other node
      c_nodes[c_len].mem  = c_beg; // set memory to the next thing, because there is no other side to XOR with
    }
    c_nodes[c_len].dat  = _d; // set the data of the current node
    c_beg = c_len; // update the storage of the begining
    ++ c_len; // update the length, which is also the index in the array where the next node will be added
  }

  template<class Data> void XLL<Data>::pushBack (Data _d)
  {
    if (c_beg == c_end) // if empty
    {
      pushFront(_d); // same thing as push front
      return;
    }
    c_nodes[c_end].mem ^= c_len;
    c_nodes[c_len].mem  = c_end;
    c_nodes[c_len].dat  = _d;
    c_end = c_len;
    ++ c_len;
  }
}
```
Notably, we cannot insert directly into the middle of an XOR linked list unless we are given two adjacent nodes to insert between, because we cannot calculate adjacent memory addreses without atleast two to XOR together. This is a good example of the primary downfall of the XOR linked list structure.

**Summary**  
XOR linked lists allow us to save around 33% of the memory used by a doubly linked list, but it is more computationally intensive and requires the memory addresses of two adjacent nodes to begin traversal at an arbitrary point. Otherwise, they are a good alternative to standard doubly linked lists.

### Maps
#### `std::map`
**Overview**  
Maps are basically the same as Python dictionaries, in that they associate a key with a value. However, in python the key must be of type `str` while in C++ the key can be any type. `std::map` tends to store values in a binary search tree based on a comparison object, which should follow a "strict weak ordering", whatever that means. The ordering makes it possible to iterate through the map, however it also means that `std::map` is slightly slower than `std::unordered_map` defined in the `<unordered_map>` header.

**Examples**  
We can create a simple `std::map` with keys of type `std::string` and values of type `int` like this:
```c plus plus
#include <bits/stdc++.h>
using namespace std;

int main ()
{
  map<string, int> mymap;

  mymap["cow"] = 6;
  mymap["dog"] = 8;
  mymap["turtle"] = 7;

  printf("%d", mymap[cow]);
}
```

We can also create a map that uses a custom ordering for its key sorting, with either a compare class or a compare function pointer, like this:
```c plus plus
#include <map>
#include <cstdio>
#include <string>
using namespace std;

bool strComp (const string& a, const string& b)
{ // Compare lexicographically as a demo, even though std::string already has this feature implemented with operator overloads
  if (a.length() < b.length()) return true;
  else if (b.length() < a.length()) return false;

  // String lengths are the same
  for (int i=0; i<a.length(); ++i)
  {
    if (a[i] < b[i]) return true;
    else if (b[i] < a[i]) return false;
  }
  // We don't actually need to worry about the case where `a[i] == b[i]` because the keys will never be exactly the same, after all, that is not allowed in a map!
  return false;
}

struct StrComp
{
  bool operator() (const string& a, const string& b) const
  { // This is the same logic as in the `bool mycmp(string, string)` function
    if (a.length() < b.length()) return true;
    else if (b.length() < a.length()) return false;

    for (int i=0; i<a.length(); ++i)
    {
      if (a[i] < b[i]) return true;
      else if (b[i] < a[i]) return false;
    }
    return false;
  }
};

int main ()
{
  bool (*fcmp) (const string&, const string&) = strComp;
  map<string, int, bool(*)(const string&,const string&)> funcComp (fcmp); // We pass the class constructor template a function pointer to specify that we are using a comparison function

  map<string, int, StrComp> classComp; // But if we use a class comparison method, we can simply pass a reference to the class definition
}
```
and accessing the info stored is done with the `[]` operator and the value of the key. Pretty much the same as an array, or again, a Python dictionary.

**Summary**  
Maps are pretty much dictionaries, but the key can be any type/class. However, they are ordered which means the key type must have a strict weak ordering property (???), and we can provide a custom compare function through either a class method or a function pointer. Maps are somewhat slower than unordered maps, but they can be iterated through which is a big advantage.  
[cplusplus.com](http://www.cplusplus.com/reference/map/map/) says that "Maps are typically implemented as _binary search trees_.", which means that they have a similar complexity. It depends on what the specific BST used is, but I assume it is a self balanced one and so it is probably AVL or a Red Black Tree.

**Sources**  
-   [Cplusplus.com - `std::map`](http://www.cplusplus.com/reference/map/map/)

### Recursive Algorithms
#### Recursion: Use when possible
It is very helpful for clean code and subproblems. Just make sure you craft your inputs, outputs, and exit cases clearly, or it can be easy to screw up.
These kinds of places are very prone to fencepost errors, so when debugging, look there first.
Also, make sure you know exacly how you are spliting the problem into subproblems before starting to write code, or else it is easy to confuse yourself and end up doing something wrong.
The pain of debugging at that point will become very great because the problems fold over on themselves. So make sure you know exactly how the algorithm
you are writing works before attempting to write it with recurssion.

Also remember: Recursion is basically brute force with some optimizations (the exit cases). So don't worry about writing a recursive brute force.
Instead, look for places to optimize exit cases.

#### Recursion: less arguments?: Sometimes using globals are better for speed and ease of use
When writting comptetition code, such as this, speed is important. Sometimes we can get away with using globals, even if they are bad practice, because it makes the code run faster.
For example, if in a recursive function you are passing a massive object that requires a copy menuver each time the function is called, then using a global is going to be much faster because it removes
that extra overhead. In these situations, it is acceptable to use globals. Infact, they will be required for some types of problems in the future.  
However, that does not mean that they are good practice. It's probably worth it to stay away from them when posssible, especially when working on normal projects and not competition code.

#### BFS for maps, DFS for trees
In general, it seems like BFS is better for maps and DFS for trees and other types of structures.
BFS increments one step at a time, and searches the entire area possible with that many steps which makes it good for finding shortest path
type solutions.    However, DFS goes all the way down the depth of the search space before returning, which makes it difficult to decide weather
to check if a specific spot can be reached through a shorter path on a map. However, in other structures such as trees, where movement is more
restricted to "coridors" DFS can work much lighter than BFS because DFS can easily be implemented with recursion, while BFS often requires a
seperate data structure to remember what still needs to be visited, such as a `queue`. Choosing BFS vs DFS is important for efficient solving of a problem and these factors need to be taken into consideration.

#### Extended Euler's Algorithm
**Math and Implementation**
`ax + by = gcd(a, b) = gcd(b, a % b)` <- this is the heart of euler's algorithm
```
ax = by + 1
ax = 1 (mod b)
```
and something about
```
x = y'
y = x' - floor( a/b )*y'
```
where `ax+by = gcd(a, b)` and `x'` and `y'` are the previous `x`, `y` respectively.

This means that once we have one solution, we can go back and find all solutions. And there is one trivial solution with Euler's GCD method: where `x = 1` and `y = 2`;

```c plus plus
// This code sample was written from a verbal dictation,
// and probably contains errors.
int exGcd(int a, int b, int& x, int& y)
{
  if (b==0)
  {
    x=1; y=0;
    return a;
  }

  int r=exGcd(b, a%b, x, y);
  int t=x;
  x=y;
  y=t-a=b*y;
  return r;
}
```
**luogu P1082**
Find the problem [here](luogu.org/problem/P1082).

_Given `a` and `b`, find the minimum `x` such that `ax=1 (mod b)`_.   This uses the above strategy, somehow? `ax=by+1` -> `ax-by=1`

**Sources**
-   [Brilliant Wiki - Extended Euclidean Algorithm](https://brilliant.org/wiki/extended-euclidean-algorithm/)
-   [Article in Mandarin explaining the math](https://blog.csdn.net/fearlessxjdx/article/details/74276376)
-   [GfG - Euclidean Algorithms (Basic and Extended)](https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/)

### Debugging
#### Submitting Stubborn Problems: Try variations
Sometimes problems refuse to AC, and in these cases you should try different meta-variations. Try it on a different submission server, or with redundant optimizations incase somehow your thinking didn't work out right. A seemingly redundant optimization is what made the difference with 7999, where a value (`tmax`) shouldn't even be greater than another value (`totmin`), so it was not explicitly checked as a redundant exit case. However, adding that exit case seems to make the entire process run significantly faster, even though it should be redundant.

### Misc
#### Exit
Exit the entire program from outside of main.
**THIS IS CONSIDERED A BAD PRACTICE** because stuff might not be cleaned up properly.  Better to throw a custom exeception class that will be caught in main and have the program exit from main normally there.

#### `size_t`: an unsigned type to represent sizes in memory
This type is usually defined per implementation to be either an `unsigned int` or `unsigned long long`, and is used as the type for variables which store memory sizes. Although it is not technically necessary, it is good practice to use the `size_t` type because it makes it more clear what the variable you are defining will be used for. It doesn't look like there are any real disadvantages, as long as you keep in mind that `size_t` will be an `unsigned` type.

An internet debate discussing the advantages and disadvantages of using `size_t` as an argument type can be found on [bytes.com](https://bytes.com/topic/c/answers/220206-what-size_t), and some quick reference from [cplusplus.com](http://www.cplusplus.com/reference/cstring/size_t/).

#### Bitwise: Fast but furious
Using bitwise operations to do things is fast, because thats how computers are stored. However, it is also painful because it is the real inards of computers. To tackle a project bitwise means that you have to be ready to go through some pain. Remember, bitshift as your best friend because it is fast and effective. That and the bitwise opperators: not `!`, and `&`, or `|`, and xor (dif) `^`. But if you can help it, still stay away from bitwise.

#### Bit Masks
**Overview**  
Bit masks are used to keep/flip/write certain bits. In general, these bits don't represent binary numbers the way most sections of memory do, and instead may represent other things, such as a snowflake. Usually, there is a value and a mask, and we can use different bitwise operators to "mask" the mask on the value. The bitwise operators used are `&` for keep, `^` for flip, and `|` for write.

**Examples**  
For example, if we are working with 8 bit numbers we might use a `0b00001111` (`0x0f`) mask to read the last 4 bits of an 8 bit value. We would do something like this:
```c plus plus
    0b01101011  <- value
 &  0b00001111  <- mask
--------------
    0b00001011  <- answer
```
which, as you can see, extracts the last four bits of the original value.

**Uses**  
Some problems are more easily solvable with bit masks, such as problem D from yesterday's test (CodeForces \#553, Div 2). The problem was solved with some complex transformations, where we start by reading the input into an array of bit masks. These bit masks can then be used for other things, such as constructing a graph, which is the next step in that problem.

Another example of using bitwise flags and masks is the N Queens problem. We can store four bitwise flags, one for board horizontal, vertical, and two for the diagonal directions and use these to store what board spaces we can place new queens on instead of storing the entire board. This significantly compresses the amount of storage needed even for bigger chessboards from a space complexity of `O(n^2)` to `O(6n)`. The lessened search space also allows a recursive backtracking algorithm to run faster.

These kinds of bit flags and masks are also used for many real world applications, such as permissions for files on linux computers, which are stored as three bit flags for read, write and execute. Bit masks are also used in IPv4 in the form of net masking, which is why so many LAN ip addresses start with 192.168 (they were masked with 11000000:10101000).

**Sources**
-   [SO - What is bit masking?](https://stackoverflow.com/questions/10493411/what-is-bit-masking)
-   [LearnCpp.com - Bit Flags and Masks](https://www.learncpp.com/cpp-tutorial/3-8a-bit-flags-and-bit-masks/)

#### Speed: look for redundancy
Finally solved the queens problem today after Teacher Wang pointed out that I had an
extra for loop that was not needed in my recursion function.
It could be simulated by recursing through the same area as the for loop, and removing the for loop
made the entire programe much faster. Next time, don't waste so much time not noticing things.
Instead, stop, and get some help.

#### Inline
The `inline` keyword defines a function that is placed in line at compile time so there is less jumping around.
this causes less calling and function jumps which makes it faster but also more space required for the compiled binary (i think). usage: `inline void myfunc (int arg)`
