MX = 100
MAXN = 10

from random import choice, randint
for i in range(MX):
    commands = ('i', 'r', 'q')
    print(f'{choice(commands)} {randint(1, MAXN)}')
print('x')

