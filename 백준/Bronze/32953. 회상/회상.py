from collections import defaultdict

n, m = map(int, input().split())

dic = defaultdict(int)

for _ in range(n):
    _ = input()
    for a in map(int, input().split()):
        dic[a] += 1

res = 0

for key, value in dic.items():
    if value >= m:
        res += 1

print(res)
