import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    b, c, a1, a2 = map(int, input().split())
    print((b + (b * b + 4 * c) ** 0.5) / 2)


if __name__ == "__main__":
    solve()
