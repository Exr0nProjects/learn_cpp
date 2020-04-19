MAXN = 25
MAXM = 50
KASE = 5

from random import randint, choice

def gen(num):
    for i in range(num):
        yield 'p' + hex(i)[2:]
for k in range(KASE):
    N = randint(1, MAXN)
    M = randint(N, MAXM)
    print(N, M)

    names = list(gen(N))

    for i in range(N):
        print(names[i], choice(names))

    for i in range(M-N):
        print(choice(names), choice(names))

print(0, 0)
