import sys
from math import gcd


def solve():
    n, m = map(int, input().split())

    print(m - gcd(n, m))


if __name__ == "__main__":
    solve()
