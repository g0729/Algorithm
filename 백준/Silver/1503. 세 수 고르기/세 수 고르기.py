import sys

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    se = set(map(int, input().split()))

    res = int(1e9)
    for i in range(1, 1010):
        if i in se:
            continue
        for j in range(1, 1010):
            if j in se:
                continue
            for k in range(1, 1010):
                if k in se:
                    continue
                res = min(res, abs(n - i * j * k))

                if n < i * j * k:
                    break

    print(res)


if __name__ == "__main__":
    solve()
