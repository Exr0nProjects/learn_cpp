MX = 10
MAXN = 10

from random import choice, randint

st = set([])

print(MX)
for i in range(MX):
    cmd = randint(1, 6)
    if cmd == 1:
        print(f'1 {randint(1, MAXN)}')
    else:
        if cmd == 2:
            print(f'2 {

