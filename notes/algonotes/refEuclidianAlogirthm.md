---
title:   Euclidian algorithm
context: CompProgramming
author:  Exr0n
source:  refGCD.md
---

#algorithm
#ref #incomplete #disorganized

# Euclidian algorithm
## #complexity log n
- if $a \ge b$ then $a \text{mod} b < \frac{a}{2}$
- Alternatively, something about fibonocci numbers? #todo-learn
## #standardcode 
```cpp
int get_gcd(int a, int b) {
	for (int c; b; c = a%b, a=b, b=c);
	return a;
}
```
- Used a for loop instead of recursion because it's faster
### Abusing the language
#todo write euclidian algorithm iteratively and with xor swap

# Correctness
- Show gcd(a, b) = gcd(b, a mod b)
	- First show less than then show greater than
	![[srcEuclidianAlgorithmCorrectness.png]]

# Induction
- You can calculate the gcd of many integers by doing it pairwise
- min \therefore gcd is communative and associative 

# Extended Euclidian Algorithm
[[refExtendedEuclidianAlgorithm]]

---
