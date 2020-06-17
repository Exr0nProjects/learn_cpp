MXN = 10000
MXM = 10000

MXN = 10
MXM = 10

from random import randint

print(MXN, MXM)

for i in range(MXM):
    left = randint(1, MXN)
    print(randint(1, 2), left, randint(left, MXN), randint(0, i))
