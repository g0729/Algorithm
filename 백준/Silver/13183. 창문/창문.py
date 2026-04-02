import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    a, b = map(int, input().split())

    print((a + 2) * (b + 2) % 1000000007)


if __name__ == "__main__":
    solve()
