import sys

input = sys.stdin.readline

n, m = map(int, input().split())
v = []
for _ in range(n):
    a, b = input().split()
    b = int(b)
    if v and v[-1][1] == b:
        continue
    v.append((a, b))


def find(target):
    left, right = -1, len(v) - 1

    while left + 1 < right:
        mid = (left + right) // 2

        if v[mid][1] < target:
            left = mid
        else:
            right = mid
    return v[right][0]


for _ in range(m):
    print(find(int(input())))
