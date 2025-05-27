from collections import Counter

n = int(input())
c = Counter(map(int, input().split()))

if n == 1 and c[0] == 1:
    print("-1")
    exit(0)

res = 0

for num, cnt in c.items():
    if num == cnt:
        res = max(res, num)

if res == 0 and c[0]:
    print("-1")
else:
    print(res)
