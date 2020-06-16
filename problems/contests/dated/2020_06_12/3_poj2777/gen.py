MX = 100000
OPS = 100000

MX = 100000
OPS = 100000

from random import randint
L = randint(MX-100, MX)
O = randint(OPS-100, OPS)
print(f'{L} 30 {O}')

for i in range(O):
    l = randint(1, L)
    r = randint(l, L)
    if randint(0, 8):
        print(f'P {l} {r}')
    else:
        print(f'C {l} {r} {randint(1, 30)}')

