import sys

input = sys.stdin.readline


def solve():
    n = int(input())

    dp = [0] * (n + 1)

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] * 2 + (-1 if i % 2 else 1)

    print(dp[n])


if __name__ == "__main__":
    solve()
