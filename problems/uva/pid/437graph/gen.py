from random import randint as rand

MX = 5
MS = 9

N = rand(1, MX)
print(N)

for i in range(N):
    print(' '.join([str(rand(1, MS)*100000000) for j in range(3)]))

print(0)
