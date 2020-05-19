MX = 10
NUM = 50000

from random import randint, choice

for i in range(NUM):
    commands = ['i', 'r', 'q', 'n', 'p']
#    commands = ['i', 'r', 'q']
    cmd = choice(commands)
    print(f'{cmd} {randint(1, MX)}')

print('x')

