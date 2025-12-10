import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    n, m = map(int, input().split())
    MOD = 10**9 + 7
    print((pow(2, n, MOD) + pow(2, m, MOD) - 2) % MOD)


if __name__ == "__main__":
    solve()
