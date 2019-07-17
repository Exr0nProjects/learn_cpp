## Summary for Day 9 (17 July 2019)

#### Problems:
|  Page  |  PID  |  Description  |  Status  |
|-------:|-------|---------------|:--------:|
 2.13 | 1227 | connected reigons | AC
 "    | 1228 | n queens | TLE
 "    | 7998 | work division | AC
 "    | 7999 | work division v2 | AC
 "    | 7087 | tree conversion | TLE

#### Concepts:
- **recursion**: use when possible
    It is very helpful for clean code and subproblems. Just make sure you craft your inputs, outputs, and exit cases clearly, or it can be easy to screw up.
    These kinds of places are very prone to fencepost errors, so when debugging, look there first. 
    Also, make sure you know exacly how you are spliting the problem into subproblems before starting to write code, or else it is easy to confuse yourself and end up doing something wrong. 
    The pain of debugging at that point will become very great because the problems fold over on themselves. So make sure you know exactly how the algorithm
    you are writing works before attempting to write it with recurssion.
    
    Also remember: Recursion is basically brute force with some optimizations (the exit cases). So don't worry about writing a recursive brute force. 
    Instead, look for places to optimize exit cases. 

- **recursion: less arguments?**: sometimes using globals are better for speed and ease of use
    when writting comptetition code, such as this, speed is important. Sometimes we can get away with using globals, even if they are bad practice, because it makes the code run faster. 
    For example, if in a recursive function you are passing a massive object that requires a copy menuver each time the function is called, then using a global is going to be much faster because it removes 
    that extra overhead. In these situations, it is acceptable to use globals. Infact, they will be required for some types of problems in the future. 
    
    * However, that does not mean that they are good practice. It's probably worth it to stay away from them when posssible, especially when working on normal projects and not competition code. *
    
- **submitting stuborn problems**: try variations
    sometimes problems refuse to AC, and in these cases you should try different meta-variations. Try it on a different submission server, or with redundant optimizations incase somehow your thinking didn't work out right. A seemingly redundant optimization is what made the difference with 7999, where a value (`tmax`) shouldn't even be greater than another value (`totmin`), so it was not explicitly checked as a redundant exit case. However, adding that exit case seems to make the entire process run significantly faster, even though it should be redundant. 
    
- **bitwise**: Fast but furious
    using bitwise operations to do things is fast, because thats how computers are stored. However, it is also painful because it is the real inards of computers. To tackle a project bitwise means that you have to be ready to go through some pain. Remember, bitshift as your best friend because it is fast and effective. That and the bitwise opperators: not `!`, and `&`, or `|`, and xor (dif) `^`. But if you can help it, still stay away from bitwise. 
    
#### Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | 8
