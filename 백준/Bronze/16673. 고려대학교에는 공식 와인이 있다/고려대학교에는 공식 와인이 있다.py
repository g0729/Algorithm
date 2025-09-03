import sys

input = sys.stdin.readline


def solve():
    c, k, p = map(int, input().split())

    print((c * (c + 1) // 2) * k + (c * (c + 1) * (2 * c + 1) // 6) * p)


if __name__ == "__main__":
    solve()
