## Summary for Day 9 (17 July 2019)

#### Problems:
|  Page  |  PID  |  Description  |  Status  |
|-------:|-------|---------------|:--------:|
 2.13 | 1227 | connected reigons | AC
 "    | 1228 | n queens | WA
 "    | 7998 | work division | AC
 "    | 7999 | work division v2 | TLE

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
    
#### Reflection:
|  Type  |  Score (/12)  |
|--------|:-------------:|
Productivity | <score>
