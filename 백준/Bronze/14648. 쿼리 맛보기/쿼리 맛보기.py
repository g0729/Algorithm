import sys

input = sys.stdin.readline


def solve():
    n, q = map(int, input().split())
    v = list(map(int, input().split()))

    for _ in range(q):
        op = list(map(int, input().split()))

        if op[0] == 1:
            print(sum(v[op[1] - 1 : op[2]]))
            v[op[1] - 1], v[op[2] - 1] = v[op[2] - 1], v[op[1] - 1]
        elif op[0] == 2:
            print(sum(v[op[1] - 1 : op[2]]) - sum(v[op[3] - 1 : op[4]]))


if __name__ == "__main__":
    solve()
