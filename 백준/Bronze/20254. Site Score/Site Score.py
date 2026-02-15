import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    a, b, c, d = map(int, input().split())
    print(56 * a + 24 * b + 14 * c + 6 * d)


if __name__ == "__main__":
    solve()
