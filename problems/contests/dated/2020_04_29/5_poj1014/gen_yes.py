from random import randint

MX = 10

for case in range(MX):
    total = randint(1, MX)
    print("total", total)
    totalcounts = [0]*6
    for i in range(2):
        t = total
        counts = [0]*6
        while (t > 0):
            rand = randint(0, min(total-1, 5))
            t -= rand + 1
            counts[rand] += 1
        for i, n in enumerate(counts):
            totalcounts[i] += n
    print(' '.join(map(lambda x: str(x), totalcounts)))
