import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    res = 1

    while res * res <= n:
        res += 1

    print(res - 1)


if __name__ == "__main__":
    solve()
