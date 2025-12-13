import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    n, m = map(int, input().split())

    v = list(input().split())
    res = 0
    for i in range((10**n)):
        s = str(i).zfill(n)

        flag = True
        for a in v:
            if a not in s:
                flag = False

        if flag:
            res += 1

    print(res)


if __name__ == "__main__":
    solve()
