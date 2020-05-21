MX = 10
MAXN = 10

from random import choice, randint

print(MX)
for i in range(MX):
    print(f'{randint(1, 6)} {randint(1, MAXN)}')

exit()

st = set([])

print(MX)
for i in range(MX):
    cmd = randint(1, 6)
    if cmd == 1:
        print(f'1 {randint(1, MAXN)}')
    else:
        if cmd == 2:
            print(f'2 {"todo"}')

