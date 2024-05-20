import sys


def init(start, end, node):
    if start == end:
        tree[node] = v[start]
        return tree[node]

    mid = (start + end) // 2
    tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1)

    return tree[node]


def update(start, end, node, idx, val):

    if idx < start or idx > end:
        return tree[node]
    if start == end:
        tree[node] = val
        return tree[node]

    mid = (start + end) // 2

    tree[node] = update(start, mid, node * 2, idx, val) + update(mid + 1, end, node * 2 + 1, idx, val)
    return tree[node]


def sum(start, end, node, left, right):
    if left > end or right < start:
        return 0
    if left <= start and end <= right:
        return tree[node]

    mid = (start + end) // 2

    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right)


input = sys.stdin.readline

n, m, k = map(int, input().split())
v = [int(input()) for _ in range(n)]

tree = [0] * (4 * n + 1)
init(0, n - 1, 1)

for _ in range(m + k):
    a, b, c = map(int, input().split())
    if a == 1:
        update(0, n - 1, 1, b - 1, c)
    else:
        print(sum(0, n - 1, 1, b - 1, c - 1))
