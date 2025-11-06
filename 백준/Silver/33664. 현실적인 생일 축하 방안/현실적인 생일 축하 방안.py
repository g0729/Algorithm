import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    b, n, m = map(int, input().split())
    v = {}

    for _ in range(n):
        name, value = input().split()
        v[name] = int(value)

    temp = sum([v[input().rstrip()] for _ in range(m)])
    print("acceptable" if temp <= b else "unacceptable")


if __name__ == "__main__":
    solve()
