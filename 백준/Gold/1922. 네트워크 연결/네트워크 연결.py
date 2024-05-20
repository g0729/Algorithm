def find(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]


def isUnion(a, b):
    a = find(a)
    b = find(b)

    return a == b


def merge(a, b):
    a = find(a)
    b = find(b)

    parent[b] = a


n = int(input())
m = int(input())
parent = [i for i in range(n + 1)]
edges = [tuple(map(int, input().split())) for _ in range(m)]

edges.sort(key=lambda x: x[2])
answer = 0
for a, b, c in edges:
    if isUnion(a, b):
        continue

    merge(a, b)
    answer += c

print(answer)
