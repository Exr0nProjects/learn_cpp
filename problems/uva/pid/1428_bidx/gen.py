MX = 20000
MXT = 20
MXN = 100000

#MX = 100
#MXT = 2
#MXN = 1000


from random import randint
t = randint(1, MXT)
print(t)
for i in range(t):
    n = randint(3, MX)
    print(n, ' '.join(str(randint(1, MX)) for k in range(n)))

