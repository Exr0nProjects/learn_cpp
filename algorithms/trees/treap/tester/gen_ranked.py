MX = 100000
MAXN = 10

commands = ('i', 'r', 'q', 'k')
from random import choice, randint

for i in range(MX):
    print(f'{choice(commands)} {randint(1, MAXN)}')
print('x')

