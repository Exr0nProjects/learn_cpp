numbe = int(input())

overall = []
for i in range(numbe):
    pair = [float(x) for x in input().split(" ")]
    overall.append(pair)
# print(overall)

for i in overall:
    test = round((((i[1]/i[0]))-1), 4) * 100
    print('{:.2f}'.format(test))

