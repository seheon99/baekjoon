n = int(input())
bulk = []
for index in range(n):
    weight, height = map(int, input().split())
    bulk.append((weight, height, index, 1))


for i in range(n):
    for j in range(n):
        if bulk[i][0] < bulk[j][0] and bulk[i][1] < bulk[j][1]:
            bulk[i] = (bulk[i][0], bulk[i][1], bulk[i][2], bulk[i][3] + 1)

bulk.sort(key=lambda x: x[2])
print(" ".join([str(x[3]) for x in bulk]))
