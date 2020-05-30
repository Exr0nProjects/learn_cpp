MX = 10000
MXN = 1000
commands = ['q', 'u']

from random import randint, choice

n, q = randint(1, MX), randint(1, MX)
print(n, q)
for i in range(q):
    c = choice(commands)
    pay = None
    if (c == 'q'):
        pay = randint(1, n)
    if (c == 'u'):
        pay = randint(-n, n)
        if (pay == 0):
            pay = 1
    print(f'{c} {randint(1, abs(pay))} {pay}')

