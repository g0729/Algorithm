n = int(input())
v = list(map(int, input().split()))
length = 0
res = 0

for i in v:
    if i == 0:
        length = 0
    else:
        length += 1
    res = max(res, length)

print(res)
