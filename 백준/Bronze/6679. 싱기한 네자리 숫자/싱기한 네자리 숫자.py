import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def f(n, base):
    ret = 0

    while n:
        n, mod = divmod(n, base)
        ret += mod

    return ret


def solve():

    for i in range(2992, 10000):
        if f(i, 10) == f(i, 12) == f(i, 16):
            print(i)


if __name__ == "__main__":
    solve()
