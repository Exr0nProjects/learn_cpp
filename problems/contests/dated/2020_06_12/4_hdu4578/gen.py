MXN = 100000
MXM = 100000
MXC = 10000

MXT = 1
MXP = 1

MXC = 10
MXN = 5
MXM = 5

from random import randint
T = randint(1, MXT)
for i in range(T):
    N = randint(1, MXN)
    M = randint(1, MXM)
    print(N, M)
    for j in range(M):
        l = randint(1, N)
        r = randint(l, N)
        if (randint(0, 1)):
            print(4, l, r, randint(1, MXP))
        else:
            print(randint(1, 3), l, r, randint(1, MXC))
print('0 0')

