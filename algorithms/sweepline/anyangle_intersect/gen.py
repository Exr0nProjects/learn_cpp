MX = 5
SIZE = 100

from random import randint

N = randint(1, MX)
print(N)

for i in range(N):
    print(' '.join([str(randint(1, SIZE)) for j in range(4)]))

