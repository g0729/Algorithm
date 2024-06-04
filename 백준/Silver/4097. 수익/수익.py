while True:
    n = int(input())
    if n == 0:
        break
    dp = [0] * (n + 1)
    for i in range(1, n + 1):
        a = int(input())
        dp[i] = max(a, dp[i - 1] + a)

    print(str(max(dp[1:])))
