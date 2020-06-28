T = 4
N = 500000
M = 100000
MX = 10000

T = 40
N = 500000
M = 100000
MX = 1000000000

# T = 4
# N = 500000
# M = 100000
# MX = 100

from random import randint

print(T)
for t in range(T):
    print(N, M)
    print(' '.join(str(randint(1, MX)) for i in range(N)))
    for i in range(M):
        cmd = 'Q' if randint(0, 1) else 'C'
        print(cmd, end=' ')
        if (cmd == 'Q'):
            l = randint(1, N)
            r = randint(l, N)
            print(l, r, randint(1, r-l+1))
        else:
            print(randint(1, N), randint(1, MX))
