import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    a, b = map(int, input().split())

    print("take it" if a * 2 > b else "double it")


if __name__ == "__main__":
    solve()
