import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    length = len(str(n))
    MOD = 1234567
    res = 0
    for i in range(1, length):
        res = (res + (10**i - 10 ** (i - 1)) * i) % MOD

    res = (res + (n - (10 ** (length - 1)) + 1) * length) % MOD
    print(res)


if __name__ == "__main__":
    solve()
