from random import randint

MX = 1000

size = randint(1, MX)
print(size)
out = ""
for i in range(size):
    if (i > 0):
        out += " "
    out += str(randint(1, size+1))
print(out)

for i in range(2, size+1):
    print(i, randint(1, i))
