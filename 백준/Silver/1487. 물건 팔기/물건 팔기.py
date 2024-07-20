n = int(input())
v = [tuple(map(int, input().split())) for _ in range(n)]
v.sort(key=lambda x: x[0])

res = 0
max_value = 0
for i in range(n):
    a = v[i][0]
    sum = 0
    for j in range(i, n):
        if a > v[j][1]:
            sum += a - v[j][1]
    if max_value < sum:
        max_value = sum
        res = a

print(res)
