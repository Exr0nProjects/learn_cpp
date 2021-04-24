ls = input().strip().split()

l = int(ls[0])
m = int(ls[1])
r = int(ls[2])
a = [int(x) for x in input().split()]

out = 0
a.sort()

# print(l,m,r, a)

if a[0]-r > 0:
    out += 1

if a[-1] + r < m-1:
    out += 1

for i in range(1, l):
    if a[i]-(r+1) <= a[i-1]+r:
        # print(a[i])
        continue
    else:
        out += 1

print(out)

