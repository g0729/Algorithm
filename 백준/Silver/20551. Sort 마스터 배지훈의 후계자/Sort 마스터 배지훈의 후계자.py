import sys
from bisect import bisect_left

input = sys.stdin.readline
print = sys.stdout.write


n, m = map(int, input().split())
v = [int(input()) for _ in range(n)]
v.sort()


for _ in range(m):
    target = int(input())
    idx = bisect_left(v, target)

    if idx == n or v[idx] != target:
        print("-1\n")
    else:
        print(str(idx) + "\n")
