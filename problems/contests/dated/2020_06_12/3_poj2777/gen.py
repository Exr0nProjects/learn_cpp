MX = 100000
OPS = 100000

MX = 100000
OPS = 100

from random import randint
L = randint(1, MX)
O = randint(1, OPS)
print(f'{L} 30 {O}')

for i in range(O):
    l = randint(1, L)
    r = randint(l, L)
    if randint(0, 1):
        print(f'C {l} {r} {randint(1, 30)}')
    else:
        print(f'P {l} {r}')

