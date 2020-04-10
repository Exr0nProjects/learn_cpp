from random import randint

MX = 20
MT = 200

N = randint(2, MX)
print(N, randint(1, MT))
print(' '.join(map(str, sorted(randint(1, 20) for i in range(N-1)))))

for i in range(2):
    M = randint(2, MX)
    print(M)
    print(' '.join(map(str, sorted(randint(1, MT) for i in range(M)))))

print(0)
