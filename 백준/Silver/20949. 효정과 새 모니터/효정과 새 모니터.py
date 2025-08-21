import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    v = [(tuple(map(int, input().split())), idx + 1) for idx, _ in enumerate(range(n))]
    v.sort(key=lambda x: (-(x[0][0] ** 2 + x[0][1] ** 2), x[1]))

    for i in range(n):
        print(v[i][1])


if __name__ == "__main__":
    solve()
