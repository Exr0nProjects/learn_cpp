---
title:   Modular Multiplicative Inverse
context: CompProgramming
author:  Exr0n
source:  refModularCongruence.md
---

#concept
#ref #incomplete #disorganized

# Modular Multiplicative Inverse
It's like weirdly hard to calculate

## #definition modular multiplicative inverse
> If $ax\equiv 1 \pmod n$ then $x$ is called the multiplicative inverse of $a$ mod $n$
## #notation inverse-- = a^{-1}
Why? Because $ca^{-1} \equiv \frac{c}{a} \equiv cx \pmod n$

# Calculation
- Use the extended euclidian algorithm [[refExtendedEuclidianAlgorithm]]
- If $ax+by = 1$ then $ax \equiv 1 \pmod b$
- #careful If there gcd(a, b) \neq 1 then there is no modular inverse
	- Because, we want something where $ax \equiv 1 \pmod b$ but $a$ and $b$ have a common divisor so whatever you multiply by, when you modulo $b$ you will have that common divisor times something remaining.
- return `x0` from the egcd algorithm.
- often the mod is a prime number, so gcd will always be 1

## Inverse of $k!$
```cpp
int fac[N], inv[N];
fac[0] = 1;
for (int i=1; i<N-1; ++i) fac[i] = i*fac[i-1];
inv[N] = (fac[N]) ^{-1}
for (int i=N-2; i; --i) inv[i] = (i+1)*inv[i+1]

```

## Interesting problems
### inverse of a range
#problem calculate all modular inverses from 1..n-1
- Trivial with $n log n$ but you can get $O(n)$
- #todo-learn 2020_09_23:1:10:00

### the multiplicative inverse of any $k$ integers
- #todo-learn 2020_09_23:1:17:00
- $O(k+log\ n) \pmod n$ s.t. $n \leq 10^18$
- log n precomp: multiplicative inverse of each prefix product
- The equation is 
$$a_i^{-1} = \frac{1}{a} = \frac{a_1a_2 ... a_{i-1} \ a_{i+1} a_{i+2} ... a_n}{a_1a_2...a_n} = (a_1a_2 ... a_{i-1} \ a_{i+1} a_{i+2} ... a_n) * (a_1a_2...a_n)^{-1}
$$
---
