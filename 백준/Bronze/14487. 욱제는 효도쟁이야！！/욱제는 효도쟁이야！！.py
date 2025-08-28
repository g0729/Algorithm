import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    print(sum(sorted(list(map(int, input().split())))[:-1]))


if __name__ == "__main__":
    solve()
