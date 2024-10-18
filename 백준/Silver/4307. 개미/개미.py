import sys

input = sys.stdin.readline

for _ in range(int(input())):
    a, b = map(int, input().split())

    res = [0, 0]

    for _ in range(b):
        c = int(input())
        res[0] = max(res[0], min(c, a - c))
        res[1] = max(res[1], max(c, a - c))

    print(res[0], res[1])
