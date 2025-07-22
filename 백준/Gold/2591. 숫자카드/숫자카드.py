import sys

input = sys.stdin.readline


def solve():
    s = list(input().strip())

    dp = [0] * 45
    dp[0] = 1
    dp[1] = 1
    for i in range(1, len(s)):
        if s[i] != "0":
            dp[i + 1] += dp[i]

        if int(s[i - 1] + s[i]) <= 34 and s[i - 1] != "0":
            dp[i + 1] += dp[i - 1]

    print(dp[len(s)])


if __name__ == "__main__":
    solve()
