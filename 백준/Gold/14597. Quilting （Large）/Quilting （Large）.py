import sys

input = sys.stdin.readline


def solve():
    h, w = map(int, input().split())
    b1 = [list(map(int, input().split())) for _ in range(h)]
    b2 = [list(map(int, input().split())) for _ in range(h)]
    dp = [[(b1[i][j] - b2[i][j]) ** 2 for j in range(w)] for i in range(h)]

    for i in range(1, h):
        for j in range(w):
            dp[i][j] += min(dp[i - 1][max(0, j - 1) : min(w, j + 2)])

    print(min(dp[h - 1]))


if __name__ == "__main__":
    solve()
