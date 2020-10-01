---
title:   Modular congruence
context: CompProgramming
author:  Exr0n
source:  AlgosMasterIndex.md
---

#concept
#ref #incomplete #disorganized

# Modular Congruence
# #definition modular congruence
> Two numbers $a$, $b$ are *congruent* modulo $n$ if $n$ is a divisor of the difference aka $a | (a-b)$
> #notation $a \equiv b \pmod n$
That is to say, $a \pmod n = b \pmod n$

## Properties of modular congruence
| Property | Result |
|----------|--------|
| reflexive |  $a \equiv a \pmod n$
| commutative | $a\equiv b \iff b\equiv a \pmod n$
| transitive | $a\equiv b \land b\equiv c \implies a\equiv c \pmod n$
| operatable? | $a\equiv b \implies a+k\equiv b+k \land ak\equiv bk \pmod n$

# Modular Multiplicative Inverse
[[refModularMultInverse]]

---
