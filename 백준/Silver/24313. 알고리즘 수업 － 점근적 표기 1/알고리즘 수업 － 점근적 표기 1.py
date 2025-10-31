import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    a1, a0 = map(int, input().split())
    c = int(input())
    n0 = int(input())

    if a1 > c:
        print(0)
    else:
        if a1 * n0 + a0 > c * n0:
            print(0)
        else:
            print(1)


if __name__ == "__main__":
    solve()
