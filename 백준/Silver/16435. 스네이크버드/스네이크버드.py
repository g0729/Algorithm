import sys

input = sys.stdin.readline


def solve():
    n, l = map(int, input().split())
    v = list(map(int, input().split()))
    v.sort()

    for a in v:
        if a <= l:
            l += 1

    print(l)


if __name__ == "__main__":
    solve()
