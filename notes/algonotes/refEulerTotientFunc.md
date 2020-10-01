---
title:   Euler totient function
context: CompProgramming
author:  Exr0n
source:  AlgosMasterIndex.md
---

#concept
#ref #incomplete #disorganized

# Euler's totient function
#definition $\varphi(n)$
> $\varphi(n)$ be the number of integers $a$ such that $a \le n$ and $gcd(a, n) = 1$

## Multiplicative Function
#incomplete 
If $\text{gcd}(n_1, n_2) = 1$ and $f(n_1n_2) = f(n_1) f(n_2)$ then $f$ is *multiplicative*.

Euler's totient function $\varphi$ is a multiplicative function.
- one to one correspondence between $x : gcd(x, n_1n_2) = 1$ and $r_1 < n_1, r_2 < n_2$
- Take the cartesian product of $\varphi(n_1)\varphi(n_2)$ to get $\varphi(n_1n_2)$

## If $p$ is prime
$$\varphi(p) = p-1$$

## Something
$$a^{\varphi(n)} \equiv 1 \pmod n$$

## Some of phi of divisors
$$\sum_{d|n} \varphi{\frac{n}{d}} = \sum_{d|n} \varphi(d) = n$$
- Each $i$ has *exactly one* gcd with $n$, so if you enumerate the possible resulting $\text{gcd}$s and calculate the number of $i$s that are coprime, then you count every number once
	- counting every number once is similar to the concept of [[refLinearSieve]], but with gcd instead of factorization.
	- If $n$ is a power of $2$, then you get [[refBInaryIndexedTree]] flashbacks

---
