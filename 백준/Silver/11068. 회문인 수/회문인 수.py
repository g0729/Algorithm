import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def f(n: int, base: int):
    ret = []

    while n:
        n, m = divmod(n, base)
        ret.append(m)

    return ret


def solve():
    n = int(input())

    for base in range(2, 65):
        s = f(n, base)

        if s == s[::-1]:
            return 1

    return 0


if __name__ == "__main__":
    for _ in range(int(input())):
        print(solve())
