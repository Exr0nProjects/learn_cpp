MX = 100000

from random import choice, randint

commands = ['i', 'q', 'r']

for i in range(MX):
    print(f"{choice(commands)} {randint(1, 100)}")
print("x")

