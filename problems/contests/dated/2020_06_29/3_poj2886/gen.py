T = 10
N = 500000
MXM = 1e8

N = 500000
MXM = 1e8

from string import ascii_lowercase as letters
from random import randint, choice

def gen_str():
    return ''.join(choice(list(letters)) for i in range(10))

for t in range(T):
    print(N, randint(1, N))
    for i in range(N):
        print(gen_str(), (randint(0, 1)*2-1)*randint(1, MXM))

