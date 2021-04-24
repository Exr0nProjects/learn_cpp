a = []
ls = input().strip().split()
l = int(ls[0])
n = int(ls[1])
o = []


for i in range(l): a.append([int(x) for x in input().split()])

# for i in range(l):
    # print("here")


for i in a:
    i.sort(reverse=True)
    o.append(i[0]*i[1])

for i in o:
    print(i)

