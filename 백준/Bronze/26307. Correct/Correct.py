import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    h, m = map(int, input().split())

    print(h * 60 + m - 9 * 60)


if __name__ == "__main__":
    solve()
