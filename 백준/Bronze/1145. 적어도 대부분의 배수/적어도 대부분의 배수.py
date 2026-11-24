import sys
from math import lcm
from itertools import combinations

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    v = list(map(int, input().split()))

    ans = int(1e9)
    for a, b, c in combinations(v, 3):
        ans = min(ans, lcm(a, b, c))

    print(ans)


if __name__ == "__main__":
    solve()
