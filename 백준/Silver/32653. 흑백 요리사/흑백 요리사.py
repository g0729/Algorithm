import sys
from math import gcd

sys.setrecursionlimit(10**6)


def solve():
    n = int(input())
    v = list(map(int, input().split()))
    res = v[0]
    for i in range(1, len(v)):
        res = res * v[i] // gcd(res, v[i])

    print(res * 2)


if __name__ == "__main__":
    solve()
