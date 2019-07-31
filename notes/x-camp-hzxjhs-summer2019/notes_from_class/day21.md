# Summary for Day 21 (31 July 2019)

## Problems:
|  Page  |  PID  |  Description  |  Status  | Notes |
|-------:|-------|---------------|:--------:|-------|
  dev.xjoi c1212| 2 | connecting letters | WIP | Segfaults are annoying

### Problem Review
**Problem 1 (dev.xjoi.net 1212) today**  
We use a "bigboi" method where each node stores its own "leader". Each node starts out being its own leader.  
Then, we go through and connect stuff from the input, where if `a` and `b` are connected then we change one's leader to the other. Say we "move" `b` to be under `a`, meaning we change `b.leader := a.leader` and then recurse upwards so that all of `b.leader->leader` and `b.leader->leader->leader` etc all go under `a`, until `b.leader->....leader->leader = b.leader->....leader`(in other words, until the leader we are modifying's leader is itself (ie we reached the end of the chain of command)). We also have a function called `find` which finds a given node's top leader, and in the process moves all of those layers to be directly under the top leader. this eventually colapses all of the chains of command down to just a single layer, which makes the find function more efficient in the future.

**Problem 2 (above)**  
Basically connect the letters together and make a graph. If you can draw it in one line without repeating edges then it is doable.  
Use Eulers number rule thing, where there must be either 2 or 0 nodes with an odd number of connections. Then run dfs and ensure we start and end on an odd node if there are odd nodes, otherwise it doesnt matter. Greedy algorithm at each step for lexographical order.

**Problem 3 (above)**  
n verticies, n-1 edges, minimal spanning tree?
Look for cycles. First find a point, then find a tree, then realize there are n edges, and because of that do something with the other thing what?
Construct a tree on every vertex in the loop, something about trees that go across the loop?
zhei yang zi a few times without visuals.
something about the width of the tree? We have to build a tree in a specific way.

## Concepts:
### Access to Class Members
**Overview**  
Things defined in classes, such as variables and functions, are known as class _members_. Compound data types such as `class`es and `struct`s can allow different levels of access to their members, specifically `public`, `protected`, and `private`.  
- `public` members can be accessed from anywhere in the program, including from `int main ()`. All members of struct are `public` by default.
- `protected` members can only be accessed by other members of the class/instance and by members of derived classes. Outside functions like `int main ()` are not allowed to access protected members, and must read them through an interface `get` method.
- `private` members can only be accessed by members of the class/instance they were declared in. Members of derived classes cannot access private members, nor can outside functions or classes.

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

### Inheritance
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


## Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 7

I forgot my laptop today but Alex G let me borrow his. However, all of my workflows were not set up and I got distracted easily by people around me. I also did not get very good sleep last night so it was hard to think efficiently. Today was not very productive. More sleep and more laptops, and more working on problems instead of spending all of my time researching concepts tomorrow.
