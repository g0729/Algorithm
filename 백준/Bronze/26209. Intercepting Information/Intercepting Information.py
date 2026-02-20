import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    print("F" if any([a == 9 for a in map(int, input().split())]) else "S")


if __name__ == "__main__":
    solve()
