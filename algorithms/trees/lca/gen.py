MX = 100000
MX = 100

from random import randint

print(MX)
for i in range(2, MX+1):
    print(randint(1, i-1), i)

