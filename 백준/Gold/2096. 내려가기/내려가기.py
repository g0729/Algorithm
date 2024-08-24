import sys

input = sys.stdin.readline

n = int(input())
v = list(map(int, input().split()))
min_dp, max_dp = v.copy(), v.copy()

for i in range(1, n):
    v = list(map(int, input().split()))
    min_temp = [
        min(min_dp[0], min_dp[1]) + v[0],
        min(min_dp[0], min_dp[1], min_dp[2]) + v[1],
        min(min_dp[1], min_dp[2]) + v[2],
    ]
    max_temp = [
        max(max_dp[0], max_dp[1]) + v[0],
        max(max_dp[0], max_dp[1], max_dp[2]) + v[1],
        max(max_dp[1], max_dp[2]) + v[2],
    ]
    min_dp = min_temp.copy()
    max_dp = max_temp.copy()

print(max(max_dp), min(min_dp))
