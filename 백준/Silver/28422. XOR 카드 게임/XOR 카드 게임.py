import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    v = [0] + list(map(int, input().split()))
    dp = [0] * (n + 1)

    if n == 1:
        print(0)
        return
    elif n == 2:
        print((v[1] ^ v[2]).bit_count())
        return
    elif n == 3:
        print((v[1] ^ v[2] ^ v[3]).bit_count())
        return
    elif n == 4:
        print((v[1] ^ v[2]).bit_count() + (v[3] ^ v[4]).bit_count())
        return
    dp[2] = (v[1] ^ v[2]).bit_count()
    dp[3] = (v[1] ^ v[2] ^ v[3]).bit_count()
    dp[4] = (v[1] ^ v[2]).bit_count() + (v[3] ^ v[4]).bit_count()
    for i in range(5, n + 1):
        cur = 0

        if dp[i - 2] != 0:
            cur = dp[i - 2] + (v[i - 1] ^ v[i]).bit_count()

        if dp[i - 3] != 0:
            cur = max(cur, dp[i - 3] + (v[i - 2] ^ v[i - 1] ^ v[i]).bit_count())

        dp[i] = cur

    print(dp[n])


if __name__ == "__main__":
    solve()
