MX = 500000

from random import randint

print(f'{MX} {MX}')
for i in range(MX):
    print(f'{randint(1, MX)}', end=' ')
print()
for i in range(MX):
    low = randint(1, MX)
    print(f'{low} {randint(low, MX)}')

