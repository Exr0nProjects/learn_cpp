# Summary for Day 22 (1 August 2019)

## Problems:
|  Page  |  PID  |  Description  |  Status  | Notes |
|-------:|-------|---------------|:--------:|-------|
  dev.xjoi 1216 | 1 | Weird knapsack | WIP | Combines different types of knapsack. I recognize the problem but I don't remember how to do the knapsack DP, so I was unable to do it
""|  2  | Serpentine Matrix addition | WA | didn't start focusing on this problem until too late, originally read problem wrong. Bad at math, will work on more later. 
""  | 3 | Create DAG, shortest path | WIP | Don't know how to test for loops, unable to do topological sort. Will work on more later.

#### Problem Review
**Problem 2 (dev.xjoi 1216 Today)**  
Brute force can get 260/400 points...  
Otherwise it's a math problem.  
I think they use dp somehow?
I originally thought it was just the sum of the sum of the numbers below of the numbers below, but then I realized that it was actually based on the serpentine matrix positioning at which point I had already spent an hour on the math. I then took a break on that problem to look at the other ones, and wasted a bunch of time trying to figure out how to find loops in a directed graph.

**Problem 3 (dev.xjoi 1216 Today)**  
first way find loop  
tower? edge?  
all verticies something  
It is very difficult to hear what is going on through the microphone from the other class...

## Concepts:
### Getters/Setters
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
- **[CPPC - Private members and encapsulation](http://www.cplusplus.com/forum/beginner/6415/)**
- **[SO - Overview of the problem](https://stackoverflow.com/questions/3647438/conventions-for-accessor-methods-getters-and-setters-in-c)**
- [SO - Java Getters and Setters](https://stackoverflow.com/questions/2036970/how-do-getters-and-setters-work)
- [Programiz - Python \@Property](https://www.programiz.com/python-programming/property)
- [SO - Implementation of G/Setters](https://stackoverflow.com/questions/1596432/getter-and-setter-pointers-or-references-and-good-syntax-to-use-in-c)
- [SO - Private variables and use](https://stackoverflow.com/questions/14399929/should-i-use-public-or-private-variables)
- [SO - Getters/Setters in C++ from a newbie standpoint](https://stackoverflow.com/questions/737409/are-get-and-set-functions-popular-with-c-programmers)
- [SO - More advanced getters](https://stackoverflow.com/questions/760777/c-getters-setters-coding-style)

## Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 10

I spent alot of time doing problems, specifically debugging a class I wrote to implement edgelists. That is what got me into rabbit hole of getters and setters and the best way to write classes. Looking at the people around me, I deffinately need to practice writting more C++ code and debugging it because I am far slower than people like Alex Du. However, that means that I can spend less time reading and gathering new information, which feels less productive to me personally. This is a problem that I struggle with in many areas and something I should work on altering in my mental state, because I often feel like I am not putting in enough effort if I am grinding practice, muscle memory or experience. So I need to accept having a short summary and tomorrow night I won't spend an additional 2.5 hours reading up on a niche subject of OOP on Stack Overflow. Hopefully. Or maybe I will find some other obscure thing to write about tommorow. Anyways I'm going to take a break now.