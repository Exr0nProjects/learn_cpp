## Summary for Day 8 (16 July 2019)

#### Problems:
|  Page  |  PID  |  Description  |  Status  |
|-------:|-------|---------------|:--------:|
2.13 | 1228 | n queens problem | WA
   " | 1227 | connected reigons | WA
   " | 7084 | binary tree encoding | AC
   " | 7998 | dp work distribution | WA
c1225|    1 | counting permutations (similar to 7977) | TLE
   " |    2 | permutations with identical digits | WA
   " |    3 | permutations without consecutive numbers | TLE

#### Concepts:
* **inline**: function that is placed in line at compile time so there is less jumping around?

    this causes less calling and function jumps which makes it faster but also more space required for the compiled binary (i think). usage: `inline void myfunc (int arg)`

* **exit**: exit the entire program from outside of main.  

    **THIS IS CONSIDERED A BAD PRACTICE** because stuff might not be cleaned up properly.  Better to throw a custom exeception class that will be caught in main and have the program exit from main normally there.

* **pointers**: stay away from them, especially in 2d arrays and with structs.  

    They are not a good choice for competition/speed coding because they screw up so easily. If you have a signal 11 (segfault), then it's probably the pointer's fault. If your code breaks, its probably the pointer's fault. Just delete them. They can usually be worked around anyways.

* **struct vs classes**: essentially just a naming convention   

    They are actually basically the same thing, because the only technical language differences are that:  
    1. struct member variables are public by default (can be overridden to make it the same as a class and vise versa)
    1. struct inheritance "connection?" (i dunno what that should be called) is also public by default, which means by default you can access a parent class private data member through the child struct. Again, this can be overridden with the `private` keyword, and a class can achive struct default behavior in the same way but with a `public` keyword.   

    This means that `struct` and `class` are actually pretty much exactly the same thing, (both can have member methods, etc), so they are used as a naming convention. Usually, people use `struct`s when they are grouping together related variables to abstract the primitive types away, while they use `class`es as an "interface" to abstract entire methods or private variables away. The rule of thumb seems to be to use `classes` if there are private data members or methods, because that means that you are creating an "interface" for other pieces of code to interact with, and if you are simply grouping together data then you should use a `struct`

#### Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 10
