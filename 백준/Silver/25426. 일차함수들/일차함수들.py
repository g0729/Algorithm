import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    v = [tuple(map(int, input().split())) for _ in range(n)]

    v.sort(key=lambda x: x[0])

    res = 0

    for i in range(n):
        res += v[i][0] * (i + 1) + v[i][1]

    print(res)


if __name__ == "__main__":
    solve()
