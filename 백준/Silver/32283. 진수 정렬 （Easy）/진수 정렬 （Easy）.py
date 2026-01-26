import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    n = int(input())
    s = input().strip()

    v = [bin(i)[2:].zfill(n) for i in range(1 << n)]
    v = sorted(v, key=lambda x: (x.count("1"), x[::-1]))

    print(v.index(s))


if __name__ == "__main__":
    solve()
