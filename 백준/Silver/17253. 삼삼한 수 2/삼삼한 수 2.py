import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    n = int(input())

    if n == 0:
        print("NO")
        return
    cur = 1
    while cur <= n:
        cur *= 3

    cur //= 3

    while cur != 0:
        if n >= cur:
            n -= cur

        cur //= 3

    print("YES" if n == 0 else "NO")


if __name__ == "__main__":
    solve()
