import sys

input = sys.stdin.readline


def dis(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** (0.5)


def solve():
    n, q = map(int, input().split())
    x = list(map(int, input().split()))
    y = list(map(int, input().split()))
    acc = [0.0] * (n + 1)
    rev_acc = [0.0] * (n + 1)
    for i in range(2, n + 1):
        acc[i] = acc[i - 1]
        distance = dis(x[i - 2], y[i - 2], x[i - 1], y[i - 1])

        if y[i - 1] > y[i - 2]:
            acc[i] += distance * 3
        elif y[i - 1] < y[i - 2]:
            acc[i] += distance
        elif y[i - 1] == y[i - 2]:
            acc[i] += distance * 2

    for i in range(n - 1, 0, -1):
        rev_acc[i] = rev_acc[i + 1]

        distance = dis(x[i - 1], y[i - 1], x[i], y[i])

        if y[i - 1] > y[i]:
            rev_acc[i] += distance * 3
        elif y[i - 1] < y[i]:
            rev_acc[i] += distance
        elif y[i - 1] == y[i]:
            rev_acc[i] += distance * 2

    for _ in range(q):
        i, j = map(int, input().split())

        if i < j:
            print(acc[j] - acc[i])
        else:
            print(rev_acc[j] - rev_acc[i])


if __name__ == "__main__":
    solve()
