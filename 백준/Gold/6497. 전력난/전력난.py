def find(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]


def isSameParent(a, b):
    a = find(a)
    b = find(b)

    return a == b


def merge(a, b):
    a = find(a)
    b = find(b)

    parent[b] = a


while True:
    m, n = map(int, input().split())
    if m == 0 and n == 0:
        break

    edges = [list(map(int, input().split())) for _ in range(n)]
    answer = sum(edge[2] for edge in edges)
    edges.sort(key=lambda x: x[2])
    parent = [0] * (m + 1)
    for i in range(m + 1):
        parent[i] = i

    for edge in edges:
        if not isSameParent(edge[0], edge[1]):
            merge(edge[0], edge[1])
            answer -= edge[2]

    print(answer)
