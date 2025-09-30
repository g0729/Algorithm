import sys

input = sys.stdin.readline


def solve():
    v = [0, 10, 20, 50, 60, 120]

    print(max(v[int(input())] - (15 if int(input()) > 1000 else 0), 0))


if __name__ == "__main__":
    solve()
