N = 300000
Q = 300000

N = 300000
Q = 300000

from random import randint

print(N, Q)
for i in range(N):
    print(randint(1, N))
for i in range(Q):
    left = randint(1, N)
    print(left, randint(left, N), randint(2, 5))

