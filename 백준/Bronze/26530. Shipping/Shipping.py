import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    res = 0.0
    for _ in range(int(input())):
        a, b, c = input().split()
        res += int(b) * float(c)

    print("${:.2f}".format(res))


if __name__ == "__main__":
    for _ in range(int(input())):
        solve()
