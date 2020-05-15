MX = 30
NUM = 1000

from random import randint, choice

for i in range(NUM):
    commands = ['i', 'r', 'q', 'n', 'p']
    cmd = choice(commands)
    print(f'{cmd} {randint(1, MX)}')

