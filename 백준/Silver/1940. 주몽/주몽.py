from collections import defaultdict

d = defaultdict(int)
n, m = int(input()), int(input())
for a in map(int, input().split()):
    d[a] += 1
res = 0

for i in range(1, m // 2 + 1):
    if i * 2 == m:
        res += d[i] // 2
    else:
        res += min(d[i], d[m - i])

print(res)
