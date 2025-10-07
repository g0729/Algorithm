import sys

input = sys.stdin.readline


def solve():
    k = int(input())

    res = 1

    while res < k:
        res <<= 1

    if res == k:
        print(res, 0)
    else:
        print(res, bin(k)[2:].rfind("1") + 1)


if __name__ == "__main__":
    solve()
