import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    n, m = map(int, input().split())
    v = [list(map(int, input().split())) for _ in range(m)]
    v = sorted(v, key=lambda x: -x[0])
    res = 0
    for i in range(m - 1):
        if v[i][0] >= n:
            continue
        res += v[i][1] - n

    print(res)


if __name__ == "__main__":
    solve()
