import sys
import math

input = sys.stdin.readline


def solve():
    n, a, b, c, d = map(int, input().split())

    if b * c < a * d:
        a, b, c, d = c, d, a, b
    res = int(1e30)

    for i in range(c):
        temp = math.ceil((n - i * a) / c)

        if temp < 0:
            res = min(res, i * b)
            break
        res = min(res, i * b + temp * d)

    print(res)


if __name__ == "__main__":
    solve()
