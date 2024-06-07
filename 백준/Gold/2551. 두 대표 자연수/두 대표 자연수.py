import sys

input = sys.stdin.readline

n = int(input())
v = list(map(int, input().split()))

v.sort()

res = sum(v) / n

if res % 1 > 0.5:
    res = int(res) + 1
else:
    res = int(res)
print(v[(n + 1) // 2 - 1], res)
