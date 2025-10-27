import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    while True:
        n = int(input())
        if n == 0:
            return

        v = sorted([int(input()) for _ in range(n)])

        print(sum(v[1:-1]) // (n - 2))


if __name__ == "__main__":
    solve()
