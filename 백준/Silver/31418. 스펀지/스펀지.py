import sys

input = sys.stdin.readline


def solve():
    w, h, k, t = map(int, input().split())
    ans = 1
    MOD = 998244353
    for _ in range(k):
        x, y = map(int, input().split())

        ans = (ans * (min(x + t, w) - max(x - t, 1) + 1) * (min(y + t, h) - max(y - t, 1) + 1)) % MOD

    print(ans)


if __name__ == "__main__":
    solve()
