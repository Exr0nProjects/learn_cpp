---
title:   Checking Primality
context: CompProgramming
author:  Exr0n
source:  refPrimes.md
---

#concept #method #algorithm #problem
#ref #incomplete #disorganized

# Check Primality
## Factors to sqrt N
- A composite number must have a factor under $\sqrt{N}$ that is not $1$ because for the smaller of two complementary factors to be greater than $\sqrt{N}$ would mean that the product is greater than $N$, so $\sqrt{N}*\sqrt{N}$ is the maximum smaller factor.
## Brute Force
- #complexity $\sqrt{N}$
- #standardcode
```cpp
bool isprime(int a)
{
	if (a < 2) return 0;
	for (int i=2; i<=sqrt(a); ++i)
		if (!(a%i)) return 1;
	return 0;
}
```

## Other big brain methods
- [[refMillarRabin]]

---
