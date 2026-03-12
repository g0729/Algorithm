import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():

    n = int(input())
    v = [input().rstrip() for _ in range(n)]

    res = 0
    for i in range(n):
        for j in range(i + 1, n):

            for k in range(min(len(v[i]), len(v[j])) + 1):

                if v[i].startswith(v[j][-k:]) or v[j].startswith(v[i][-k:]):
                    res += 1
                    break

    print(res)


if __name__ == "__main__":
    solve()
