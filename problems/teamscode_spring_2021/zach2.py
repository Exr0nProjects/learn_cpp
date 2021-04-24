numbe = int(input())

peoples = [int(x) for x in input().split(" ")]

peopleIndexPairs = []

for i in range(len(peoples)):
    peopleIndexPairs.append((i, peoples[i]))

peopleIndexPairs = sorted(peopleIndexPairs, key=lambda x: x[1], reverse=True)
'''
5
5 3 6 3 1
'''
# print(peopleIndexPairs)
# last = ""
# lastplace = 0
# for i in range(len(peopleIndexPairs)):
#     if last == peopleIndexPairs[i][1]:
#         peoples[peopleIndexPairs[i][0]] = lastplace
#     else:
#         peoples[peopleIndexPairs[i][0]] = i + 1
#         last = peoples[peopleIndexPairs[i][1]]
#         lastplace = i + 1
prev = 10000
num = 0
for name, val in peopleIndexPairs:
    if val != prev: num += 1
    prev = val
    peoples[name] = num

print(" ".join(map(str, peoples)))

