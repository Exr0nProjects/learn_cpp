16 July 2019: Day 8

Problems worked on today:
1. 2.13 1228 - n queens problem
1. 2.13 1227 - connected reigons

New concepts:
* **inline**: function that is placed in line at compile time so there is less jumping around? this causes less calling and function jumps which makes it faster but also more space required for the compiled binary (i think). usage: `inline void myfunc (int arg)`

* **exit**: exit the entire program from outside of main. **THIS IS CONSIDERED A BAD PRACTICE** because stuff might not be cleaned up properly. Better to throw a custom exeception class that will be caught in main and have the program exit from main normally there. 

* **pointers***: stay away from them, especiall in 2d arrays and with structs. They are not a good choice for competition/speed coding because they screw up so easily. If you have a signal 11 (segfault), then it's probably the pointer's fault. If your code breaks, its probably the pointer's fault. Just delete them. They can usually be worked around anyways. 
