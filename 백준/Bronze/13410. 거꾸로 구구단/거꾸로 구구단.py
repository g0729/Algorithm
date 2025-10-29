import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    n, k = map(int, input().split())

    print(max([int(str(n * i)[::-1]) for i in range(1, k + 1)]))


if __name__ == "__main__":
    solve()
