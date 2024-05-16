def find(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]


def merge(a, b):
    a = find(a)
    b = find(b)
    if a < b:
        parent[b] = a
    elif a > b:
        parent[a] = b
    else:
        parent[a] = parent[b] = 0


idx = 1
while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    parent = [0] * (n + 1)
    for i in range(1, n + 1):
        parent[i] = i
    isTree = [True] * (n + 1)
    for _ in range(m):
        a, b = map(int, input().split())
        merge(a, b)
    se = set([find(i) for i in range(1, n + 1) if find(i)])
    answer = len(se)
    print(f"Case {idx}: ", end="")
    if answer == 0:
        print("No trees.")
    elif answer == 1:
        print("There is one tree.")
    else:
        print(f"A forest of {answer} trees.")
    idx += 1
