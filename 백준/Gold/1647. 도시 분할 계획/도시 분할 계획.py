import heapq


def find(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]


def merge(a, b):
    a = find(a)
    b = find(b)

    parent[b] = a


def isUnion(a, b):
    a = find(a)
    b = find(b)

    return a == b


n, m = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(m)]

edges.sort(key=lambda x: x[2])
parent = [i for i in range(n + 1)]
answer = 0
max_value = 0
for a, b, c in edges:
    if isUnion(a, b):
        continue
    merge(a, b)
    answer += c
    max_value = max(max_value, c)

print(answer - max_value)
