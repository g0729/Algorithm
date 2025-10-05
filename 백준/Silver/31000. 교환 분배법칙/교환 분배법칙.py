import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    res = (2 * n + 1) ** 2
    for i in range(-n, n + 1):
        if i == 0:
            continue
        for j in range(-n, n + 1):
            sum = i + j
            if abs(1 - sum) <= n:
                res += 1

    print(res)


if __name__ == "__main__":
    solve()
