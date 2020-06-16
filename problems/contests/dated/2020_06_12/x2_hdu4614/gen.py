MXT = 10
MXN = 50000
MXM = 50000

MXT = 10
MXN = 50000
MXM = 50000

from random import randint

T = randint(1, MXT)
print(T)
for i in range(T):
    N = randint(2, MXN)
    M = randint(2, MXM)
    print(f'{N} {M}')
    for j in range(M):
        if (randint(0, 1)):
            print(f'1 {randint(0, N-1)} {randint(1, N)}')
        else:
            lhs = randint(0, N-1)
            print(f'2 {lhs} {randint(lhs, N-1)}')

